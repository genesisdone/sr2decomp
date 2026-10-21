/* FUN_00b7fda0: draws a random float from the generator at 0x00ec30f8 (FUN_00bdce30), scales it by DAT_0252a19c,
   then walks the four 16-byte {x, y, z, weight} entries at 0x00ebd108 summing weights and copies the xyz of the
   first entry whose running sum reaches the scaled value to out; if none does, entry 3's xyz.
   Native takes out in ESI. */
typedef struct { float x, y, z; } vec3_t;
typedef struct { vec3_t pos; float weight; } weighted_entry_t;
float FUN_00bdce30(void *generator);
extern unsigned char DAT_00ec30f8[];
extern float DAT_0252a19c;
extern weighted_entry_t DAT_00ebd108[4];

__declspec(noinline) void FUN_00b7fda0(vec3_t *out)
{
	float pick;
	float sum;
	int index;
	pick = FUN_00bdce30(DAT_00ec30f8) * DAT_0252a19c;
	sum = 0.0f;
	for (index = 0; index < 4; index++) {
		sum = sum + DAT_00ebd108[index].weight;
		if (pick <= sum) {
			*out = DAT_00ebd108[index].pos;
			return;
		}
	}
	*out = DAT_00ebd108[3].pos;
}
