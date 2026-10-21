/* FUN_009cc420: resets the four 0x30-byte melee style records at 0x0215fef0: for each, looks up the 21 names in
   the table at 0x00e881e0 with FUN_00980390 and stores the 21 result bytes from +8, clears bit 0 of +0x28, sets
   +0x2c = 1.0 and clears +0x20 and +0x24. Then stores FUN_007f49e0("MELEE_STYLE_DEFAULT", NULL) in the first
   record's first word and tail-calls FUN_009cc320. No inputs. */
typedef struct {
	int name;
	int unknown_04;
	unsigned char ids[21];
	unsigned char unknown_1d[3];
	int unknown_20;
	int unknown_24;
	unsigned int active : 1;
	float scale;
} melee_style_t;
unsigned char FUN_00980390(const char *name);
int FUN_007f49e0(const char *name, const char *alternate);
void FUN_009cc320(void);
extern melee_style_t DAT_0215fef0[4];
extern const char *DAT_00e881e0[21];
extern const char s_MELEE_STYLE_DEFAULT_00e3c6c0[];

static __forceinline void style_reset(melee_style_t *style)
{
	unsigned int i;
	if (style == 0) {
		return;
	}
	for (i = 0; i < sizeof(DAT_00e881e0) / sizeof(DAT_00e881e0[0]); i++) {
		style->ids[i] = FUN_00980390(DAT_00e881e0[i]);
	}
	style->scale = 1.0f;
	style->unknown_20 = 0;
	style->unknown_24 = 0;
	style->active = 0;
}

__declspec(noinline) void FUN_009cc420(void)
{
	unsigned int i;
	for (i = 0; i < 4; i++) {
		style_reset(DAT_0215fef0 + i);
	}
	DAT_0215fef0[0].name = FUN_007f49e0(s_MELEE_STYLE_DEFAULT_00e3c6c0, 0);
	FUN_009cc320();
}
