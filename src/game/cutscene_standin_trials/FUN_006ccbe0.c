#include "../cutscene_types.h"
/* Whole HUMAN SHIELD done check (action table 0x00DD2B28): true when both named objects resolve and the
 * first one's +EA8 word equals the second one's +44 handle. One found flag is shared by both lookups.
 * FUN_00a52bb0 and FUN_00a52c70 are /GL context stand-ins; the interfaces LTCG chooses for them are NOT
 * claimed as native ABI bindings. */
typedef struct CsCommandOption { CsWord unknown_00[2],identifier; const char *name,*value; } CsCommandOption;
void *FUN_00a52bb0(const char *name,unsigned char *found);
void *FUN_00a52c70(const char *name);
/* Inlined name lookup with the shape of native FUN_00a52ca0 (00A52CA0-00A52CC9): a NULL name gives 0; else
 * FUN_00a52bb0 with a cleared found flag and, when the flag stays clear, FUN_00a52c70. Keeping the
 * FUN_00a52c70 result in its own local reproduces the native double TEST EAX after that call. The helper
 * name describes the code; no original name is known. */
static unsigned char *find_object_by_name(const char *name, unsigned char *found)
{
    unsigned char *object;
    if (name==0) return 0;
    *found=0;
    object=FUN_00a52bb0(name,found);
    if (*found==0) {
        unsigned char *other=FUN_00a52c70(name);
        if (other==0) return 0;
        return other;
    }
    return object;
}
__declspec(noinline) unsigned char __cdecl FUN_006ccbe0(const CsCommandOption *option)
{
    unsigned char found;
    unsigned char *first,*second;
    first=find_object_by_name((const char *)option->identifier,&found);
    if (!first) return 0;
    second=find_object_by_name(option->name,&found);
    if (!second) return 0;
    return *(CsWord *)(first+0xea8)==*(CsWord *)(second+0x44);
}
