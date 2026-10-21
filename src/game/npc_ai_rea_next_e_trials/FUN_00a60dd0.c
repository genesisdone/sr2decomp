/* FUN_00a60dd0: calls the object's vtable slot 11 (+0x2c; runtime target unknown, certified only as the literal
   audited call chain) and, when it returns true, FUN_009ce370(object->owner, 0, 1). The method takes the object
   in ECX (one-parameter __fastcall, the C spelling of a thiscall without stack arguments). Moved from gate
   npc-ai-rea-next-a8. */
struct object_a60dd0;
typedef unsigned char (__fastcall *check_fn)(struct object_a60dd0 *self);
struct object_a60dd0 {
	check_fn *vtable;
	unsigned char pad[0x170];
	int owner;
};
extern void __stdcall FUN_009ce370(int object, char second, char third);
__declspec(noinline) void __fastcall FUN_00a60dd0(struct object_a60dd0 *object)
{
	if (object->vtable[11](object)) {
		FUN_009ce370(object->owner, 0, 1);
	}
}
