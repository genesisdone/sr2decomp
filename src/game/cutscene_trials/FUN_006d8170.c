/* Fog Distance: full 006d8170..006d81e0. Native zero-vs-value TEST AH,41
 * accepts equal/less, rejects greater/unordered: all three inputs nonnegative.
 * The three floats are staged through x87 into one local, copied as a word
 * triple, then stored to the three separately named globals. */
#include "../cutscene_types.h"
typedef struct CsFogVector { float x,y,z; } CsFogVector;
typedef struct CsFogOption { CsWord unknown_00,unknown_04; const CsFogVector *value; } CsFogOption;
typedef union CsFogBits { CsFogVector floats; CsWords3 words; } CsFogBits;
extern unsigned char DAT_02658ca4;
extern CsWord DAT_02658ca8,DAT_02658cac,DAT_02658cb0;
__declspec(noinline) void __cdecl FUN_006d8170(const CsFogOption *option)
{
    const CsFogVector *value=option->value;
    if (value->x>=0.0f && value->y>=0.0f && value->z>=0.0f) {
        CsFogBits staged;
        CsWords3 words;
        staged.floats.x=value->x;
        staged.floats.y=value->y;
        staged.floats.z=value->z;
        words=staged.words;
        DAT_02658ca4=1;
        DAT_02658ca8=words.x;
        DAT_02658cac=words.y;
        DAT_02658cb0=words.z;
    } else {
        DAT_02658ca4=0;
    }
}
