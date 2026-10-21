/* FUN_00787e40 (moved from gate npc-ai-rea-a-named-data): finds the group (0x3ac-byte records at DAT_029dc238,
   DAT_02528400 of them) whose member list (+0x2c pointers, +0x3c count) holds a member with +8 == input. Only offsets
   +0x2c / +0x3c and the 0x3ac size are established; the member array's bound (4 here) is not. */
struct group {
	unsigned char pad[0x2c];
	int *members[4];
	int count;
	unsigned char rest[0x3ac - 0x40];
};
extern int DAT_02528400;
extern struct group DAT_029dc238[];
__declspec(noinline) struct group *FUN_00787e40(int input)
{
	int i;
	int j;
	struct group *group;
	for (i = 0; i < DAT_02528400; i++) {
		group = &DAT_029dc238[i];
		for (j = 0; j < group->count; j++) {
			if (input == group->members[j][2]) {
				return group;
			}
		}
	}
	return 0;
}
