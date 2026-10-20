/* FUN_00580780: whole 41-byte native body. */
typedef unsigned char View;
extern unsigned int DAT_00e843ac;
__declspec(noinline) void __cdecl FUN_00580780(View *object,unsigned int value) {
 int deadline;*(unsigned int *)(object+0x4d0)=value;deadline=(int)(DAT_00e843ac+10000u);*(int *)(object+0x50c)=deadline;if(deadline>1800000000)*(int *)(object+0x50c)=deadline-1800000000;
}
