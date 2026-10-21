/* FUN_00922e30 (moved from gate npc-ai-rea-next-named-data): weighted random pick among the object's +0x1c
   0x20-byte choices at +0x18 (weight = first float): returns the only choice when there is one, else draws from
   the 0x800-entry random table (DAT_00ec3ac0, cursor DAT_00ec3abc), scales the running total by word / 2^32
   (DAT_00e5c030) and returns the first choice whose cumulative weight reaches it, else the last. */
struct choice {
	float weight;
	unsigned char rest[0x1c];
};
struct choices {
	unsigned char pad[0x18];
	struct choice *list;
	int count;
};
extern int DAT_00ec3abc;
extern unsigned int DAT_00ec3ac0[];
extern double DAT_00e5c030;
static __forceinline unsigned int random_word(void)
{
	unsigned int word = DAT_00ec3ac0[DAT_00ec3abc];
	DAT_00ec3abc++;
	if (DAT_00ec3abc == 0x800) {
		DAT_00ec3abc = 0;
	}
	return word;
}

__declspec(noinline) struct choice *FUN_00922e30(struct choices *object)
{
	float cumulative[20];
	float total;
	float unit;
	float threshold;
	struct choice *entry;
	int i;
	if (object->count == 1) {
		return object->list;
	}
	total = 0.0f;
	entry = object->list;
	for (i = 0; i < object->count; i++) {
		total += entry->weight;
		cumulative[i] = total;
		entry++;
	}
	unit = (float)((float)random_word() * DAT_00e5c030);
	threshold = total * unit;
	for (i = 0; i < object->count; i++) {
		if (cumulative[i] >= threshold) {
			return &object->list[i];
		}
	}
	return &object->list[object->count - 1];
}
