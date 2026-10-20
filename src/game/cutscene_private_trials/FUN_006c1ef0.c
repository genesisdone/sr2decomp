#include "../cutscene_types.h"
/* Whole 006c1ef0..006c1f62, including internal alignment before 006c1f10.
 * Native instance=EDI (LTCG-chosen) and force byte on stack. Handles pass in ECX.
 * Field roles beyond the native comparisons remain unknown.
 * Plain indexed loop: the per-entry current-pointer read 006C1F2A is
 * unconditional in the native body and in this C (no qualifiers needed).
 * Agent-1 probe 2026-10-19: both /LTCG links equal, 114/114 bytes; canonical
 * private gate not yet run on this revision.
 */
typedef struct CsSoundEntryView
{
    unsigned char unknown_00[0x18];
    int shot_index;
    unsigned char flag_1c, unknown_1d[3];
    unsigned int handle;
    unsigned char unknown_24[8];
} CsSoundEntryView;
typedef struct CsSoundShotIndex
{
    unsigned char unknown_00[8];
    int index;
} CsSoundShotIndex;
typedef struct CsSoundCurrentShot
{
    unsigned char unknown_00[0x190];
    CsSoundShotIndex *index;
} CsSoundCurrentShot;
typedef struct CsSoundInstance
{
    unsigned char unknown_00[0x124];
    CsSoundEntryView *sounds;
    int capacity, count;
} CsSoundInstance;
typedef struct CsSoundRoot
{
    unsigned char unknown_00[0x1688];
    CsSoundCurrentShot *current;
} CsSoundRoot;
typedef char cs_sound_entry_stride[(sizeof(CsSoundEntryView) == 0x2c) ? 1 : -1];
extern CsSoundRoot *DAT_02527d10;
extern void __fastcall FUN_0047feb0(unsigned int *handle);
__declspec(noinline) void __cdecl FUN_006c1ef0(CsSoundInstance *instance, unsigned char force)
{
    if (instance->count > 0)
    {
        int index = 0;
        if (index < instance->count)
        {
            CsSoundRoot *root = DAT_02527d10;
            do
            {
                CsSoundEntryView *sound = &instance->sounds[index];
                int shot_index = sound->shot_index;
                CsSoundCurrentShot *current = root->current;
                if ((shot_index == -1 || (current && shot_index == current->index->index + 1)) &&
                    (!sound->flag_1c || force))
                    FUN_0047feb0(&sound->handle);
            } while (++index < instance->count);
        }
    }
}
static CsSoundInstance *volatile instance_input;
static unsigned char volatile force_input;
void comparison_entry(void)
{
    FUN_006c1ef0(instance_input, force_input);
}
