#include "../cutscene_types.h"
/* Whole 006beed0..006befb4, native ECX=record, EAX=output (LTCG-chosen).
 * Distinct vector-copy/add/scale stages retain float rounding boundaries.
 * Logical output-first order agrees with all five worklist caller adapters.
 * The count==0 and flag==0 paths both zero the output (native tail-merged).
 * Agent-1 probe 2026-10-19: both /LTCG links equal, 228/228 bytes; canonical
 * private gate not yet run on this revision. */
typedef struct CsFloat3
{
    float x, y, z;
} CsFloat3;
typedef struct CsPoint7c
{
    CsWord field_00;
    CsFloat3 point;
    unsigned char unknown_10[0x6c];
} CsPoint7c;
typedef struct CsPointSourceView
{
    unsigned char unknown_000[0x100];
    CsPoint7c *items;
    int capacity, count;
} CsPointSourceView;
typedef struct CsInstanceFlagAfd
{
    unsigned char unknown_000[0xafd];
    unsigned char field_afd;
} CsInstanceFlagAfd;
extern CsInstanceFlagAfd *DAT_02527d10;
extern double DAT_00e5bf70;
__declspec(noinline) void __cdecl FUN_006beed0(CsFloat3 *output, const CsPointSourceView *source)
{
    if (DAT_02527d10->field_afd == 0)
    {
        output->x = 0.0f;
        output->y = 0.0f;
        output->z = 0.0f;
        return;
    }
    if (source->count == 1)
    {
        const CsFloat3 *point = &source->items[0].point;
        output->x = point->x;
        output->y = point->y;
        output->z = point->z;
        return;
    }
    if (source->count == 0)
    {
        output->x = 0.0f;
        output->y = 0.0f;
        output->z = 0.0f;
        return;
    }
    {
        const CsPoint7c *items = source->items;
        CsFloat3 first, second, sum, scaled;
        first.x = items[0].point.x;
        first.y = items[0].point.y;
        first.z = items[0].point.z;
        second.x = items[1].point.x;
        second.y = items[1].point.y;
        second.z = items[1].point.z;
        sum.x = second.x + first.x;
        sum.y = second.y + first.y;
        sum.z = second.z + first.z;
        scaled.x = (float)(sum.x * DAT_00e5bf70);
        scaled.y = (float)(sum.y * DAT_00e5bf70);
        scaled.z = (float)(sum.z * DAT_00e5bf70);
        output->x = scaled.x;
        output->y = scaled.y;
        output->z = scaled.z;
    }
}
static const CsPointSourceView *volatile source_input;
static CsFloat3 *volatile output_input;
void comparison_entry(void)
{
    FUN_006beed0(output_input, source_input);
}
