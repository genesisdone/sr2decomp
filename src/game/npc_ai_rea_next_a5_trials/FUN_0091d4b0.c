/* Complete canonical REA search caller. String comparison boundary is address-named. */
extern int __cdecl FUN_00c99030(const char *left,const char *right);
extern int DAT_0214442c;
extern unsigned char DAT_02aefef0[];
extern char DAT_023460e0[];
__declspec(noinline) int FUN_0091d4b0(void) {
    int index=0;
    unsigned char *record=DAT_02aefef0;
    if(DAT_0214442c>0) do {
        if(FUN_00c99030(*(char **)record,DAT_023460e0)==0) return index;
        ++index; record+=0x60;
    } while(index<DAT_0214442c);
    return -1;
}
