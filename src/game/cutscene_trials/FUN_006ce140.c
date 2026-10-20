/* Whole 006ce140..006ce170. Native ECX receiver / EAX returned receiver.
 * Existing map_fixups_f117.cpp holds a naked-assembly version of this same
 * original. This trial upgrades representation to /TC C, not project-wide
 * unique-original coverage. Names describe only proven native offsets.
 */
typedef struct CsAnimationConstructorView {
    unsigned int field_00,field_04,field_08,field_0c;
    unsigned char field_10,field_11,unknown_12[2];
    unsigned int field_14,field_18,field_1c;
    float field_20;
    unsigned char field_24,unknown_25[3];
    int field_28,field_2c;
} CsAnimationConstructorView;
__declspec(noinline) CsAnimationConstructorView * __fastcall FUN_006ce140(CsAnimationConstructorView *record)
{
    record->field_20 = 0.0f;
    record->field_00 = 0;
    record->field_04 = 0;
    record->field_08 = 0;
    record->field_0c = 0;
    record->field_10 = 0;
    record->field_11 = 0;
    record->field_14 = 0;
    record->field_18 = 0;
    record->field_1c = 0;
    record->field_24 = 0;
    record->field_28 = -1;
    record->field_2c = -1;
    return record;
}
