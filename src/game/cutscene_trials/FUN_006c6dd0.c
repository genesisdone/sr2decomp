/* Whole native predicate: 006c6dd0..006c6df9. No invented null guard. */
typedef struct CsFlagsAfdView {
    unsigned char unknown_000[0xafd];
    unsigned char field_afd, unknown_afe, field_aff;
} CsFlagsAfdView;
extern CsFlagsAfdView *DAT_02527d10;
extern unsigned char DAT_02527d14;
__declspec(noinline) int __cdecl FUN_006c6dd0(void)
{
    if (DAT_02527d14 != 0 && DAT_02527d10->field_aff == 0 &&
        DAT_02527d10->field_afd != 0)
        return 1;
    return 0;
}
