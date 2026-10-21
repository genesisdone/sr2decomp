/* FUN_0041dad0: records that npc has seen target. Unless target is null, or target's byte +0x3cc is 2 and
   FUN_009ce0a0(npc, target) fails, or npc's +0xc3c is zero: refreshes the matching entry of the 16-byte table
   at DAT_0253ad30 (DAT_02526a2c entries: npc handle, target handle, time, flag) with the time DAT_00e843ac
   (wrapped past 1800000000) and flag |= argument, or appends a new entry while there are fewer than 0x40. */
struct seen_entry {
	int npc;
	int target;
	int time;
	char flag;
};
extern int DAT_02526a2c;
extern int DAT_00e843ac;
extern struct seen_entry DAT_0253ad30[];
char FUN_009ce0a0(int target, int npc);

static __forceinline void timer_start(int *timer, int ms)
{
	int value = DAT_00e843ac + ms;
	*timer = value;
	if (value > 1800000000) {
		*timer = value - 1800000000;
	}
}

__declspec(noinline) void FUN_0041dad0(int target, int npc, char flag)
{
	int count;
	int index;
	int value;
	struct seen_entry *entry;
	if (target == 0) {
		return;
	}
	if (*(char *)(target + 0x3cc) == 2 && !FUN_009ce0a0(target, npc)) {
		return;
	}
	if (*(int *)(npc + 0xc3c) == 0) {
		return;
	}
	count = DAT_02526a2c;
	entry = DAT_0253ad30;
	for (index = 0; index < count; index++, entry++) {
		if (*(int *)(npc + 0x44) == entry->npc && entry->target == *(int *)(target + 0x44)) {
			timer_start(&entry->time, 0);
			if (entry->flag == 0 && flag == 0) {
				value = 0;
			} else {
				value = 1;
			}
			entry->flag = value;
			return;
		}
	}
	if (count < 0x40) {
		entry = &DAT_0253ad30[count];
		DAT_02526a2c = count + 1;
		entry->npc = *(int *)(npc + 0x44);
		entry->target = *(int *)(target + 0x44);
		timer_start(&entry->time, 0);
		entry->flag = flag;
	}
}
