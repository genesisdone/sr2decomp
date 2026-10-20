#include "../cutscene_types.h"
extern CsInstanceSlateView *DAT_02527d10;
/* EXE: 006C70D0-006C7110; partial instance fields at 10c/118. */
__declspec(noinline) void __fastcall FUN_006c70d0(CsWords3 *second,CsWords3 *first)
{
    CsInstanceSlateView *instance=DAT_02527d10;
    if(instance) {
        instance->field_10c.x=first->x;
        instance->field_10c.y=first->y;
        instance->field_10c.z=first->z;
        instance->field_118.x=second->x;
        instance->field_118.y=second->y;
        instance->field_118.z=second->z;
    }
}
