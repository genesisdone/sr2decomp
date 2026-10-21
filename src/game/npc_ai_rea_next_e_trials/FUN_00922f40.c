/* FUN_00922f40: weighted random pick from a table of 16-byte entries (weight float at +0; table: entries +0xc,
   count +0x10). One entry is returned directly. Otherwise it accumulates the running weight sums (rounded to float
   each step), draws the next word of the DAT_00ec3ac0 random ring (index DAT_00ec3abc, 0x800 words) as an unsigned
   value times DAT_00e5c030, scales the total by it and returns the first entry whose running sum reaches that
   threshold, or the last entry. */
struct choice_922f40 {
	float weight;
	int pad[3];
};
struct table_922f40 {
	int pad[3];
	struct choice_922f40 *entries;
	int count;
};
extern int DAT_00ec3abc;
extern unsigned int DAT_00ec3ac0[];
extern double DAT_00e5c030;

__declspec(noinline) struct choice_922f40 *FUN_00922f40(struct table_922f40 *table)
{
	float sums[20];
	float sum;
	float unit;
	float threshold;
	unsigned int word;
	struct choice_922f40 *entry;
	int i;
	if (table->count == 1) {
		return table->entries;
	}
	sum = 0.0f;
	entry = table->entries;
	for (i = 0; i < table->count; i++) {
		sum = sum + entry->weight;
		sums[i] = sum;
		entry++;
	}
	word = DAT_00ec3ac0[DAT_00ec3abc];
	DAT_00ec3abc = DAT_00ec3abc + 1;
	if (DAT_00ec3abc == 0x800) {
		DAT_00ec3abc = 0;
	}
	unit = (float)((float)word * DAT_00e5c030);
	threshold = sum * unit;
	for (i = 0; i < table->count; i++) {
		if (sums[i] >= threshold) {
			return &table->entries[i];
		}
	}
	return &table->entries[table->count - 1];
}
