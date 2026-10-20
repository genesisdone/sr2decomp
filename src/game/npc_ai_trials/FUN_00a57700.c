/* EXE: FUN_00a57700; full native C trial. Semantic ownership unestablished. */
extern unsigned char *DAT_02e7df0c;
__declspec(noinline) unsigned char *__fastcall FUN_00a57700(int unused,const int *wanted) {
    unsigned char *first=DAT_02e7df0c,*node=first;
    if (first) {
        do {
            if (*(int *)(node+0xc)==*wanted) return node;
            node=*(unsigned char **)(node+0x30);
        } while (node!=first && node);
    }
    return 0;
}
