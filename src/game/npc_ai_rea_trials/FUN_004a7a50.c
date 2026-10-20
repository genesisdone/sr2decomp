/* Complete C translation from REA ev_5b937133aaf3d06ccaca16ad9d7b6476925ea2840e6f37b61780870d46f13fc1.
 * Source-level names/types beyond literal accesses remain unestablished.
 * Byte status is recorded by tools/build_npc_ai_rea.py.
 */
extern unsigned int DAT_02526c70;
extern unsigned char *DAT_02526c74;
__declspec(noinline) void __cdecl FUN_004a7a50(void) {
    unsigned int remaining = DAT_02526c70;
    unsigned char *record;
    if (remaining > 0) {
        record = DAT_02526c74 + 0x48;
        do {
            *(float *)record = 0.0f;
            *(unsigned int *)(record - 4) = 0;
            *(float *)(record + 4) = 0.0f;
            record = record + 0x5c;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
}
