/* FUN_00bfbf40: walks the node list of the record (first node at +8, next at +4, name pointer at +0) and returns the
   node whose name is "LaneSpeed" (s_LaneSpeed_00e447a8, compared with FUN_00c99030) after skipping `skip` earlier
   matches, or NULL. Native takes the record in EAX and the skip count in ECX. */
struct node_00bfbf40 {
	const char *name;
	struct node_00bfbf40 *next;
};
struct record_00bfbf40 {
	int pad0;
	int pad4;
	struct node_00bfbf40 *first;
};
extern const char s_LaneSpeed_00e447a8[];
int FUN_00c99030(const char *first, const char *second);

__declspec(noinline) struct node_00bfbf40 *FUN_00bfbf40(struct record_00bfbf40 *record, int skip)
{
	struct node_00bfbf40 *node;
	if (record == 0) {
		return 0;
	}
	for (node = record->first; node != 0; node = node->next) {
		if (FUN_00c99030(node->name, s_LaneSpeed_00e447a8) == 0) {
			if (skip-- == 0) {
				return node;
			}
		}
	}
	return 0;
}
