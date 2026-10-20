__declspec(noinline) int __fastcall FUN_00b819e0(unsigned char *object)
{
    int value;
    if (*(unsigned char *)(object + 0x20) == 0 || *(unsigned char *)(object + 0x21) == 0) return 0;
    value = *(int *)(object + 0x18);
    return value * 60;
}
