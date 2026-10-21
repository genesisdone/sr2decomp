/* FUN_00927020: adds (first, second, key) to the 500-entry pair table at DAT_0215ac00 (count DAT_02159c58) and
   indexes it in the 1000-slot open-addressing hash DAT_02159c60 (empty slots are -1; linear probing from
   key % 1000). Returns 0 when the table is full, else 1. Moved from gate npc-ai-rea-next-leaf (deferred there). */
typedef unsigned int U32;
struct pair_entry {
	U32 first;
	U32 second;
	U32 key;
};
extern U32 DAT_02159c58;
extern U32 DAT_02159c60[1000];
extern struct pair_entry DAT_0215ac00[500];

__declspec(noinline) unsigned char FUN_00927020(U32 first, U32 second, U32 key)
{
	U32 count = DAT_02159c58;
	U32 slot;
	struct pair_entry *entry;
	if (count == 500) {
		return 0;
	}
	slot = key % 1000;
	while (DAT_02159c60[slot] != 0xffffffffU) {
		slot = (slot + 1) % 1000;
	}
	entry = &DAT_0215ac00[count];
	entry->first = first;
	entry->second = second;
	DAT_02159c60[slot] = count;
	entry->key = key;
	DAT_02159c58 = count + 1;
	return 1;
}
