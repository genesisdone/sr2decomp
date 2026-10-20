/* Complete REA ev_5c43543efbd5791b7eb4c2c7b64a1d85cac2e978c345d85bf655e857d0e571ac.
 * Literal data identities; no original semantic names established. */
extern unsigned char DAT_00e447b4[], DAT_00ec5cc8[], DAT_00ec5d38[];
extern int DAT_00e8314c, DAT_00e87b3c, DAT_00e87b44, DAT_00e87b40;
extern unsigned short __stdcall FUN_00c07160(void *table, const char *name);
__declspec(noinline) void FUN_00a8d640(void) {
    unsigned short value;
    int selected;
    value = FUN_00c07160(DAT_00ec5cc8, (const char *)DAT_00e447b4);
    if (value == 0xffff) value = FUN_00c07160(DAT_00ec5d38, (const char *)DAT_00e447b4);
    selected = (short)value;
    if (selected == -1) selected = DAT_00e8314c;
    DAT_00e87b3c = selected;
    value = FUN_00c07160(DAT_00ec5cc8, (const char *)DAT_00e447b4);
    if (value == 0xffff) value = FUN_00c07160(DAT_00ec5d38, (const char *)DAT_00e447b4);
    selected = (short)value;
    if (selected == -1) selected = DAT_00e8314c;
    DAT_00e87b44 = selected;
    value = FUN_00c07160(DAT_00ec5cc8, (const char *)DAT_00e447b4);
    if (value == 0xffff) value = FUN_00c07160(DAT_00ec5d38, (const char *)DAT_00e447b4);
    selected = (short)value;
    if (selected == -1) selected = DAT_00e8314c;
    DAT_00e87b40 = selected;
}
