/* EXE: FUN_00956f00; complete 70-byte C trial. Native read order, wrap, guards and outputs retained. */
typedef unsigned char View;
extern View *DAT_0215e578[];
extern View DAT_0215e5bc[];
__declspec(noinline) View *__cdecl FUN_00956f00(const View *object) {
 unsigned int handle=*(const unsigned int *)(object+0x44);View **table=DAT_0215e578,*record,*slot,*result;int index;
 do {record=*table;index=0;slot=record+0x60;do {
 if(*(unsigned int *)slot==handle) {result=(View *)((unsigned int)record+(unsigned int)index*0x30u+0x5cu);if(result)return result;break;}
 ++index;slot+=0x30;}while(index<8);
 ++table;}while((int)table<(int)DAT_0215e5bc);return 0;
}
