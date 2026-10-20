/* Complete effect dispatcher: 006d8900..006d894e.
 * Native EDI=root. Records at +118, count +120, stride 12.
 * Type 0 is skipped; type 3 is skipped when payload is null. No bounds guard
 * is invented for the effect index: the original loads its callback from the
 * DD28A4 table and performs one cdecl CALL EDX. No callee body is claimed here. */
#include "../cutscene_types.h"
typedef struct CsDispatchOption { CsWord index,kind,value; } CsDispatchOption;
typedef struct CsDispatchRoot {
    unsigned char unknown_000[0x118];
    CsDispatchOption *items;
    int capacity,count;
} CsDispatchRoot;
typedef struct CsDispatchTableStride {
    void (__cdecl *execute)(CsDispatchOption *option);
    CsWord expected_kind;
    const char *next_name;
} CsDispatchTableStride;
extern CsDispatchTableStride DAT_00dd28a4[53];
__declspec(noinline) void __cdecl FUN_006d8900(CsDispatchRoot *root)
{
    int index=0;
    int offset;
    if (root->count>0) {
        offset=0;
        do {
            CsDispatchOption *option=(CsDispatchOption *)
                ((unsigned char *)root->items+offset);
            CsWord kind=option->kind;
            if (kind!=0 && (kind!=3 || option->value!=0))
                DAT_00dd28a4[option->index].execute(option);
            ++index;
            offset+=sizeof(CsDispatchOption);
        } while (index<root->count);
    }
}
static CsDispatchRoot *volatile input;
void comparison_entry(void) { FUN_006d8900(input); }
