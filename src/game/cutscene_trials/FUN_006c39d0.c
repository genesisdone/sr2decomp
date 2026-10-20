/* Complete name lookup: 006c39d0..006c3a1c. The count global is re-read
 * after each external comparison, as the original does. */
#include "../cutscene_types.h"
typedef struct CsNamedRecord14 {
    const char *name;
    CsWord unknown_04,unknown_08,unknown_0c,unknown_10;
} CsNamedRecord14;
extern CsNamedRecord14 *DAT_0145a4a4;
extern int DAT_0145a4ac;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) CsNamedRecord14 * __cdecl FUN_006c39d0(const char *volatile name)
{
    const char *needle=name; /* Native argument read at 006C39D1 precedes count. */
    int index;
    for (index = 0; index < DAT_0145a4ac; ++index) {
        if (FUN_00c99030(DAT_0145a4a4[index].name,needle)==0)
            return &DAT_0145a4a4[index];
    }
    return 0;
}
