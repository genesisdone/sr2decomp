/* Complete C translation from REA ev_692b343bac5270bbac3921a6690c1173a5afb47a40bf834b416e72838633a638.
 * Source-level names/types beyond literal accesses remain unestablished.
 * Byte status is recorded by tools/build_npc_ai_rea.py.
 */
__declspec(noinline) unsigned char __fastcall FUN_004b1eb0(unsigned char *object) {
    int count = *(int *)(object + 0x7c);
    unsigned int index = 0;
    unsigned char **items;
    if (count > 0) {
        items = *(unsigned char ***)(object + 0x78);
        do {
            if (*(unsigned int *)(*items + 0x4c) == 0) return 1;
            index = index + 1;
            items = items + 1;
        } while ((int)index < count);
    }
    return 0;
}
