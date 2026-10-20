/* EXE: FUN_00bfdb20; full 48-byte C trial. Logical inputs, fields and partial-byte returns follow native instructions; not yet certified. */
typedef unsigned char View;
__declspec(noinline) void __cdecl FUN_00bfdb20(View *object) {
 int kind=*(int *)(object+0x148);View *nested;
 *(unsigned int *)(object+0x168)&=0xfffffff7u;
 if(!kind) {nested=*(View **)(object+0x14c);*(unsigned int *)(nested+8)&=0xfffffff7u;return;}
 if(kind==1) {nested=**(View ***)(object+0x14c);*(unsigned int *)(nested+8)&=0xfffffff7u;}
}
