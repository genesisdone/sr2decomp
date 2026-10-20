#include "../cutscene_types.h"
/* Whole Chunk Show shot option handler (option table 0x00DD28A0): finds the chunk by name and clears
 * flag bit 0 at +1D. FUN_004a9770 is a /GL context stand-in; the interface LTCG chooses for it is NOT
 * claimed as a native ABI binding. */
typedef struct CsCommandNameTrial { unsigned char unknown_00[8]; const char *name; } CsCommandNameTrial;
typedef struct CsCommandChunkTrial { unsigned char unknown_00[0x1d]; unsigned char flags; } CsCommandChunkTrial;
CsCommandChunkTrial *FUN_004a9770(const char *name);
__declspec(noinline) void __cdecl FUN_006d82b0(const CsCommandNameTrial *option)
{
    CsCommandChunkTrial *chunk=FUN_004a9770(option->name);
    if (chunk!=0) chunk->flags&=0xfe;
}
