/* FUN_00784630: on the object (native: EAX) clears the float +0x85dc and bit 0x10 of byte +0x856a, then on the
   sub-object at +0x8554 (native moves its object pointer there): FUN_00b2b8a0(sub, 0) (native: stdcall-style, the flag
   a full stack word); FUN_00683fb0(handle +0x5c) when that handle is non-zero; clears +0x24 and the handle;
   FUN_00b2c220(sub, 0); tail-calls FUN_00b44110(sub). */
void __stdcall FUN_00b2b8a0(int sub, int flag);
void FUN_00683fb0(unsigned short handle);
void __stdcall FUN_00b2c220(int sub, char flag);
void __fastcall FUN_00b44110(int sub);

__declspec(noinline) void FUN_00784630(int object)
{
	*(float *)(object + 0x85dc) = 0.0f;
	*(unsigned char *)(object + 0x856a) &= 0xef;
	object = object + 0x8554;
	FUN_00b2b8a0(object, 0);
	if (*(unsigned short *)(object + 0x5c) != 0) {
		FUN_00683fb0(*(unsigned short *)(object + 0x5c));
	}
	*(int *)(object + 0x24) = 0;
	*(unsigned short *)(object + 0x5c) = 0;
	FUN_00b2c220(object, 0);
	FUN_00b44110(object);
}
