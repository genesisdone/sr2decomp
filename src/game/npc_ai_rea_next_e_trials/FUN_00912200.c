/* FUN_00912200: resets DAT_02529598/90/94 and DAT_0213d824, sets DAT_00e88c1c to 1, schedules DAT_00eb5354 one tick
   after the game time DAT_00e843ac (wrapping at 1,800,000,000), stores the FUN_00bdcb30 hash (seed 0) of the name
   at DAT_00e383f8 in DAT_02a4e504, runs FUN_00917cf0 and FUN_00916600 and tail-calls FUN_00917eb0. */
extern unsigned char DAT_02529598;
extern int DAT_02529590;
extern int DAT_02529594;
extern int DAT_0213d824;
extern int DAT_00e843ac;
extern unsigned short DAT_00e88c1c;
extern int DAT_00eb5354;
extern const char DAT_00e383f8[];
extern unsigned int DAT_02a4e504;
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
void FUN_00917cf0(void);
void FUN_00916600(void);
void FUN_00917eb0(void);

__declspec(noinline) void FUN_00912200(void)
{
	DAT_02529598 = 0;
	DAT_02529590 = 0;
	DAT_02529594 = 0;
	DAT_0213d824 = 0;
	DAT_00e88c1c = 1;
	DAT_00eb5354 = DAT_00e843ac + 1;
	if (DAT_00eb5354 > 0x6b49d200) {
		DAT_00eb5354 = DAT_00eb5354 - 0x6b49d200;
	}
	{
		unsigned int hash;
		DAT_02a4e504 = *FUN_00bdcb30(DAT_00e383f8, 0, &hash);
	}
	FUN_00917cf0();
	FUN_00916600();
	FUN_00917eb0();
}
