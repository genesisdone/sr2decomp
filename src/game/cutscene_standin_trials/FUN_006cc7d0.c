#include "../cutscene_types.h"
/* Whole command handler. FUN_00a5b6e0 is a /GL context stand-in and FUN_00a5bf40 a non-/GL
 * stub; the interfaces chosen for them are NOT claimed as native ABI bindings. */
typedef struct CsCommandNameTrial { unsigned char unknown_00[8]; const char *name; } CsCommandNameTrial;
void *FUN_00a5b6e0(const char *name);
void __fastcall FUN_00a5bf40(void *object); /* native object=ECX, tail JMP at 006CC7E6 */
__declspec(noinline) void __cdecl FUN_006cc7d0(const CsCommandNameTrial *option)
{
    if (option->name!=0) {
        void *object=FUN_00a5b6e0(option->name);
        if (object!=0) FUN_00a5bf40(object);
    }
}
