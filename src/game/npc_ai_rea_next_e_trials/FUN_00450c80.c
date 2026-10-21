/* FUN_00450c80: loads rank_reactions.xtbl (FUN_00b743f0 with the default loader). For each NPCGroup child, the Name
   value (copied into a 0x40-byte buffer, FUN_00c990f0) is matched against the four group names (Civilian; Gang,
   Enemy; Gang, Friendly; Police); for each ReactionPercentages child of its Reactions child, the PlayerRank value is
   matched against the four rank names, and the seven reaction percentages (Ignore, Avoid, Compliment, FlipOff,
   GangSign, SayAmbient, Threaten; FUN_00b747d0) are stored as fractions (times the double 0.01, the float 0.01
   widened) into the seven floats of entry group * 4 + rank of DAT_00ee27e8. Then releases the parse through the
   loader DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134) and clears the handle to -1; the release
   method is a thiscall with one stack word, written as __fastcall whose EDX word is the method pointer itself,
   which is what native holds in EDX there. The name compares are the compiler's inline strcmp.
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0 and FUN_00917cf0); the
   Reactions lookup (find_list, the found-variable shape like find_first, defined after next_sibling), and the NPCGroup step takes the node before its parent. */
typedef struct node_00450c80 {
	const char *name;
	struct node_00450c80 *next;
	struct node_00450c80 *children;
	const char *value;
} node_t;
struct loader_00450c80;
typedef void (__fastcall *loader_release)(struct loader_00450c80 *loader, int unused, int handle);
struct loader_00450c80 {
	loader_release *vtable;
};
extern const char DAT_00dd76dc[];
extern const char DAT_00dd76f0[];
extern const char DAT_00dd76fc[];
extern const char DAT_00dd7708[];
extern const char DAT_00dd6c68[];
extern const char s_Name_00dc5804[];
extern const char DAT_00dd7628[], DAT_00dd7634[], DAT_00dd7640[], DAT_00dd7650[];
extern const char DAT_00dd7658[], DAT_00dd7668[], DAT_00dd7678[], DAT_00dd768c[];
extern const char DAT_00dd76a0[], DAT_00dd76a8[], DAT_00dd76b0[], DAT_00dd76bc[], DAT_00dd76c4[], DAT_00dd76d0[];
extern const char DAT_00dd6bb8[];
extern struct loader_00450c80 *DAT_00e87138;
extern int DAT_00e87134;
extern float DAT_00ee27e8[16][7];
void *FUN_00b743f0(const char *name, struct loader_00450c80 *loader);
int FUN_00c99030(const char *first, const char *second);
char *__cdecl FUN_00c990f0(char *destination, const char *source, unsigned int count);
void FUN_00b747d0(int *output, const char *tag, node_t *node);
int __cdecl strcmp(const char *first, const char *second);

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

static __forceinline node_t *find_list(node_t *parent, const char *name)
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

static __forceinline node_t *next_sibling_from(node_t *from, node_t *parent, const char *name)
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

__declspec(noinline) void FUN_00450c80(void)
{
	const char *groups[4];
	const char *ranks[4];
	const char *reactions[7];
	char group_name[0x40];
	char rank_name[0x40];
	node_t *root;
	node_t *next_group;
	node_t *group;
	node_t *list;
	node_t *next_entry;
	node_t *entry;
	node_t *child;
	int group_index;
	int rank_index;
	int index;
	int value;
	float *percent;
	loader_release release;
	groups[0] = DAT_00dd7628;
	groups[1] = DAT_00dd7634;
	groups[2] = DAT_00dd7640;
	groups[3] = DAT_00dd7650;
	ranks[0] = DAT_00dd7658;
	ranks[1] = DAT_00dd7668;
	ranks[2] = DAT_00dd7678;
	ranks[3] = DAT_00dd768c;
	reactions[0] = DAT_00dd76a0;
	reactions[1] = DAT_00dd76a8;
	reactions[2] = DAT_00dd76b0;
	reactions[3] = DAT_00dd76bc;
	reactions[4] = DAT_00dd76c4;
	reactions[5] = DAT_00dd76d0;
	reactions[6] = DAT_00dd6bb8;
	root = (node_t *)FUN_00b743f0(DAT_00dd76dc, 0);
	next_group = find_first(root, DAT_00dd76f0);
	for (group = next_group; group != 0; group = next_group) {
		child = first_child(group, s_Name_00dc5804);
		if (child != 0 && child->value != 0) {
			FUN_00c990f0(group_name, child->value, 0x40);
			group_name[0x3f] = 0;
		}
		for (group_index = 0; group_index < 4; group_index++) {
			if (strcmp(group_name, groups[group_index]) == 0) {
				break;
			}
		}
		list = find_list(group, DAT_00dd76fc);
		next_entry = find_first(list, DAT_00dd7708);
		for (entry = next_entry; entry != 0; entry = next_entry) {
			child = first_child(entry, DAT_00dd6c68);
			if (child != 0 && child->value != 0) {
				FUN_00c990f0(rank_name, child->value, 0x40);
				rank_name[0x3f] = 0;
			}
			for (rank_index = 0; rank_index < 4; rank_index++) {
				if (strcmp(rank_name, ranks[rank_index]) == 0) {
					break;
				}
			}
			index = 0;
			percent = DAT_00ee27e8[group_index * 4 + rank_index];
			for (; index < 7; index++) {
				FUN_00b747d0(&value, reactions[index], entry);
				*percent++ = value * 0.009999999776482582;
			}
			next_entry = next_sibling(list, entry, DAT_00dd7708);
		}
		next_group = next_sibling_from(group, root, DAT_00dd76f0);
	}
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
