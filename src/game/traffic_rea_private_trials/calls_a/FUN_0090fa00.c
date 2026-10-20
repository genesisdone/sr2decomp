/* FUN_0090fa00: object in ECX. Returns 0 when byte +0x94 of the record at object+0x34 has bit 0x40
   or bit 2 set, when byte +0x48 of the record at object+0x30 has bit 0x80 set, or when the int at
   object+0x58 is negative; otherwise returns whether FUN_00bdd230(&object+0x58) is non-zero. */
unsigned char FUN_00bdd230(int *value);
__declspec(noinline) unsigned char __fastcall FUN_0090fa00(int object)
{
    unsigned char *record = *(unsigned char **)(object + 0x34);
    if ((record[0x94] & 0x40) != 0) {
        return 0;
    }
    if ((record[0x94] & 2) != 0) {
        return 0;
    }
    record = *(unsigned char **)(object + 0x30);
    if ((record[0x48] & 0x80) != 0) {
        return 0;
    }
    if (*(int *)(object + 0x58) < 0) {
        return 0;
    }
    if (FUN_00bdd230((int *)(object + 0x58)) != 0) {
        return 1;
    }
    return 0;
}
