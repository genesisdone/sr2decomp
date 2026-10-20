/* FUN_005759d0: whole 35-byte native body. */
typedef unsigned char View;
extern unsigned int DAT_00e843ac;
__declspec(noinline) void __cdecl FUN_005759d0(View *object) {
 int deadline=(int)(DAT_00e843ac+30000u);*(int *)(object+0x14c8)=deadline;if(deadline>1800000000)*(int *)(object+0x14c8)=deadline-1800000000;
}
