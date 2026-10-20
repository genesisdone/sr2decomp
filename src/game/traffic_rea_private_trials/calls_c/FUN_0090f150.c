/* FUN_0090f150: when the byte flag DAT_02529585 is set, takes entries from FUN_0090f0c0(0) and hands
   each to FUN_0090e7b0 until it returns 0; otherwise takes one entry from FUN_0090f0c0(10) and hands
   it on if non-zero. */
extern unsigned char DAT_02529585;
int FUN_0090f0c0(int amount);
void FUN_0090e7b0(int item);
__declspec(noinline) void FUN_0090f150(void)
{
    int item;
    if (DAT_02529585 != 0) {
        item = FUN_0090f0c0(0);
        while (item != 0) {
            FUN_0090e7b0(item);
            item = FUN_0090f0c0(0);
        }
        return;
    }
    item = FUN_0090f0c0(10);
    if (item != 0) {
        FUN_0090e7b0(item);
    }
}
