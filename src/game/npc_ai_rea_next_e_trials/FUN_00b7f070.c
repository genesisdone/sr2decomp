/* Complete C trial from REA instructions and exact incoming PUSH operand. Moved from gate npc-ai-rea-callbacks; the
   two "return 1" conditions are one OR, as native tests them. */
__declspec(noinline) int __cdecl FUN_00b7f070(signed char *first, signed char *second) {
    int left = *first;
    int right = *second;
    if (left == right) return 0;
    if (left == -1 || (right >= 0 && right < left)) return 1;
    return -1;
}
