#include "../cutscene_types.h"
/* Whole vector tween evaluator: before the start (or inactive) the start vector, at or after the end the end
 * vector, otherwise FUN_006ca1e0 interpolates by FUN_006c9dc0's weight. Native tween ESI, output EDI, time on
 * the stack with RET 4; the interface LTCG chooses here is not claimed as the native ABI. */
typedef struct CsFloat3Trial { float x,y,z; } CsFloat3Trial;
typedef struct CsTweenFloatTrial { unsigned char active,unknown_01[3]; CsWord blend; float start_time; CsFloat3Trial start; float end_time; CsFloat3Trial end; } CsTweenFloatTrial;
float __stdcall FUN_006c9dc0(const CsTweenFloatTrial *tween,float time);
CsFloat3Trial *FUN_006ca1e0(CsFloat3Trial *out,const CsFloat3Trial *start,const CsFloat3Trial *end,float weight);
__declspec(noinline) CsFloat3Trial *__stdcall FUN_006c92a0(const CsTweenFloatTrial *tween,CsFloat3Trial *output,float time)
{
    if (!(time<=tween->start_time) && tween->active) {
        if (tween->end_time<=time) {
            output->x=tween->end.x;
            output->y=tween->end.y;
            output->z=tween->end.z;
            return output;
        }
        FUN_006ca1e0(output,&tween->start,&tween->end,FUN_006c9dc0(tween,time));
        return output;
    }
    output->x=tween->start.x;
    output->y=tween->start.y;
    output->z=tween->start.z;
    return output;
}
