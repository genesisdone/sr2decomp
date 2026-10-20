/* Canonical REA complete caller. Callee is an audited address boundary, not newly recovered. */
extern void __fastcall FUN_00956080(void *object);
__declspec(noinline) void __fastcall FUN_006794d0(unsigned char *object) {
    FUN_00956080(object);
    *(unsigned int *)(object+0x1e4)=0;
    *(unsigned int *)(object+0x1fc)=0;
}
