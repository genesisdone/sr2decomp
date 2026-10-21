/* Recovered from REA ev_dab81e697b67bae990492922c082bc7c22a2b2b3d8638c582792ed6f828ca2d4; whole body at 004b45f0.
   Byte return follows the native AL-only default path. */
extern unsigned char *DAT_02612d00;
unsigned char FUN_004b45f0(void)
{
    if (DAT_02612d00 != 0) {
        return (unsigned char)((*(unsigned int *)(DAT_02612d00 + 0x20) >> 3) & 1);
    }
    return 0;
}
