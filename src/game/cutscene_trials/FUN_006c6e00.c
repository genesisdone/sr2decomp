/* Whole native predicate: 006c6e00..006c6e24. Return AL, not Ghidra's
 * incidental AX status-word view. TEST AH,41 / JP rejects greater and unordered;
 * less and equal take the AL=1 path (006c6e15..006c6e23). */
extern unsigned char DAT_02527d14;
extern float DAT_027e66fc, DAT_027e6700;
__declspec(noinline) unsigned char __cdecl FUN_006c6e00(void)
{
    if (DAT_02527d14 != 0 && DAT_027e66fc >= DAT_027e6700)
        return 1;
    return 0;
}
