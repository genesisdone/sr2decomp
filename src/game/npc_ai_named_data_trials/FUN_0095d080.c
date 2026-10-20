/* EXE: FUN_0095d080; complete 95-byte body. Logical C inputs are uncertified until whole linked bytes match. */
typedef unsigned char View;
extern View *DAT_02149c64[];
__declspec(noinline) int __cdecl FUN_0095d080(const View *object) {
 const View *selected;unsigned int handle;int result;
 if(!object) selected=0;
 else {handle=*(const unsigned int *)(object+0x2a4);if(!handle || !(selected=DAT_02149c64[(handle&0xfff)*4]) || *(const unsigned int *)(selected+0x44)!=handle || *(const int *)(selected+0x4c)!=1 || (selected[0x80]&0xb))selected=object;}
 /* Native code still dereferences both pointers on the null-input path. */
 result=*(const signed char *)(selected+0x111c);
 if(object[0x3cc]==2 && !result && (object[0x1172]&4))result=4;
 return result;
}
