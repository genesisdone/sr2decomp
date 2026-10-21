/* FUN_0090f830: when the object's +0x2c handle resolves (16-byte table at DAT_02149c64, entry +0x44 == handle) to
   a type-1 record (+0x4c), looks at the group at object+0x30. If the object is the group's leader (+8), the
   partner is FUN_009149a0(group[+0x1c]); otherwise it is the member following the object in the group's list
   (count at (group[+4])+0x48, members from group+0xc). With a live partner (its +0x30 record has a non-zero +4)
   whose +0x2c is 0, FUN_0090f390(object, 0). A leader without a live partner instead calls FUN_0090f390(object, 0)
   when its timer at +0x54 is not negative and FUN_00bdd230(&timer) is true. Native takes the object in EDI. */
extern int DAT_02149c64[];
int FUN_009149a0(int handle);
char FUN_00bdd230(int *timer);
void FUN_0090f390(int entry, char forced);

__declspec(noinline) void FUN_0090f830(int object)
{
	int handle = *(int *)(object + 0x2c);
	int record;
	int group;
	int partner;
	int live;
	int count;
	int i;
	if (handle == 0 || (record = DAT_02149c64[(handle & 0xfff) * 4]) == 0 ||
	    *(int *)(record + 0x44) != handle || *(int *)(record + 0x4c) != 1) {
		return;
	}
	group = *(int *)(object + 0x30);
	if (object == *(int *)(group + 8)) {
		partner = FUN_009149a0(*(int *)(group + 0x1c));
		if (partner == 0 || (live = *(int *)(partner + 0x30)) == 0 || *(int *)(live + 4) == 0) {
			if (*(int *)(object + 0x54) < 0) {
				return;
			}
			if (FUN_00bdd230((int *)(object + 0x54)) != 0) {
				FUN_0090f390(object, 0);
			}
			return;
		}
	} else {
		count = *(unsigned char *)(*(int *)(group + 4) + 0x48);
		for (i = 1; i < count; i++) {
			if (((int *)(group + 8))[i] == object) {
				break;
			}
		}
		partner = ((int *)(group + 4))[i];
		if (partner == 0 || (live = *(int *)(partner + 0x30)) == 0 || *(int *)(live + 4) == 0) {
			return;
		}
	}
	if (*(int *)(partner + 0x2c) == 0) {
		FUN_0090f390(object, 0);
	}
}
