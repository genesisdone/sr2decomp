/* Whole predicate 006c6d90..006c6db0. No invented null guard. */
typedef struct CsInstanceFlagAff {
    unsigned char unknown_000[0xaff];
    unsigned char field_aff;
} CsInstanceFlagAff;
extern unsigned char DAT_02527d14;
extern CsInstanceFlagAff *DAT_02527d10;
__declspec(noinline) int __cdecl FUN_006c6d90(void)
{
    if (DAT_02527d14 != 0 && DAT_02527d10->field_aff == 0)
        return 1;
    return 0;
}
