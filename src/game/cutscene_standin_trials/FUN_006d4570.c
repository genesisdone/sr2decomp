#include "../cutscene_types.h"
/* Whole title lookup: formats DAT_00e0d2e4 with the name into a 0x100-byte buffer (FUN_00bf2c10), upper-cases
 * it (FUN_00c9fe83), turns every '-' into '_', and looks the result up with FUN_007f4bc0, falling back to the
 * plain name. Native /GS: the gate compiles this trial with /GS (GS_TRIALS). Callee stand-ins live in the context
 * file; their interfaces are not claimed as native ABI bindings. */
extern const char DAT_00e0d2e4[];
void FUN_00bf2c10(char *buffer,unsigned int size,const char *format,...);
char *__cdecl FUN_00c9fe83(char *text);
char *__cdecl FUN_00c9a0f0(const char *text,int c);
void *FUN_007f4bc0(const char *name);
__declspec(noinline) void *__cdecl FUN_006d4570(const char *name)
{
    char title[0x100];
    char *hyphen;
    void *result;
    FUN_00bf2c10(title,0x100,DAT_00e0d2e4,name);
    FUN_00c9fe83(title);
    hyphen=FUN_00c9a0f0(title,'-');
    while (hyphen!=0) {
        *hyphen='_';
        hyphen=FUN_00c9a0f0(title,'-');
    }
    result=FUN_007f4bc0(title);
    if (result==0) result=FUN_007f4bc0(name);
    return result;
}
