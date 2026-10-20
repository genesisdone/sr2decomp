#include "../cutscene_types.h"
/* Whole command handler: hashes the text option, looks the marker up and calls FUN_004a29e0 with its position
 * (+1C) and orientation (+28), then FUN_006cb5e0(option).
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsTextCommandTrial { unsigned char unknown_00[0xc]; const char *text; } CsTextCommandTrial;
unsigned int *__stdcall FUN_00bdca30(unsigned int *output, unsigned int seed, const char *text);
unsigned char *FUN_00a5eb50(const unsigned int *key);
void FUN_004a29e0(unsigned char *actor, const char *label, const CsWords3 *position, unsigned char *orientation);
void FUN_006cb5e0(const CsTextCommandTrial *option);
__declspec(noinline) void __cdecl FUN_006cb2a0(const CsTextCommandTrial *option)
{
    unsigned int key;
    unsigned char *marker=FUN_00a5eb50(FUN_00bdca30(&key,0,option->text));
    if (marker!=0) {
        FUN_004a29e0(0,0,(const CsWords3 *)(marker+0x1c),marker+0x28);
        FUN_006cb5e0(option);
    }
}
