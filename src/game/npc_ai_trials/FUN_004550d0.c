/* EXE: FUN_004550d0; complete body from native instructions and retained export.
 * Shared-service dependency candidate; semantic NPC AI ownership is not established.
 * Trial status is in reports/npc-ai-readable-match.json. */
extern int DAT_00e99cc0;
extern int DAT_0253ef58[];
__declspec(noinline) int __cdecl FUN_004550d0(int value) {
    int index=0;
    int *record;
    if (DAT_00e99cc0 > 0) {
        record=DAT_0253ef58;
        do {
            if (*record==value) return index;
            ++index;
            record+=0x10;
        } while (index<DAT_00e99cc0);
    }
    return -1;
}
