/* EXE: FUN_004a96a0; complete native dependency C trial with all original inputs explicit.
 * Register allocation and cleanup are accepted only by whole linked byte equality. */
typedef unsigned char View;
__declspec(noinline) const unsigned char *__cdecl FUN_004a96a0(unsigned int value,const View *object) {
    int index=(int)(value-*(const unsigned int *)(object+0x4c))/0x50;
    if (index>=0 && index<*(const int *)(object+0x48))
        return *(const unsigned char * const *)(object+0xe8)+index*8;
    return 0;
}
