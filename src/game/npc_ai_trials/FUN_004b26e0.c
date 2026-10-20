/* EXE: FUN_004b26e0; complete body from native instructions and retained export.
 * Shared-service dependency candidate; semantic NPC AI ownership is not established.
 * Trial status is in reports/npc-ai-readable-match.json. */
__declspec(noinline) void __fastcall FUN_004b26e0(int *object, void *unused_edx, int value) {
    if (value>2000000000) { *object=2000000000; return; }
    if (value<-2000000000) { *object=-2000000000; return; }
    *object=value;
}
