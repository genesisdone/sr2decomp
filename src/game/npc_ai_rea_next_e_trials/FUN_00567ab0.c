/* FUN_00567ab0: calls FUN_00567dc0(object), then sets object+0x1f0 = 4. Native takes the object in ESI. */
void __stdcall FUN_00567dc0(int object);

__declspec(noinline) void FUN_00567ab0(int object)
{
	FUN_00567dc0(object);
	*(int *)(object + 0x1f0) = 4;
}
