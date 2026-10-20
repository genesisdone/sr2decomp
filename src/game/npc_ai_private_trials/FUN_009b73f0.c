/* EXE: FUN_009b73f0; complete 84-byte dependency trial; private ABI uncertified until full linked equality. */
typedef unsigned char View;
/* Only native AL is exposed as the logical predicate result. Native FNSTSW writes AX. */
__declspec(noinline) unsigned char __cdecl FUN_009b73f0(const View *object) {
 const View *state=*(const View *const *)(object+0x5e0);unsigned int kind=*(const unsigned int *)(state+0x14);
 if(kind!=0xa3 && kind!=0xa2 && kind!=0xa4) {
 kind=*(const unsigned int *)(state+0x40);
 if(kind==0xa3 || kind==0xa2 || kind==0xa4) {
 if(*(const float *)(state+0x50)>0.0f && *(const float *)(state+0x24)<1.0f)return 1;
 }}return 0;
}
