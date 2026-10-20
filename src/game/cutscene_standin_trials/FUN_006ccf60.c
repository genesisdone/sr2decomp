#include "../cutscene_types.h"
/* Whole MARK FOR CUTSCENE action handler (action table 0x00DD2B28): looks the named object up and sets
 * bit 0x400000 in its +CC flags. FUN_00a52bb0 and FUN_00a52c70 are /GL context stand-ins; the interfaces
 * LTCG chooses for them are NOT claimed as native ABI bindings. */
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
typedef struct CsObjectFlagCommandTrial { unsigned char unknown_00[0xcc]; CsWord flags_cc; } CsObjectFlagCommandTrial;
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
__declspec(noinline) void __cdecl FUN_006ccf60(const CsNameCommandTrial *option)
{
    unsigned char found;
    CsObjectFlagCommandTrial *object=(CsObjectFlagCommandTrial *)find_object_by_name(option->name,&found);
    if (object!=0) object->flags_cc|=0x400000;
}
