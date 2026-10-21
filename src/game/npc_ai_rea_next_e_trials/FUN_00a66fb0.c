/* FUN_00a66fb0: forwards its object (ECX) to FUN_00a67190, which takes it in EDX, as a tail jump. */
int FUN_00a67190(int object);

__declspec(noinline) int __fastcall FUN_00a66fb0(int object)
{
	return FUN_00a67190(object);
}
