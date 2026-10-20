/* EXE: FUN_009902a0; full native body C trial. Semantics from native branches, including unordered float paths. */
typedef unsigned char View;
extern float DAT_00dd1c90;
__declspec(noinline) float __fastcall FUN_009902a0(const View *object) {
    const View *state=*(const View *const *)(object+0x5e0),*nested;
    if (*(const int *)(state+0x40)==0x1f && *(const int *)(state+0x14)==1 &&
        (nested=*(const View *const *)(object+0x10cc))!=0 &&
        (nested=*(const View *const *)(nested+0xc4))!=0 &&
        (nested=*(const View *const *)(nested+8))!=0 && *(const int *)(nested+0x34)==4) return 1.0f;
    return DAT_00dd1c90;
}
