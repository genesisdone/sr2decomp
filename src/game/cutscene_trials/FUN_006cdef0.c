/* Complete 006cdef0..006cdf3f. Four distinct handle addresses are passed
 * in ECX to native 0047FEB0; Ghidra's old void() calls omitted these inputs.
 */
extern unsigned int DAT_00e94d04, DAT_00eab83c;
extern unsigned int DAT_00eab868, DAT_00eab844, DAT_00eab850, DAT_00eab85c;
extern unsigned char DAT_02527d25;
extern void __fastcall FUN_0047feb0(unsigned int *handle);
__declspec(noinline) void __cdecl FUN_006cdef0(void)
{
    if (DAT_00e94d04 != 0xffff) {
        if (DAT_00eab83c != 0) {
            FUN_0047feb0(&DAT_00eab868);
            FUN_0047feb0(&DAT_00eab844);
            FUN_0047feb0(&DAT_00eab850);
            FUN_0047feb0(&DAT_00eab85c);
        }
        DAT_02527d25 = 0;
        DAT_00e94d04 = 0xffff;
    }
}
