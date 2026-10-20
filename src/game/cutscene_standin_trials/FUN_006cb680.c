#include "../cutscene_types.h"
/* Whole command handler: FUN_004a29e0 with position DAT_025f5b20 and no label, actor or orientation.
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
extern CsWords3 DAT_025f5b20;
void FUN_004a29e0(unsigned char *actor, const char *label, const CsWords3 *position, unsigned char *orientation);
__declspec(noinline) void __cdecl FUN_006cb680(void)
{
    FUN_004a29e0(0,0,&DAT_025f5b20,0);
}
