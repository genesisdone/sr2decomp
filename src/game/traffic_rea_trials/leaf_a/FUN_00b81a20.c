__declspec(noinline) int __fastcall FUN_00b81a20(unsigned char *object)
{
    int value;
    if (*(unsigned char *)(object + 0x22) == 0) return 0;
    value = *(int *)(object + 0x18);
    return value * 60;
}
