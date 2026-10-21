/* Complete canonical REA virtual caller. Runtime callee remains unknown; the slot +0x14 call is an audited literal
   virtual CALL. Moved from gate npc-ai-rea-next-a7. */
typedef int (__fastcall *VirtualMethod)(void *,void *);
extern int *DAT_0215e5bc;
extern int DAT_0252a0d8;
extern int DAT_02fad294[];
__declspec(noinline) unsigned char FUN_009576c0(void) {
    int *receiver=DAT_0215e5bc;
    if(receiver) {
        VirtualMethod method=(VirtualMethod)(*(int **)receiver)[5];
        int index=method(receiver,(void *)method);
        if(index>=0 && index<DAT_0252a0d8) return (unsigned char)(DAT_02fad294[index*500]==3);
    }
    return 0;
}
