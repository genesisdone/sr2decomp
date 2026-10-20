/* FUN_00a62d90: forwards its ECX object to FUN_00a63140, which takes it in EDX (native 00a62d90-00a62d96:
   mov edx, ecx ; jmp 00a63140). Expressed as __fastcall with the object in both registers. */
void __fastcall FUN_00a63140(int ecx_value, int object);

__declspec(noinline) void __fastcall FUN_00a62d90(int object)
{
	FUN_00a63140(object, object);
}
