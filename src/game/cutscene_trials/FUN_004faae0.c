/* Complete clock update 004faae0..004faafc; raw RET then INT3 padding. */
extern int DAT_00e843ac, DAT_00e9d4a8;
__declspec(noinline) void __cdecl FUN_004faae0(void)
{
    int time=DAT_00e843ac;
    DAT_00e9d4a8=time;
    if (time>1800000000)
        DAT_00e9d4a8=time-1800000000;
}
