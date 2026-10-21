/* FUN_00567990: arms the timer at object+0x1e4 with FUN_00bdd1b0 (random duration in [3600000, 0x5265c0] ms on the
   ms clock), clears the byte object+0x1f5 and sets the state object+0x1f0 = 1. Native takes the object in ESI. */
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);

__declspec(noinline) void FUN_00567990(int object)
{
	FUN_00bdd1b0((int *)(object + 0x1e4), 0x5265c0, 3600000);
	*(unsigned char *)(object + 0x1f5) = 0;
	*(int *)(object + 0x1f0) = 1;
}
