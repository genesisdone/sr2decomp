/* EXE: FUN_009cce00; complete10-byte constructor callback.
 * Native ECX input, EAX retained result, plain RET; full refreshed Ghidra span. */
__declspec(noinline) unsigned char *__fastcall FUN_009cce00(unsigned char *object) {
    *(int *)(object+4)=-1;
    return object;
}
