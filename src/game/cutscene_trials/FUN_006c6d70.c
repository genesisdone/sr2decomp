/* Whole native predicate: 006c6d70..006c6d8b. */
typedef struct CsFlagB01View {
    unsigned char unknown_000[0xb01];
    unsigned char field_b01;
} CsFlagB01View;
extern CsFlagB01View *DAT_02527d10;
__declspec(noinline) int __cdecl FUN_006c6d70(void)
{
    if (DAT_02527d10 != 0 && DAT_02527d10->field_b01 != 0)
        return 1;
    return 0;
}
