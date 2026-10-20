/* FUN_0090f1a0: scans the count (records +0x78) 24-byte entries starting at records +0x18 and returns
   the index of the first whose id is not -1 and that FUN_006eed80 finds in the object's table at
   +0x5e0; -1 when none does. */
int FUN_006eed80(unsigned char *table, int id);
__declspec(noinline) int FUN_0090f1a0(unsigned char *records, unsigned char *object)
{
    int count;
    int index;
    int *entry;
    unsigned char *table;
    count = *(int *)(records + 0x78);
    index = 0;
    if (count > 0) {
        table = *(unsigned char **)(object + 0x5e0);
        entry = (int *)(records + 0x18);
        do {
            if (*entry != -1 && FUN_006eed80(table, *entry) != -1) {
                return index;
            }
            index = index + 1;
            entry = entry + 6;
        } while (index < count);
    }
    return -1;
}
