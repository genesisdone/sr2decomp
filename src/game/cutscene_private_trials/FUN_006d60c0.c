/* Complete shot-record copy: 006d60c0..006d6275, 437 bytes.
 * Native EAX=destination, EDX=source. Aggregate blocks at +1c/+bc retain
 * the two REP MOVSD copies; explicit typed scalars retain all other accesses.
 * Names describe offsets only. No original class name is claimed. */
#include "../cutscene_types.h"
typedef struct CsBlock39 { CsWord words[39]; } CsBlock39;
typedef struct CsBlock16 { CsWord words[16]; } CsBlock16;
typedef struct CsShotCopyView {
    CsWord field_00,field_04,field_08,field_0c,field_10,field_14;
    float field_18;
    CsBlock39 field_1c;
    unsigned char field_b8,unknown_b9[3];
    CsBlock16 field_bc;
    CsWord field_0fc;
    CsWord field_100;
    CsWord field_104;
    CsWord field_108;
    CsWord field_10c;
    CsWord field_110;
    CsWord field_114;
    CsWord field_118;
    CsWord field_11c;
    CsWord field_120;
    CsWord field_124;
    CsWord field_128;
    CsWord field_12c;
    CsWord field_130;
    CsWord field_134;
    CsWord field_138;
    CsWord field_13c;
    CsWord field_140;
    CsWord field_144;
    CsWord field_148;
    CsWord field_14c;
    CsWord field_150;
    CsWord field_154;
    float field_158;
    CsWord field_15c,field_160;
    float field_164,field_168;
    unsigned char field_16c,unknown_16d[3];
} CsShotCopyView;
typedef char check_shot_size[(sizeof(CsShotCopyView)==0x170)?1:-1];
typedef char check_shot_blocks[(offsetof(CsShotCopyView,field_bc)==0xbc && offsetof(CsShotCopyView,field_158)==0x158)?1:-1];
__declspec(noinline) void __cdecl FUN_006d60c0(const CsShotCopyView *source, CsShotCopyView *destination)
{
    destination->field_00 = source->field_00;
    destination->field_04 = source->field_04;
    destination->field_08 = source->field_08;
    destination->field_0c = source->field_0c;
    destination->field_10 = source->field_10;
    destination->field_14 = source->field_14;
    destination->field_18 = source->field_18;
    destination->field_1c = source->field_1c;
    destination->field_b8 = source->field_b8;
    destination->field_bc = source->field_bc;
    destination->field_0fc = source->field_0fc;
    destination->field_100 = source->field_100;
    destination->field_104 = source->field_104;
    destination->field_108 = source->field_108;
    destination->field_10c = source->field_10c;
    destination->field_110 = source->field_110;
    destination->field_114 = source->field_114;
    destination->field_118 = source->field_118;
    destination->field_11c = source->field_11c;
    destination->field_120 = source->field_120;
    destination->field_124 = source->field_124;
    destination->field_128 = source->field_128;
    destination->field_12c = source->field_12c;
    destination->field_130 = source->field_130;
    destination->field_134 = source->field_134;
    destination->field_138 = source->field_138;
    destination->field_13c = source->field_13c;
    destination->field_140 = source->field_140;
    destination->field_144 = source->field_144;
    destination->field_148 = source->field_148;
    destination->field_14c = source->field_14c;
    destination->field_150 = source->field_150;
    destination->field_154 = source->field_154;
    destination->field_158 = source->field_158;
    destination->field_15c = source->field_15c;
    destination->field_160 = source->field_160;
    destination->field_164 = source->field_164;
    destination->field_168 = source->field_168;
    destination->field_16c = source->field_16c;
}
static CsShotCopyView *volatile output;
static const CsShotCopyView *volatile input;
void comparison_entry(void) { FUN_006d60c0(input,output); }
