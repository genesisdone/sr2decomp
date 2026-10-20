/* FUN_00b71790: whole 37-byte body, cached count/base and signed loop. */
typedef unsigned char View;
extern int DAT_022d7bd0;extern View *DAT_022d7bcc;
__declspec(noinline) View *__cdecl FUN_00b71790(unsigned int handle) {
 int count=DAT_022d7bd0,index=0;View *record=DAT_022d7bcc;
 if(count>0)do {if(*(unsigned int *)(record+0x44)==handle)return record;++index;record+=0x498;}while(index<count);
 return 0;
}
