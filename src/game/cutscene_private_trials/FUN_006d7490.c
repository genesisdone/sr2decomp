/* Full effect-option kind lookup: 006d7490..006d7500.
 * Native EDI=name. Seven local pointers, exact strings named by address.
 * 0 empty/default; 1 OptBool, 2 OptFloat, 3 OptString, 4 OptColor,
 * 5 OptLight, 6 OptVector. Unknown/null returns 0. */
#include "../cutscene_types.h"
extern char DAT_00dc5797[],DAT_00e0d758[],DAT_00e0d760[],DAT_00e0d76c[];
extern char DAT_00e0d778[],DAT_00e0d784[],DAT_00e0d790[];
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) int __cdecl FUN_006d7490(const char *name)
{
    const char *names[7];
    int index;
    if (name==0)
        return 0;
    names[0]=DAT_00dc5797;
    names[1]=DAT_00e0d758;
    names[2]=DAT_00e0d760;
    names[3]=DAT_00e0d76c;
    names[4]=DAT_00e0d778;
    names[5]=DAT_00e0d784;
    names[6]=DAT_00e0d790;
    index=0;
    do {
        if (FUN_00c99030(name,names[index])==0)
            return index;
        ++index;
    } while (index<7);
    return 0;
}
static const char *volatile input;
static volatile int result;
void comparison_entry(void) { result=FUN_006d7490(input); }
