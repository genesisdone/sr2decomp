/* EXE: FUN_0099bad0; complete 57-byte dependency trial; private ABI uncertified until full linked equality. */
typedef unsigned char View;
/* Native AL predicate; AX includes x87 status after a matching-key comparison. */
__declspec(noinline) unsigned char __cdecl FUN_0099bad0(const View *object,int key) {
 const View *state=*(const View *const *)(object+0x5e0),*slot=state+0x14;int count=*(const int *)(state+0x10),i=0;
 if(count>0) {do {if(*(const int *)slot==key && *(const float *)(slot+0x14)>=1.0f)return 1;++i;slot+=0x2c;}while(i<count);}
 return 0;
}
