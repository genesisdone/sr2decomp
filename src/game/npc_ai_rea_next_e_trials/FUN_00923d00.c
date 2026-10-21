/* FUN_00923d00: a factor for the object's +0x1e4 kind as rated by FUN_0055f670: DAT_00e87628, DAT_00e88150,
   DAT_00e5cb28 or DAT_00e88364 for ratings 2..5, else 1.0. The switch is an audited local jump table. */
extern float DAT_00e87628;
extern float DAT_00e88150;
extern float DAT_00e5cb28;
extern float DAT_00e88364;
int FUN_0055f670(int kind);

__declspec(noinline) float __fastcall FUN_00923d00(unsigned char *object)
{
	switch (FUN_0055f670(*(int *)(object + 0x1e4))) {
	case 2:
		return DAT_00e87628;
	case 3:
		return DAT_00e88150;
	case 4:
		return DAT_00e5cb28;
	case 5:
		return DAT_00e88364;
	}
	return 1.0f;
}
