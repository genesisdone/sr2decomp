/* FUN_00436da0: looks up the animation-state index of the DAT_00dc594c action twice (FUN_00980390) into
   DAT_00ee1301 and DAT_00ee1300, runs the setup functions FUN_00402dd0, FUN_004271a0, FUN_004463d0 and
   FUN_00453ba0, sets bits 0x0b of DAT_0253b130, runs FUN_00417850 and FUN_00433720 and tail-calls FUN_00436e70. */
extern const char DAT_00dc594c[];
extern unsigned char DAT_00ee1301;
extern unsigned char DAT_00ee1300;
extern unsigned char DAT_0253b130;
unsigned char FUN_00980390(const char *name);
void FUN_00402dd0(void);
void FUN_004271a0(void);
void FUN_004463d0(void);
void FUN_00453ba0(void);
void FUN_00417850(void);
void FUN_00433720(void);
void FUN_00436e70(void);

__declspec(noinline) void FUN_00436da0(void)
{
	DAT_00ee1301 = FUN_00980390(DAT_00dc594c);
	DAT_00ee1300 = FUN_00980390(DAT_00dc594c);
	FUN_00402dd0();
	FUN_004271a0();
	FUN_004463d0();
	FUN_00453ba0();
	DAT_0253b130 |= 0x0b;
	FUN_00417850();
	FUN_00433720();
	FUN_00436e70();
}
