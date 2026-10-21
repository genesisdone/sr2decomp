/* FUN_00436e70: clears the four 0x4c-byte AI rank records at DAT_00ee26b0 (FUN_00ca0bc0, memset), loads
   ai_rank_attribs.xtbl (FUN_00b743f0 with the default loader) and, for each Rank_tag child, reads its Rank
   (FUN_00b747d0) and fills that record from the Detection, Firearms and Melee children: floats through
   FUN_00b74ef0, the two React_after_hits counts through FUN_00b747d0. The detection cone angles are halved and
   turned from degrees into their cosines (FUN_0040b820), and the lock-on constant is turned from degrees into
   radians, both with the double 0.017453 (the float 0.017453 widened). Then releases the parse through the loader
   DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134) and clears the handle to -1; the release method is
   a thiscall with one stack word, written as __fastcall whose EDX word is the method pointer itself, which is what
   native holds in EDX there. Nothing is released when the file does not parse.
   The node helpers are the shapes the original's inlined lookups have (see FUN_009221c0 and FUN_00917cf0). */
typedef struct node_00436e70 {
	const char *name;
	struct node_00436e70 *next;
	struct node_00436e70 *children;
	const char *value;
} node_t;
typedef struct rank_00436e70 {
	float detection_length_far;
	float detection_cos_far;
	float detection_length_near;
	float detection_cos_near;
	float lock_on_constant;
	float lock_on_time;
	float block_to_attack_time_min;
	float block_to_attack_time_max;
	float hit_to_block_time_min;
	float hit_to_block_time_max;
	float hit_to_attack_time_min;
	float hit_to_attack_time_max;
	int react_after_hits_min;
	int react_after_hits_max;
	float grabbed_to_escape_time_min;
	float grabbed_to_escape_time_max;
	float combo_chance;
	float hard_punch_odds;
	float block_odds;
} rank_t;
struct loader_00436e70;
typedef void (__fastcall *loader_release)(struct loader_00436e70 *loader, int unused, int handle);
struct loader_00436e70 {
	loader_release *vtable;
};
extern const char s_ai_rank_attribs_xtbl_00dd6d0c[];
extern const char s_Rank_tag_00dd6d24[];
extern const char s_Rank_00dd6d30[];
extern const char s_Detection_00dd6d38[];
extern const char s_Detection_cone_length_far_00dd6d44[];
extern const char s_Detection_cone_length_near_00dd6d60[];
extern const char s_Detection_cone_angle_far_00dd6d7c[];
extern const char s_Detection_cone_angle_near_00dd6d98[];
extern const char s_Firearms_00dd6db4[];
extern const char s_Weapon_lock_on_constant_00dd6dc0[];
extern const char s_Weapon_lock_on_time_00dd6dd8[];
extern const char s_Melee_00dd6dec[];
extern const char s_Block_to_attack_time_min_00dd6df4[];
extern const char s_Block_to_attack_time_max_00dd6e10[];
extern const char s_Hit_to_block_time_min_00dd6e2c[];
extern const char s_Hit_to_block_time_max_00dd6e44[];
extern const char s_Hit_to_attack_time_min_00dd6e5c[];
extern const char s_Hit_to_attack_time_max_00dd6e74[];
extern const char s_React_after_hits_min_00dd6e8c[];
extern const char s_React_after_hits_max_00dd6ea4[];
extern const char s_Grabbed_to_escape_time_min_00dd6ebc[];
extern const char s_Grabbed_to_escape_time_max_00dd6ed8[];
extern const char s_Combo_chance_00dd6ef4[];
extern const char s_Hard_Punch_Odds_00dd6f04[];
extern const char s_Block_Odds_00dd5cc0[];
extern struct loader_00436e70 *DAT_00e87138;
extern int DAT_00e87134;
extern rank_t DAT_00ee26b0[4];
void *FUN_00ca0bc0(void *destination, int value, unsigned int length);
void *FUN_00b743f0(const char *name, struct loader_00436e70 *loader);
int FUN_00c99030(const char *first, const char *second);
void FUN_00b747d0(int *output, const char *tag, node_t *node);
void FUN_00b74ef0(float *output, const char *tag, node_t *node);
float FUN_0040b820(float angle);

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

