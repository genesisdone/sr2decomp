/* Complete C trial from REA instructions and exact incoming PUSH operand. */
__declspec(noinline) int __cdecl FUN_004363a0(unsigned char *first, unsigned char *second) {
    unsigned int second_value = *(unsigned int *)(second + 4);
    return (int)(second_value - *(unsigned int *)(first + 4));
}
