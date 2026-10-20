#include "../cutscene_types.h"
/* Whole 88-entry name lookup 009e7530..009e7559, native EDI=name. */
extern const char *DAT_00e87f78[88];
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) int __cdecl FUN_009e7530(const char *name)
{
    int index=0;
    do {
        if (FUN_00c99030(DAT_00e87f78[index],name)==0)
            return index;
        ++index;
    } while (index<88);
    return -1;
}
static const char *volatile name_input;
static int volatile result;
void comparison_entry(void) { result=FUN_009e7530(name_input); }
