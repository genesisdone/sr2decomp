/* Complete canonical REA caller. EDX is an unused physical fastcall position. */
extern int __fastcall FUN_009d06a0(int handle);
extern unsigned char __cdecl FUN_00985630(int object);
__declspec(noinline) int __fastcall FUN_00783c20(unsigned char *object,void *unused,char allow) {
    int state=*(int *)(object+0x200);
    if(state!=0 && state!=1) {
        int result=FUN_009d06a0(*(int *)(object+0x1f8));
        if(!allow && FUN_00985630(result)) return 0;
        return result;
    }
    return 0;
}
