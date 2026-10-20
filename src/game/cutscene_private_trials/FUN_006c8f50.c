#include "../cutscene_types.h"
/* Whole 006c8f50..006c8f9b, native EAX=output. EAX is preserved on both
 * original return paths, so express that returned pointer explicitly.
 * Partial offset views only; certification still requires every byte.
 * The volatile pointer-slot read is an imposed access-order choice: native
 * 006C8F6D loads the base before 006C8F73 multiplies the selected index.
 * Original source qualifiers are unknown. Unsigned byte-address arithmetic
 * preserves the native 32-bit multiply/add representation. */
typedef struct CsRecord4cView {
    CsWord unknown_00[2];
    unsigned char field_08,unknown_09[15];
    float field_18[3];
    unsigned char unknown_24[0x28];
} CsRecord4cView;
typedef struct CsRecordSelectionView {
    unsigned char unknown_000[0x124];
    CsRecord4cView *items;
    int capacity,count;
    unsigned char unknown_130[0x980];
    int selected;
} CsRecordSelectionView;
typedef char cs_selection_offset[(offsetof(CsRecordSelectionView,selected)==0xab0)?1:-1];
typedef char cs_record_stride[(sizeof(CsRecord4cView)==0x4c)?1:-1];
extern CsRecordSelectionView *DAT_02527d10;
__declspec(noinline) float * __cdecl FUN_006c8f50(float *output)
{
    CsRecordSelectionView *instance=DAT_02527d10;
    if (instance!=0 && instance->count>0 && instance->selected>=0) {
        int selected=instance->selected;
        CsWord items=(CsWord)*(CsRecord4cView *volatile *)&instance->items;
        CsWord byte_offset=(CsWord)selected*0x4cU;
        CsRecord4cView *record=(CsRecord4cView *)(items+byte_offset);
        if (record->field_08==1) {
            output[0]=record->field_18[0];
            output[1]=record->field_18[1];
            output[2]=record->field_18[2];
            return output;
        }
    }
    output[0]=0.0f;
    output[1]=0.0f;
    output[2]=0.0f;
    return output;
}
static float *volatile output_input;
static float *volatile result;
void comparison_entry(void) { result=FUN_006c8f50(output_input); }
