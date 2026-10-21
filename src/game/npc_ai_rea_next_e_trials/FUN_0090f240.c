/* FUN_0090f240: when the timer object+0x54 is not armed (negative) and the handle object+0x2c names a live entry
   (slot DAT_02149c64[(handle & 0xfff) * 4], entry+0x44 == handle, entry+0x4c == 1), and FUN_0096f3f0(entry) is -1:
   looks the entry up with FUN_006ac360 (index into the 0x18-byte table at 0x027d83c8, field +4, or -1) and, unless
   that equals a valid object[+0x34]+8, arms the timer with FUN_00bdd1b0 in [x+0x8c, x+0x90] for x = object[+0x34].
   Native takes the object as a cdecl stack argument. */
int FUN_0096f3f0(int entry);
int __fastcall FUN_006ac360(int entry);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);
extern int DAT_02149c64[];
extern int DAT_027d83cc[];

__declspec(noinline) void FUN_0090f240(int object)
{
	unsigned int handle;
	int entry;
	int value;
	int current;
	if (*(int *)(object + 0x54) >= 0) {
		return;
	}
	handle = *(unsigned int *)(object + 0x2c);
	if (handle == 0) {
		return;
	}
	entry = DAT_02149c64[(handle & 0xfff) * 4];
	if (entry == 0 || *(unsigned int *)(entry + 0x44) != handle || *(int *)(entry + 0x4c) != 1) {
		return;
	}
	if (FUN_0096f3f0(entry) != -1) {
		return;
	}
	value = FUN_006ac360(entry);
	if (value >= 0) {
		value = DAT_027d83cc[value * 6];
	} else {
		value = -1;
	}
	current = *(int *)(*(int *)(object + 0x34) + 8);
	if (value != current || current == -1) {
		int settings = *(int *)(object + 0x34);
		FUN_00bdd1b0((int *)(object + 0x54), *(int *)(settings + 0x90), *(int *)(settings + 0x8c));
	}
}
