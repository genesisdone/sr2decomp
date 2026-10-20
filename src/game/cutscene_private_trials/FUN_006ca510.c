#include "../cutscene_types.h"
/* Complete 006ca510..006ca554. Native actor=ESI, reference=EDI.
 * State helper 00968930 reads two stack inputs and returns with RET 8.
 * The native helper consumes the first byte of each local integer state.
 */
typedef struct CsCommandActorState {
    unsigned char unknown_0000[0x141];
    unsigned char field_0141;
    unsigned char unknown_0142[0xfda];
    unsigned char field_111c;
} CsCommandActorState;
typedef char cs_actor_state_offset[(offsetof(CsCommandActorState,field_111c)==0x111c)?1:-1];
extern void __stdcall FUN_00968930(void *actor, const int *state);
__declspec(noinline) void __cdecl FUN_006ca510(CsCommandActorState *actor, const CsCommandActorState *reference)
{
    int state;
    if (actor && reference) {
        state = 1;
        FUN_00968930(actor,&state);
        if (reference->field_111c == actor->field_111c) {
            state = 3;
            FUN_00968930(actor,&state);
        }
        actor->field_0141 = 3;
    }
}
static CsCommandActorState *volatile actor_input;
static const CsCommandActorState *volatile reference_input;
void comparison_entry(void) { FUN_006ca510(actor_input,reference_input); }
