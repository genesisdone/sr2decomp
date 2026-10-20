/* EXE: FUN_00aa7d30; complete 84-byte C trial; every native guard and output retained. */
typedef unsigned char View;
__declspec(noinline) float __cdecl FUN_00aa7d30(const View *object,unsigned int index) {
 const View *record,*owner;volatile float value;
 if(object[0x84d8]==1 && index<*(const unsigned int *)(object+0x55c)) {
 record=(const View *)((unsigned int)object+index*0x120u+0x560u);
 if(record && (owner=*(const View *const *)(record+0xb4),*(const int *)(owner+4)==4)) {
 if(*(const unsigned int *)(record+0x11c)&0x200000)value=1.0f;else value=*(const float *)(record+0x30);return value;
 }}return 1.0f;
}
