/* FUN_006abce0: complete 94-byte body; cached key, two divisions and terminal reload. */
typedef unsigned char View;
extern int DAT_01450418[];extern View DAT_027d5a78[];
__declspec(noinline) int __cdecl FUN_006abce0(const unsigned int *key_pointer) {
 unsigned int key=*key_pointer,index=key%1322u;int slot=DAT_01450418[index];
 while(slot!=-1) {
  if(*(unsigned int *)(DAT_027d5a78+(unsigned int)slot*16u)==key)return slot;
  index=(index+1u)%1322u;slot=DAT_01450418[index];
 }
 return DAT_01450418[index];
}
