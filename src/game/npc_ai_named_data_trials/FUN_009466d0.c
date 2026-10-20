/* EXE: FUN_009466d0; whole readable C trial.
 * Only exact named native HIGHLOW operands may relocate.
 * No call/indirect/tail normalization. Field meanings remain unestablished. */
extern unsigned int DAT_0215dec8[];
__declspec(noinline) unsigned int __cdecl FUN_009466d0(int index) {
    if (index==-1) return 0;
    return DAT_0215dec8[index*2];
}
