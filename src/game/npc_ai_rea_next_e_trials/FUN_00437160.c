/* FUN_00437160: increments DAT_02526a44, clears DAT_02526a10 and DAT_00ee201e, and calls fifteen no-argument
   routines in a fixed order (FUN_00408e90 ... FUN_00436490). */
extern int DAT_02526a44;
extern int DAT_02526a10;
extern char DAT_00ee201e;
void FUN_00408e90(void);
void FUN_00410560(void);
void FUN_0041ac50(void);
void FUN_0041acf0(void);
void FUN_0041ae70(void);
void FUN_00421060(void);
void FUN_00428e90(void);
void FUN_0044ad10(void);
void FUN_00451460(void);
void FUN_0054b090(void);
void FUN_00435270(void);
void FUN_004355e0(void);
void FUN_0045ebe0(void);
void FUN_00436490(void);

__declspec(noinline) void FUN_00437160(void)
{
	DAT_02526a44++;
	DAT_02526a10 = 0;
	FUN_00408e90();
	FUN_00410560();
	FUN_0041ac50();
	FUN_0041acf0();
	FUN_0041ae70();
	FUN_00421060();
	FUN_00428e90();
	DAT_00ee201e = 0;
	FUN_0044ad10();
	FUN_00451460();
	FUN_0054b090();
	FUN_00435270();
	FUN_004355e0();
	FUN_0045ebe0();
	FUN_00436490();
}
