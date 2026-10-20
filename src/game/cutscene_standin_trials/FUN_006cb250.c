#include "../cutscene_types.h"
/* Whole LOOK AT NOTHING action handler (action table 0x00DD2B28): looks the named actor up, sets bit 0 of +758
 * and, when its +3CC kind is 2, clears bit 2 of +140. FUN_00a52bb0 and FUN_00a52c70 are /GL context
 * stand-ins; the interfaces LTCG chooses for them are NOT claimed as native ABI bindings. */
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
typedef struct CsActorCommandTrial { unsigned char unknown_00[0x140]; unsigned char flags_140; unsigned char unknown_141[0x28b]; unsigned char kind_3cc; unsigned char unknown_3cd[0x38b]; unsigned int flags_758; } CsActorCommandTrial;
typedef char cs_actor_check[(offsetof(CsActorCommandTrial,kind_3cc)==0x3cc && offsetof(CsActorCommandTrial,flags_758)==0x758)?1:-1];
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
__declspec(noinline) void __cdecl FUN_006cb250(const CsNameCommandTrial *option)
{
    unsigned char found;
    CsActorCommandTrial *actor=(CsActorCommandTrial *)find_object_by_name(option->name,&found);
    if (actor==0) return;
    actor->flags_758|=1;
    if (actor->kind_3cc==2) actor->flags_140&=0xfb;
}
