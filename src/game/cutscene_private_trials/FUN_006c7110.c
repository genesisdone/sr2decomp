#include "../cutscene_types.h"
/* Whole 006c7110..006c718e. Native root=EDI, target on stack, AL result.
 * Four virtual calls use exactly vtable slot +34; both calls per node are
 * retained. Dynamic callee implementations are outside this caller's scope.
 * keep takes target's address and is otherwise unused: it keeps target a
 * stack argument under /LTCG, as natively (006C7113 MOV EBX,[ESP+8]).
 */
typedef struct CsLinkedEntity { unsigned char unknown_00[0x44]; unsigned int handle; } CsLinkedEntity;
typedef struct CsLinkedActor CsLinkedActor;
typedef CsLinkedEntity * (__fastcall *CsGetLinkedEntity)(CsLinkedActor *actor);
typedef struct CsLinkedActorVtable {
    unsigned int unknown_00[13];
    CsGetLinkedEntity get_entity;
} CsLinkedActorVtable;
struct CsLinkedActor {
    CsLinkedActorVtable *vtable;
    unsigned char unknown_04[0x60];
    CsLinkedActor *next_64,*next_68;
};
typedef struct CsLinkedActorRoot {
    unsigned char unknown_00[0x20];
    CsLinkedActor *head_20;
    unsigned int unknown_24;
    CsLinkedActor *head_28;
} CsLinkedActorRoot;
typedef char cs_linked_actor_offsets[(offsetof(CsLinkedActor,next_64)==0x64 && offsetof(CsLinkedActorVtable,get_entity)==0x34)?1:-1];
__declspec(noinline) unsigned char __cdecl FUN_006c7110(const CsLinkedActorRoot *root, const CsLinkedEntity *target)
{
    const CsLinkedEntity **keep=&target;
    CsLinkedActor *actor;
    if (!root || !target)
        return 0;
    actor = root->head_20;
    while (actor) {
        if (actor->vtable->get_entity(actor) &&
            actor->vtable->get_entity(actor)->handle == target->handle)
            return 1;
        actor = actor->next_64;
        if (actor == root->head_20)
            break;
    }
    actor = root->head_28;
    while (actor) {
        if (actor->vtable->get_entity(actor) &&
            actor->vtable->get_entity(actor)->handle == target->handle)
            return 1;
        actor = actor->next_68;
        if (actor == root->head_28)
            break;
    }
    (void)keep;
    return 0;
}
static const CsLinkedActorRoot *volatile root_input;
static const CsLinkedEntity *volatile target_input;
void comparison_entry(void) { FUN_006c7110(root_input,target_input); }
