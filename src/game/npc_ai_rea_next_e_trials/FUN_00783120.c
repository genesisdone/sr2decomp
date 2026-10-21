/* FUN_00783120: callback for a handle. Resolves it in the handle table at 0x02149c64 (slot = handle & 0xfff,
   16 bytes each); when the object's +0x44 matches, its +0x4c is 1 and its +0x3cc byte is 2, and FUN_00787020
   gives an index inside [0, DAT_02528400), runs FUN_00787bd0, FUN_00447cd0, FUN_00968010, FUN_009d2150 and
   FUN_009d1c40 on the object and FUN_004406a0, FUN_00440a60, FUN_00440ce0, FUN_00441e60 on object+0xf8.
   Whenever the object passed the first checks it then sets four globals (5, 2, 0, 0).
   Native takes the handle as a cdecl stack word (it is registered as a callback). */
int FUN_00787020(unsigned char *object);
void FUN_00787bd0(unsigned char *object);
void FUN_00447cd0(unsigned char *object, int a, int b);
void __stdcall FUN_00968010(unsigned char *object, int a);
void __stdcall FUN_009d2150(unsigned char *object, int a);
void __stdcall FUN_009d1c40(unsigned char *object, int a);
void __stdcall FUN_004406a0(unsigned char *part, int a);
void __stdcall FUN_00440a60(unsigned char *part, int a);
void __stdcall FUN_00440ce0(unsigned char *part, int a);
void __stdcall FUN_00441e60(unsigned char *part, int a);
extern unsigned char DAT_02149c64[];
extern int DAT_02528400;
extern unsigned char DAT_029dc238[];
extern int DAT_029dc1e8;
extern int DAT_029dc224;
extern int DAT_029dc048;
extern int DAT_029dc050;

__declspec(noinline) void FUN_00783120(int handle)
{
	unsigned char *object;
	unsigned char *part;
	unsigned char *record;
	int index;
	if (handle == 0) {
		return;
	}
	object = *(unsigned char **)(DAT_02149c64 + (handle & 0xfff) * 16);
	if (object == 0 || *(int *)(object + 0x44) != handle || *(int *)(object + 0x4c) != 1 ||
	    object[0x3cc] != 2) {
		return;
	}
	index = FUN_00787020(object);
	if (index >= 0 && index < DAT_02528400) {
		record = DAT_029dc238 + index * 0x3ac;
	} else {
		record = 0;
	}
	if (record != 0) {
		FUN_00787bd0(object);
		FUN_00447cd0(object, 0, 0);
		FUN_00968010(object, 0);
		FUN_009d2150(object, 0);
		FUN_009d1c40(object, 0);
		part = object + 0xf8;
		FUN_004406a0(part, 0);
		FUN_00440a60(part, 0);
		FUN_00440ce0(part, 0);
		FUN_00441e60(part, 0);
	}
	DAT_029dc1e8 = 5;
	DAT_029dc224 = 2;
	DAT_029dc048 = 0;
	DAT_029dc050 = 0;
}
