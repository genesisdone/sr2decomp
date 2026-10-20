/* Complete worklist C trials as compiler context; no duplicate coverage.
 * One global pointer uses explicit casts for the two original offset views. */
#ifndef SR2_CUTSCENE_MEMBERSHIP_CONTEXT_H
#define SR2_CUTSCENE_MEMBERSHIP_CONTEXT_H
extern void *DAT_02527d10;
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
extern unsigned char DAT_02527d14;
__declspec(noinline) unsigned char __cdecl FUN_006c6e80(const CsMembershipEntity *entity)
{
    if (DAT_02527d14) {
        int index;
        if (entity->flags_cc & 0x400000)
            return 1;
        for (index = 0; index < ((CsMembershipRoot *)DAT_02527d10)->count; ++index) {
            CsMembershipActor *actor = ((CsMembershipRoot *)DAT_02527d10)->actors[index];
            if (entity == actor->vtable->get_entity(actor))
                return 1;
        }
    }
    return 0;
}
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
extern unsigned char DAT_02527d14;
__declspec(noinline) unsigned char __cdecl FUN_006c6ee0(const CsVehicleMemberEntity *target)
{
    if (DAT_02527d14) {
        int index;
        for (index = 0; index < ((CsVehicleMemberRoot *)DAT_02527d10)->count; ++index) {
            CsVehicleMember *vehicle = ((CsVehicleMemberRoot *)DAT_02527d10)->vehicles[index];
            if (vehicle->vtable->get_entity(vehicle)) {
                vehicle = ((CsVehicleMemberRoot *)DAT_02527d10)->vehicles[index];
                if (target->handle == vehicle->vtable->get_entity(vehicle)->handle)
                    return 1;
            }
        }
    }
    return 0;
}
#endif
