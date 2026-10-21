/* FUN_006abe60: loads persona_situations.xtbl (FUN_00b743f0 with the default loader). For each Situation of the
   Situations child of each Situation_List child, hashes its Type value (copied into a 0xff-byte buffer,
   FUN_00c990f0; FUN_00bdcb30, seed 0) and looks the hash up in the situation table (FUN_006abce0). For a known
   situation it stores the Global_Delay and Local_Delay values (FUN_00b747d0) in seconds as shorts at +6 and +4 of
   its 16-byte record in DAT_027d5a78, ChanceToPlay as a fraction (times the double 0.01, the float 0.01 widened)
   at +8, and at +0xc the index of the Distance value's hash in the DAT_02526abc 12-byte entries of DAT_02574270, or
   0xffff. Then releases the parse through the loader DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134)
   and clears the handle to -1; the release method is a thiscall with one stack word, written as __fastcall whose
   EDX word is the method pointer itself, which is what native holds in EDX there.
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0 and FUN_00917cf0); the
   Situations lookup is the return-in-loop shape and the inner loop's sibling step has no parent test. */
typedef struct node_006abe60 {
	const char *name;
	struct node_006abe60 *next;
	struct node_006abe60 *children;
	const char *value;
} node_t;
typedef struct situation_006abe60 {
	unsigned int key;
	short local_delay;
	short global_delay;
	float chance;
	unsigned short distance;
	unsigned short pad;
} situation_t;
typedef struct distance_006abe60 {
	unsigned int key;
	int pad4;
	int pad8;
} distance_t;
struct loader_006abe60;
typedef void (__fastcall *loader_release)(struct loader_006abe60 *loader, int unused, int handle);
struct loader_006abe60 {
	loader_release *vtable;
};
extern const char s_persona_situations_xtbl_00e06b88[];
extern const char s_Situation_List_00e06ba0[];
extern const char s_Situations_00e06bb0[];
extern const char s_Situation_00dee3b4[];
extern const char s_Type_00dd92d4[];
extern const char s_Global_Delay_00e06bbc[];
extern const char s_Local_Delay_00e06bcc[];
extern const char s_ChanceToPlay_00de7a30[];
extern const char s_Distance_00dd88a0[];
extern struct loader_006abe60 *DAT_00e87138;
extern int DAT_00e87134;
extern situation_t DAT_027d5a78[];
extern distance_t DAT_02574270[];
extern unsigned short DAT_02526abc;
void *FUN_00b743f0(const char *name, struct loader_006abe60 *loader);
int FUN_00c99030(const char *first, const char *second);
char *__cdecl FUN_00c990f0(char *destination, const char *source, unsigned int count);
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
int FUN_006abce0(const unsigned int *key);
void FUN_00b747d0(int *output, const char *tag, node_t *node);

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

static __forceinline node_t *next_named(node_t *from, const char *name)
{
	node_t *child = from;
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

static __forceinline int distance_index(unsigned int key)
{
	unsigned short index;
	for (index = 0; index < DAT_02526abc; index++) {
		if (DAT_02574270[index].key == key) {
			return index;
		}
	}
	return 0xffff;
}

static __forceinline node_t *lookup_return(node_t *parent, const char *name)
{
	node_t *child;
	if (parent != 0) {
		for (child = parent->children; child != 0; child = child->next) {
			if (FUN_00c99030(child->name, name) == 0) {
				return child;
			}
		}
	}
	return 0;
}

__declspec(noinline) void FUN_006abe60(void)
{
	char text[0xff];
	node_t *root;
	node_t *table;
	node_t *current;
	node_t *list;
	node_t *entry;
	node_t *situation;
	node_t *child;
	situation_t *record;
	int slot;
	int delay;
	int chance;
	unsigned int key;
	unsigned int distance;
	loader_release release;
	root = (node_t *)FUN_00b743f0(s_persona_situations_xtbl_00e06b88, 0);
	table = find_first(root, s_Situation_List_00e06ba0);
	for (current = table; current != 0; current = table) {
		list = lookup_return(current, s_Situations_00e06bb0);
		if (list != 0) {
			entry = find_first(list, s_Situation_00dee3b4);
			for (situation = entry; situation != 0; situation = entry) {
				child = first_child(situation, s_Type_00dd92d4);
				if (child != 0 && child->value != 0) {
					FUN_00c990f0(text, child->value, 0xff);
					text[0xfe] = 0;
				}
				FUN_00bdcb30(text, 0, &key);
				slot = FUN_006abce0(&key);
				if (slot > -1) {
					record = &DAT_027d5a78[slot];
					FUN_00b747d0(&delay, s_Global_Delay_00e06bbc, situation);
					record->global_delay = (short)(delay / 1000);
					FUN_00b747d0(&delay, s_Local_Delay_00e06bcc, situation);
					record->local_delay = (short)(delay / 1000);
					FUN_00b747d0(&chance, s_ChanceToPlay_00de7a30, situation);
					record->chance = chance * 0.009999999776482582;
					child = first_child(situation, s_Distance_00dd88a0);
					if (child != 0 && child->value != 0) {
						FUN_00c990f0(text, child->value, 0xff);
						text[0xfe] = 0;
					}
					FUN_00bdcb30(text, 0, &distance);
					record->distance = (unsigned short)distance_index(distance);
				}
				entry = next_named(situation, s_Situation_00dee3b4);
			}
		}
		table = next_sibling(root, current, s_Situation_List_00e06ba0);
	}
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
