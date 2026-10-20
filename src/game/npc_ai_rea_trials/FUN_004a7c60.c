/* Complete C translation from REA ev_f31db58e8f855585eda2d4968185bd8f27aa6d854b069c01baf535fa1cabd458.
 * Source-level names/types beyond literal accesses remain unestablished.
 * Byte status is recorded by tools/build_npc_ai_rea.py.
 */
extern unsigned int DAT_02526c70;
extern unsigned char *DAT_02526c74;
__declspec(noinline) void __cdecl FUN_004a7c60(void) {
    unsigned int remaining = DAT_02526c70;
    unsigned char *record;
    if (remaining > 0) {
        record = DAT_02526c74 + 0x54;
        do {
            *(float *)record = 0.0f;
            *(unsigned int *)(record - 4) = 0;
            *(float *)(record + 4) = 0.0f;
            record = record + 0x5c;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
}
