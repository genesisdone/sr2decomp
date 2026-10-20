/* EXE: FUN_00cec1e0; complete 188-byte logical C trial. Whole native body and all outputs retained; ABI uncertified. */
typedef unsigned char View;
extern int DAT_024e1864;
extern View DAT_024f2f00[];
extern double DAT_00e5bf60;
__declspec(noinline) void __cdecl FUN_00cec1e0(float *output,int index) {
 View *record,*data;int ticks;float duration,inverse;
 output[0]=0.0f;output[1]=0.0f;output[2]=0.0f;
 if(index<0 || index>=DAT_024e1864)return;
 record=(View *)((unsigned int)DAT_024f2f00+(unsigned int)index*32u);if(!record)return;
 data=*(View **)(record+0x1c);
 ticks=data ? *(unsigned short *)(data+6)*80:0;
 duration=(float)((double)ticks/DAT_00e5bf60);
 if(duration>0.0f) {
 output[0]=0.0f;output[1]=0.0f;output[2]=0.0f;
 data=*(View **)(record+0x1c);
 if(!data) {output[0]=0.0f;output[1]=0.0f;output[2]=0.0f;}
 else {*(unsigned int *)(output)=*(unsigned int *)(data+0x1c);*(unsigned int *)(output+1)=*(unsigned int *)(data+0x20);*(unsigned int *)(output+2)=*(unsigned int *)(data+0x24);}
 inverse=(float)(1.0/duration);
 output[0]=inverse*output[0];output[1]=output[1]*inverse;output[2]=inverse*output[2];
 }
}
