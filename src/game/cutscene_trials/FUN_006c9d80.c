/* Whole native constructor: 006c9d80..006c9d97. */
#include "../cutscene_types.h"
typedef struct CsValueRecordView {
    CsWord field_00,field_04,field_08,field_0c;
} CsValueRecordView;
extern CsWord DAT_033d630c;
__declspec(noinline) void __fastcall FUN_006c9d80(CsValueRecordView *record)
{
    CsWord value = DAT_033d630c;
    record->field_00 = (CsWord)-1;
    record->field_04 = 0;
    record->field_08 = 0;
    record->field_0c = value;
}
