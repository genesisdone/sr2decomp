/* FUN_00567d00: dispatches on the state word object+0x1f0: 0 does nothing, 1 FUN_00567b30, 2 FUN_00567bc0,
   3 FUN_00567c10, 4 FUN_00567990; any other state is reset to 0. The switch is an audited local jump table. */
void FUN_00567b30(unsigned char *object);
void FUN_00567bc0(unsigned char *object);
void FUN_00567c10(unsigned char *object);
void FUN_00567990(unsigned char *object);

__declspec(noinline) void __fastcall FUN_00567d00(unsigned char *object)
{
	switch (*(int *)(object + 0x1f0)) {
	case 0:
		return;
	case 1:
		FUN_00567b30(object);
		return;
	case 2:
		FUN_00567bc0(object);
		return;
	case 3:
		FUN_00567c10(object);
		return;
	case 4:
		FUN_00567990(object);
		return;
	}
	*(int *)(object + 0x1f0) = 0;
}
