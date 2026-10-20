/* FUN_00524fa0: picks table DAT_0277cbf0 when flag is set, else DAT_0277ce00, and returns 0 unless
   FUN_00a020c0(table, first, second) is non-zero; then returns 1 when flag is clear, otherwise
   whether FUN_00524550(first, second) is zero. first and second are pointers this function only
   passes on (native: in EDX and ESI; FUN_00a020c0 gets the ESI one in ECX). */
extern unsigned char DAT_0277cbf0[];
extern unsigned char DAT_0277ce00[];
int FUN_00a020c0(unsigned char *table, const float *first, const float *second);
unsigned char FUN_00524550(const float *first, const float *second);
__declspec(noinline) unsigned char FUN_00524fa0(const float *first, const float *second, unsigned char flag)
{
    unsigned char *table;
    unsigned char *keep = &flag;
    (void)keep;
    table = DAT_0277cbf0;
    if (flag == 0) {
        table = DAT_0277ce00;
    }
    if (FUN_00a020c0(table, first, second) == 0) {
        return 0;
    }
    if (flag == 0) {
        return 1;
    }
    return FUN_00524550(first, second) == 0;
}
