#include "../cutscene_types.h"
/* Whole callback: decrements DAT_02527d30 and, unless DAT_02527d27 is set, plays the animation FUN_007f4bc0 finds
 * for *name through FUN_006d9610(animation, 0, DAT_00e87998, 0), discarding its float result. The pointer arrives
 * in EAX natively; the interface LTCG chooses here is not claimed as the native ABI. */
extern CsWord DAT_02527d30;
extern unsigned char DAT_02527d27;
extern float DAT_00e87998;
void *FUN_007f4bc0(const char *name);
float FUN_006d9610(void *animation, float start, float duration, CsWord flags);
__declspec(noinline) void __cdecl FUN_006d9400(const char **name)
{
    --DAT_02527d30;
    if (DAT_02527d27==0)
        FUN_006d9610(FUN_007f4bc0(*name),0.0f,DAT_00e87998,0);
}
