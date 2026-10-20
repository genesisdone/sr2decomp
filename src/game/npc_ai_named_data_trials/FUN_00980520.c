/* EXE: FUN_00980520; complete native C trial, semantic AI ownership unestablished. */
typedef unsigned char View;
extern View *DAT_025296c4;
__declspec(noinline) unsigned char __cdecl FUN_00980520(unsigned char index) {
    if (index==0xff) return 0;
    return (*(unsigned int *)(DAT_025296c4+(unsigned int)index*0x74+0x48)>>11)&1;
}
