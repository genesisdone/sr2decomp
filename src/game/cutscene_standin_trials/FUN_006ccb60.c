#include "../cutscene_types.h"
/* Whole LOOK AT NOTHING action handler (action table 0x00DD2B28): looks the named actor up, sets bit 0 of +758
 * and, when its +3CC kind is 2, clears bit 2 of +140. FUN_00a52bb0 and FUN_00a52c70 are /GL context
 * stand-ins; the interfaces LTCG chooses for them are NOT claimed as native ABI bindings. */
typedef struct CsPairCommandTrial { unsigned char unknown_00[8]; const char *first,*second; } CsPairCommandTrial;
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
void FUN_009b2fe0(unsigned char *object, int flag);
void FUN_00409b30(unsigned char *object, unsigned char *other, int flag);
/* Whole two-name command 006CCB60-006CCBE0: looks both names up; the same object gets FUN_009b2fe0(object, 1),
 * two different objects get FUN_00409b30(object, other, 1). FUN_00a52bb0, FUN_00a52c70, FUN_009b2fe0 and
 * FUN_00409b30 are /GL context stand-ins; their LTCG-chosen interfaces are NOT claimed as native ABI bindings.
 * Compiled with /GS for the cookies in the 009B2FE0 / 00409B30 stand-ins (both natives carry one). */
__declspec(noinline) void __cdecl FUN_006ccb60(const CsPairCommandTrial *option)
{
    unsigned char found;
    unsigned char *object=find_object_by_name(option->first,&found);
    unsigned char *other;
    if (object==0) return;
    other=find_object_by_name(option->second,&found);
    if (other==0) return;
    if (object==other) { FUN_009b2fe0(object,1); return; }
    FUN_00409b30(object,other,1);
}
