/* FUN_00417850: parses human_firehose.xtbl (FUN_00b743f0 with the default loader), finds its Human_Firehose_Table
   child, reads Waterspray_Strength, Max_Distance, Pressure_Use_Rate, Pressure_Recovery_Rate and
   Rotation_Sensitivity into DAT_00ee1574, DAT_00ee1578, DAT_00ee1570, DAT_00ee156c and DAT_00ee157c (FUN_00b74ef0;
   the two pressure rates are scaled by 0.01), looks up the effect named by its Reticle_Effect child
   (FUN_00bfbee0, FUN_0050db60) into DAT_00ee1568, releases the parse through the loader DAT_00e87138 (vtable
   slot +0x34 with the handle DAT_00e87134, cleared to -1) and looks up the firetruck_spray effect into
   DAT_02526a20. The release method is a thiscall with one stack word, written as __fastcall with an unused EDX
   word (the loaded method pointer). */
typedef struct node_00417850 {
	const char *name;
	struct node_00417850 *next;
	struct node_00417850 *children;
	const char *value;
} node_t;
struct loader_00417850;
typedef void (__fastcall *loader_release)(struct loader_00417850 *loader, int unused, int handle);
struct loader_00417850 {
	loader_release *vtable;
};
extern const char s_human_firehose_xtbl_00dd5d3c[];
extern const char s_Human_Firehose_Table_00dd5d50[];
extern const char s_Waterspray_Strength_00dd5d68[];
extern const char s_Max_Distance_00dd5d7c[];
extern const char s_Pressure_Use_Rate_00dd5d8c[];
extern const char s_Pressure_Recovery_Rate_00dd5da0[];
extern const char s_Rotation_Sensitivity_00dd5db8[];
extern const char s_Reticle_Effect_00dd5dd0[];
extern const char s_firetruck_spray_00dd5d2c[];
extern float DAT_00ee1574;
extern float DAT_00ee1578;
extern float DAT_00ee1570;
extern float DAT_00ee156c;
extern float DAT_00ee157c;
extern int DAT_00ee1568;
extern int DAT_02526a20;
extern struct loader_00417850 *DAT_00e87138;
extern int DAT_00e87134;
int FUN_00c99030(const char *first, const char *second);
void *FUN_00b743f0(const char *name, struct loader_00417850 *loader);
node_t *FUN_00bfbee0(node_t *parent, const char *name);
void FUN_00b74ef0(float *output, const char *tag, node_t *node);
int FUN_0050db60(const char *name);

static __forceinline node_t *first_child(node_t *parent, const char *name)
{
	node_t *child;
	if (parent == 0) {
		return 0;
	}
	for (child = parent->children; child != 0; child = child->next) {
		if (FUN_00c99030(child->name, name) == 0) {
			return child;
		}
	}
	return 0;
}

static __forceinline const char *child_value(node_t *parent, const char *name)
{
	node_t *child;
	if (parent == 0) {
		return 0;
	}
	child = FUN_00bfbee0(parent, name);
	if (child == 0) {
		return 0;
	}
	return child->value;
}

__declspec(noinline) void FUN_00417850(void)
{
	node_t *table;
	loader_release release;
	table = first_child(FUN_00b743f0(s_human_firehose_xtbl_00dd5d3c, 0), s_Human_Firehose_Table_00dd5d50);
	FUN_00b74ef0(&DAT_00ee1574, s_Waterspray_Strength_00dd5d68, table);
	FUN_00b74ef0(&DAT_00ee1578, s_Max_Distance_00dd5d7c, table);
	FUN_00b74ef0(&DAT_00ee1570, s_Pressure_Use_Rate_00dd5d8c, table);
	DAT_00ee1570 = (float)(DAT_00ee1570 * 0.009999999776482582);
	FUN_00b74ef0(&DAT_00ee156c, s_Pressure_Recovery_Rate_00dd5da0, table);
	DAT_00ee156c = (float)(DAT_00ee156c * 0.009999999776482582);
	FUN_00b74ef0(&DAT_00ee157c, s_Rotation_Sensitivity_00dd5db8, table);
	DAT_00ee1568 = FUN_0050db60(child_value(table, s_Reticle_Effect_00dd5dd0));
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
	DAT_02526a20 = FUN_0050db60(s_firetruck_spray_00dd5d2c);
}
