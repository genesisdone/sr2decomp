/* FUN_00955b10 (moved from gate npc-ai-rea-next-a): returns the first of ids 2, 3, 8 whose receiver in DAT_0215e578
   answers true (1) to its vtable slot 11 (+0x2c; runtime target unknown, certified only as the audited literal call
   chain), else -1. The method takes the receiver in ECX (one-parameter __fastcall, the C spelling of a thiscall). */
struct receiver_955b10;
typedef unsigned char (__fastcall *check_fn)(struct receiver_955b10 *self);
struct receiver_955b10 {
	check_fn *vtable;
};
extern struct receiver_955b10 *DAT_0215e578[];
__declspec(noinline) int FUN_00955b10(void)
{
	int choices[3] = {2, 3, 8};
	int i;
	for (i = 0; i < 3; i++) {
		int id = choices[i];
		struct receiver_955b10 *receiver = DAT_0215e578[id];
		if (receiver->vtable[11](receiver) == 1) {
			return id;
		}
	}
	return -1;
}
