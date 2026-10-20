#include "../cutscene_types.h"
/* Whole command handler. FUN_00a5b6e0 is a /GL context stand-in; FUN_0091b590/FUN_0091b140 are
 * non-/GL stubs. None of these interfaces is claimed as a native ABI binding. */
typedef struct CsCommandTwoNamesTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsCommandTwoNamesTrial;
typedef struct CsCommandResourceTrial { unsigned char unknown_00[0x94]; void *resource; } CsCommandResourceTrial;
void *FUN_00a5b6e0(const char *name);
void *__cdecl FUN_0091b590(void *resource); /* one stack input, caller pops 4 */
void __fastcall FUN_0091b140(void *object); /* native ECX, tail JMP at 006CC605 */
__declspec(noinline) void __cdecl FUN_006cc5e0(const CsCommandTwoNamesTrial *option)
{
    if (option->value!=0) {
        CsCommandResourceTrial *object=FUN_00a5b6e0(option->value);
        if (object!=0) {
            void *resource=FUN_0091b590(object->resource);
            FUN_0091b140(resource);
        }
    }
}
