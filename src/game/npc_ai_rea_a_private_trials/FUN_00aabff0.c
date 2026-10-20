/* REA complete translation; logical C interface, original ABI unclaimed until byte gate. ev_4b4b88d927b9ed2211d4e1f7a8e3167c72f8d58f3975ab99437d1535de33a374 */
typedef unsigned char View;
__declspec(noinline) unsigned int FUN_00aabff0(const View *input) {
    unsigned int value = *(const unsigned int *)(input + 0x8f50);
    if ((value & 0x10) != 0 && ((value & 0x40) != 0 || (value & 0x100) != 0)) return 1;
    return 0;
}
