/* Complete canonical REA caller; fields are unnamed observed byte offsets. */
extern void __fastcall FUN_00956080(void *object);
__declspec(noinline) void __fastcall FUN_00922da0(unsigned char *object) {
    FUN_00956080(object);
    object[0x1e8]=0;
    *(unsigned int *)(object+0x1ec)=0xffffffff;
    *(unsigned int *)(object+0x1f0)=0xffffffff;
    *(unsigned int *)(object+0x1f4)=0;
    *(unsigned int *)(object+0x1fc)=0;
    object[0x2b0]=0;
    object[0x2b1]=0;
    *(unsigned int *)(object+0x2b4)=0xffffffff;
    object[0x2a4]=0;
    object[0x20c]=0;
    object[0x20d]=0;
    *(unsigned int *)(object+0x210)=0xffffffff;
    *(unsigned int *)(object+0x214)=0xffffffff;
    *(unsigned int *)(object+0x218)=0xffffffff;
}
