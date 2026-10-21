/* Complete C trial from REA ev_ecd7d941a5fc0cd8447c141370e862cba05360e1823b2d0eb8fd4fc7e00afeec.
 * Original field purposes and source ABI remain unestablished.
 * Moved from gate npc-ai-rea to batch E: `value <= 0.0f` and the limit test written as `scale * value > limit`
 * give native's compare order (as FUN_00b7c250).
 */
extern float DAT_025f5b18, DAT_00e86f94, DAT_00e86fa4, DAT_00e86fa8, DAT_00e86fac;
extern double DAT_00e5bf40;
__declspec(noinline) void __cdecl FUN_00b7efb0(void) {
    float value = DAT_025f5b18;
    if (value <= 0.0f) {
        DAT_00e86f94 = 1.0f;
        return;
    }
    DAT_00e86f94 = value / DAT_00e86fa4 + DAT_00e5bf40;
    if (DAT_00e86fac * DAT_00e86f94 > DAT_00e86fa8) {
        DAT_00e86f94 = DAT_00e86fa8 / DAT_00e86fac;
    }
}
