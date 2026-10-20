/* Full 16-byte-record name search: 006cefb0..006ceff0.
 * Native ESI=list, name is a caller-cleaned stack argument. */
#include "../cutscene_types.h"
typedef struct CsNameRecord10 {
    const char *name;
    CsWord field_04,field_08,field_0c;
} CsNameRecord10;
typedef struct CsNameList10 { CsNameRecord10 *items; int capacity,count; } CsNameList10;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) CsNameRecord10 * __cdecl FUN_006cefb0(CsNameList10 *list, const char *name)
{
    int index=0;
    if (list->count>0) {
        int offset=0;
        do {
            CsNameRecord10 *record=(CsNameRecord10 *)
                ((unsigned char *)list->items+offset);
            if (FUN_00c99030(name,record->name)==0)
                return list->items+index;
            ++index;
            offset+=sizeof(CsNameRecord10);
        } while (index<list->count);
    }
    return 0;
}
static CsNameList10 *volatile list_input;
static const char *volatile name_input;
static CsNameRecord10 *volatile result;
void comparison_entry(void) { result=FUN_006cefb0(list_input,name_input); }
