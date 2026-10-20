#include "../cutscene_types.h"
typedef struct CsNameValueCommandTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsNameValueCommandTrial;
typedef struct CsReferencedHandleTrial { unsigned char unknown_00[0x44]; CsWord handle; } CsReferencedHandleTrial;
typedef struct CsReferencedRecordTrial { unsigned char unknown_00[0xc]; CsReferencedHandleTrial *object; } CsReferencedRecordTrial;
typedef struct CsNamedPair { const char *name; CsWord field_04; } CsNamedPair;
typedef struct CsNamedPairList { CsNamedPair *items; int capacity,count; } CsNamedPairList;
typedef struct CsNamedRootCommandTrial { unsigned char unknown_00[0x16d8]; CsNamedPairList list; } CsNamedRootCommandTrial;
extern CsNamedRootCommandTrial *DAT_02527d10;
CsReferencedRecordTrial *FUN_004a80b0(const char *name);
void FUN_009fa810(CsWord handle);
int __stdcall FUN_006d8b00(CsNamedPairList *list, const char **name);
/* Whole record command 006D7C80-006D7CF7: looks the name up among the record containers (FUN_004a80b0) and,
 * when the record has an object, passes its +44 handle to FUN_009fa810; then appends (name, 0) to the root's
 * +16D8 list unless it is already there, as 006D7C20 does. FUN_004a80b0, FUN_009fa810 and FUN_006d8b00 are /GL
 * context stand-ins; their LTCG-chosen interfaces are NOT claimed as native ABI bindings. The 8-byte aligned frame
 * (006D7C83) comes from the 009FA810 stand-in's double. */
__declspec(noinline) void __cdecl FUN_006d7c80(const CsNameValueCommandTrial *option)
{
    if (option->name) {
        CsNamedPair entry,key;
        CsNamedPairList *list;
        int index,count;
        CsReferencedRecordTrial *record=FUN_004a80b0(option->name);
        if (record!=0 && record->object!=0) FUN_009fa810(record->object->handle);
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
