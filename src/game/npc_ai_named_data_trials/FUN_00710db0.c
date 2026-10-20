/* EXE: FUN_00710db0; complete 99-byte dependency C trial. Native instructions govern reloads, wrap and comparisons. */
typedef unsigned char View;
extern int DAT_00ed7428;
extern View DAT_02961060[],DAT_029600f0[],DAT_0296efe0[];
__declspec(noinline) View *__cdecl FUN_00710db0(const View *object) {
 int index=DAT_00ed7428;unsigned int handle;View *slot;
 if(index>0 && *(unsigned int *)(DAT_02961060+(unsigned int)index*0x12a0u)==*(const unsigned int *)(object+0x44))return DAT_029600f0+(unsigned int)index*0x12a0u;
 handle=*(const unsigned int *)(object+0x44);index=0;slot=DAT_02961060;
 do {if(*(unsigned int *)slot==handle) {DAT_00ed7428=index;return DAT_029600f0+(unsigned int)index*0x12a0u;}slot+=0x12a0;++index;}while((int)slot<(int)DAT_0296efe0);
 DAT_00ed7428=-1;return 0;
}
