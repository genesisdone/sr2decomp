/* FUN_004463d0: clears DAT_00ee201e, runs FUN_00450c80, copies DAT_027976c8 to DAT_00ee27e0 when it lies in
   [0, 1], arms the timer DAT_00e9a3cc for a random 10,000..20,000 ms (FUN_00bdd1b0), then looks up "PML_Streaker"
   in the table DAT_028f0578 (FUN_00c07160) and points DAT_02526a4c at its 20-byte record in DAT_0168b090, or at
   nothing when the index is negative or not below DAT_02527d74. */
extern unsigned char DAT_00ee201e;
extern float DAT_027976c8;
extern float DAT_00ee27e0;
extern int DAT_00e9a3cc;
extern int DAT_028f0578;
extern char s_PML_Streaker_00dd75f0[];
extern short DAT_02527d74;
extern int DAT_0168b090[];
extern int *DAT_02526a4c;
void FUN_00450c80(void);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);
short __stdcall FUN_00c07160(int *table, char *name);

__declspec(noinline) void FUN_004463d0(void)
{
	short index;
	int *record;
	DAT_00ee201e = 0;
	FUN_00450c80();
	if (!(DAT_027976c8 < 0.0f) && !(DAT_027976c8 > 1.0f)) {
		DAT_00ee27e0 = DAT_027976c8;
	}
	FUN_00bdd1b0(&DAT_00e9a3cc, 20000, 10000);
	index = FUN_00c07160(&DAT_028f0578, s_PML_Streaker_00dd75f0);
	if (index >= 0 && index < DAT_02527d74) {
		record = DAT_0168b090 + index * 5;
	} else {
		record = 0;
	}
	DAT_02526a4c = record;
}
