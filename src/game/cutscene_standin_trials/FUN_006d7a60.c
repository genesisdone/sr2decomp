#include "../cutscene_types.h"
/* Whole Hide Player Compnt. shot option handler (option table 0x00DD28A0): looks the component name up;
 * a found index goes to FUN_009ea4e0 with the player owner word, otherwise the native tail E9 at
 * 006D7A99 transfers to FUN_009ea660 with the owner word. FUN_009e7530 is a /GL context stand-in; the
 * interface LTCG chooses for it is NOT claimed as a native ABI binding. */
typedef struct CsCommandTwoNamesTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsCommandTwoNamesTrial;
typedef struct CsCommandPlayerTrial { unsigned char unknown_00[0x13b0]; CsWord field_13b0; } CsCommandPlayerTrial;
extern CsCommandPlayerTrial *DAT_021703d4;
int FUN_009e7530(const char *name);
void __cdecl FUN_009ea4e0(CsWord owner,int index);
void __cdecl FUN_009ea660(CsWord owner);
__declspec(noinline) void __cdecl FUN_006d7a60(const CsCommandTwoNamesTrial *option)
{
    int index=FUN_009e7530(option->name);
    if (index!=-1) FUN_009ea4e0(DAT_021703d4->field_13b0,index);
    else FUN_009ea660(DAT_021703d4->field_13b0);
}
