/* Complete C trial from REA instruction evidence and entry-pointer proof.
 * Original source ABI and field purposes remain unestablished.
 * Byte certificate: tools/build_npc_ai_rea_unregistered.py; never executed.
 */
extern int DAT_00e843ac;
__declspec(noinline) void __fastcall FUN_00669970(unsigned char *object) {
    int value = (int)((unsigned int)DAT_00e843ac + 30000u);
    *(int *)(object + 0x1e4) = value;
    if (value > 1800000000) *(int *)(object + 0x1e4) = (int)((unsigned int)value - 1800000000u);
}
