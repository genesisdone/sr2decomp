/* FUN_00784680: creates an object with FUN_00a6e880(0x2d, 1), sets it up with FUN_00a6b4d0 from the vectors
   {A, 0, A} (A = DAT_00e5d9d4) and {B, C, B} (B = DAT_00dd5190, C = DAT_00dd0550) and three arguments, then
   FUN_00a68650(object, 0x2d, 3), sets the top three bits of byte +0x110 to 101, FUN_00a6bce0, FUN_00a6c140, and
   stores the object's +0x44 handle through out. */
extern float DAT_00e5d9d4;
extern float DAT_00dd5190;
extern float DAT_00dd0550;
int __stdcall FUN_00a6e880(int type, int count);
void __stdcall FUN_00a6b4d0(int object, int value, float *second, float *first, int a, int b);
void FUN_00a68650(int object, int type, int mode);
void FUN_00a6bce0(int object);
void FUN_00a6c140(int object);

__declspec(noinline) void FUN_00784680(int *out, int a, int b, int value)
{
	float first[3];
	float second[3];
	int object;
	first[0] = DAT_00e5d9d4;
	first[1] = 0.0f;
	first[2] = DAT_00e5d9d4;
	second[0] = DAT_00dd5190;
	second[1] = DAT_00dd0550;
	second[2] = DAT_00dd5190;
	object = FUN_00a6e880(0x2d, 1);
	FUN_00a6b4d0(object, value, second, first, a, b);
	FUN_00a68650(object, 0x2d, 3);
	*(unsigned char *)(object + 0x110) = (*(unsigned char *)(object + 0x110) & 0x1f) | 0xa0;
	FUN_00a6bce0(object);
	FUN_00a6c140(object);
	*out = *(int *)(object + 0x44);
}
