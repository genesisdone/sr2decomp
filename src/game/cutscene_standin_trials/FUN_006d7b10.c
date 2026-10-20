#include "../cutscene_types.h"
/* Whole Mesh Mover Show shot option handler: looks the mover up by name, then shows it.
 * FUN_00a5b6e0 and FUN_00a5b970 are /GL context stand-ins; the interfaces LTCG chooses for them are
 * NOT claimed as native ABI bindings. */
typedef struct CsCommandNameTrial { unsigned char unknown_00[8]; const char *name; } CsCommandNameTrial;
void *FUN_00a5b6e0(const char *name);
void FUN_00a5b970(unsigned char *mover);
__declspec(noinline) void __cdecl FUN_006d7b10(const CsCommandNameTrial *option)
{
    if (option->name!=0) {
        unsigned char *mover=FUN_00a5b6e0(option->name);
        if (mover!=0) FUN_00a5b970(mover);
    }
}
