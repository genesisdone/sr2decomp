/* EXE: FUN_0040eaf0; complete body from native instructions and retained export.
 * Shared-service dependency candidate; semantic NPC AI ownership is not established.
 * Trial status is in reports/npc-ai-readable-match.json. */
extern unsigned char *DAT_02149c64[];
__declspec(noinline) void __fastcall FUN_0040eaf0(unsigned int handle, unsigned char **output) {
    unsigned char *object;
    if (handle == 0 || (object=DAT_02149c64[(handle & 0xfff)*4]) == 0 ||
        *(unsigned int *)(object+0x44) != handle || *(int *)(object+0x4c) != 5 ||
        (object[0x80] & 0xb) != 0) object=0;
    *output=object;
}
