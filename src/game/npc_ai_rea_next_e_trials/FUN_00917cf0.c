/* FUN_00917cf0: loads action_node_notoriety.xtbl (FUN_00b743f0 with the default loader) and, for each
   Action_Node_Notoriety child while the one-entry table DAT_02acda24 (count DAT_025295b4) has room, fills a 0x18-byte
   record: the Name value copied into the string pool DAT_02ae4380 (FUN_00c06d60) and its hash (FUN_00bdcb30, seed 0);
   Min_Notoriety and Max_Notoriety (FUN_00b747d0); the Air_Only and Gang flags of the Spawn_Flags child (FUN_00b75050)
   into bits 0 and 1 of +8; and the Weapon value's weapon (FUN_0091d380). Then releases the parse through the loader
   DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134) and clears the handle to -1; the release method is a
   thiscall with one stack word, written as __fastcall with the EDX word native holds there (the handle).
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0); the table lookup is the
   found-variable shape find_first; the value lookups call FUN_00bfbee0 out of line, as native does here. */
typedef struct node_00917cf0 {
	const char *name;
	struct node_00917cf0 *next;
	struct node_00917cf0 *children;
	const char *value;
} node_t;
typedef struct record_00917cf0 {
	const char *name;
	unsigned int hash;
	unsigned char air_only : 1;
	unsigned char gang : 1;
	int min_notoriety;
	int max_notoriety;
	int weapon;
} record_t;
struct pool_00917cf0;
struct loader_00917cf0;
typedef void (__fastcall *loader_release)(struct loader_00917cf0 *loader, int unused, int handle);
struct loader_00917cf0 {
	loader_release *vtable;
};
extern const char s_action_node_notoriety_xtbl_00e38708[];
extern const char s_Action_Node_Notoriety_00e38724[];
extern const char s_Name_00dc5804[];
extern const char s_Min_Notoriety_00e3873c[];
extern const char s_Max_Notoriety_00df7614[];
extern const char s_Spawn_Flags_00e3874c[];
extern const char s_Air_Only_00e38758[];
extern const char s_Gang_00ddac18[];
extern const char s_Weapon_00de3b74[];
extern struct loader_00917cf0 *DAT_00e87138;
extern int DAT_00e87134;
extern int DAT_025295b4;
extern record_t DAT_02acda24[];
extern struct pool_00917cf0 DAT_02ae4380;
void *FUN_00b743f0(const char *name, struct loader_00917cf0 *loader);
int FUN_00c99030(const char *first, const char *second);
node_t *FUN_00bfbee0(node_t *root, const char *name);
const char *__stdcall FUN_00c06d60(struct pool_00917cf0 *pool, const char *text);
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
void FUN_00b747d0(int *output, const char *tag, node_t *node);
void FUN_00b75050(const char *tag, unsigned char *output, node_t *node);
int FUN_0091d380(const char *name);

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
	node = FUN_00bfbee0(node, name);
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

static __forceinline node_t *find_first(node_t *parent, const char *name)
{
	node_t *child;
	node_t *found;
	if (parent != 0) {
		for (child = parent->children; child != 0; child = child->next) {
			if (FUN_00c99030(child->name, name) == 0) {
				found = child;
				goto done;
			}
		}
	}
	found = 0;
done:
	return found;
}

__declspec(noinline) void FUN_00917cf0(void)
{
	node_t *root;
	node_t *table;
	node_t *current;
	node_t *flags;
	record_t *record;
	unsigned int hash;
	unsigned char flag;
	loader_release release;
	root = (node_t *)FUN_00b743f0(s_action_node_notoriety_xtbl_00e38708, 0);
	table = find_first(root, s_Action_Node_Notoriety_00e38724);
	for (current = table; current != 0; current = table) {
		if (DAT_025295b4 < 1) {
			record = &DAT_02acda24[DAT_025295b4];
			DAT_025295b4 = DAT_025295b4 + 1;
			record->name = FUN_00c06d60(&DAT_02ae4380, child_value(current, s_Name_00dc5804));
			record->hash = *FUN_00bdcb30(record->name, 0, &hash);
			FUN_00b747d0(&record->min_notoriety, s_Min_Notoriety_00e3873c, current);
			FUN_00b747d0(&record->max_notoriety, s_Max_Notoriety_00df7614, current);
			flags = first_child(current, s_Spawn_Flags_00e3874c);
			FUN_00b75050(s_Air_Only_00e38758, &flag, flags);
			record->air_only = flag;
			FUN_00b75050(s_Gang_00ddac18, &flag, flags);
			record->gang = flag;
			record->weapon = FUN_0091d380(child_value(current, s_Weapon_00de3b74));
		}
		table = next_sibling(root, current, s_Action_Node_Notoriety_00e38724);
	}
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
