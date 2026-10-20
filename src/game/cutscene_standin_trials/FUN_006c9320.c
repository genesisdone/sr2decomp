#include "../cutscene_types.h"
typedef struct CsScalarSampleView {
    unsigned char active,unknown_01[3];
    CsWord blend;
    float start_time,start_value,end_time,end_value;
} CsScalarSampleView;
float __stdcall FUN_006c9e70(const CsScalarSampleView *record,float time);
__declspec(noinline) float __stdcall FUN_006c9320(const CsScalarSampleView *record,float time)
{
    if (!(time<=record->start_time) && record->active) {
        float weight,result;
        if (record->end_time<=time) return record->end_value;
        weight=FUN_006c9e70(record,time);
        result=(1.0f-weight)*record->start_value+record->end_value*weight;
        return result;
    }
    return record->start_value;
}
