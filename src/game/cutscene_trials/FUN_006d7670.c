/* Shader LOD Force Highest effect: complete 006d7670..006d76a1.
 * Preserve the -2 save-once sentinel and both global stores. */
#include "../cutscene_types.h"
typedef struct CsSavedLodView {
    unsigned char unknown_0000[0x165c];
    int field_165c;
} CsSavedLodView;
extern CsSavedLodView *DAT_02527d10;
extern int DAT_00e849d0;
extern unsigned char DAT_02526dc4;
__declspec(noinline) void __cdecl FUN_006d7670(const CsEffectBoolOption *option)
{
    if (option->value==1) {
        if (DAT_02527d10->field_165c==-2)
            DAT_02527d10->field_165c=DAT_00e849d0;
        DAT_02526dc4=0;
        DAT_00e849d0=0;
    }
}
