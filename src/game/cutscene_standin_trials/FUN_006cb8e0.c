#include "../cutscene_types.h"
/* Whole HIDE GROUP action handler (action table 0x00DD2B28): looks the group up by name and sets its
 * members' hidden flag to 1. FUN_00a57730 and FUN_00a58070 are /GL context stand-ins; the
 * interfaces LTCG chooses for them are NOT claimed as native ABI bindings. */
typedef struct CsCommandNameTrial { unsigned char unknown_00[8]; const char *name; } CsCommandNameTrial;
void *FUN_00a57730(const char *name);
void __stdcall FUN_00a58070(unsigned char *group, int hidden);
__declspec(noinline) void __cdecl FUN_006cb8e0(const CsCommandNameTrial *option)
{
    if (option->name!=0) {
        unsigned char *group=FUN_00a57730(option->name);
        if (group!=0) FUN_00a58070(group,1);
    }
}
