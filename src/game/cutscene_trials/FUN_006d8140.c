/* Whole 006d8140..006d8153: float payload -> compiler integer conversion,
 * ECX argument -> exact tail JMP 0068A5C0 at 006D814E. The callee's time
 * adjustment logic is not part of this 19-byte body.
 */
typedef struct CsTimeCommandOption { unsigned int unknown_00[2]; float value; } CsTimeCommandOption;
extern void __fastcall FUN_0068a5c0(int time);
__declspec(noinline) void __cdecl FUN_006d8140(const CsTimeCommandOption *option)
{
    FUN_0068a5c0((int)option->value);
}
