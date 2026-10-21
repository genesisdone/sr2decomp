/* Complete C trial from REA instruction evidence and entry-pointer proof.
 * Original source ABI and field purposes remain unestablished.
 * Moved from gate npc-ai-rea-unregistered to batch E; the walk pointer re-reads the list head instead of copying
 * `first`, which gives native's register order.
 */
__declspec(noinline) unsigned int __fastcall FUN_0098fef0(unsigned char *object) {
    unsigned char *first, *node;
    unsigned int count;
    if (object[0x20] != 0 && *(unsigned int *)(object + 0x14) == 0) return 0;
    first = *(unsigned char **)(object + 0xc);
    node = *(unsigned char **)(object + 0xc);
    count = 0;
    while (node != 0) {
        node = *(unsigned char **)(node + 0x8);
        count = count + 1;
        if (node == first) break;
    }
    return count;
}
