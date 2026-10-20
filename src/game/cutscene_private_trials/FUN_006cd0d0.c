/* Entire command flags accessor, bit 2: 006cd0d0..
 * Native EAX=command; index read at +4; unsigned bound 63.
 * DD2B34 is the flags word of table record zero, stride 16.
 * Return AL is authoritative; no AX/EAX high-bit result is claimed. */
#include "../cutscene_types.h"
typedef struct CsCommandIndex { CsWord unknown_00,index; } CsCommandIndex;
typedef struct CsCommandFlagsStride { CsWord flags,unknown_04,unknown_08,unknown_0c; } CsCommandFlagsStride;
extern CsCommandFlagsStride DAT_00dd2b34[63];
__declspec(noinline) unsigned char __cdecl FUN_006cd0d0(const CsCommandIndex *command)
{
    unsigned int index=command->index;
    if (index>=63)
        return 0;
    return (unsigned char)((DAT_00dd2b34[index].flags >> 2) & 1);
}
static const CsCommandIndex *volatile input;
static volatile unsigned char result;
void comparison_entry(void) { result=FUN_006cd0d0(input); }
