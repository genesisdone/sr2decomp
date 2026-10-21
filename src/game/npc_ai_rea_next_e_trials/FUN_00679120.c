/* Complete listed instruction-CFG trial from REA. Offsets are literal observations. Moved from gate
   npc-ai-rea-next-virtual; the vtable slot +4 call is an audited literal virtual CALL.
 * Original source declaration and runtime virtual target are unknown. Never executed. */
typedef unsigned char U8;
typedef unsigned int U32;
typedef int (__fastcall *Method)(U8 *, void *);
extern U8 *DAT_027b3c60;
extern U8 *DAT_01408e88;
extern int DAT_00e843ac;
__declspec(noinline) int __cdecl FUN_00679120(void) {
 U8 *state=DAT_027b3c60; U8 *receiver; U8 *outer; U8 *record; Method method;
 if (!state || *(int *)(state+0x3c)!=1) return 0;
 receiver=*(U8 **)(state+0x90);
 method=*(Method *)(*(U8 **)receiver+4);
 if (method(receiver,(void *)method)!=2) return 0;
 outer=DAT_01408e88;
 if (outer && (record=*(U8 **)(outer+0x10)) && *(int *)(record+0x24)==3) return 1;
 return 0;
}
