/* EXE: FUN_0097a380; full original C trial. Private input layout is not certified until whole linked bytes match. */
typedef unsigned char View;
__declspec(noinline) unsigned char __cdecl FUN_0097a380(View *object,const View *other) {
    int count;
    if (object && other && (count=*(int *)(object+0xb78))<16) {
        *(unsigned int *)(object+0xb7c+count*4)=*(const unsigned int *)(other+0x44);
        ++*(int *)(object+0xb78);return 1;
    }
    return 0;
}
