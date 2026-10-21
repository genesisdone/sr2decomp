/* REA ev_623df4c1b9383442e7261be673a88f68ffa3457c9f4a15158e5311b166cbe1ba; complete native body. */
extern unsigned char *DAT_02225b3c[];
unsigned char FUN_00a7d5a0(unsigned int handle)
{
    unsigned char *record = DAT_02225b3c[handle >> 16] + (handle & 0xffff) * 0x28;
    if (record == 0) return 0;
    return *(int *)(record + 4) == 4;
}
