/* REA ev_cefc541539fafb6a65a14d9c705b490859129ec4fd04a5ca9c6678a1cae8cb54; logical C interface, not a callable native ABI declaration. */
extern unsigned char DAT_021c5840[];
__declspec(noinline) void FUN_009e53b0(unsigned int group, int slot)
{
    if (group <= 11) {
        unsigned char *base = DAT_021c5840 + group * 0x424;
        unsigned int *entry = (unsigned int *)(base + slot * 12);
        if (entry[0] == 2) --*(unsigned int *)(base + 0x420);
        entry[0] = 0; entry[1] = 0; entry[2] = 0;
    }
}
