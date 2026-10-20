/* EXE: FUN_006add30; whole readable C trial.
 * Only exact named native HIGHLOW operands may relocate.
 * No call/indirect/tail normalization. Field meanings remain unestablished. */
extern int DAT_01450410;
extern unsigned char *DAT_0145040c;
__declspec(noinline) unsigned char *__cdecl FUN_006add30(int index) {
    if (index>=0 && index<DAT_01450410) return DAT_0145040c+index*0x18;
    return 0;
}
