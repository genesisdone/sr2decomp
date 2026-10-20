#include "../cutscene_types.h"
/* EXE: 006CDB80-006CDBBC, start/end words in EDX/ECX; RET 12. */
__declspec(noinline) void __fastcall FUN_006cdb80(CsWords3 *end,CsWords3 *start,CsTweenVector *out,float start_time,float end_time)
{
    CsWord last;
    out->active=1;
    out->start.x=start->x;
    out->start.y=start->y;
    out->start.z=start->z;
    out->end.x=end->x;
    out->end.y=end->y;
    last=end->z;
    out->start_time=start_time;
    out->end.z=last;
    out->end_time=end_time;
}
