#include "../cutscene_types.h"
/* Whole six-component interpolation 006ca270..006ca36a.
 * Native ABI: start=EDX, end=ECX, output and weight on the stack, output
 * returned in EAX; result = start*(1-weight) + end*weight, each product
 * rounded to float first. Taking the output parameter's address (keep,
 * otherwise unused) keeps it a stack argument under /LTCG, as natively; the
 * 1-weight value then occupies that parameter's dead slot, as natively.
 */
typedef struct CsFloat6 { float a,b,c,d,e,f; } CsFloat6;
__declspec(noinline) CsFloat6 * __cdecl FUN_006ca270(const CsFloat6 *start, const CsFloat6 *end, CsFloat6 *out, float weight)
{
    CsFloat6 *target=out;
    CsFloat6 **keep=&out;
    CsFloat6 x,y,sum;
    float inverse;
    x.a=end->a*weight; x.b=end->b*weight; x.c=end->c*weight;
    x.d=end->d*weight; x.e=end->e*weight; x.f=end->f*weight;
    inverse=1.0f-weight;
    y.a=start->a*inverse; y.b=start->b*inverse; y.c=start->c*inverse;
    y.d=start->d*inverse; y.e=start->e*inverse; y.f=start->f*inverse;
    sum.a=y.a+x.a; sum.b=y.b+x.b; sum.c=y.c+x.c;
    sum.d=y.d+x.d; sum.e=y.e+x.e; sum.f=y.f+x.f;
    *target=sum;
    (void)keep;
    return target;
}
static const CsFloat6 *volatile first_input,*volatile second_input;
static CsFloat6 *volatile output_input;
static float volatile weight_input;
void comparison_entry(void) { FUN_006ca270(first_input,second_input,output_input,weight_input); }
