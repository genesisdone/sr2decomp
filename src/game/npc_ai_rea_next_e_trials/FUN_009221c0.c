/* FUN_009221c0: in a parsed document tree (node: name +0, next sibling +4, first child +8, value +0xc), finds the
   first "Table" child of root (DAT_00e249b8) whose "Name" child (DAT_00dc5804) has a value equal to wanted, comparing
   with FUN_00c99030 (a missing Name compares as a null value); 0 when there is none.
   The three node helpers are the shapes the original's inlined lookups have: the child search ends in one
   `child = 0` that the exhausted and the NULL-parent paths share (written with a goto), and the sibling search is a
   do-while on the compare. The table is walked through a copy (`current`), so the root test inside the inlined
   sibling search stays. Both parameters are read once at entry (declared volatile only to fix that load point;
   hypothesis, unconfirmed, that the original declared them so). */
typedef struct node_9221c0 {
	const char *name;
	struct node_9221c0 *next;
	struct node_9221c0 *children;
	const char *value;
} node_t;
extern const char DAT_00e249b8[];
extern const char DAT_00dc5804[];
int FUN_00c99030(const char *first, const char *second);

static __forceinline node_t *first_child(node_t *parent, const char *name)
{
	node_t *child;
	if (parent != 0) {
		for (child = parent->children; child != 0; child = child->next) {
			if (FUN_00c99030(child->name, name) == 0) {
				goto found;
			}
		}
	}
	child = 0;
found:
	return child;
}

static __forceinline const char *child_value(node_t *node, const char *name)
{
	if (node == 0) {
		return 0;
	}
	node = first_child(node, name);
	if (node == 0) {
		return 0;
	}
	return node->value;
}

static __forceinline node_t *next_sibling(node_t *parent, node_t *from, const char *name)
{
	node_t *child = from;
	if (parent == 0 || from == 0) {
		goto none;
	}
	do {
		child = child->next;
		if (child == 0) {
			goto none;
		}
	} while (FUN_00c99030(child->name, name) != 0);
	return child;
none:
	return 0;
}

__declspec(noinline) node_t *FUN_009221c0(node_t *volatile root_word, const char *volatile wanted_word)
{
	node_t *root = root_word;
	const char *wanted = wanted_word;
	node_t *table = first_child(root, DAT_00e249b8);
	node_t *current;
	for (current = table; current != 0; current = table) {
		if (FUN_00c99030(child_value(current, DAT_00dc5804), wanted) == 0) {
			return current;
		}
		table = next_sibling(root, current, DAT_00e249b8);
	}
	return current;
}
