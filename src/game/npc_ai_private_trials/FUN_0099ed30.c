/* EXE: FUN_0099ed30; entire native C trial, no guessed field identities. */
typedef unsigned char View;
__declspec(noinline) int __cdecl FUN_0099ed30(const View *object) {
    if ((*(const unsigned int *)(object+0xc0)&0x40000000)!=0 &&
        *(const int *)(*(const View *const *)(object+0x5e0)+0x164)!=0x526) return 1;
    return 0;
}
