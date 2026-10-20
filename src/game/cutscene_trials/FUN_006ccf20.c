/* EXIT command handler, whole 006ccf20..006ccf53 (51 bytes).
 * A distinct original from 006d9030, with the same rounded clock adjustment. */
extern float DAT_027e6714,DAT_027e6710,DAT_027e66fc;
__declspec(noinline) void __cdecl FUN_006ccf20(void)
{
    float difference=DAT_027e6714-DAT_027e6710;
    DAT_027e6710=difference+DAT_027e6710;
    DAT_027e66fc=difference+DAT_027e66fc;
}
