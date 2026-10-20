#include "../cutscene_types.h"
/* Whole 006c6e80..006c6ed8, including internal alignment.
 * Native entity=EDI, AL result; sole virtual call at 006C6EBE uses slot +34.
 */
typedef struct CsMembershipEntity {
    unsigned char unknown_00[0xcc]; unsigned int flags_cc;
} CsMembershipEntity;
typedef struct CsMembershipActor CsMembershipActor;
typedef CsMembershipEntity * (__fastcall *CsMembershipGetter)(CsMembershipActor *actor);
typedef struct CsMembershipVtable { unsigned int unknown_00[13]; CsMembershipGetter get_entity; } CsMembershipVtable;
struct CsMembershipActor { CsMembershipVtable *vtable; };
typedef struct CsMembershipRoot {
    unsigned char unknown_00[0xac8];
    CsMembershipActor **actors;
    int capacity,count;
} CsMembershipRoot;
extern CsMembershipRoot *DAT_02527d10;
extern unsigned char DAT_02527d14;
__declspec(noinline) unsigned char __cdecl FUN_006c6e80(const CsMembershipEntity *entity)
{
    if (DAT_02527d14) {
        int index;
        if (entity->flags_cc & 0x400000)
            return 1;
        for (index = 0; index < DAT_02527d10->count; ++index) {
            CsMembershipActor *actor = DAT_02527d10->actors[index];
            if (entity == actor->vtable->get_entity(actor))
                return 1;
        }
    }
    return 0;
}
static const CsMembershipEntity *volatile entity_input;
void comparison_entry(void) { FUN_006c6e80(entity_input); }