__declspec(noinline) void FUN_00436e70(void)
{
	node_t *root;
	node_t *table;
	node_t *current;
	node_t *group;
	rank_t *rank;
	int index;
	float angle;
	float half;
	loader_release release;
	FUN_00ca0bc0(DAT_00ee26b0, 0, sizeof(DAT_00ee26b0));
	root = (node_t *)FUN_00b743f0(s_ai_rank_attribs_xtbl_00dd6d0c, 0);
	if (root == 0) {
		return;
	}
	table = find_first(root, s_Rank_tag_00dd6d24);
	for (current = table; current != 0; current = table) {
		FUN_00b747d0(&index, s_Rank_00dd6d30, current);
		rank = &DAT_00ee26b0[index];
		group = first_child(current, s_Detection_00dd6d38);
		FUN_00b74ef0(&rank->detection_length_far, s_Detection_cone_length_far_00dd6d44, group);
		FUN_00b74ef0(&rank->detection_length_near, s_Detection_cone_length_near_00dd6d60, group);
		FUN_00b74ef0(&angle, s_Detection_cone_angle_far_00dd6d7c, group);
		half = angle * 0.5 * 0.01745299994945526;
		rank->detection_cos_far = FUN_0040b820(half);
		FUN_00b74ef0(&angle, s_Detection_cone_angle_near_00dd6d98, group);
		half = angle * 0.5 * 0.01745299994945526;
		rank->detection_cos_near = FUN_0040b820(half);
		group = find_first(current, s_Firearms_00dd6db4);
		FUN_00b74ef0(&rank->lock_on_constant, s_Weapon_lock_on_constant_00dd6dc0, group);
		rank->lock_on_constant = rank->lock_on_constant * 0.01745299994945526;
		FUN_00b74ef0(&rank->lock_on_time, s_Weapon_lock_on_time_00dd6dd8, group);
		group = first_child(current, s_Melee_00dd6dec);
		FUN_00b74ef0(&rank->block_to_attack_time_min, s_Block_to_attack_time_min_00dd6df4, group);
		FUN_00b74ef0(&rank->block_to_attack_time_max, s_Block_to_attack_time_max_00dd6e10, group);
		FUN_00b74ef0(&rank->hit_to_block_time_min, s_Hit_to_block_time_min_00dd6e2c, group);
		FUN_00b74ef0(&rank->hit_to_block_time_max, s_Hit_to_block_time_max_00dd6e44, group);
		FUN_00b74ef0(&rank->hit_to_attack_time_min, s_Hit_to_attack_time_min_00dd6e5c, group);
		FUN_00b74ef0(&rank->hit_to_attack_time_max, s_Hit_to_attack_time_max_00dd6e74, group);
		FUN_00b747d0(&rank->react_after_hits_min, s_React_after_hits_min_00dd6e8c, group);
		FUN_00b747d0(&rank->react_after_hits_max, s_React_after_hits_max_00dd6ea4, group);
		FUN_00b74ef0(&rank->grabbed_to_escape_time_min, s_Grabbed_to_escape_time_min_00dd6ebc, group);
		FUN_00b74ef0(&rank->grabbed_to_escape_time_max, s_Grabbed_to_escape_time_max_00dd6ed8, group);
		FUN_00b74ef0(&rank->combo_chance, s_Combo_chance_00dd6ef4, group);
		FUN_00b74ef0(&rank->hard_punch_odds, s_Hard_Punch_Odds_00dd6f04, group);
		FUN_00b74ef0(&rank->block_odds, s_Block_Odds_00dd5cc0, group);
		table = next_sibling(root, current, s_Rank_tag_00dd6d24);
	}
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
