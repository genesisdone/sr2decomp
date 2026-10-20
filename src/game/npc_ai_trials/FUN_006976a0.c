/* EXE: FUN_006976a0; complete shared-service/helper C trial.
 * Exact semantic NPC AI ownership is not established by the caller link. */
extern int DAT_00e96b7c;
extern unsigned int DAT_0144e760[];
__declspec(noinline) unsigned int __cdecl FUN_006976a0(void) {
    if (DAT_00e96b7c>-1) return DAT_0144e760[DAT_00e96b7c];
    return 0;
}
