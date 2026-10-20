/* EXE: FUN_0096e3a0; full original C trial. Private input layout is not certified until whole linked bytes match. */
typedef unsigned char View;
__declspec(noinline) void __cdecl FUN_0096e3a0(View *object,float delta) {
    float remaining;
    if (*(int *)(object+0x1020)==-1) {
        *(int *)(object+0x101c)=-1;*(float *)(object+0x1024)=0.0f;return;
    }
    remaining=*(float *)(object+0x1024)-delta;
    *(float *)(object+0x1024)=remaining;
    if (remaining<=0.0f) {
        *(float *)(object+0x1024)=0.0f;*(int *)(object+0x1020)=-1;*(int *)(object+0x101c)=-1;
    }
}
