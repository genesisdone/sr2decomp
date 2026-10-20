#include "../cutscene_types.h"
/* Whole engine XML boolean reader 00b74120..00b7417e. Native ESI=text,
 * AL=result. Retain the false/no comparisons even though both return zero. */
extern const char DAT_00ddb838[],DAT_00ddc0dc[],DAT_00ddb840[],DAT_00e32c04[];
extern int __cdecl FUN_00c986c0(const char *left, const char *right, unsigned int count);
__declspec(noinline) unsigned char __cdecl FUN_00b74120(const char *text)
{
    if (FUN_00c986c0(text,DAT_00ddb838,0x400)!=0) {
        if (FUN_00c986c0(text,DAT_00ddc0dc,0x400)!=0) {
            if (FUN_00c986c0(text,DAT_00ddb840,0x400)!=0)
                FUN_00c986c0(text,DAT_00e32c04,0x400);
            return 0;
        }
    }
    return 1;
}
static const char *volatile text_input;
static unsigned char volatile result;
void comparison_entry(void) { result=FUN_00b74120(text_input); }
