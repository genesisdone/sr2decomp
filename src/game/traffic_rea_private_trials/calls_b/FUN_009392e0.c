/* FUN_009392e0: calls FUN_00929540 with selector 0 and then 1 (in EAX), the caller's input and the
   constant 1 (stack); returns whether the second call returned non-zero, as a byte. */
unsigned char FUN_00929540(int selector, int input, int one);
__declspec(noinline) unsigned char FUN_009392e0(int input)
{
    if (FUN_00929540(0, input, 1) == 0) {
        return 0;
    }
    if (FUN_00929540(1, input, 1) != 0) {
        return 1;
    }
    return 0;
}
