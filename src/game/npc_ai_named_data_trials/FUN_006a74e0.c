/* FUN_006a74e0: whole 61-byte body, including conditional state reset. */
typedef unsigned char View;
extern View *DAT_027b3c60,*DAT_02527c80;
extern unsigned int DAT_02527888,DAT_01450380;
__declspec(noinline) unsigned int __cdecl FUN_006a74e0(const View *unused) {
 View *object=DAT_027b3c60;unsigned int state;
 if(object)return *(unsigned int *)(object+60);
 if(DAT_02527888)return 4;
 state=DAT_01450380;
 if(state==5 || state==6) {
  object=DAT_02527c80;if(object)return *(unsigned int *)(object+60);
  DAT_01450380=(unsigned int)object;
 }
 return 0xffffffffu;
}
