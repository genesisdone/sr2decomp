/* Complete C trial from REA ev_edeb5faf86f16f46c5ad09769fae38fef4eba98e8d5db0e481ed5afef4cd4d4f.
 * Original field purposes and source ABI remain unestablished.
 * Moved from gate npc-ai-rea to batch E: `value <= 0.0f` and the limit test written as `scale * value > limit`
 * give native's compare order.
 */
extern float DAT_025f5b18, DAT_00e87038, DAT_00e87044, DAT_00e87048, DAT_00e8704c;
extern double DAT_00e5bf40;
__declspec(noinline) void __cdecl FUN_00b7c250(void) {
    float value = DAT_025f5b18;
    if (value <= 0.0f) {
        DAT_00e87038 = 1.0f;
        return;
    }
    DAT_00e87038 = value / DAT_00e87044 + DAT_00e5bf40;
    if (DAT_00e8704c * DAT_00e87038 > DAT_00e87048) {
        DAT_00e87038 = DAT_00e87048 / DAT_00e8704c;
    }
}
