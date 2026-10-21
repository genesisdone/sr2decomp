/* FUN_00923e30: whether another spawn of the object fits: the limit is 1, or 2 when FUN_009e1ea0 accepts the
   DAT_021703d4 player at DAT_0279ab14 level 5; the three counters DAT_00eb78bc + DAT_00eb6864 + DAT_00eb65a4 must
   be below it, byte +0x1e8 set, the +0x2b8 timer unset or at least 15000 ms old (FUN_00bdd2a0), and the object's
   vtable slot 14 (+0x38; runtime target unknown, certified only as the audited literal call chain) must agree.
   The method takes the object in ECX (one-parameter __fastcall, the C spelling of a thiscall). */
struct object_923e30;
typedef int (__fastcall *agree_fn)(struct object_923e30 *self);
struct object_923e30 {
	agree_fn *vtable;
	unsigned char pad_04[0x1e4];
	unsigned char enabled;
	unsigned char pad_1e9[0xcf];
	int timer;
};
extern unsigned char *DAT_021703d4;
extern int DAT_0279ab14;
extern int DAT_00eb78bc;
extern int DAT_00eb6864;
extern int DAT_00eb65a4;
unsigned char FUN_009e1ea0(unsigned char *person);
int FUN_00bdd2a0(int *timer);

__declspec(noinline) unsigned char __fastcall FUN_00923e30(struct object_923e30 *object)
{
	int limit = 1;
	if (FUN_009e1ea0(DAT_021703d4) && DAT_0279ab14 == 5) {
		limit = 2;
	}
	if (DAT_00eb65a4 + DAT_00eb6864 + DAT_00eb78bc >= limit) {
		return 0;
	}
	if (object->enabled == 0) {
		return 0;
	}
	if (object->timer >= 0 && FUN_00bdd2a0(&object->timer) < 15000) {
		return 0;
	}
	return (unsigned char)(object->vtable[14](object) != 0);
}
