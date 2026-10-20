#include "../cutscene_types.h"
/* Whole Chunk Hide shot option handler (option table 0x00DD28A0): finds the chunk by name, sets flag
 * bit 0 at +1D and records the option's name word in the cutscene instance's +1EE4 word list.
 * FUN_004a9770 and FUN_006d8a10 are /GL context stand-ins; the interfaces LTCG chooses for them are
 * NOT claimed as native ABI bindings. */
typedef struct CsCommandNameTrial { unsigned char unknown_00[8]; const char *name; } CsCommandNameTrial;
typedef struct CsCommandChunkTrial { unsigned char unknown_00[0x1d]; unsigned char flags; } CsCommandChunkTrial;
extern unsigned char *DAT_02527d10;
CsCommandChunkTrial *FUN_004a9770(const char *name);
int __stdcall FUN_006d8a10(CsWordList *list, const CsWord *value);
__declspec(noinline) void __cdecl FUN_006d8280(const CsCommandNameTrial *option)
{
    CsCommandChunkTrial *chunk=FUN_004a9770(option->name);
    if (chunk!=0) {
        chunk->flags|=1;
        FUN_006d8a10((CsWordList *)(DAT_02527d10+0x1ee4),(const CsWord *)&option->name);
    }
}
