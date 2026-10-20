/* EXE: FUN_004803f0; full shared-service C trial; native source/assembly retained.
 * Inclusion is a recorded caller dependency, not confirmed exclusive AI ownership. */
extern unsigned char DAT_00eeb9ac[],DAT_00eeb8f8[],DAT_00eeba8e[];
__declspec(noinline) void __fastcall FUN_004803f0(const unsigned int *handle,unsigned char flag) {
    unsigned char index=*(const unsigned char *)handle;
    unsigned int generation,offset;
    if (index!=0xff && (generation=*handle>>8)!=0 &&
        (offset=(unsigned int)index*0x19c,generation==*(unsigned int *)(DAT_00eeb9ac+offset)) &&
        *(int *)(DAT_00eeb8f8+offset)!=-1)
        *(unsigned short *)(DAT_00eeba8e+offset)=((unsigned short)(flag&1)<<12)|(*(unsigned short *)(DAT_00eeba8e+offset)&0xefff);
}
