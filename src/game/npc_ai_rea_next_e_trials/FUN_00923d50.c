/* FUN_00923d50: a factor for the object's +0x1e4 kind as rated by FUN_0055f670: DAT_00dd0794, DAT_00dd0550,
   DAT_00e1d904 or DAT_00dd071c for ratings 2..5, else 0.0. The switch is an audited local jump table. */
extern float DAT_00dd0794;
extern float DAT_00dd0550;
extern float DAT_00e1d904;
extern float DAT_00dd071c;
int FUN_0055f670(int kind);

__declspec(noinline) float __fastcall FUN_00923d50(unsigned char *object)
{
	switch (FUN_0055f670(*(int *)(object + 0x1e4))) {
	case 2:
		return DAT_00dd0794;
	case 3:
		return DAT_00dd0550;
	case 4:
		return DAT_00e1d904;
	case 5:
		return DAT_00dd071c;
	}
	return 0.0f;
}
