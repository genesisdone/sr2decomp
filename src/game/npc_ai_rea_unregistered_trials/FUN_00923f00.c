/* Complete C trial from REA instruction evidence and entry-pointer proof.
 * Original source ABI and field purposes remain unestablished.
 * Byte certificate: tools/build_npc_ai_rea_unregistered.py; never executed.
 */
extern int DAT_00e843ac, DAT_00eb6680, DAT_00eb6940, DAT_00eb7998;
__declspec(noinline) void __cdecl FUN_00923f00(void) {
    int value = DAT_00e843ac;
    DAT_00eb6680 = value;
    if (value > 1800000000) DAT_00eb6680 = (int)((unsigned int)value - 1800000000u);
    DAT_00eb6940 = value;
    if (value > 1800000000) DAT_00eb6940 = (int)((unsigned int)value - 1800000000u);
    DAT_00eb7998 = value;
    if (value > 1800000000) DAT_00eb7998 = (int)((unsigned int)value - 1800000000u);
}
