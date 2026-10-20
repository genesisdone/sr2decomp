#include "../cutscene_types.h"
/* Whole nine-float basis tween evaluator: start before the start time (or inactive), FUN_00be2c60 copy of the
 * end at or after the end time, else FUN_006bd6e0 interpolation by FUN_006ca070's weight. Native output EAX,
 * tween ESI, time on the stack with RET 4; the interface LTCG chooses here is not claimed as the native ABI.
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsBasisTween { unsigned char active,unknown_01[3]; CsWord blend; float start_time,start[9],end_time,end[9]; } CsBasisTween;
float __stdcall FUN_006ca070(const CsBasisTween *tween,float time);
void FUN_00be2c60(const float *value,float *output);
typedef struct CsDirectionVector { float x,y,z; } CsDirectionVector;
typedef struct CsDirectionFrame { float unknown_00[6]; CsDirectionVector field_18; } CsDirectionFrame;
typedef char cs_direction_offset[(offsetof(CsDirectionFrame,field_18)==0x18)?1:-1];
CsDirectionFrame *FUN_006bd6e0(const CsDirectionFrame *first,const CsDirectionFrame *second,float weight,CsDirectionFrame *output);

__declspec(noinline) float *__stdcall FUN_006c98b0(float *output,const CsBasisTween *tween,float time)
{
    if (!(time<=tween->start_time) && tween->active) {
        if (tween->end_time<=time) {
            FUN_00be2c60(tween->end,output);
            return output;
        }
        FUN_006bd6e0((const CsDirectionFrame *)tween->start,(const CsDirectionFrame *)tween->end,FUN_006ca070(tween,time),(CsDirectionFrame *)output);
        return output;
    }
    output[0]=tween->start[0];
    output[1]=tween->start[1];
    output[2]=tween->start[2];
    output[3]=tween->start[3];
    output[4]=tween->start[4];
    output[5]=tween->start[5];
    output[6]=tween->start[6];
    output[7]=tween->start[7];
    output[8]=tween->start[8];
    return output;
}
