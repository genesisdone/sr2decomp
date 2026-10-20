#include "../cutscene_types.h"
/* Whole string-to-float command 006cb6a0..006cb6da. Incoming text at +10.
 * Native unordered/zero/negative comparisons clear the active flag; the
 * value global is written on both paths after the flag is set. */
typedef struct CsStringCommand { unsigned char unknown_00[0x10]; const char *text; } CsStringCommand;
extern unsigned char DAT_025f5d90;
extern float DAT_025f5d94;
extern double __cdecl FUN_00c984f5(const char *text);
__declspec(noinline) void __cdecl FUN_006cb6a0(const CsStringCommand *command)
{
    float value=(float)FUN_00c984f5(command->text);
    DAT_025f5d90=1;
    if (!(value>0.0f)) DAT_025f5d90=0;
    DAT_025f5d94=value;
}
