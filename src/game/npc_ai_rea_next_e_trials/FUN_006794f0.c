/* Complete listed instruction-CFG trial from REA. Offsets are literal observations.
 * Original source declaration and runtime virtual target are unknown. Never executed. Moved to batch E; the vtable slot +0x38 call is an audited literal virtual CALL.
   The timer helper reads through a volatile pointer because native reads +0x204 a second time after the caller's
   own sign test; whether SR2 declared that field volatile (or read it through a helper VC8 could not merge) is an
   unconfirmed hypothesis. */
typedef unsigned char U8;
typedef unsigned int U32;
typedef int (__fastcall *Method)(U8 *, void *);
extern U8 *DAT_027b3c60;
extern U8 *DAT_01408e88;
extern int DAT_00e843ac;
static __forceinline int timer_expired(const volatile int *timer) {
 int value=*timer, now;
 if (value<0) return 0;
 now=DAT_00e843ac;
 if (value>now) { if (value-now<900000000) return 0; }
 else { if (now-value>=900000000) return 0; }
 return 1;
}
__declspec(noinline) int __fastcall FUN_006794f0(U8 *receiver) {
 Method method;
 if (*(int *)(receiver+0x1fc)!=1 || *(int *)(receiver+0x204)<0) return 0;
 if (timer_expired((int *)(receiver+0x204)) &&
     (method=*(Method *)(*(U8 **)receiver+0x38), method(receiver,(void *)method)>0)) return 1;
 return 0;
}
