#include "../cutscene_types.h"
/* Whole 006c1660..006c16e6, including seven internal alignment bytes.
 * Native EAX=mask index, ECX=mask list, actors on stack. Field roles beyond
 * this update are not established; all native strides are asserted below. */
typedef struct CsByteMask { unsigned char *bits; int capacity,count; } CsByteMask;
typedef struct CsByteMaskList { CsByteMask *items; int capacity,count; } CsByteMaskList;
typedef struct CsAnimation90Flag { unsigned char unknown_00[0x7c]; unsigned char field_7c; unsigned char unknown_7d[0x13]; } CsAnimation90Flag;
typedef struct CsActor50Flags {
    CsWord unknown_00[3];
    CsAnimation90Flag *animations;
    int animation_count;
    unsigned char field_14,unknown_15[0x3b];
} CsActor50Flags;
typedef struct CsActorsFlagRoot { CsWord field_00; CsActor50Flags *items; int count; } CsActorsFlagRoot;
typedef char cs_flag_strides[(sizeof(CsActor50Flags)==0x50 && sizeof(CsAnimation90Flag)==0x90)?1:-1];
__declspec(noinline) void __cdecl FUN_006c1660(unsigned int index, const CsByteMaskList *masks, CsActorsFlagRoot *actors)
{
    if (index<(unsigned int)masks->count) {
        const CsByteMask *mask=&masks->items[index];
        int actor_index=0;
        if (actors->count>0) {
            int actor_offset=0;
            do {
                CsActor50Flags *actor=(CsActor50Flags *)((unsigned char *)actors->items+actor_offset);
                if (actor->field_14==1) {
                    int animation_index=0;
                    if (actor->animation_count>0) {
                        int animation_offset=0;
                        do {
                            if (animation_index<mask->count) {
                                CsAnimation90Flag *animation=(CsAnimation90Flag *)((unsigned char *)actor->animations+animation_offset);
                                animation->field_7c=mask->bits[animation_index]==0;
                            }
                            ++animation_index;
                            animation_offset+=0x90;
                        } while (animation_index<actor->animation_count);
                    }
                }
                actor_offset+=0x50;
                ++actor_index;
            } while (actor_index<actors->count);
        }
    }
}
static unsigned int volatile index_input;
static const CsByteMaskList *volatile masks_input;
static CsActorsFlagRoot *volatile actors_input;
void comparison_entry(void) { FUN_006c1660(index_input,masks_input,actors_input); }
