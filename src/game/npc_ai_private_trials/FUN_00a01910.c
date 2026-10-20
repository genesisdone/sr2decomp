/* EXE: FUN_00a01910; full native helper C trial; offsets reflect original inputs.
 * Semantic AI ownership and unnamed fields remain unestablished. */
typedef unsigned char View;
__declspec(noinline) unsigned int __cdecl FUN_00a01910(const View *object) {
    const unsigned char *nested=*(const unsigned char * const *)(object+0xc8);
    if (nested!=0) return *(const unsigned int *)(nested+8);
    return 0;
}
