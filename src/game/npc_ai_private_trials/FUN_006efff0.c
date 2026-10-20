/* EXE: FUN_006efff0; complete native dependency C trial with all original inputs explicit.
 * Register allocation and cleanup are accepted only by whole linked byte equality. */
typedef unsigned char View;
__declspec(noinline) const unsigned char *__cdecl FUN_006efff0(const View *object,int wanted) {
    int ordinal=0;
    int index=0;
    const int *record=(const int *)(object+0xcc);
    do {
        if ((((const unsigned char *)record)[0x18]&1)!=0 && *record!=0xffff) {
            if (ordinal==wanted) return object+0xe8+index*0x34;
            ++ordinal;
        }
        ++index;record+=0xd;
    } while (index<3);
    return 0;
}
