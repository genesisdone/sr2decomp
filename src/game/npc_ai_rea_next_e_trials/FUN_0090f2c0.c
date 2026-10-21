/* FUN_0090f2c0: for an object whose +0x30 record has a +4 word, resolves the handle at +0x2c in the DAT_02149c64
   table (live entry, +0x4c == 1, +0x2f8 set) and, if FUN_00806720(entry) and the DAT_00eb5358 timer allow it
   (FUN_00bdd230), calls FUN_006ae180(entry, id from +0x34 record +8 or 0x120, DAT_00e87998, 0xffff, 1); on 1
   it rearms the timer (FUN_00bdd1b0, 5000/3000) and returns 1. */
extern int DAT_02149c64[];
extern int DAT_00eb5358;
extern float DAT_00e87998;
char FUN_00806720(int entry);
char FUN_00bdd230(int *timer);
char FUN_006ae180(int entry, int id, float value, int mask, int flag);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);

__declspec(noinline) char FUN_0090f2c0(int object)
{
	int record;
	unsigned int handle;
	int entry;
	int id;
	if (object == 0 || *(int *)(object + 0x30) == 0 || *(int *)(*(int *)(object + 0x30) + 4) == 0) {
		return 0;
	}
	record = *(int *)(object + 0x34);
	handle = *(unsigned int *)(object + 0x2c);
	if (handle == 0) {
		return 0;
	}
	entry = DAT_02149c64[(handle & 0xfff) * 4];
	if (entry == 0 || *(unsigned int *)(entry + 0x44) != handle || *(int *)(entry + 0x4c) != 1 ||
	    *(int *)(entry + 0x2f8) == 0) {
		return 0;
	}
	if (FUN_00806720(entry) == 0) {
		return 0;
	}
	if (DAT_00eb5358 >= 0 && FUN_00bdd230(&DAT_00eb5358) != 1) {
		return 0;
	}
	id = *(int *)(record + 8);
	if (id == -1) {
		id = 0x120;
	}
	if (FUN_006ae180(entry, id, DAT_00e87998, 0xffff, 1) != 1) {
		return 0;
	}
	FUN_00bdd1b0(&DAT_00eb5358, 5000, 3000);
	return 1;
}
