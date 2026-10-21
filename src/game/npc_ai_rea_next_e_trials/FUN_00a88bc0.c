/* FUN_00a88bc0: parses traffic_lanes.xtbl (FUN_00b743f0 with the default loader), finds its NewEntity/LaneGrid node
   (FUN_00bfbee0 twice), reads the Speed value of each of its LaneSpeed children (FUN_00bfc110 counts them,
   FUN_00bfbf40 picks the i-th, FUN_00b74ef0 stores the value) into the float table DAT_0223e3e8, keeping the
   largest in DAT_0252a040 (from 0) and the count in DAT_0252a03c, then releases the parse through the loader
   DAT_00e87138 (vtable slot +0x34 with the handle DAT_00e87134) and clears the handle to -1. The release method is
   a thiscall with one stack word, written as __fastcall with an unused EDX word (the loaded method pointer).
   Native has FUN_00bfbee0 inlined here (the original LTCG inlined it across modules) for the NewEntity lookup; the
   LaneGrid lookup is find_child, the same search written with the return inside the loop, whose exhausted search
   joins the first lookup's NULL path as native's does. */
typedef struct node_00a88bc0 {
	const char *name;
	struct node_00a88bc0 *next;
	struct node_00a88bc0 *children;
	const char *value;
} node_t;
struct loader_00a88bc0;
typedef void (__fastcall *loader_release)(struct loader_00a88bc0 *loader, int unused, int handle);
struct loader_00a88bc0 {
	loader_release *vtable;
};
extern const char s_traffic_lanes_xtbl_00e44788[];
extern const char s_NewEntity_00e2db8c[];
extern const char s_LaneGrid_00e4479c[];
extern const char s_LaneSpeed_00e447a8[];
extern const char s_Speed_00de3610[];
extern float DAT_0223e3e8[];
extern float DAT_0252a040;
extern int DAT_0252a03c;
extern struct loader_00a88bc0 *DAT_00e87138;
extern int DAT_00e87134;
void *FUN_00b743f0(const char *name, struct loader_00a88bc0 *loader);
node_t *FUN_00bfbee0(node_t *parent, const char *name);
int FUN_00c99030(const char *first, const char *second);
int FUN_00bfc110(node_t *parent, const char *name);
node_t *FUN_00bfbf40(node_t *parent, int skip);
void FUN_00b74ef0(float *output, const char *tag, node_t *node);

static __forceinline node_t *find_child(node_t *parent, const char *name)
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

__declspec(noinline) void FUN_00a88bc0(void)
{
	node_t *grid;
	int count;
	int index;
	float *speed;
	loader_release release;
	grid = FUN_00bfbee0(FUN_00b743f0(s_traffic_lanes_xtbl_00e44788, 0), s_NewEntity_00e2db8c);
	grid = grid != 0 ? find_child(grid, s_LaneGrid_00e4479c) : 0;
	count = FUN_00bfc110(grid, s_LaneSpeed_00e447a8);
	DAT_0252a040 = 0.0f;
	speed = DAT_0223e3e8;
	for (index = 0; index < count; index++) {
		FUN_00b74ef0(speed, s_Speed_00de3610, FUN_00bfbf40(grid, index));
		if (*speed > DAT_0252a040) {
			DAT_0252a040 = *speed;
		}
		speed++;
	}
	DAT_0252a03c = count;
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
