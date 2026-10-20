#include "../cutscene_types.h"
/* Whole 006C37D0..006C381E: returns the index (0..2) of the first of three names whose hash equals the
 * value, else 0. FUN_00bdcb30 is a /GL context stand-in; the interface LTCG chooses for it is NOT claimed
 * as a native ABI binding. */
extern char DAT_00e0c670,DAT_00dfeea4,DAT_00e0c678;
unsigned int *__stdcall FUN_00bdcb30(const char *text,unsigned int seed,unsigned int *output);
__declspec(noinline) int __cdecl FUN_006c37d0(unsigned int value)
{
    const char *names[3];
    int index;
    names[0]=&DAT_00e0c670;
    names[1]=&DAT_00dfeea4;
    names[2]=&DAT_00e0c678;
    for (index=0; index<3; ++index) {
        unsigned int output;
        if (value==*FUN_00bdcb30(names[index],0,&output)) return index;
    }
    return 0;
}
