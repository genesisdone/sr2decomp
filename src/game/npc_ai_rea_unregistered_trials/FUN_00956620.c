/* Complete C trial from REA instruction evidence and entry-pointer proof.
 * Original source ABI and field purposes remain unestablished.
 * Byte certificate: tools/build_npc_ai_rea_unregistered.py; never executed.
 */
__declspec(noinline) unsigned int __fastcall FUN_00956620(unsigned char *object) {
    unsigned int count = 0;
    if (object[0x5c] == 0) count = 1;
    if (object[0x8c] == 0) count = count + 1;
    if (object[0xbc] == 0) count = count + 1;
    if (object[0xec] == 0) count = count + 1;
    if (object[0x11c] == 0) count = count + 1;
    if (object[0x14c] == 0) count = count + 1;
    if (object[0x17c] == 0) count = count + 1;
    if (object[0x1ac] == 0) count = count + 1;
    return count;
}
