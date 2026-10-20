/* Command record initializer; complete native body 006cd050..006cd081.
 * EAX retains the ECX input. Padding/unknown fields are not invented. */
#include "../cutscene_types.h"
typedef struct CsCommandView {
    CsWord field_00,field_04,field_08,field_0c,field_10,field_14;
    CsWord field_18,field_1c,field_20,field_24;
    volatile float field_28;
    CsWord field_2c;
} CsCommandView;
__declspec(noinline) CsCommandView * __fastcall FUN_006cd050(CsCommandView *record)
{
    record->field_00 = (CsWord)-1;
    record->field_04 = 0;
    record->field_08 = 0;
    record->field_0c = 0;
    record->field_10 = 0;
    record->field_14 = (CsWord)-1;
    record->field_18 = 0;
    record->field_1c = 255;
    record->field_24 = (CsWord)-1;
    record->field_20 = (CsWord)-1;
    record->field_28 = 0.0f;
    record->field_2c = 0;
    return record;
}
