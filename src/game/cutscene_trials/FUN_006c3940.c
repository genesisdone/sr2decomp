/* Whole initialization 006c3940..006c396a. Eight 0xac-byte slot headers. */
typedef struct CsBootstrapSlot { int field_00; unsigned char unknown_04[0xa8]; } CsBootstrapSlot;
extern CsBootstrapSlot DAT_027e6158[8];
/* Exact original end-address symbol, 8 * 0xac bytes after the start. */
extern CsBootstrapSlot DAT_027e66b8[];
extern unsigned char DAT_02527d26;
extern void __cdecl FUN_006d4630(void);
__declspec(noinline) void __cdecl FUN_006c3940(void)
{
    CsBootstrapSlot *item;
    FUN_006d4630();
    /* Native 006c3960 uses signed JL for this 32-bit address comparison. */
    item=DAT_027e6158;
    do {
        item->field_00=-1;
        ++item;
    } while ((int)item<(int)DAT_027e66b8);
    DAT_02527d26=0;
}
