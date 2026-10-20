/* EXE: FUN_00556610; complete 84-byte C trial. Native read order, wrap, guards and outputs retained. */
typedef unsigned char View;
extern unsigned int DAT_02799308,DAT_0279938c;
extern View *DAT_02799304,*DAT_02799388;
extern unsigned char DAT_0279932c;
__declspec(noinline) unsigned char __cdecl FUN_00556610(const View *object) {
 unsigned int handle=*(const unsigned int *)(object+0x44);View *data;
 if(DAT_02799308==handle && (data=DAT_02799304)!=0 && (data=*(View **)(data+0x24))!=0 && *(int *)(data+0x94) && (DAT_0279932c&1))return 1;
 if(DAT_0279938c==handle && (data=DAT_02799388)!=0 && (data=*(View **)(data+0x24))!=0 && *(int *)(data+0x94))return 1;
 return 0;
}
