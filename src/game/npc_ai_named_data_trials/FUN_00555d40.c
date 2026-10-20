/* FUN_00555d40: whole 27-byte native body. */
typedef unsigned char View;
extern int DAT_025274e0;extern View DAT_02797be0[];
__declspec(noinline) View * __cdecl FUN_00555d40(int index) {
 if(index>=0 && index<DAT_025274e0)return (View *)((unsigned int)DAT_02797be0+(unsigned int)index*0x94u);return 0;
}
