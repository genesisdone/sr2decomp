/* FUN_00783970: complete 67-byte body; state guard precedes clock and owner reads. */
typedef unsigned char View;
extern int DAT_029dc1e8;extern unsigned int DAT_00e843ac;extern View *DAT_021703d4;extern unsigned char DAT_025283c2;
__declspec(noinline) void __cdecl FUN_00783970(const View *unused) {
 int deadline;View *object;
 if(DAT_029dc1e8!=17)return;
 deadline=(int)DAT_00e843ac;object=DAT_021703d4;deadline=(int)((unsigned int)deadline+500u);
 *(int *)(object+0xf80)=deadline;if(deadline>1800000000)*(int *)(object+0xf80)=deadline-1800000000;
 DAT_029dc1e8=18;DAT_025283c2=1;
}
