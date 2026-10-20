/* FUN_00948d30: unless FUN_009e1ea0(DAT_021703d4) is non-zero or any of the six bytes at
   DAT_0215da14 is zero, calls FUN_009484a0, FUN_00947f40, FUN_009480a0, FUN_00948120 and
   FUN_00948770(0). */
extern unsigned char DAT_0215da14[];
extern unsigned char *DAT_021703d4;
unsigned char FUN_009e1ea0(unsigned char *object);
void FUN_009484a0(void);
void FUN_00947f40(void);
void FUN_009480a0(void);
void FUN_00948120(void);
void FUN_00948770(int value);
__declspec(noinline) void FUN_00948d30(void)
{
    unsigned int i;
    unsigned int *keep = &i;
    (void)keep;
    if (FUN_009e1ea0(DAT_021703d4) != 0) {
        return;
    }
    for (i = 0; i < 6; i = i + 1) {
        if (DAT_0215da14[i] == 0) {
            return;
        }
    }
    FUN_009484a0();
    FUN_00947f40();
    FUN_009480a0();
    FUN_00948120();
    FUN_00948770(0);
}
