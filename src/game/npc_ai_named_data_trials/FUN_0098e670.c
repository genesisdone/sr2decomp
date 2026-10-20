/* EXE: FUN_0098e670; complete native C trial, semantic AI ownership unestablished. */
typedef unsigned char View;
extern View *DAT_02149c64[];
__declspec(noinline) int __cdecl FUN_0098e670(const View *object) {
    int count=0;unsigned int handle;View *resolved;
    if (object) {
        handle=*(const unsigned int *)(object+0xc40);
        if (handle && (resolved=DAT_02149c64[(handle&0xfff)*4])!=0 && *(unsigned int *)(resolved+0x44)==handle && *(int *)(resolved+0x4c)==1) ++count;
        handle=*(const unsigned int *)(object+0xc58);
        if (handle && (resolved=DAT_02149c64[(handle&0xfff)*4])!=0 && *(unsigned int *)(resolved+0x44)==handle && *(int *)(resolved+0x4c)==1) ++count;
        handle=*(const unsigned int *)(object+0xc70);
        if (handle && (resolved=DAT_02149c64[(handle&0xfff)*4])!=0 && *(unsigned int *)(resolved+0x44)==handle && *(int *)(resolved+0x4c)==1) ++count;
    }
    return count;
}
