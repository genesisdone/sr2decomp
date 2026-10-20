/* EXE: FUN_00994e70; entire native C trial, no guessed field identities. */
typedef unsigned char View;
__declspec(noinline) int __cdecl FUN_00994e70(const View *object) {
    const View *state=*(const View *const *)(object+0x5e0);
    if (*(const int *)(state+0x40)!=0x170 && *(const int *)(state+0x6c)!=0x170) return 0;
    return 1;
}
