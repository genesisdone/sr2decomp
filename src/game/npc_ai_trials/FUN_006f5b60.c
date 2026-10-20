/* EXE: FUN_006f5b60; complete shared-system C trial.
 * All original reads, sentinels, wraps and writes retained; no semantic AI ownership claim. */
extern unsigned int DAT_02527db0;
extern unsigned int DAT_0168e970[];
extern unsigned short DAT_00e8ecb4;
__declspec(noinline) unsigned int __cdecl FUN_006f5b60(void) {
    unsigned int slot,generation;
    if (DAT_02527db0>=0x157c) return 0;
    slot=DAT_0168e970[DAT_02527db0];
    DAT_0168e970[DAT_02527db0]=0xffffffff;
    DAT_02527db0+=1;
    generation=DAT_00e8ecb4;
    DAT_00e8ecb4=(unsigned short)(DAT_00e8ecb4+1);
    if (DAT_00e8ecb4==0) DAT_00e8ecb4=1;
    return (generation<<16)|slot;
}
