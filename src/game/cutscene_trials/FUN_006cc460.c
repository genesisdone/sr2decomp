/* Whole 006cc460..006cc4be. Native atof result is rounded to float before
 * scaling by double E5C0D8 and truncating through compiler helper 00DA0140.
 * 004D1090 consumes duration/byte/target in three caller-cleaned stack words.
 */
typedef struct CsFadeStringOption {
    unsigned int unknown_00[4];
    const char *text;
} CsFadeStringOption;
typedef struct CsFadeFlagsView {
    unsigned char unknown_000[0xb02];
    unsigned char flag_b02,flag_b03;
} CsFadeFlagsView;
extern CsFadeFlagsView *DAT_02527d10;
extern double DAT_00e5c0d8;
extern double __cdecl FUN_00c984f5(const char *text);
extern void __cdecl FUN_00d14840(int red, int green, int blue, int alpha);
extern int __cdecl FUN_004d1090(int duration, unsigned char flag, float target);
__declspec(noinline) void __cdecl FUN_006cc460(const CsFadeStringOption *option)
{
    if (option->text) {
        float duration = (float)FUN_00c984f5(option->text);
        FUN_00d14840(0,0,0,255);
        FUN_004d1090((int)(duration * DAT_00e5c0d8),0,1.0f);
        if (!DAT_02527d10->flag_b02)
            DAT_02527d10->flag_b03 = 1;
    }
}
