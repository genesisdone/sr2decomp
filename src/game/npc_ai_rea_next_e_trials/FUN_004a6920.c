/* FUN_004a6920: for each of the children "melee_weapon_chances", "firearm_weapon_chances" and
   "thrown_weapon_chances" of node (the list at +8 of {name, next}, matched with _stricmp FUN_00c99030; the lookup is the shape of the
   original's inlined one, see FUN_009221c0), hands
   the first match to FUN_004a6790(owner, table, kind 0/1/2, child). */
struct child {
	char *name;
	struct child *next;
	struct child *children;
	const char *value;
};
extern char s_melee_weapon_chances_00ddacd4[];
extern char s_firearm_weapon_chances_00ddacec[];
extern char s_thrown_weapon_chances_00ddad04[];
int FUN_00c99030(const char *a, const char *b);
void FUN_004a6790(int owner, int table, int kind, struct child *item);

/* The two stack words (owner, table) as one struct by value, so that LTCG keeps them on the stack as natively. */
struct words_004a6920 {
	int owner;
	int table;
};

static __forceinline struct child *first_child(struct child *parent, const char *name)
{
	struct child *item;
	if (parent != 0) {
		for (item = parent->children; item != 0; item = item->next) {
			if (FUN_00c99030(item->name, name) == 0) {
				goto found;
			}
		}
	}
	item = 0;
found:
	return item;
}

__declspec(noinline) void FUN_004a6920(struct child *node, struct words_004a6920 words)
{
	int owner = words.owner;
	int table = words.table;
	struct child *item;
	item = first_child(node, s_melee_weapon_chances_00ddacd4);
	if (item != 0) {
		FUN_004a6790(owner, table, 0, item);
	}
	item = first_child(node, s_firearm_weapon_chances_00ddacec);
	if (item != 0) {
		FUN_004a6790(owner, table, 1, item);
	}
	item = first_child(node, s_thrown_weapon_chances_00ddad04);
	if (item != 0) {
		FUN_004a6790(owner, table, 2, item);
	}
}
