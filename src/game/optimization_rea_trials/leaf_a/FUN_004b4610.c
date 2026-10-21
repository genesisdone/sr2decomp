/* Recovered from REA ev_3f9f7bf42bc23471b3ac4d80f7e9299f80e1ba14fb81b16fbc2d45bf6e2014ad; whole body at 004b4610.
   Byte return follows the native AL-only default path. */
extern unsigned char *DAT_02612d00;
unsigned char FUN_004b4610(void)
{
    if (DAT_02612d00 != 0) {
        return (unsigned char)(~(*(unsigned int *)(DAT_02612d00 + 0x20) >> 2) & 1);
    }
    return 1;
}
