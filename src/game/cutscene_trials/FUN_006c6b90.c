/* Complete lifecycle state body 006c6b90..006c6bdf.
 * 006c6b99 clears instance +160c; the native no-argument call is at 006c6bc2.
 * Flag names remain addresses because their meanings are not established here.
 */
typedef struct CsCallbackInstanceView {
    unsigned char unknown_0000[0x160c];
    void *field_160c;
} CsCallbackInstanceView;
extern CsCallbackInstanceView *DAT_02527d10;
extern unsigned char DAT_02527d14, DAT_02527cf7, DAT_02527d15, DAT_02527d20;
extern void __cdecl FUN_006c44c0(void);
__declspec(noinline) void __cdecl FUN_006c6b90(void)
{
    CsCallbackInstanceView *instance = DAT_02527d10;
    if (instance)
        instance->field_160c = 0;
    if ((DAT_02527d14 && DAT_02527cf7) || DAT_02527d15) {
        if (instance)
            FUN_006c44c0();
        if (DAT_02527d15) {
            DAT_02527d20 = 1;
            DAT_02527d15 = 0;
        }
    }
}
