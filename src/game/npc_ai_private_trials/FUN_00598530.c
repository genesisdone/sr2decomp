/* EXE: FUN_00598530; complete native dependency C trial with all original inputs explicit.
 * Register allocation and cleanup are accepted only by whole linked byte equality. */
typedef unsigned char View;
__declspec(noinline) unsigned int __cdecl FUN_00598530(int value,int index,const View *object) {
    int remainder=value%*(const int *)(object+index*0x16c8+0x5a4);
    return *(const unsigned int *)(object+0x584+(remainder+index*0x5b2)*4);
}
