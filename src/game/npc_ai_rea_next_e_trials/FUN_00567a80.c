/* FUN_00567a80: arms the timer at object+0x1e8 with FUN_00bdd1b0 (random duration in [20000, 0xafc8] ms on the
   ms clock) and sets the state object+0x1f0 = 3. Native takes the object in ESI. */
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);

__declspec(noinline) void FUN_00567a80(int object)
{
	FUN_00bdd1b0((int *)(object + 0x1e8), 0xafc8, 20000);
	*(int *)(object + 0x1f0) = 3;
}
