/* FUN_0090d1b0 (moved from gate npc-ai-rea-next-b): six {id, count} slots at DAT_0213f828. If a used slot already
   holds the id of the object's +0x24 record (its +8 word), bumps its count. Otherwise takes the first free slot
   (count 1); with no free slot clears object+0x24. On a new slot: when the +0x30 record has flag 0x80 at +0x48 and
   the +0x34 record's +0xc0 word is 0, sets bit 0 of DAT_021703d4+0x1164; else FUN_00944120(id, 3, 0, 1). Native
   compares the slot pointer with a signed JL, the strength-reduced form of an int index loop. */
struct slot {
	int id;
	int count;
};
extern struct slot DAT_0213f828[6];
extern unsigned char *DAT_021703d4;
void FUN_00944120(int id, int kind, int second, int third);
__declspec(noinline) void __fastcall FUN_0090d1b0(unsigned char *object)
{
	struct slot *slot;
	for (slot = DAT_0213f828; (int)slot < (int)(DAT_0213f828 + 6); slot++) {
		if (slot->count != 0 && slot->id == *(int *)(*(unsigned char **)(object + 0x24) + 8)) {
			slot->count++;
			return;
		}
	}
	for (slot = DAT_0213f828; (int)slot < (int)(DAT_0213f828 + 6); slot++) {
		if (slot->count == 0) {
			slot->id = *(int *)(*(unsigned char **)(object + 0x24) + 8);
			slot->count = 1;
			if ((*(unsigned char *)(*(unsigned char **)(object + 0x30) + 0x48) & 0x80) != 0 &&
			    *(int *)(*(unsigned char **)(object + 0x34) + 0xc0) == 0) {
				DAT_021703d4[0x1164] |= 1;
				return;
			}
			FUN_00944120(*(int *)(*(unsigned char **)(object + 0x24) + 8), 3, 0, 1);
			return;
		}
	}
	*(int *)(object + 0x24) = 0;
}
