/* FUN_009244a0: returns 1 when every non-null record of the eight at object+0x224 passes and the handle at
   *(object+0x220) is live (FUN_00a796d0), plus, when object is DAT_02149c38, the handle reached through
   DAT_02149c3c+0xa0. A record passes through FUN_009435f0(object[+0x1e4], 1) when its +8 entry is non-null,
   has bit 1 of +0x60 clear, +0x48 != 7 and its +8 name compares equal (FUN_00bf2770) to the string at
   00dda808; otherwise through FUN_00a796d0 of the entry's +0x68 handle. */
extern char DAT_00dda808[];
extern int DAT_02149c38;
extern int DAT_02149c3c;
int FUN_00bf2770(int name, const char *text);
int FUN_009435f0(int value, int flag);
char FUN_00a796d0(int handle);

__declspec(noinline) char __fastcall FUN_009244a0(int object)
{
	int index;
	int *record;
	int *pointer;
	for (index = 0, record = (int *)(object + 0x224); index < 8; index++, record++) {
		if (*record != 0) {
			int entry = *(int *)(*record + 8);
			if (entry != 0 && (*(unsigned char *)(entry + 0x60) & 2) == 0 && *(int *)(entry + 0x48) != 7 &&
			    FUN_00bf2770(*(int *)(entry + 8), DAT_00dda808) == 0) {
				if (FUN_009435f0(*(int *)(object + 0x1e4), 1) == 0) {
					return 0;
				}
			} else if (!FUN_00a796d0(*(int *)(*(int *)(*record + 8) + 0x68))) {
				return 0;
			}
		}
	}
	pointer = *(int **)(object + 0x220);
	if (pointer == 0 || !FUN_00a796d0(*pointer)) {
		return 0;
	}
	if (DAT_02149c38 == object &&
	    !FUN_00a796d0(*(int *)(*(int *)(*(int *)(DAT_02149c3c + 0xa0) + 8) + 0x68))) {
		return 0;
	}
	return 1;
}
