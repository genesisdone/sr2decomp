/* FUN_00924310: false while the DAT_025295cb override is clear and the DAT_021703d4 player's +0x14f8 record has
   flag 0x400000 at +0x10; otherwise true when FUN_0055f670 of the object's +0x1e4 kind reaches its +0x200 level
   and its vtable slot 28 (+0x70; runtime target unknown, certified only as the audited literal call chain)
   agrees. The final checks are an inline helper returning int (native's two kinds of false return). The method
   takes the object in ECX (one-parameter __fastcall, the C spelling of a thiscall). */
struct object_924310;
typedef unsigned char (__fastcall *ready_fn)(struct object_924310 *self);
struct object_924310 {
	ready_fn *vtable;
	unsigned char pad_04[0x1e0];
	int kind;
	unsigned char pad_1e8[0x18];
	int level;
};
extern unsigned char DAT_025295cb;
extern unsigned char *DAT_021703d4;
int FUN_0055f670(int kind);

static __forceinline int object_ready(struct object_924310 *object)
{
	if (FUN_0055f670(object->kind) >= object->level && object->vtable[28](object)) {
		return 1;
	}
	return 0;
}

__declspec(noinline) unsigned char __fastcall FUN_00924310(struct object_924310 *object)
{
	if (DAT_025295cb == 0 && DAT_021703d4 != 0) {
		unsigned char *record = *(unsigned char **)(DAT_021703d4 + 0x14f8);
		if (record != 0 && (*(unsigned int *)(record + 0x10) & 0x400000) != 0) {
			return 0;
		}
	}
	return object_ready(object);
}
