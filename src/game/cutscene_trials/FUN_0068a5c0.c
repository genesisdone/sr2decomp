#include "../cutscene_types.h"
/* Complete hour/minute delta helper. Native FILD interprets wrapped seconds
 * as signed32. Original RET0068A645 closes134 bytes, not inventory253.
 * CMP EDX,-1 / JLE0068A630 is written as minute>-1, preserving the native
 * expression and exact compiler selection; >=0 produced a different body. */
extern unsigned char DAT_0140e72c,DAT_0140e72d;
extern void __cdecl FUN_0068a1e0(float seconds,int unscaled,int suppress_callbacks,int force);
__declspec(noinline) void __fastcall FUN_0068a5c0(int time)
{
    int hour=time,minute=-1;CsWord seconds;
    if(time>99){hour=time/100;minute=time%100;}
    hour-=DAT_0140e72c;if(hour<0)hour+=24;seconds=(CsWord)hour*3600U;
    if(minute>-1){minute-=DAT_0140e72d;if(minute<0){minute+=60;--hour;if(hour<0)hour+=24;seconds=(CsWord)hour*3600U;}seconds+=(CsWord)minute*60U;}
    FUN_0068a1e0((float)(int)seconds,1,0,1);
}
