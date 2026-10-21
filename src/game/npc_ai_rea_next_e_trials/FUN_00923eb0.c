/* FUN_00923eb0: runs FUN_00922da0 on the object (native: ECX); when its +0x1e4 is 5 and byte +0x2a9 is 0, clears
   DAT_025295ca and starts the timer DAT_00eb799c 120000 ms from DAT_00e843ac (wrapped past 1800000000); always sets
   +0x2b8 to -1. Moved from gate npc-ai-rea-next-a3 (deferred there). */
extern void __fastcall FUN_00922da0(void *object);
extern int DAT_00e843ac;
extern int DAT_00eb799c;
extern unsigned char DAT_025295ca;
static __forceinline void timer_start(int *timer, int ms)
{
    *timer = DAT_00e843ac + ms;
    if (*timer > 1800000000) {
        *timer -= 1800000000;
    }
}
__declspec(noinline) void __fastcall FUN_00923eb0(unsigned char *object) {
    FUN_00922da0(object);
    if(*(int *)(object+0x1e4)==5 && object[0x2a9]==0) {
        DAT_025295ca=0;
        timer_start(&DAT_00eb799c, 120000);
    }
    *(unsigned int *)(object+0x2b8)=0xffffffff;
}
