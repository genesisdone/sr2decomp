/* FUN_00421060: prunes the "seen" table at DAT_0253ad30 (DAT_02526a2c 16-byte entries: npc handle, target handle,
   time, flag; filled by FUN_0041dad0). An entry is removed (the rest moved down with FUN_00c96060 = memmove) when
   either handle no longer names a usable human (type 1 at +0x4c, none of flags +0x80 bits 0/1/3/4, not excluded
   by FUN_00985630, bit 22 of +0xc8 set) or its time is more than 5000 ms in the past on the clock DAT_00e843ac
   (wrapping at 1800000000; a negative time counts as far in the future). Moved from gate npc-ai-rea-next-c
   (deferred there). */
struct seen_entry {
	unsigned int npc;
	unsigned int target;
	int time;
	char flag;
};
char FUN_00985630(int object);
void *FUN_00c96060(void *destination, const void *source, unsigned int bytes);
extern int DAT_02526a2c;
extern struct seen_entry DAT_0253ad30[];
extern int DAT_02149c64[];
extern int DAT_00e843ac;

static __forceinline int alert_human_from_handle(unsigned int handle)
{
	int object;
	unsigned int flags;
	if (handle == 0) {
		return 0;
	}
	object = DAT_02149c64[(handle & 0xfff) * 4];
	if (object == 0 || *(unsigned int *)(object + 0x44) != handle || *(int *)(object + 0x4c) != 1) {
		return 0;
	}
	flags = *(unsigned int *)(object + 0x80);
	if ((flags & 0xb) != 0 || FUN_00985630(object) || ((unsigned char)(flags >> 4) & 1) != 0 ||
	    (*(unsigned int *)(object + 0xc8) & 0x400000) == 0) {
		return 0;
	}
	return object;
}

static __forceinline int timer_remaining(int timer)
{
	int now;
	int delta;
	if (timer < 0) {
		return 1800000000;
	}
	now = DAT_00e843ac;
	if (timer > now) {
		delta = timer - now;
		if (delta > 900000000) {
			return delta - 1800000000;
		}
		return delta;
	}
	delta = now - timer;
	if (delta > 900000000) {
		return timer - now + 1800000000;
	}
	return -delta;
}

__declspec(noinline) void FUN_00421060(void)
{
	int index;
	struct seen_entry *entry;
	int npc;
	int target;
	int remaining;
	int count;
	index = 0;
	entry = DAT_0253ad30;
	if (DAT_02526a2c > 0) {
		do {
			npc = alert_human_from_handle(entry->npc);
			target = alert_human_from_handle(entry->target);
			remaining = timer_remaining(entry->time);
			if (npc == 0 || target == 0 || -remaining > 5000) {
				count = DAT_02526a2c - index - 1;
				if (count > 0) {
					FUN_00c96060(entry, entry + 1, count * sizeof(struct seen_entry));
				}
				DAT_02526a2c -= 1;
				index -= 1;
				entry -= 1;
			}
			index++;
			entry++;
		} while (index < DAT_02526a2c);
	}
}
