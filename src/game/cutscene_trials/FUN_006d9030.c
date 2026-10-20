/* Complete timeline adjustment: 006d9030..006d9063. */
extern float DAT_027e6714, DAT_027e6710, DAT_027e66fc;
__declspec(noinline) void __cdecl FUN_006d9030(void)
{
    float difference = DAT_027e6714-DAT_027e6710;
    DAT_027e6710 = difference+DAT_027e6710;
    DAT_027e66fc = difference+DAT_027e66fc;
}
