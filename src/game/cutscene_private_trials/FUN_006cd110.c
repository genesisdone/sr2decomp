#include "../cutscene_types.h"
#include "../cutscene_delay_context.h"
/* Complete delay predicate; native base ECX / state ESI, AL result (caller 006CDA2E keeps the
 * state live in ESI). The included complete FUN_006cd010 trial is compiler context only: native
 * 006CD010 reads list ECX / identifier EDI and leaves the caller's x87 zero on the stack. */
typedef struct CsDelayStateTrial { unsigned char unknown_00[0x14]; int identifier; unsigned char unknown_18[0x10]; float remaining; CsWord blocked; } CsDelayStateTrial;
extern float DAT_027e6718;
__declspec(noinline) unsigned char __cdecl FUN_006cd110(void *base,CsDelayStateTrial *state)
{
    if (state->blocked!=0) return 0;
    if (state->identifier==-1 && state->remaining<=0.0f) return 1;
    if (state->identifier!=-1 && !FUN_006cd010((CsActionListView *)((unsigned char *)base+0x130),state->identifier)) return 0;
    if (state->remaining<=0.0f) return 1;
    state->remaining=state->remaining-DAT_027e6718;
    return 0;
}
static void *volatile base_input;
static CsDelayStateTrial *volatile state_input;
static unsigned char volatile result;
static CsDelayStateTrial *volatile state_output;
/* The state stays live after the call, as at native 006CDA35, so LTCG keeps it in a callee-saved register. */
void comparison_entry(void)
{
    CsDelayStateTrial *state=state_input;
    result=FUN_006cd110(base_input,state);
    state_output=state;
}
