/* Effect-name lookup. Evidence: 006d8300..006d833e.
 * Table: 53 records, 12 bytes each; name is the first word.
 * The CRT comparison body is an external dependency, not recovered here. */
#include "../cutscene_types.h"
typedef struct CsEffectNameRecord {
    const char *name;
    CsWord unknown_04, unknown_08;
} CsEffectNameRecord;
extern CsEffectNameRecord DAT_00dd28a0[53];
extern int __cdecl FUN_00c99030(const char *left, const char *right);

__declspec(noinline) int __cdecl FUN_006d8300(const char *name)
{
    int index = 0;
    unsigned int offset = 0;
    do {
        const CsEffectNameRecord *record = (const CsEffectNameRecord *)
            ((const unsigned char *)DAT_00dd28a0 + offset);
        if (FUN_00c99030(name, record->name) == 0)
            return index;
        offset += sizeof(CsEffectNameRecord);
        ++index;
    } while (offset < 53 * sizeof(CsEffectNameRecord));
    return 0;
}
