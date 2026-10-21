/* FUN_00923fa0: whether the object is eligible now. Requires its +0x1e4 kind to be the DAT_00e88be4 kind, FUN_0055f670
   of that kind within [+0x200, +0x204], its +0x2ac partner (if any) not to report busy through vtable slot 29
   (+0x74; runtime target unknown, certified only as the audited literal call chain), and, when byte +0x2a7 is 1,
   FUN_00921fc0 to accept both the DAT_021703d4 player and FUN_009d7bd0()'s result. Then returns byte +0x2a5,
   +0x2a8 or +0x2a6 for DAT_025295e4 mode 0, 1 or 2, else false. The method takes the partner in ECX (one-parameter
   __fastcall, the C spelling of a thiscall). */
struct partner_923fa0;
typedef unsigned char (__fastcall *busy_fn)(struct partner_923fa0 *self);
struct partner_923fa0 {
	busy_fn *vtable;
};
struct object_923fa0 {
	unsigned char pad_00[0x1e4];
	int kind;
	unsigned char pad_1e8[0x18];
	int minimum;
	int maximum;
	unsigned char pad_208[0x9d];
	unsigned char allowed_0;
	unsigned char allowed_2;
	unsigned char needs_people;
	unsigned char allowed_1;
	unsigned char pad_2a9[3];
	struct partner_923fa0 *partner;
};
extern int DAT_00e88be4;
extern int DAT_025295e4;
extern unsigned char *DAT_021703d4;
int FUN_0055f670(int kind);
unsigned char *FUN_009d7bd0(void);
unsigned char FUN_00921fc0(unsigned char *person);

__declspec(noinline) unsigned char __fastcall FUN_00923fa0(struct object_923fa0 *object)
{
	int level;
	if (DAT_00e88be4 != object->kind) {
		return 0;
	}
	level = FUN_0055f670(object->kind);
	if (level < object->minimum || level > object->maximum) {
		return 0;
	}
	if (object->partner != 0 && object->partner->vtable[29](object->partner)) {
		return 0;
	}
	if (object->needs_people == 1) {
		unsigned char *player = DAT_021703d4;
		unsigned char *other = FUN_009d7bd0();
		if (!FUN_00921fc0(player) || !FUN_00921fc0(other)) {
			return 0;
		}
	}
	switch (DAT_025295e4) {
	case 0:
		return object->allowed_0;
	case 1:
		return object->allowed_1;
	case 2:
		return object->allowed_2;
	}
	return 0;
}
