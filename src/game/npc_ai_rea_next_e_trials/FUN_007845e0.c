/* FUN_007845e0 (moved from gate npc-ai-rea-virtual): 1 when byte +0x204 is set and the receiver's vtable slot 14
   (+0x38; runtime target unknown, certified only as the audited literal call chain) returns a positive value,
   else 0. The method takes the receiver in ECX (one-parameter __fastcall, the C spelling of a thiscall). */
struct receiver_7845e0;
typedef int (__fastcall *count_fn)(struct receiver_7845e0 *self);
struct receiver_7845e0 {
	count_fn *vtable;
	unsigned char pad[0x200];
	unsigned char active;
};
__declspec(noinline) unsigned int __fastcall FUN_007845e0(struct receiver_7845e0 *receiver)
{
	if (receiver->active != 0 && receiver->vtable[14](receiver) > 0) {
		return 1;
	}
	return 0;
}
