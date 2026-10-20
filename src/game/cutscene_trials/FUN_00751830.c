/* Whole 00751830..0075185f; no gameplay names inferred from flags.
 * Both calls have no incoming arguments; their bodies are separate work.
 */
extern unsigned char DAT_02527d14, DAT_02527cf7, DAT_02527d15, DAT_00e8d56b;
extern void __cdecl FUN_00751960(void);
extern void __cdecl FUN_006c43f0(void);
__declspec(noinline) int __cdecl FUN_00751830(void)
{
    if ((DAT_02527d14 && DAT_02527cf7) || DAT_02527d15) {
        FUN_00751960();
        FUN_006c43f0();
        DAT_00e8d56b = 1;
    }
    return 0;
}
