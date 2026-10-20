/* EXE: FUN_009a0270; entire native C trial, no guessed field identities. */
typedef unsigned char View;
extern double DAT_00e5c1c8,DAT_00e5c1c0;
extern float DAT_00e88414;
__declspec(noinline) float __fastcall FUN_009a0270(const View *object) {
    if (*(const float *)(object+0x43c)>0.0f) return (float)(*(const float *)(object+0x43c)*DAT_00e5c1c8+DAT_00e5c1c0);
    return DAT_00e88414;
}
