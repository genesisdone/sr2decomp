/* EXE: FUN_00971de0; entire native body C trial; logical field names unestablished. */
typedef unsigned char View;
__declspec(noinline) unsigned char __cdecl FUN_00971de0(const View *object) {
    const View *state;unsigned int value;
    if (object && (state=*(const View *const *)(object+0x5e0))!=0) {
        value=*(const unsigned int *)(state+0x164);
        if (value==0x52d || value==0x52b) return 1;
    }
    return 0;
}
