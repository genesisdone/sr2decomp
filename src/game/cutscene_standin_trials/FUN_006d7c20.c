#include "../cutscene_types.h"
typedef struct CsNamedPair { const char *name; CsWord field_04; } CsNamedPair;
typedef struct CsNamedPairList { CsNamedPair *items; int capacity,count; } CsNamedPairList;
void FUN_006d7b30(const char *name,unsigned char flag);
int __stdcall FUN_006d8b00(CsNamedPairList *list, const char **name);
/* Whole record-flag command 006D7C20-006D7C80 (published as a kind-3 handler at 00DD29E4+4): clears the named
 * records' flags through FUN_006d7b30(name, 0) and, when the name is not yet in the root's +16D8 list, appends
 * (name, 0). The pair is built once and copied (key for the lookup, entry for the append): native keeps the
 * entry in EBX/ESI across the lookup and stores the key's +04 word first (006D7C51/55). FUN_006d7b30 and
 * FUN_006d8b00 are /GL context stand-ins; their LTCG-chosen interfaces are NOT claimed as native ABI bindings. */
typedef struct CsRecordFlagRoot { unsigned char unknown_00[0x16d8]; CsNamedPairList list; } CsRecordFlagRoot;
typedef struct CsRecordFlagOption { CsWord unknown_00,unknown_04; const char *name; } CsRecordFlagOption;
extern CsRecordFlagRoot *DAT_02527d10;
__declspec(noinline) void __cdecl FUN_006d7c20(const CsRecordFlagOption *option)
{
    if (option->name) {
        CsNamedPair entry,key;
        CsNamedPairList *list;
        int index,count;
        FUN_006d7b30(option->name,0);
        key.field_04=0;
        key.name=option->name;
        entry=key;
        list=&DAT_02527d10->list;
        index=FUN_006d8b00(list,&key.name);
        if (index<0) {
            count=list->count;
            if (count+1<=list->capacity) {
                list->count=count+1;
                list->items[count]=entry;
            }
        }
    }
}
