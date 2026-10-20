/* FUN_008865c0: resolves the handle through the 16-byte-stride table DAT_02149c64 (slot = id & 0xfff,
   the entry must echo the id at +0x44 and have kind 5 at +0x4c); when flag is set calls
   FUN_00aabcc0(entry, 1000, 1, 0), otherwise FUN_00806b90(entry, 0, FUN_008865c0) with itself as the
   callback. Both inputs are caller-cleaned stack words. */
extern unsigned char *DAT_02149c64[];
void FUN_00aabcc0(unsigned char *entry, int duration, int enabled, int final_flag);
void FUN_00806b90(unsigned char *entry, int mode, void (*callback)(unsigned int, unsigned char));
__declspec(noinline) void FUN_008865c0(unsigned int id, unsigned char flag)
{
    unsigned int *keep_id = &id;
    unsigned char *keep_flag = &flag;
    unsigned char *entry;
    (void)keep_id;
    (void)keep_flag;
    if (id == 0) {
        return;
    }
    entry = DAT_02149c64[(id & 0xfff) * 4];
    if (entry == 0) {
        return;
    }
    if (*(unsigned int *)(entry + 0x44) != id) {
        return;
    }
    if (*(int *)(entry + 0x4c) != 5) {
        return;
    }
    if (flag != 0) {
        FUN_00aabcc0(entry, 1000, 1, 0);
        return;
    }
    FUN_00806b90(entry, 0, FUN_008865c0);
}
