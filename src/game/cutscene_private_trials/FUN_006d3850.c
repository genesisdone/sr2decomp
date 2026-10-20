#include "../cutscene_types.h"
#include "../cutscene_constructor_context.h"
/* Whole shot initializer 006d3850..006d3875. Receiver ECX, return EAX.
 * Calls the complete, independently deferred camera initializer at +1c.
 * Including that body supplies compiler context, not callee certification. */
typedef struct CsShotCtorView {
    CsWord unknown_00,field_04;
    unsigned char unknown_08[0x14];
    CsCameraTweenOptions camera;
    unsigned char unknown_b8[4];
    unsigned char field_bc,unknown_bd[3];
    CsWord field_c0;
} CsShotCtorView;
typedef char cs_ctor_offsets[(offsetof(CsShotCtorView,camera)==0x1c && offsetof(CsShotCtorView,field_bc)==0xbc && offsetof(CsShotCtorView,field_c0)==0xc0)?1:-1];
extern CsWord DAT_033d6308;
__declspec(noinline) CsShotCtorView * __fastcall FUN_006d3850(CsShotCtorView *shot)
{
    shot->field_04=DAT_033d6308;
    FUN_006ce1f0(&shot->camera);
    shot->field_bc=0;
    shot->field_c0=0;
    return shot;
}
static CsShotCtorView *volatile shot_input,*volatile result;
/* An address-taken fastcall interface keeps the real external ECX receiver;
 * direct-only LTCG calls otherwise specialize it to an ESI argument. */
static CsShotCtorView * (__fastcall *volatile constructor)(CsShotCtorView *)=FUN_006d3850;
void comparison_entry(void) { result=constructor(shot_input); }
