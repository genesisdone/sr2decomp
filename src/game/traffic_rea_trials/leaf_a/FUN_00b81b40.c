__declspec(noinline) void __fastcall FUN_00b81b40(unsigned char *object)
{
    if (*(unsigned char *)(object + 0x20) != 0 && *(int *)(object + 0x14) != 0) {
        *(int *)(object + 0x14) = 0;
        *(unsigned char *)(object + 0x21) = 0;
    }
}
