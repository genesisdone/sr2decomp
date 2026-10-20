/* Complete six-word tween initializer. Native EAX=out, ECX=value.
 * Evidence: 006d7170..006d71c2. Field access order retained from assembly.
 * Volatile access is imposed to express the observed order, not evidence of
 * original source qualifiers. Whole private body requires both static links. */
#include "../cutscene_types.h"
__declspec(noinline) void __cdecl FUN_006d7170(volatile CsTweenSix *out, const volatile CsWords6 *value)
{
    CsWord second,penultimate,last;
    out->start.a = value->a;
    out->end_time = 0.0f;
    second=value->b;
    out->start_time = 0.0f;
    out->start.b = second;
    out->start.c = value->c;
    out->start.d = value->d;
    out->start.e = value->e;
    out->start.f = value->f;
    out->end.a = value->a;
    out->end.b = value->b;
    out->end.c = value->c;
    out->end.d = value->d;
    penultimate=value->e;last=value->f;
    out->end.e=penultimate;
    out->active=0;
    out->end.f=last;
}
static CsTweenSix *volatile output;
static const CsWords6 *volatile input;
void comparison_entry(void) { FUN_006d7170(output,input); }
