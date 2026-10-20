/* FUN_007b36f0: whole 57-byte body; state input and conditional marker. */
typedef unsigned char View;
extern unsigned char DAT_02528adf,DAT_025287cb;extern View *DAT_02528834;extern unsigned int DAT_00e8cf7c;
__declspec(noinline) void __cdecl FUN_007b36f0(View *object) {
 unsigned char locked=DAT_02528adf;unsigned int state;
 DAT_02528834=object;
 if(locked!=1){state=DAT_00e8cf7c;if(state!=13 && state!=11)DAT_00e8cf7c=5;}
 if(*(int *)(object+0x13c)==5)DAT_025287cb=1;
}
