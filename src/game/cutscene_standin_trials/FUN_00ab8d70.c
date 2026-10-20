#include "../cutscene_types.h"
/* Whole helper: -1 unless the vehicle's +84D8 byte is 1, else FUN_006f0170(vehicle+82A0, identifier, 0x539, 0,
 * a, b, c). Vehicle and identifier arrive in EAX and ECX natively; the interface LTCG chooses here is not
 * claimed as the native ABI. */
int FUN_006f0170(unsigned char *slots, CsWord identifier, int type, int flags, float a, float b, float c);
__declspec(noinline) int __cdecl FUN_00ab8d70(unsigned char *vehicle, CsWord identifier, float a, float b, float c)
{
    if (vehicle[0x84d8]!=1) return -1;
    return FUN_006f0170(vehicle+0x82a0,identifier,0x539,0,a,b,c);
}
