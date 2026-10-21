/* FUN_00784530: FUN_007a20a0(10, object[+0x1f4]). Native takes the object in EAX. */
void FUN_007a20a0(int kind, int value);

__declspec(noinline) void FUN_00784530(int object)
{
	FUN_007a20a0(10, *(int *)(object + 0x1f4));
}
