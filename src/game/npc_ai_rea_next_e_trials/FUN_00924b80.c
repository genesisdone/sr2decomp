/* Complete C trial from REA ev_7aa08495e355649d70171b18492144624f2015fb3139b0a942b09c975c840feb.
 * Original field purposes and source ABI remain unestablished.
 * Moved from gate npc-ai-rea (tools/build_npc_ai_rea.py) to batch E; the timer is re-read through the global so the
 * wrap is a SUB of 1800000000 as in native.
 */
extern int DAT_00eb799c, DAT_00e843ac;
extern unsigned char DAT_025295ca;
__declspec(noinline) void __cdecl FUN_00924b80(void) {
    int value_eb799c = DAT_00eb799c;
    int value_e843ac;
    if (value_eb799c < 0) return;
    value_e843ac = DAT_00e843ac;
    if (value_eb799c > value_e843ac) {
        if ((int)((unsigned int)value_eb799c - (unsigned int)value_e843ac) < 900000000) return;
    } else {
        if ((int)((unsigned int)value_e843ac - (unsigned int)value_eb799c) >= 900000000) return;
    }
    DAT_025295ca = DAT_025295ca == 0;
    DAT_00eb799c = (int)((unsigned int)value_e843ac + 120000u);
    if (DAT_00eb799c > 1800000000) DAT_00eb799c -= 1800000000;
}
