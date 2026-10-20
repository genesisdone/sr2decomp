#include "../cutscene_types.h"
/* Whole Weather Stage shot option handler (option table 0x00DD28A0): resolves the stage name; a found
 * index sets instance +43D4 and, through the native tail E9 at 006D7DD7, selects that stage with flag 1.
 * FUN_004dec00 is a /GL context stand-in; the interface LTCG chooses for it is NOT claimed as the native
 * ABI (native: index EAX, flag CL). */
typedef struct CsCommandTwoNamesTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsCommandTwoNamesTrial;
typedef struct CsCommandRootTrial { unsigned char unknown_00[0x43d4]; unsigned char field_43d4; } CsCommandRootTrial;
extern CsCommandRootTrial *DAT_02527d10;
int __cdecl FUN_004dee30(const char *name);
void FUN_004dec00(int index,unsigned char flag);
__declspec(noinline) void __cdecl FUN_006d7db0(const CsCommandTwoNamesTrial *option)
{
    if (option->name!=0) {
        int index=FUN_004dee30(option->name);
        if (index!=-1) {
            DAT_02527d10->field_43d4=1;
            FUN_004dec00(index,1);
        }
    }
}
