/* Complete listed instruction-CFG trial from REA. Offsets are literal observations. Moved from gate
   npc-ai-rea-next-virtual; the vtable slot +4 call is an audited literal virtual CALL, and the state checks are an
   inline helper returning int (native's two kinds of zero return).
 * Original source declaration and runtime virtual target are unknown. Never executed. */
typedef unsigned char U8;
typedef unsigned int U32;
typedef int (__fastcall *Method)(U8 *, void *);
extern U8 *DAT_027b3c60;
extern U8 *DAT_01408e88;
extern int DAT_00e843ac;
static __forceinline int state_ready(U8 *record) {
 U8 *state=DAT_027b3c60; U8 *receiver; Method method;
 if (!state || *(int *)(state+0x3c)!=1) return 0;
 receiver=*(U8 **)(state+0x90);
 method=*(Method *)(*(U8 **)receiver+4);
 if (method(receiver,(void *)method)==0x10 && *(U32 *)(record+0x78)>=0x14) return 1;
 return 0;
}
__declspec(noinline) U8 __cdecl FUN_00669830(void) {
 U8 *outer=DAT_01408e88; U8 *record;
 if (!outer || !(record=*(U8 **)(outer+0x10))) return 0;
 return state_ready(record);
}
