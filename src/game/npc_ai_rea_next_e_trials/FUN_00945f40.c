/* FUN_00945f40: FUN_009459d0(first, second); then restarts the timer at DAT_00eb7b7c with FUN_00bdd1b0 on
   5000..20000 when the DAT_021703d4->+0xf00 record has bit 1 of +0x58 or DAT_00e9e3f8 is 1 or 2, else on
   20000..60000; and sets DAT_0215da34 to -1. */
extern int DAT_021703d4;
extern int DAT_00e9e3f8;
extern int DAT_00eb7b7c;
extern int DAT_0215da34;
void FUN_009459d0(int first, int second);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);

static __forceinline char quick_respawn(void)
{
	int record = *(int *)(DAT_021703d4 + 0xf00);
	if (record != 0 && (*(unsigned char *)(record + 0x58) & 1) != 0) {
		return 1;
	}
	if (DAT_00e9e3f8 == 1 || DAT_00e9e3f8 == 2) {
		return 1;
	}
	return 0;
}

__declspec(noinline) void FUN_00945f40(int first, int second)
{
	FUN_009459d0(first, second);
	if (quick_respawn()) {
		FUN_00bdd1b0(&DAT_00eb7b7c, 20000, 5000);
	} else {
		FUN_00bdd1b0(&DAT_00eb7b7c, 60000, 20000);
	}
	DAT_0215da34 = -1;
}
