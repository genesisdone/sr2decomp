#include "../cutscene_types.h"
/* Whole sound-event start 006C1CB0-006C1D29. Native event EDI, group EDX (register inputs: the driver calls it
 * directly so LTCG gives it a custom interface). Marks the event started, sets handle.x to 0xFF and, for a real
 * sound, resolves the actor's name (FUN_00a52ca0), builds a descriptor (FUN_00464920), sets flags 0x802 and
 * plays it (FUN_00465b00), copying the returned three-word handle. All three callees are /GL context
 * stand-ins whose LTCG-chosen interfaces are NOT claimed as native ABI bindings. The named `entry` pointer
 * gives native's unfolded LEA + MOV name load (006C1CE6-006C1CEA). */
typedef struct CsSoundEvent { unsigned short sound; unsigned char unknown_02[0x12]; int actor; unsigned char unknown_18[5]; unsigned char started; unsigned char unknown_1e[2]; CsWords3 handle; } CsSoundEvent;
typedef struct CsSoundActor { const char *name; unsigned char unknown_04[0x78]; } CsSoundActor;
typedef struct CsSoundGroup { unsigned char unknown_00[0x100]; CsSoundActor *actors; int capacity,count; } CsSoundGroup;
typedef struct CsSoundDescriptor { unsigned short sound,unknown_02; unsigned char unknown_04[8]; float scale_0c,scale_10; unsigned char unknown_14[4]; int kind; unsigned char unknown_1c[0x3c]; unsigned short flags,unknown_5a; } CsSoundDescriptor;
CsWord FUN_00a52ca0(const char *);
void __stdcall FUN_00464920(CsSoundDescriptor *,unsigned int,int,CsWord);
CsWords3 *FUN_00465b00(CsWords3 *,CsSoundDescriptor *); /* EAX/ECX */
__declspec(noinline) void __cdecl FUN_006c1cb0(CsSoundEvent *event,CsSoundGroup *group)
{
    if(event->started!=1){
        event->started=1;event->handle.x=0xff;
        if(event->sound!=0xffff){
            CsWord actor=0;CsSoundDescriptor descriptor;CsWords3 result,*returned;
            if(event->actor>=1 && event->actor<=group->count){CsSoundActor *entry=&group->actors[event->actor-1];actor=FUN_00a52ca0(entry->name);}
            FUN_00464920(&descriptor,event->sound,1,actor);descriptor.flags|=0x802;
            returned=FUN_00465b00(&result,&descriptor);event->handle.x=returned->x;event->handle.y=returned->y;event->handle.z=returned->z;
        }
    }
}
