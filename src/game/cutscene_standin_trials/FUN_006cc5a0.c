#include "../cutscene_types.h"
/* Whole command handler. FUN_00a5b6e0 and FUN_0091ad80 are /GL context stand-ins, FUN_0091b590 a
 * non-/GL stub; none of these interfaces is claimed as a native ABI binding. */
typedef struct CsCommandTwoNamesTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsCommandTwoNamesTrial;
typedef struct CsCommandResourceTrial { unsigned char unknown_00[0x94]; void *resource; } CsCommandResourceTrial;
void *FUN_00a5b6e0(const char *name);
void *__cdecl FUN_0091b590(void *resource); /* one stack input, caller pops 4 */
void FUN_0091ad80(void *object,int mode,unsigned char enabled); /* native ECX plus two stack args, caller pops 8 */
__declspec(noinline) void __cdecl FUN_006cc5a0(const CsCommandTwoNamesTrial *option)
{
    if (option->value!=0) {
        CsCommandResourceTrial *object=FUN_00a5b6e0(option->value);
        if (object!=0) FUN_0091ad80(FUN_0091b590(object->resource),0,1);
    }
}
