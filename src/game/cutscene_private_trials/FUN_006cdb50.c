/* Complete tween initializer. Native EAX=out, ECX=value.
 * Evidence: 006cdb50..006cdb7e. Private ABI selected through LTCG.
 * Blend and padding are intentionally untouched. */
#include "../cutscene_types.h"
__declspec(noinline) void __cdecl FUN_006cdb50(CsTweenVector *out, const CsWords3 *value)
{
    out->active = 0;
    out->start.x = value->x;
    out->start.y = value->y;
    out->start.z = value->z;
    out->end.x = value->x;
    out->end.y = value->y;
    out->end.z = value->z;
    out->end_time = 0.0f;
    out->start_time = 0.0f;
}
static CsTweenVector *volatile output;
static const CsWords3 *volatile input;
void comparison_entry(void) { FUN_006cdb50(output,input); }
