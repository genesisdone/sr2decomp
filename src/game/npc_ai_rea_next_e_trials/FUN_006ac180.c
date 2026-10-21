/* FUN_006ac180: loads persona.xtbl (FUN_00b743f0 with the default loader) and, for each Persona child, looks its
   Name value up in the persona table (FUN_006add50). For a known persona: with a Radio_Station value, sets bit 0 of
   the record's +0x15 byte and stores the station name's hash (FUN_00bdcb30, seed 0) at +4; without one, clears the
   bit. Then releases the parse through the loader DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134)
   and clears the handle to -1; the release method is a thiscall with one stack word, written as __fastcall with the
   EDX word native holds there (the handle).
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0). */
typedef struct node_006ac180 {
	const char *name;
	struct node_006ac180 *next;
	struct node_006ac180 *children;
	const char *value;
} node_t;
struct loader_006ac180;
typedef void (__fastcall *loader_release)(struct loader_006ac180 *loader, int unused, int handle);
struct loader_006ac180 {
	loader_release *vtable;
};
extern const char s_persona_xtbl_00e06bd8[];
extern const char s_Persona_00dec000[];
extern const char s_Name_00dc5804[];
extern const char s_Radio_Station_00e06be8[];
extern struct loader_006ac180 *DAT_00e87138;
extern int DAT_00e87134;
void *FUN_00b743f0(const char *name, struct loader_006ac180 *loader);
int FUN_00c99030(const char *first, const char *second);
unsigned char *FUN_006add50(const char *name);
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);

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

__declspec(noinline) void FUN_006ac180(void)
{
	node_t *root;
	node_t *persona;
	node_t *current;
	unsigned char *record;
	const char *station;
	unsigned int hash;
	root = (node_t *)FUN_00b743f0(s_persona_xtbl_00e06bd8, 0);
	persona = first_child(root, s_Persona_00dec000);
	for (current = persona; current != 0; current = persona) {
		record = FUN_006add50(child_value(current, s_Name_00dc5804));
		if (record != 0) {
			station = child_value(current, s_Radio_Station_00e06be8);
			if (station != 0) {
				record[0x15] |= 1;
				*(unsigned int *)(record + 4) = *FUN_00bdcb30(station, 0, &hash);
			} else {
				record[0x15] &= 0xfe;
			}
		}
		persona = next_sibling(root, current, s_Persona_00dec000);
	}
	DAT_00e87138->vtable[0x34 / 4](DAT_00e87138, DAT_00e87134, DAT_00e87134);
	DAT_00e87134 = -1;
}
