#include "../cutscene_types.h"
/* Whole TEAM DESPAWN action handler (action table 0x00DD2B28): looks the named actor up and passes its
 * +111C team byte (sign-extended) with 1 to FUN_00ae4a00 and FUN_00964660. FUN_00a52bb0 and FUN_00a52c70
 * are /GL context stand-ins; the interfaces LTCG chooses for them are NOT claimed as native ABI bindings. */
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
typedef struct CsTeamActorTrial { unsigned char unknown_00[0x111c]; signed char team_111c; } CsTeamActorTrial;
void __cdecl FUN_00ae4a00(int team,int enabled);
void __cdecl FUN_00964660(int team,int enabled);
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
__declspec(noinline) void __cdecl FUN_006cc4f0(const CsNameCommandTrial *option)
{
    unsigned char found;
    CsTeamActorTrial *actor=(CsTeamActorTrial *)find_object_by_name(option->name,&found);
    if (actor!=0) {
        int team=actor->team_111c;
        FUN_00ae4a00(team,1);
        FUN_00964660(team,1);
    }
}
