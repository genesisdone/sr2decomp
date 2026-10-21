/* FUN_00567190: for each of the 8 handles at object+0x8abc (stride 0x24), when the handle is live (non-zero,
   the slot DAT_02149c64[(handle & 0xfff) * 4] holds an entry whose +0x44 equals the handle and whose +0x4c is 1),
   calls FUN_00558fb0(entry + 0x10c4, FUN_0091d380(<string at 0x00dd5fb4>), 0, 0, 0). Native takes the object in
   EAX and passes the string to FUN_0091d380 in ESI. */
void __fastcall FUN_00558fb0(int target, int id, int a, int b, int c);
int FUN_0091d380(const char *name);
extern int DAT_02149c64[];
extern char DAT_00dd5fb4[];

__declspec(noinline) void FUN_00567190(int object)
{
	if (object != 0) {
		unsigned int *handle = (unsigned int *)(object + 0x8abc);
		int count = 8;
		do {
			unsigned int value = *handle;
			if (value != 0) {
				int entry = DAT_02149c64[(value & 0xfff) * 4];
				if (entry != 0 && *(unsigned int *)(entry + 0x44) == value && *(int *)(entry + 0x4c) == 1) {
					int id = FUN_0091d380(DAT_00dd5fb4);
					FUN_00558fb0(entry + 0x10c4, id, 0, 0, 0);
				}
			}
			handle = handle + 9;
			count = count - 1;
		} while (count != 0);
	}
}
