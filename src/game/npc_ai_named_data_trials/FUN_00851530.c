/* FUN_00851530: complete 31-byte body, retain pre-increment native EAX. */
typedef unsigned char View;
extern View *DAT_0168d678;
__declspec(noinline) unsigned int __cdecl FUN_00851530(const View *unused) {
 View *object=DAT_0168d678;unsigned int previous;
 if(*(unsigned int *)(object+56)>=65536u)*(unsigned int *)(object+56)=*(unsigned int *)(object+48);
 previous=*(unsigned int *)(object+56);*(unsigned int *)(object+56)=previous+1u;return previous;
}
