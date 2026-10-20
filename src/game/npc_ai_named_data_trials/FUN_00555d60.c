/* FUN_00555d60: whole 51-byte body; native caches table count. */
typedef unsigned char View;
extern int DAT_025274e0;extern View DAT_02797be0[];
__declspec(noinline) View *__cdecl FUN_00555d60(const View *owner) {
 View *record;int count,i;
 if(owner) {
  count=DAT_025274e0;i=0;record=DAT_02797be0;
  if(count>0)do {
   if(*(const View **)(record+24)==owner || *(const View **)(record+20)==owner || *(const View **)(record+16)==owner)return record;
   ++i;record+=0x94;
  }while(i<count);
 }
 return 0;
}
