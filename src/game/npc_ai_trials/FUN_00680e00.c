/* EXE: FUN_00680e00; complete shared-service/helper C trial.
 * Exact semantic NPC AI ownership is not established by the caller link. */
extern int DAT_02527b2c;
extern int DAT_027a5efc[],DAT_027a5f00[];
__declspec(noinline) int __cdecl FUN_00680e00(int key) {
    int index=0;
    int *record;
    if (DAT_02527b2c>0) {
        record=DAT_027a5efc;
        do {
            if (*record==key) return DAT_027a5f00[index*9];
            ++index; record+=9;
        } while (index<DAT_02527b2c);
    }
    return -2;
}
