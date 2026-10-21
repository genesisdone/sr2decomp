/* FUN_00402a50: a debug command that selects the nearest living character (hypothesis, unconfirmed). Does nothing
   unless FUN_00be1b50(2, 0) allows it. Hashes the text buffer DAT_02345a60 (FUN_00bdcb30, seed 0) and looks the
   hash up in the DAT_02526a0c 0x40-byte entries at DAT_0253a700, keeping the index (0xff when absent). Then walks
   the character ring from DAT_0215ffc0 through +0x1160, taking every character whose +0x44 handle resolves to
   itself in DAT_02149c64 and whose health (+0x1124) is above 0, and keeps the one nearest the camera position
   DAT_025f5b14 (squared distance, starting from DAT_00e8725c). With none, prints DAT_00dc5798. Otherwise passes
   the index to FUN_00443b00 for the character's +0xf8 block, gives it 10000 through FUN_00969ed0 and DAT_00e9802c
   through FUN_00969c90, and prints its handle with DAT_00dc57b8, or the index and handle with DAT_00dc57dc.
   The nearest-character search is written as an inline helper taking the ring head and the starting distance;
   whether the original had such a helper is unconfirmed. */
typedef struct character_00402a50 character_t;
extern char DAT_02345a60[];
extern int DAT_02526a0c;
extern unsigned int DAT_0253a700[];
extern float DAT_00e8725c;
typedef struct vec3_00402a50 {
	float x;
	float y;
	float z;
} vec3_t;
extern vec3_t DAT_025f5b14;
extern float DAT_00e9802c;
extern char *DAT_0215ffc0;
extern char *DAT_02149c64[];
extern char DAT_00dc5798[];
extern char DAT_00dc57b8[];
extern char DAT_00dc57dc[];
unsigned char __cdecl FUN_00be1b50(int mode, int flag);
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
void __stdcall FUN_00443b00(char *block, unsigned char *kind);
void __stdcall FUN_00969ed0(char *character, int *maximum);
void __stdcall FUN_00969c90(char *character, float *value);
void __cdecl FUN_00be1b10(const char *format, ...);

static __forceinline char *resolve(char *node)
{
	int handle = *(int *)(node + 0x44);
	char *object;
	if (handle == 0) {
		return 0;
	}
	object = DAT_02149c64[(handle & 0xfff) * 4];
	if (object == 0 || *(int *)(object + 0x44) != handle) {
		return 0;
	}
	return object;
}

static __forceinline char *nearest(char *head, float closest)
{
	char *node;
	char *selected;
	float difference;
	float distance;
	node = head;
	selected = 0;
	if (node != 0) {
		do {
			if (resolve(node) == node && !(*(float *)(node + 0x1124) <= 0.0f)) {
				difference = DAT_025f5b14.x - *(float *)(node + 0x14);
				distance = difference * difference;
				difference = DAT_025f5b14.y - *(float *)(node + 0x18);
				distance = difference * difference + distance;
				difference = DAT_025f5b14.z - *(float *)(node + 0x1c);
				distance = difference * difference + distance;
				if (distance < closest) {
					closest = distance;
					selected = node;
				}
			}
			node = *(char **)(node + 0x1160);
		} while (node != head && node != 0);
	}
	return selected;
}

__declspec(noinline) void FUN_00402a50(void)
{
	unsigned char kind;
	unsigned char index;
	unsigned int hash;
	int count;
	int maximum;
	float value;
	char *selected;
	kind = 0xff;
	if (!FUN_00be1b50(2, 0)) {
		return;
	}
	FUN_00bdcb30(DAT_02345a60, 0, &hash);
	count = DAT_02526a0c;
	index = 0;
	if (count > 0) {
		do {
			if (DAT_0253a700[index * 16] == hash) {
				kind = index;
				break;
			}
			index++;
		} while ((int)index < count);
	}
	selected = nearest(DAT_0215ffc0, DAT_00e8725c);
	if (selected == 0) {
		FUN_00be1b10(DAT_00dc5798);
		return;
	}
	FUN_00443b00(selected + 0xf8, &kind);
	maximum = 10000;
	FUN_00969ed0(selected, &maximum);
	value = DAT_00e9802c;
	FUN_00969c90(selected, &value);
	if (kind == 0xff) {
		FUN_00be1b10(DAT_00dc57b8, *(int *)(selected + 0x44));
	} else {
		FUN_00be1b10(DAT_00dc57dc, kind, *(int *)(selected + 0x44));
	}
}
