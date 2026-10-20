/* Complete listed C caller trial. Registers and slot offsets are observed.
 * Runtime target and original source ABI remain unestablished; never executed.
 */
extern unsigned char DAT_02771278[];
typedef void (__fastcall *Slot1c)(unsigned char *receiver, void *edx_value);
__declspec(noinline) void __fastcall FUN_00b65dd0(unsigned char *receiver) {
    Slot1c method;
    if (receiver[0x22] == 0) return;
    if (*(unsigned char **)(receiver + 0x1c) == 0) *(unsigned char **)(receiver + 0x1c) = DAT_02771278;
    method = *(Slot1c *)(*(unsigned char **)receiver + 0x1c);
    method(receiver, (void *)method);
}
