/* FUN_00923db0: kind = object+0x1e4, level = FUN_0055f670(kind). 0 unless object+0x200 <= level <= object+0x204.
   If FUN_009e1ea0(DAT_021703d4): the byte object+0x2a9 must equal (level > 3 || kind == 6). Otherwise level 3
   fails, and kind 5 at level 4 needs object+0x2a9 == DAT_025295ca. Then returns DAT_00e88be4 == kind.
   Native takes the object in ECX. */
int FUN_0055f670(int kind);
char FUN_009e1ea0(int object);
extern int DAT_021703d4;
extern char DAT_025295ca;
extern int DAT_00e88be4;

__declspec(noinline) char __fastcall FUN_00923db0(int object)
{
	int kind = *(int *)(object + 0x1e4);
	int level = FUN_0055f670(kind);
	char want;
	if (level < *(int *)(object + 0x200) || level > *(int *)(object + 0x204))
		return 0;
	if (FUN_009e1ea0(DAT_021703d4)) {
		if (level > 3 || kind == 6)
			want = 1;
		else
			want = 0;
		if (*(char *)(object + 0x2a9) != want)
			return 0;
	} else {
		if (level == 3)
			return 0;
		if (kind == 5 && level == 4 && *(char *)(object + 0x2a9) != DAT_025295ca)
			return 0;
	}
	return DAT_00e88be4 == kind;
}
