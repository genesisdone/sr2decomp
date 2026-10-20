/* EXE: FUN_00b168f0; complete shared-service/helper C trial.
 * Exact semantic NPC AI ownership is not established by the caller link. */
__declspec(noinline) int __fastcall FUN_00b168f0(const unsigned char *object, int key) {
    int index=0;
    const int *record=(const int *)(object+0x34c);
    do {
        if (*record==key) return index;
        ++index; record+=0x2a;
    } while (index<8);
    return -1;
}
