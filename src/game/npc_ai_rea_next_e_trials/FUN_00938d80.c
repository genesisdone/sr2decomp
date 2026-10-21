/* FUN_00938d80: 1 when the NPC may act, 0 otherwise. 0 for no NPC; 0 when its +0xb0 record is set and the player
   (DAT_02528c14 +0x408) exists and either the record's first byte differs from the player's +0x1b0 byte or the
   record's +0x67c bit 0 is set; 0 when its +0x84e4 block's +0x59c is not -1 and its +0x904c entry's +4 is set;
   0 when FUN_00ae4dc0 or FUN_00ae4f70 says so; 0 when any of its first eight 0x24-byte slots at +0x8abc (eight,
   or +0x6ce8 when the +0x84d8 byte is 1) resolves (FUN_00960d60) to an object FUN_0098e8a0 accepts; and, when its
   +0x44 matches DAT_021703d4 +0x18d0, 0 when its xz distance squared to that object is below DAT_0215d9f8.
   Native takes the NPC in EAX. */
unsigned char *FUN_00960d60(int handle);
char FUN_0098e8a0(unsigned char *object);
char FUN_00ae4dc0(unsigned char *npc);
char FUN_00ae4f70(unsigned char *npc);
extern unsigned char *DAT_02528c14;
extern unsigned char *DAT_021703d4;
extern int DAT_0215d9f8;

static __forceinline char same_team(unsigned char *npc)
{
	unsigned char *record;
	unsigned char *player;
	if (npc == 0) {
		return 0;
	}
	record = *(unsigned char **)(npc + 0xb0);
	if (record == 0 || DAT_02528c14 == 0) {
		return 1;
	}
	player = *(unsigned char **)(DAT_02528c14 + 0x408);
	if (player == 0) {
		return 1;
	}
	if (record[0] != player[0x1b0]) {
		return 0;
	}
	if ((record[0x67c] & 1) != 0) {
		return 0;
	}
	return 1;
}

__declspec(noinline) char FUN_00938d80(unsigned char *npc)
{
	unsigned char *entry;
	unsigned char *object;
	unsigned char *slot;
	char single;
	char active;
	int count;
	unsigned int index;
	float dx;
	float dz;
	float distance;
	if (!same_team(npc)) {
		return 0;
	}
	if (*(int *)(*(unsigned char **)(npc + 0x84e4) + 0x59c) != -1) {
		entry = *(unsigned char **)(npc + 0x904c);
		active = 0;
		if (entry != 0) {
			active = (char)(*(int *)(entry + 4) != 0);
		}
		if (active == 1) {
			return 0;
		}
	}
	if (FUN_00ae4dc0(npc) != 0) {
		return 0;
	}
	if (FUN_00ae4f70(npc) != 0) {
		return 0;
	}
	single = npc[0x84d8];
	index = 0;
	slot = npc + 0x8abc;
	for (; index < 8; index++) {
		if (single != 1) {
			count = 8;
		} else {
			count = *(int *)(npc + 0x6ce8);
		}
		if (count != 0 && (int)index < count) {
			object = FUN_00960d60(*(int *)slot);
			if (object != 0 && FUN_0098e8a0(object) != 0) {
				return 0;
			}
		}
		slot += 0x24;
	}
	if (*(int *)(npc + 0x44) == *(int *)(DAT_021703d4 + 0x18d0)) {
		dx = *(float *)(npc + 0x14) - *(float *)(DAT_021703d4 + 0x14);
		dz = *(float *)(npc + 0x1c) - *(float *)(DAT_021703d4 + 0x1c);
		distance = dx * dx + dz * dz;
		if (distance < DAT_0215d9f8) {
			return 0;
		}
	}
	return 1;
}
