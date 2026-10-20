/* FUN_00667300: complete 83-byte body; cached old pointer before current-index write. */
typedef unsigned char View;
__declspec(noinline) void __cdecl FUN_00667300(View *object,unsigned int index,unsigned int unused) {
 unsigned int *previous=*(unsigned int **)(object+0x88),value;
 *(unsigned int *)(object+0x84)=index;
 if(previous)*(unsigned int *)(object+0xc4)=*previous;else *(unsigned int *)(object+0xc4)=0;
 if(index==*(unsigned int *)(object+0xa4)){*(unsigned int *)(object+0x88)=0;return;}
 value=(*(unsigned int **)(object+0xa8))[index];
 *(unsigned int *)(object+0x88)=*(unsigned int *)(object+0xcc)+value*20u;
}
