/* FUN_00567d60: sets the byte object+0x1f4 = 1 and, unless the state object+0x1f0 is already 1, re-arms the state
   with FUN_00567990(object). Native takes the object in ECX and passes it to FUN_00567990 in ESI. */
void FUN_00567990(int object);

__declspec(noinline) void __fastcall FUN_00567d60(int object)
{
	*(unsigned char *)(object + 0x1f4) = 1;
	if (*(int *)(object + 0x1f0) != 1) {
		FUN_00567990(object);
	}
}
