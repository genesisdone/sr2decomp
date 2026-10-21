/* Complete C trial from REA instruction evidence and entry-pointer proof.
 * Original source ABI and field purposes remain unestablished.
 * Moved from gate npc-ai-rea-unregistered to batch E. Native takes the object in ECX and pops three stack words
 * (ret 0xc); written as fastcall with an unused EDX word, the usual C spelling of that interface. Never executed.
 */
__declspec(noinline) unsigned int __fastcall FUN_00923f50(unsigned char *object, unsigned int unused_edx, unsigned char *stack_object, int index, int unused_stack) {
    if (object[0x2a9] != 0) {
        if (index == 0) return *(unsigned int *)(stack_object + 8);
    } else if (index == 0 || (index > 1 && index <= 5)) {
        return *(unsigned int *)(stack_object + 8);
    }
    return 0;
}
