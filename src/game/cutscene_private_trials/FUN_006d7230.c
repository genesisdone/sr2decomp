/* Full blend parser: 006d7230..006d7296. Native ESI=name, EDI=record.
 * 0=Linear, 1=Soft Param, 2=Hard Param, 3=Accel; unknown falls back to 0.
 * Strings and call targets are audited named operands, not embedded bytes. */
#include "../cutscene_types.h"
extern char DAT_00ddc404[],DAT_00e0caf4[],DAT_00e0cb00[],DAT_00e0cad8[];
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) void __cdecl FUN_006d7230(const char *name, CsBlendView *record)
{
    if (FUN_00c99030(name,DAT_00ddc404)==0) {
        record->blend=0;
        return;
    }
    if (FUN_00c99030(name,DAT_00e0caf4)==0) {
        record->blend=1;
        return;
    }
    if (FUN_00c99030(name,DAT_00e0cb00)==0) {
        record->blend=2;
        return;
    }
    record->blend=FUN_00c99030(name,DAT_00e0cad8)==0 ? 3 : 0;
}
static const char *volatile input;
static CsBlendView *volatile output;
void comparison_entry(void) { FUN_006d7230(input,output); }
