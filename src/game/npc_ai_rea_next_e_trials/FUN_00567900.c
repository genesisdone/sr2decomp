/* FUN_00567900: only in game mode DAT_00e96c00 == 3: true when the object's byte +0x1f5 is 1; otherwise, when the
   local player DAT_021703d4 has an entry at +0xf00 without bit 1 of its byte +0x58, and FUN_0055f670(entry[+0x4c])
   is at most 1, returns whether DAT_0215da1d is set. Native takes the object as one stack word and pops it. */
extern int DAT_00e96c00;
extern int DAT_021703d4;
extern unsigned char DAT_0215da1d;
int FUN_0055f670(int kind);

__declspec(noinline) char __stdcall FUN_00567900(int object)
{
	int entry;
	if (DAT_00e96c00 == 3) {
		if (*(char *)(object + 0x1f5) == 1) {
			return 1;
		}
		if (DAT_021703d4 != 0) {
			entry = *(int *)(DAT_021703d4 + 0xf00);
			if (entry != 0 && (*(unsigned char *)(entry + 0x58) & 1) == 0) {
				if (FUN_0055f670(*(int *)(entry + 0x4c)) <= 1) {
					return (char)(DAT_0215da1d != 0);
				}
			}
		}
	}
	return 0;
}
