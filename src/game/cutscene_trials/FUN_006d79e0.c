/* Force TOD Lights: 006d79e0..006d79f5. */
#include "../cutscene_types.h"
extern unsigned char DAT_02526cc3,DAT_02526cc4;
__declspec(noinline) const CsEffectBoolOption * __cdecl FUN_006d79e0(const CsEffectBoolOption *option)
{
    unsigned char value=option->value;
    DAT_02526cc3=1;
    DAT_02526cc4=value;
    return option; /* Native EAX retains the argument; CL carries the byte. */
}
