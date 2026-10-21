/* FUN_00956590: returns 1 when every object referenced by the record (the eight slots at +0x30 whose entry's +8
   record names an id at +0x68, and the id at *(+0x2c) when +0x2c is set) is present in the id hash at DAT_02f9b2e8
   (0xd4-byte buckets selected by the id's top byte, each a circular list from +0xc, nodes linked at +0x2c with their
   id at +4); otherwise 0. The bucket lookup is an inline helper used twice. Moved from gate npc-ai-rea-b. */
struct id_node {
	unsigned int unknown_00;
	unsigned int id;
	unsigned char unknown_08[0x24];
	struct id_node *next;
};
struct id_bucket {
	unsigned char unknown_00[0xc];
	struct id_node *first;
	unsigned char unknown_10[0xc4];
};
extern struct id_bucket DAT_02f9b2e8[];

static __forceinline struct id_node *id_lookup(unsigned int id)
{
	struct id_bucket *bucket = &DAT_02f9b2e8[id >> 24];
	struct id_node *first = bucket->first;
	struct id_node *node = first;
	if (node == 0) {
		return 0;
	}
	do {
		if (node->id == id) {
			return node;
		}
		node = node->next;
	} while (node != bucket->first && node != 0);
	return 0;
}

__declspec(noinline) unsigned char __fastcall FUN_00956590(unsigned char *base)
{
	int index;
	unsigned int *slot;
	index = 0;
	slot = (unsigned int *)(base + 0x30);
	for (; index < 8; index++, slot++) {
		if (*slot != 0 && id_lookup(*(unsigned int *)(*(unsigned int *)(*slot + 8) + 0x68)) == 0) {
			return 0;
		}
	}
	if (*(unsigned int **)(base + 0x2c) != 0 && id_lookup(**(unsigned int **)(base + 0x2c)) == 0) {
		return 0;
	}
	return 1;
}
