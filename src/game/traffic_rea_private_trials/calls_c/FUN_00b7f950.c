/* FUN_00b7f950: for each of the count (third argument) entries of the item array (second
   argument), calls FUN_00b7e8d0 on the entry. The first argument is not read. */
void FUN_00b7e8d0(const unsigned char *item);
__declspec(noinline) void FUN_00b7f950(unsigned int unused, const unsigned char **items, int count)
{
    int i;
    const unsigned char **keep = &items;
    int *keep_count = &count;
    unsigned int *keep_unused = &unused;
    (void)keep;
    (void)keep_count;
    (void)keep_unused;
    for (i = 0; i < count; i = i + 1) {
        FUN_00b7e8d0(items[i]);
    }
}
