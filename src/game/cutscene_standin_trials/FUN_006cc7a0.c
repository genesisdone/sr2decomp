#include "../cutscene_types.h"
/* Whole command handler. FUN_00a5b6e0 is a context stand-in; the private
 * LTCG interface chosen for it is NOT claimed as the native ABI. */
typedef struct CsCommandNameTrial { unsigned char unknown_00[8]; const char *name; } CsCommandNameTrial;
typedef struct CsCommandStateTrial { unsigned char unknown_00[0xa]; unsigned char flags; } CsCommandStateTrial;
typedef struct CsCommandObjectTrial { unsigned char unknown_00[0x94]; CsCommandStateTrial *state; } CsCommandObjectTrial;
void *FUN_00a5b6e0(const char *name);
__declspec(noinline) unsigned char __cdecl FUN_006cc7a0(const CsCommandNameTrial *option)
{
    if (option->name!=0) {
        CsCommandObjectTrial *object=FUN_00a5b6e0(option->name);
        if (object!=0 && object->state!=0) return (unsigned char)((object->state->flags>>1)&1);
    }
    return 1;
}
