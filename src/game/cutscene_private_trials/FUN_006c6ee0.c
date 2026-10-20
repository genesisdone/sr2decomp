#include "../cutscene_types.h"
/* Whole 006c6ee0..006c6f4a. Native target=EDI, AL result.
 * Retain both +34 virtual calls and the global/list reload between them.
 */
typedef struct CsVehicleMemberEntity { unsigned char unknown_00[0x44]; unsigned int handle; } CsVehicleMemberEntity;
typedef struct CsVehicleMember CsVehicleMember;
typedef CsVehicleMemberEntity * (__fastcall *CsVehicleMemberGetter)(CsVehicleMember *actor);
typedef struct CsVehicleMemberVtable { unsigned int unknown_00[13]; CsVehicleMemberGetter get_entity; } CsVehicleMemberVtable;
struct CsVehicleMember { CsVehicleMemberVtable *vtable; };
typedef struct CsVehicleMemberRoot {
    unsigned char unknown_00[0xae0];
    CsVehicleMember **vehicles;
    int capacity,count;
} CsVehicleMemberRoot;
extern CsVehicleMemberRoot *DAT_02527d10;
extern unsigned char DAT_02527d14;
__declspec(noinline) unsigned char __cdecl FUN_006c6ee0(const CsVehicleMemberEntity *target)
{
    if (DAT_02527d14) {
        int index;
        for (index = 0; index < DAT_02527d10->count; ++index) {
            CsVehicleMember *vehicle = DAT_02527d10->vehicles[index];
            if (vehicle->vtable->get_entity(vehicle)) {
                vehicle = DAT_02527d10->vehicles[index];
                if (target->handle == vehicle->vtable->get_entity(vehicle)->handle)
                    return 1;
            }
        }
    }
    return 0;
}
static const CsVehicleMemberEntity *volatile target_input;
void comparison_entry(void) { FUN_006c6ee0(target_input); }
