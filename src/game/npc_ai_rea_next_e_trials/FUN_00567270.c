/* FUN_00567270: resets the object: FUN_00956080(object), the three handles at +0x1fc/+0x200/+0x1f8 = -1, state
   +0x1f0 = 0, byte +0x1f5 = 0, byte +0x1f4 = 1, then (as FUN_00567990 does) arms the timer at +0x1e4 with
   FUN_00bdd1b0 (random duration in [3600000, 0x5265c0] ms), clears +0x1f5 again and sets the state to 1.
   Native takes the object in ECX. */
void __fastcall FUN_00956080(int object);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);

__declspec(noinline) void __fastcall FUN_00567270(int object)
{
	FUN_00956080(object);
	*(int *)(object + 0x1fc) = -1;
	*(int *)(object + 0x200) = -1;
	*(int *)(object + 0x1f8) = -1;
	*(int *)(object + 0x1f0) = 0;
	*(unsigned char *)(object + 0x1f5) = 0;
	*(unsigned char *)(object + 0x1f4) = 1;
	FUN_00bdd1b0((int *)(object + 0x1e4), 0x5265c0, 3600000);
	*(unsigned char *)(object + 0x1f5) = 0;
	*(int *)(object + 0x1f0) = 1;
}
