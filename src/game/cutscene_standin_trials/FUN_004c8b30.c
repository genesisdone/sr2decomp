#include "../cutscene_types.h"
/* Whole light lookup: hashes the name with FUN_00bdcb30, returns the matching entry of DAT_02652198 (16-byte
 * entries, DAT_02526d44 of them) or tail-calls FUN_004c8b80(name, 0) on a miss (004C8B6B). The name arrives in
 * EDI natively; the interface LTCG chooses here is not claimed as the native ABI. */
typedef struct CsLightLookup { CsWord hash, unknown_04[3]; } CsLightLookup;
extern int DAT_02526d44;
extern CsLightLookup DAT_02652198[];
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
CsLightLookup *__fastcall FUN_004c8b80(const char *name, int create);
__declspec(noinline) CsLightLookup *__cdecl FUN_004c8b30(const char *name)
{
    unsigned int hash;
    int index;
    FUN_00bdcb30(name,0,&hash);
    for (index=0; index<DAT_02526d44; ++index)
        if (hash==DAT_02652198[index].hash) return &DAT_02652198[index];
    return FUN_004c8b80(name,0);
}
