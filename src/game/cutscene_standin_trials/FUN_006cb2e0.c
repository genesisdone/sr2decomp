#include "../cutscene_types.h"
/* Whole command handler: looks the actor up by name and calls FUN_004a29e0(actor, DAT_00dd80c8,
 * DAT_025f5b20, 0).
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsActorNameCommandTrial { unsigned char unknown_00[0xc]; const char *name; } CsActorNameCommandTrial;
extern CsWords3 DAT_025f5b20;
extern const char DAT_00dd80c8[];
void FUN_004a29e0(unsigned char *actor, const char *label, const CsWords3 *position, unsigned char *orientation);
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
__declspec(noinline) void __cdecl FUN_006cb2e0(const CsActorNameCommandTrial *option)
{
    unsigned char found;
    unsigned char *actor=find_object_by_name(option->name,&found);
    if (actor!=0) FUN_004a29e0(actor,DAT_00dd80c8,&DAT_025f5b20,0);
}
