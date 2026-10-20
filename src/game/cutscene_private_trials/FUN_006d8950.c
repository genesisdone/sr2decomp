/* Complete typed effect-option query: 006d8950..006d89a4.
 * Native ECX=record, EDI=effect index. The expected option kind at DD28A8 and
 * matching record type must both be exactly 3 before returning its word +8. */
#include "../cutscene_types.h"
typedef struct CsEffectOptionRecord { CsWord index,type,value; } CsEffectOptionRecord;
typedef struct CsEffectOptionsView {
    unsigned char unknown_000[0x118];
    CsEffectOptionRecord *items;
    int capacity,count;
} CsEffectOptionsView;
typedef struct CsEffectKindStride { CsWord expected_kind,unknown_04,unknown_08; } CsEffectKindStride;
extern CsEffectKindStride DAT_00dd28a8[53];
__declspec(noinline) CsWord __fastcall FUN_006d8950(const CsEffectOptionsView *record, unsigned int effect)
{
    int index,count;
    const CsEffectOptionRecord *base,*item;
    if (record==0)
        return 0;
    if (effect>=53)
        return 0;
    if (DAT_00dd28a8[effect].expected_kind!=3)
        return 0;
    count=record->count;
    index=0;
    if (count>0) {
        base=record->items;
        item=base;
        do {
            if (effect==item->index) {
                if (base[index].type!=3)
                    return 0;
                return base[index].value;
            }
            ++index;
            ++item;
        } while (index<count);
    }
    return 0;
}
static const CsEffectOptionsView *volatile input;
static volatile unsigned int effect_input;
static volatile CsWord result;
void comparison_entry(void) { result=FUN_006d8950(input,effect_input); }
