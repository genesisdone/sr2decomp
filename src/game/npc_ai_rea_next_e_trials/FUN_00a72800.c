/* FUN_00a72800: runs a swept-sphere query and returns its result. Clears the 0x54-byte query record at 0x02f9b190
   (FUN_00ca0bc0 = memset), sets its +0x50 from DAT_00e8725c and +0x38 from DAT_00e87998, copies the start (native:
   ESI) to +4 and the end (native: EDI) to +0x10, stores the squared radii (+0x30, +0x34), sets bits 2-3 of the
   flags byte, stores the two caller words (+0x24, +0x28), overwrites +0x38 with DAT_00e87058, runs FUN_00bf79a0 on
   the world tree (DAT_02529e20 +0x24: root at +8, user word at +0) and returns the record's +0x2c. */
typedef struct { float x, y, z; } vec3_t;
typedef struct {
	unsigned char flags;
	unsigned char pad[3];
	vec3_t start;
	vec3_t end;
	int unknown_1c;
	int unknown_20;
	int word_24;
	int word_28;
	int result;
	float radius_squared;
	float other_radius_squared;
	float limit;
	int unknown_3c[5];
	float scale;
} query_t;
void *FUN_00ca0bc0(void *destination, int value, unsigned int size);
void __stdcall FUN_00bf79a0(int node, vec3_t *start, float radius, float other_radius, int user);
extern query_t DAT_02f9b190;
extern float DAT_00e8725c;
extern float DAT_00e87998;
extern float DAT_00e87058;
extern int DAT_02529e20;

__declspec(noinline) int FUN_00a72800(vec3_t *start, vec3_t *end, int a, int b, float radius, float other_radius)
{
	int *tree;
	FUN_00ca0bc0(&DAT_02f9b190, 0, sizeof(query_t));
	DAT_02f9b190.scale = DAT_00e8725c;
	DAT_02f9b190.limit = DAT_00e87998;
	DAT_02f9b190.start = *start;
	DAT_02f9b190.end = *end;
	DAT_02f9b190.radius_squared = radius * radius;
	DAT_02f9b190.other_radius_squared = other_radius * other_radius;
	DAT_02f9b190.word_24 = a;
	DAT_02f9b190.word_28 = b;
	DAT_02f9b190.flags |= 0xc;
	DAT_02f9b190.limit = DAT_00e87058;
	tree = *(int **)(DAT_02529e20 + 0x24);
	FUN_00bf79a0(tree[2], start, radius, other_radius, tree[0]);
	return DAT_02f9b190.result;
}
