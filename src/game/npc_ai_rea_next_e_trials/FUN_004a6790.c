/* FUN_004a6790: reads one weapon-chance table entry from XML. The entry is the 0x44-byte record at
   table + 0x14 + (column + row * 3) * 0x44: byte 0 is read from the node's DAT_00ddac7c value (cleared again when
   the node has no "weapon_equip_chances" child), byte 1 counts the "weapon_chance_element" children of that child.
   Each element fills an 8-byte slot at +4: the index of its "weapon" child's named 0x498-byte weapon record
   (FUN_00b716e0, relative to DAT_022d7bcc) and a byte read from the element's DAT_00ddaccc value. The node helpers
   are the shapes the original's inlined lookups have (see FUN_009221c0 and FUN_00917cf0). */
typedef struct xml_node_004a6790 {
	const char *name;
	struct xml_node_004a6790 *next;
	struct xml_node_004a6790 *children;
	const char *value;
} xml_node_004a6790;
extern const char DAT_00ddac7c[];
extern const char DAT_00ddac94[];
extern const char DAT_00ddacac[];
extern const char DAT_00ddacc4[];
extern const char DAT_00ddaccc[];
extern unsigned char *DAT_022d7bcc;
int FUN_00c99030(const char *first, const char *second);
char *FUN_00c990f0(char *destination, const char *source, unsigned int count);
void FUN_00b74910(int *output, const char *tag, xml_node_004a6790 *node);
unsigned char *FUN_00b716e0(const char *name);

static __forceinline xml_node_004a6790 *first_child(xml_node_004a6790 *parent, const char *name)
{
	xml_node_004a6790 *child;
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

static __forceinline xml_node_004a6790 *next_named(xml_node_004a6790 *from, const char *name)
{
	xml_node_004a6790 *child = from;
	if (from == 0) {
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

__declspec(noinline) void FUN_004a6790(int row, unsigned char *table, int column, xml_node_004a6790 *node)
{
	unsigned char *entry;
	unsigned char *slot;
	xml_node_004a6790 *list;
	xml_node_004a6790 *element;
	xml_node_004a6790 *weapon;
	xml_node_004a6790 *next;
	unsigned char count;
	int value;
	unsigned char *weapon_record;
	char name[0x40];
	entry = table + 0x14 + (column + row * 3) * 0x44;
	entry[0] = 0;
	entry[1] = 0;
	FUN_00b74910(&value, DAT_00ddac7c, node);
	entry[0] = (unsigned char)value;
	list = first_child(node, DAT_00ddac94);
	if (list != 0) {
		next = first_child(list, DAT_00ddacac);
		for (element = next; element != 0; element = next) {
			count = entry[1];
			slot = entry + 4 + count * 8;
			entry[1] = count + 1;
			weapon = first_child(element, DAT_00ddacc4);
			if (weapon != 0 && weapon->value != 0) {
				FUN_00c990f0(name, weapon->value, 0x40);
				name[0x3f] = 0;
			}
			weapon_record = FUN_00b716e0(name);
			*(int *)slot = (int)(weapon_record - DAT_022d7bcc) / 0x498;
			FUN_00b74910(&value, DAT_00ddaccc, element);
			slot[4] = (unsigned char)value;
			next = next_named(element, DAT_00ddacac);
		}
	} else {
		entry[0] = 0;
	}
}
