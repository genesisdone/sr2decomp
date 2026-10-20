/* FUN_00828590: when the counter DAT_00e96c00 is above 10, the object DAT_02528c14 exists, the byte
   flag DAT_02528b56 is clear or DAT_02528b2b is set, and the object's byte +0x3f8 is set: if
   FUN_00881a70() and FUN_00bdd230(&DAT_00eb21ac) are both non-zero, calls FUN_00827f00 and sets the
   deadline DAT_00eb21ac to the clock DAT_00e843ac + 10000, wrapped down by 1,800,000,000. */
extern int DAT_00e96c00;
extern unsigned char *DAT_02528c14;
extern unsigned char DAT_02528b56;
extern unsigned char DAT_02528b2b;
extern int DAT_00e843ac;
extern int DAT_00eb21ac;
unsigned char FUN_00881a70(void);
unsigned char FUN_00bdd230(int *deadline);
void FUN_00827f00(void);
__declspec(noinline) void FUN_00828590(void)
{
    if (DAT_00e96c00 < 11) {
        return;
    }
    if (DAT_02528c14 == 0) {
        return;
    }
    if (DAT_02528b56 != 0 && DAT_02528b2b == 0) {
        return;
    }
    if (DAT_02528c14[0x3f8] == 0) {
        return;
    }
    if (FUN_00881a70() == 0) {
        return;
    }
    if (FUN_00bdd230(&DAT_00eb21ac) == 0) {
        return;
    }
    FUN_00827f00();
    DAT_00eb21ac = DAT_00e843ac + 10000;
    if (DAT_00eb21ac > 1800000000) {
        DAT_00eb21ac = DAT_00eb21ac - 1800000000;
    }
}
