#include "../cutscene_types.h"
#include "../cutscene_membership_context.h"
/* Whole 006c6f50..006c6fa7. Native input=EAX, AL result. Helpers in the
 * context are complete existing worklist trials, not additional recovery.
 */
typedef struct CsTypedMembershipEntity {
    unsigned char unknown_00[0x4c];
    int type;
    unsigned char unknown_50[0x37c];
    unsigned char field_3cc;
} CsTypedMembershipEntity;
extern unsigned char DAT_02527cf7,DAT_02527d15;
__declspec(noinline) unsigned char __cdecl FUN_006c6f50(const CsTypedMembershipEntity *entity)
{
    switch (entity->type) {
    case 1:
        return FUN_006c6e80((const CsMembershipEntity *)entity) ||
               (((DAT_02527d14 && DAT_02527cf7) || DAT_02527d15) &&
                entity->type == 1 && entity->field_3cc == 1);
    case 5:
        return FUN_006c6ee0((const CsVehicleMemberEntity *)entity);
    default:
        return 0;
    }
}
static const CsTypedMembershipEntity *volatile entity_input;
void comparison_entry(void) { FUN_006c6f50(entity_input); }
