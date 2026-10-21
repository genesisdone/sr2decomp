/* FUN_005679c0: if FUN_00567840(object) is false, arms the timer at object+0x1e4 with FUN_00bdd1b0 (random in
   [3600000, 0x5265c0]), clears byte +0x1f5 and sets state +0x1f0 = 1. Otherwise clears byte +0x230 and word
   +0x20c, advances the 0x800-entry random index DAT_00ec3abc, sets +0x208 = 2 and +0x21c = 0, advances the index
   again, sets +0x218 = 2, arms +0x1ec to clock DAT_00e843ac + 300000 (wrapped at 1800000000) and state = 2.
   Native takes the object in EAX (moved to ESI). */
char FUN_00567840(unsigned char *object);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);
extern int DAT_00ec3abc;
extern int DAT_00e843ac;

__declspec(noinline) void FUN_005679c0(unsigned char *object)
{
	int clock;
	int value;
	if (FUN_00567840(object) == 0) {
		FUN_00bdd1b0((int *)(object + 0x1e4), 0x5265c0, 3600000);
		object[0x1f5] = 0;
		*(int *)(object + 0x1f0) = 1;
		return;
	}
	object[0x230] = 0;
	*(int *)(object + 0x20c) = 0;
	DAT_00ec3abc = DAT_00ec3abc + 1;
	if (DAT_00ec3abc >= 0x800) {
		DAT_00ec3abc = 0;
	}
	*(int *)(object + 0x208) = 2;
	*(int *)(object + 0x21c) = 0;
	DAT_00ec3abc = DAT_00ec3abc + 1;
	if (DAT_00ec3abc >= 0x800) {
		DAT_00ec3abc = 0;
	}
	clock = DAT_00e843ac;
	value = clock + 300000;
	*(int *)(object + 0x218) = 2;
	*(int *)(object + 0x1ec) = value;
	if (value > 1800000000) {
		*(int *)(object + 0x1ec) = value - 1800000000;
	}
	*(int *)(object + 0x1f0) = 2;
}
