#include "../cutscene_types.h"
/* Whole Level Effect Show shot option handler (option table 0x00DD28A0): hashes the effect name and
 * re-enables the first effect with that hash (+0C = 1) in each container of DAT_00f6fbd8. The search is a
 * static helper inlined by the compiler; written that way, the found flag becomes native's `found =
 * * matched || found` (TEST BL / JNE / JMP at 006D7F8F); the flag is never read afterwards. The helper name
 * describes the code; no original name is known. FUN_00bdcb30 is a /GL context stand-in; the interface
 * LTCG chooses for it is NOT claimed as a native ABI binding. */
typedef struct CsActivationRecord {
    CsWord unknown_00;
    unsigned int name_hash;
    CsWord unknown_08;
    unsigned char field_0c,unknown_0d[0x43];
} CsActivationRecord;
typedef struct CsActivationContainer { unsigned char unknown_00[0x180]; int count; CsActivationRecord *items; } CsActivationContainer;
typedef struct CsActivationOption { CsWord unknown_00,unknown_04; const char *name; } CsActivationOption;
typedef char cs_activation_stride[(sizeof(CsActivationRecord)==0x50)?1:-1];
typedef char cs_activation_items_offset[(offsetof(CsActivationContainer,items)==0x184)?1:-1];
extern unsigned int DAT_00f6fbc4;
extern CsActivationContainer *DAT_00f6fbd8[];
unsigned int *__stdcall FUN_00bdcb30(const char *text,unsigned int seed,unsigned int *output);
static unsigned char activate_matching_record(CsActivationContainer *container, unsigned int hash)
{
    int index;
    for (index=0; index<container->count; ++index) {
        CsActivationRecord *record=&container->items[index];
        if (record->name_hash==hash) {
            record->field_0c=1;
            return 1;
        }
    }
    return 0;
}
__declspec(noinline) void __cdecl FUN_006d7f30(const CsActivationOption *option)
{
    if (option->name) {
        unsigned int output;
        unsigned char found=0;
        unsigned int hash=*FUN_00bdcb30(option->name,0,&output);
        CsActivationContainer **cursor;
        for (cursor=DAT_00f6fbd8; cursor<DAT_00f6fbd8+DAT_00f6fbc4; ++cursor) {
            CsActivationContainer *container=*cursor;
            if (!container) return;
            found=(hash!=0 && activate_matching_record(container,hash)) || found;
        }
    }
}
