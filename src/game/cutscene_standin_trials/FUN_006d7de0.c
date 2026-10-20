#include "../cutscene_types.h"
/* Whole Level Effect Hide shot option handler (option table 0x00DD28A0): hashes the effect name, disables
 * the first effect with that hash (+0C = 0) in each container of DAT_00f6fbd8, then records the hash in the
 * cutscene instance's +1F30 word list. Both helpers are static and inlined by the compiler: the search is
 * the Level Effect Show pattern (found = matched || found), and the list update is the same find-or-append
 * as the certified FUN_006d8a10 (its always-true found-index test is native's TEST ECX / JGE at 006D7E90).
 * Helper names describe the code; no original names are known. FUN_00bdcb30 is a /GL context stand-in; the
 * interface LTCG chooses for it is NOT claimed as a native ABI binding. */
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
typedef struct CsDisabledHashRoot { unsigned char unknown_00[0x1f30]; CsWordList hashes; } CsDisabledHashRoot;
extern CsDisabledHashRoot *DAT_02527d10;
static unsigned char deactivate_matching_record(CsActivationContainer *container, unsigned int hash)
{
    int index;
    for (index=0; index<container->count; ++index) {
        CsActivationRecord *record=&container->items[index];
        if (record->name_hash==hash) {
            record->field_0c=0;
            return 1;
        }
    }
    return 0;
}
static int word_list_find_or_append(CsWordList *list, const CsWord *value)
{
    int index;
    int count;
    for (index=0; index<list->count; ++index)
        if (list->items[index]==*value) {
            if (index>=0) return index;
            break;
        }
    count=list->count;
    if (count+1>list->capacity) return -1;
    list->count=count+1;
    list->items[count]=*value;
    return count;
}
__declspec(noinline) void __cdecl FUN_006d7de0(const CsActivationOption *option)
{
    if (option->name) {
        unsigned int output;
        unsigned char found=0;
        unsigned int hash=*FUN_00bdcb30(option->name,0,&output);
        CsActivationContainer **cursor;
        for (cursor=DAT_00f6fbd8; cursor<DAT_00f6fbd8+DAT_00f6fbc4; ++cursor) {
            CsActivationContainer *container=*cursor;
            if (!container) break;
            found=(hash!=0 && deactivate_matching_record(container,hash)) || found;
        }
        word_list_find_or_append(&DAT_02527d10->hashes,(const CsWord *)&hash);
    }
}
