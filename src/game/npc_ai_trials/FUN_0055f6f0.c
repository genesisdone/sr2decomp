/* EXE: FUN_0055f6f0; complete shared-system C trial.
 * All original reads, sentinels, wraps and writes retained; no semantic AI ownership claim. */
extern int DAT_0279aa60[],DAT_01409b50[];
extern float DAT_0279aa64[];
__declspec(noinline) float __fastcall FUN_0055f6f0(int index) {
    int whole=DAT_0279aa60[index*15];
    float result=(float)whole;
    if (whole<5) result=DAT_0279aa64[index*15]/(float)DAT_01409b50[whole]+result;
    return result;
}
