/* Full listed caller trial. ECX receiver and pushed zero are native observations.
 * Runtime virtual target and original source-level declaration remain unknown.
 */
typedef void (__fastcall *Slot4)(void *receiver, void *edx_value, unsigned int value);
__declspec(noinline) void __fastcall FUN_00a642f0(void *receiver) {
    Slot4 method = *(Slot4 *)(*(unsigned char **)receiver + 4);
    method(receiver, (void *)method, 0);
}
