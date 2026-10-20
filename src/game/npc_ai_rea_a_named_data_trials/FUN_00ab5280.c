/* REA complete translation; logical C interface, original ABI unclaimed until byte gate. ev_13848af8b06a86bcb920c2690381d107956a20e2b4e85be6e417988175342fb4 */
typedef int View;
extern int DAT_0252a0d8;
extern int DAT_02fad294[];
__declspec(noinline) unsigned char FUN_00ab5280(int input) {
    if (input >= 0 && input < DAT_0252a0d8) return DAT_02fad294[input * 500] == 3;
    return 0;
}
