#include "../cutscene_types.h"
/* Whole stop routine: for a live slot, stops the animation (FUN_006f0660(animation, 0, -1)), releases the voice
 * slot (FUN_00cedc10, FUN_00cedc50(slot, 0)) and resets +24, +14 and +18. The record arrives in ESI natively; the
 * interface LTCG chooses here is not claimed as the native ABI. */
typedef struct CsStopAnimation {
    int slot;
    CsWord unknown_04,unknown_08,unknown_0c,unknown_10;
    int field_14,field_18;
    CsWord unknown_1c,unknown_20;
    float field_24;
} CsStopAnimation;
void FUN_006f0660(CsStopAnimation *animation,float time,int flag);
void FUN_00cedc10(int slot);
void FUN_00cedc50(int slot,int flag);
__declspec(noinline) void __cdecl FUN_006c32a0(CsStopAnimation *animation)
{
    if (animation!=0 && animation->slot!=-1) {
        FUN_006f0660(animation,0.0f,-1);
        FUN_00cedc10(animation->slot);
        FUN_00cedc50(animation->slot,0);
        animation->field_24=0.0f;
        animation->field_14=-1;
        animation->field_18=0xffff;
    }
}
