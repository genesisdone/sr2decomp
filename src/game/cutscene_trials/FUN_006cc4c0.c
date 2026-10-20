/* Complete 006CC4C0..006CC4EF: FADE IN / FADE OUT done check (action table 0x00DD2B28). True when no
 * fade is active (state 0), or when the fade amount has reached its target: 0 for state 2, 1 for
 * state 1. Comparing the global against each literal is what yields native's FLDZ/FLD1 + FCOMP m32
 * with one shared compare tail; comparing against a variable gives FUCOMPP instead. */
extern int DAT_02526d9c;
extern float DAT_02526da0;
__declspec(noinline) int __cdecl FUN_006cc4c0(void)
{
    int state=DAT_02526d9c;
    return state==0 || (state==2 && DAT_02526da0==0.0f) || (state==1 && DAT_02526da0==1.0f);
}
