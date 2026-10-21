/* REA ev_9f0aab9fdab29e0f00a89445a27f3665a90b272b0a15c5fe90f653e10d8992a4; logical C interface, not a callable native ABI declaration. */
__declspec(noinline) void FUN_004b9570(unsigned char *record)
{
    *(unsigned __int64 *)(record + 0x30) &= ~0x180ui64;
    *(unsigned __int64 *)(record + 0x30) |= 0x40ui64;
    *(int *)(record + 0x28) = -1;
    *(float *)(*(unsigned char **)(record + 0x40) + 0x4c) = 0.0f;
}
