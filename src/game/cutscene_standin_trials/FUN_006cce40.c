#include "../cutscene_types.h"
/* Complete command handler. FUN_00a618a0 and FUN_00918500 are /GL context stand-ins, FUN_009184c0 a
 * non-/GL stub; the interfaces LTCG chooses are NOT claimed as native ABI bindings. FUN_00918500
 * (index -> 0xD0-byte record at 02AD7040, 0 when out of range) has its native body inline here. */
typedef struct CsCommandTwoNamesTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsCommandTwoNamesTrial;
typedef struct CsCommandNodeTrial { unsigned char unknown_00[0x168]; float blend_168; int index_16c; } CsCommandNodeTrial;
void *FUN_00a618a0(const char *name);
int __fastcall FUN_009184c0(const char *name); /* native ECX name, result EAX */
void *FUN_00918500(int index);
extern float DAT_00dd0550,DAT_00e87998;
extern unsigned char *DAT_02527d10;
__declspec(noinline) void __cdecl FUN_006cce40(const CsCommandTwoNamesTrial *option)
{
    if (option->name!=0 && option->value!=0) {
        CsCommandNodeTrial *node=FUN_00a618a0(option->name);
        if (node!=0) {
            int index=FUN_009184c0(option->value);
            if (FUN_00918500(index)!=0) {
                node->index_16c=index;
                node->blend_168=DAT_00dd0550;
                DAT_02527d10[0x15e1]=0;
            } else {
                node->index_16c=-1;
                node->blend_168=DAT_00e87998;
            }
        }
    }
}
