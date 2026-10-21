/* FUN_00b7b800: clears the distant pedestrian skin, hair and clothing colour counts (DAT_022dbbf8, DAT_022dbbfc,
   DAT_022d7bf4), loads distant_ped_colors.xtbl (FUN_00b743f0 with the default loader) and, for each Color_Set
   child, reads the Skin_Color entries of its Skin_Colors child (at most 6, 12-byte colours at DAT_0319ede0), the
   Hair_Color entries of its Hair_Colors child (at most 8, at DAT_0319ed80) and the Clothing_Color_Set entries of
   its Clothing_Colors child (at most 32 0x3c-byte sets at DAT_0319ee28: the Undershirt, Overshirt, Pants, Shoe and
   Accent colours, each read only when present). Each colour is its R, G and B values (FUN_00b74ef0) divided by
   255. Then releases the parse through the loader DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134)
   and clears the handle to -1; the release method is a thiscall with one stack word, written as __fastcall with
   the EDX word native holds there (the handle).
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0 and FUN_00917cf0). */
typedef struct node_00b7b800 {
	const char *name;
	struct node_00b7b800 *next;
	struct node_00b7b800 *children;
	const char *value;
} node_t;
typedef struct color_00b7b800 {
	float r;
	float g;
	float b;
} color_t;
typedef struct clothing_00b7b800 {
	color_t undershirt;
	color_t overshirt;
	color_t pants;
	color_t shoe;
	color_t accent;
} clothing_t;
struct loader_00b7b800;
typedef void (__fastcall *loader_release)(struct loader_00b7b800 *loader, int unused, int handle);
struct loader_00b7b800 {
	loader_release *vtable;
};
extern const char s_distant_ped_colors_xtbl_00e4aff4[];
extern const char s_Color_Set_00e45578[];
extern const char s_Skin_Colors_00e4b00c[];
extern const char s_Skin_Color_00e21f44[];
extern const char s_Hair_Colors_00e4b018[];
extern const char s_Hair_Color_00e21e2c[];
extern const char s_Clothing_Colors_00e4b024[];
extern const char s_Clothing_Color_Set_00e4b034[];
extern const char s_Undershirt_Color_00e4b048[];
extern const char s_Overshirt_Color_00e4b05c[];
extern const char s_Pants_Color_00e4b06c[];
extern const char s_Shoe_Color_00e4b078[];
extern const char s_Accent_Color_00e4b084[];
extern const char s_R_00ddc4a0[];
extern const char s_G_00ddc4a4[];
extern const char s_B_00ddc4a8[];
extern int DAT_022dbbf8;
extern int DAT_022dbbfc;
extern int DAT_022d7bf4;
extern color_t DAT_0319ede0[6];
extern color_t DAT_0319ed80[8];
extern clothing_t DAT_0319ee28[32];
extern struct loader_00b7b800 *DAT_00e87138;
extern int DAT_00e87134;
void *FUN_00b743f0(const char *name, struct loader_00b7b800 *loader);
int FUN_00c99030(const char *first, const char *second);
void FUN_00b74ef0(float *output, const char *tag, node_t *node);

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

static __forceinline void read_rgb(color_t *color, node_t *node)
{
	FUN_00b74ef0(&color->r, s_R_00ddc4a0, node);
	FUN_00b74ef0(&color->g, s_G_00ddc4a4, node);
	FUN_00b74ef0(&color->b, s_B_00ddc4a8, node);
}

static __forceinline void scale_rgb(color_t *color)
{
	color->r = color->r / 255.0;
	color->g = color->g / 255.0;
	color->b = color->b / 255.0;
}

static __forceinline void read_part(color_t *color, node_t *set, const char *name)
{
	node_t *part = first_child(set, name);
	if (part != 0) {
		read_rgb(color, part);
		scale_rgb(color);
	}
}

__declspec(noinline) void FUN_00b7b800(void)
{
	node_t *root;
	node_t *table;
	node_t *current;
	node_t *list;
	node_t *entry;
	node_t *next;
	color_t *color;
	clothing_t *clothing;
	DAT_022dbbf8 = 0;
	DAT_022dbbfc = 0;
	DAT_022d7bf4 = 0;
	root = (node_t *)FUN_00b743f0(s_distant_ped_colors_xtbl_00e4aff4, 0);
	table = find_first(root, s_Color_Set_00e45578);
	for (current = table; current != 0; current = table) {
		list = find_first(current, s_Skin_Colors_00e4b00c);
		next = find_first(list, s_Skin_Color_00e21f44);
		for (entry = next; entry != 0; entry = next) {
			if (DAT_022dbbf8 == 6) {
				break;
			}
			color = &DAT_0319ede0[DAT_022dbbf8];
			read_rgb(color, entry);
			DAT_022dbbf8++;
			scale_rgb(color);
			next = next_sibling(list, entry, s_Skin_Color_00e21f44);
		}
		list = find_first(current, s_Hair_Colors_00e4b018);
		next = find_first(list, s_Hair_Color_00e21e2c);
		for (entry = next; entry != 0; entry = next) {
			if (DAT_022dbbfc == 8) {
				break;
			}
			color = &DAT_0319ed80[DAT_022dbbfc];
			read_rgb(color, entry);
			DAT_022dbbfc++;
			scale_rgb(color);
			next = next_sibling(list, entry, s_Hair_Color_00e21e2c);
		}
		list = find_first(current, s_Clothing_Colors_00e4b024);
		next = find_first(list, s_Clothing_Color_Set_00e4b034);
		for (entry = next; entry != 0; entry = next) {
			if (DAT_022d7bf4 == 32) {
				break;
			}
			clothing = &DAT_0319ee28[DAT_022d7bf4];
			read_part(&clothing->undershirt, entry, s_Undershirt_Color_00e4b048);
			read_part(&clothing->overshirt, entry, s_Overshirt_Color_00e4b05c);
			read_part(&clothing->pants, entry, s_Pants_Color_00e4b06c);
			read_part(&clothing->shoe, entry, s_Shoe_Color_00e4b078);
			read_part(&clothing->accent, entry, s_Accent_Color_00e4b084);
			DAT_022d7bf4++;
			next = next_sibling(list, entry, s_Clothing_Color_Set_00e4b034);
		}
		table = next_sibling(root, current, s_Color_Set_00e45578);
	}
	DAT_00e87138->vtable[0x34 / 4](DAT_00e87138, DAT_00e87134, DAT_00e87134);
	DAT_00e87134 = -1;
}
