/* Command-name lookup. Evidence: 006ccfa0..006ccfdd.
 * Null and unknown names both return index zero, as in the native body. */
#include "../cutscene_types.h"
typedef struct CsCommandNameRecord {
    const char *name;
    CsWord execute, done, flags;
} CsCommandNameRecord;
extern CsCommandNameRecord DAT_00dd2b28[63];
extern int __cdecl FUN_00c99030(const char *left, const char *right);

__declspec(noinline) unsigned int __cdecl FUN_006ccfa0(const char *name)
{
    unsigned int index;
    const CsCommandNameRecord *record;
    if (name == 0)
        return 0;
    index = 0;
    record = DAT_00dd2b28;
    do {
        if (FUN_00c99030(record->name, name) == 0)
            return index;
        ++index;
        ++record;
    } while (index < 63);
    return 0;
}
