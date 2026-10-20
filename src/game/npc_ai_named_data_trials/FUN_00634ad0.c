/* EXE: FUN_00634ad0; complete private-input C trial with exact named data. */
typedef unsigned char View;
extern const View *DAT_00ea1004;
__declspec(noinline) unsigned char __cdecl FUN_00634ad0(const View *object) {
    if (object==0) return 0;
    return object==DAT_00ea1004;
}
