/* FUN_00b7b660: clears the distant pedestrian count DAT_022dbc08, loads distant_peds.xtbl (FUN_00b743f0 with the
   default loader) and, for each Distant_Pedestrian child while fewer than three are loaded, fills the next
   0xf3c-byte record of DAT_0319bfc8: the Name value copied into its first 0x19 bytes (FUN_00c990f0, last byte
   cleared), and the Mesh child's Filename value with the .cmesh_pc suffix written into the 0x41 bytes after it
   (FUN_00bff930). Then releases the parse through the loader DAT_00e87138 (vtable slot +0x34 with the handle
   DAT_00e87134) and clears the handle to -1; the release method is a thiscall with one stack word, written as
   __fastcall whose EDX word is the method pointer itself, which is what native holds in EDX there.
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0). */
typedef struct node_00b7b660 {
	const char *name;
	struct node_00b7b660 *next;
	struct node_00b7b660 *children;
	const char *value;
} node_t;
typedef struct record_00b7b660 {
	char name[0x19];
	char mesh[0x41];
	unsigned char rest[0xf3c - 0x5a];
} record_t;
struct loader_00b7b660;
typedef void (__fastcall *loader_release)(struct loader_00b7b660 *loader, int unused, int handle);
struct loader_00b7b660 {
	loader_release *vtable;
};
extern const char s_distant_peds_xtbl_00e4afcc[];
extern const char s_Distant_Pedestrian_00e4afe0[];
extern const char s_Name_00dc5804[];
extern const char s_Mesh_00e20ce4[];
extern const char s_Filename_00dd86c8[];
extern const char s__cmesh_pc_00dda728[];
extern struct loader_00b7b660 *DAT_00e87138;
extern int DAT_00e87134;
extern int DAT_022dbc08;
extern record_t DAT_0319bfc8[];
void *FUN_00b743f0(const char *name, struct loader_00b7b660 *loader);
int FUN_00c99030(const char *first, const char *second);
char *__cdecl FUN_00c990f0(char *destination, const char *source, unsigned int count);
unsigned char FUN_00bff930(const char *base, char *destination, unsigned int capacity, const char *suffix);

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

__declspec(noinline) void FUN_00b7b660(void)
{
	node_t *root;
	node_t *current;
	node_t *table;
	node_t *child;
	record_t *record;
	loader_release release;
	DAT_022dbc08 = 0;
	root = (node_t *)FUN_00b743f0(s_distant_peds_xtbl_00e4afcc, 0);
	table = first_child(root, s_Distant_Pedestrian_00e4afe0);
	for (current = table; current != 0 && DAT_022dbc08 != 3; current = table) {
		record = &DAT_0319bfc8[DAT_022dbc08];
		child = first_child(current, s_Name_00dc5804);
		if (child != 0 && child->value != 0) {
			FUN_00c990f0(record->name, child->value, 0x19);
			record->name[0x18] = 0;
		}
		child = first_child(current, s_Mesh_00e20ce4);
		FUN_00bff930(child_value(child, s_Filename_00dd86c8), record->mesh, 0x41, s__cmesh_pc_00dda728);
		DAT_022dbc08 = DAT_022dbc08 + 1;
		table = next_sibling(root, current, s_Distant_Pedestrian_00e4afe0);
	}
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
