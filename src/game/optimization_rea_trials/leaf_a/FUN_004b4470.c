/* Recovered from REA ev_3b42cf831f1e63b7487807b4cc009558ab62a38740f85982172335fd521632e2; whole body at 004b4470.
   Byte return follows the native AL-only default path. */
extern unsigned char *DAT_02612d00;
unsigned char FUN_004b4470(void)
{
    if (DAT_02612d00 != 0) {
        return (unsigned char)((*(unsigned int *)(DAT_02612d00 + 0x20) >> 8) & 1);
    }
    return 0;
}
