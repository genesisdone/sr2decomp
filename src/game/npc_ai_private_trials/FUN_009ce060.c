/* EXE: FUN_009ce060; full native leaf trial; field semantics not established.
 * Exact C recovery requires both complete linked bodies. */
typedef unsigned char View;
__declspec(noinline) unsigned char __cdecl FUN_009ce060(const View *object) {
    const unsigned char *nested;
    if (object!=0 && (nested=*(const unsigned char * const *)(object+0xd4))!=0 && (nested[0x3c]&0x10)!=0)
        return 0;
    /* Retain original dereference even when object is zero. */
    nested=*(const unsigned char * const *)(object+0x1178);
    if (nested==0 || ((nested[0x70]&0x80)==0 && *(const int *)(nested+0x10c)<0 && nested[0x7c]==0))
        return 1;
    return 0;
}
