#include "../cutscene_types.h"
/* Whole command handler. FUN_00a5b6e0 and FUN_00a5bd40 are /GL context stand-ins; the interfaces
 * LTCG chooses for them are NOT claimed as native ABI bindings. */
typedef struct CsCommandTwoNamesTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsCommandTwoNamesTrial;
void *FUN_00a5b6e0(const char *name);
void __stdcall FUN_00a5bd40(void *object,const char *value); /* native ECX object + stack value, RET 4 */
__declspec(noinline) void __cdecl FUN_006cc770(const CsCommandTwoNamesTrial *option)
{
    if (option->name!=0 && option->value!=0) {
        void *object=FUN_00a5b6e0(option->name);
        if (object!=0) FUN_00a5bd40(object,option->value);
    }
}
