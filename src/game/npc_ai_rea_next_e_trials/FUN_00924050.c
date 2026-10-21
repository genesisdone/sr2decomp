/* FUN_00924050 (moved from gate npc-ai-rea-next-a): the index of the current record comes from the DAT_0215e5bc
   receiver's vtable slot 5 (+0x14; runtime target unknown, certified only as the audited literal call chain), -1
   with no receiver. When it equals the index of the 2000-byte record DAT_0215ded0 points at (in the array at
   DAT_02fad1f8), returns the first word of the +0x24 list of DAT_02529634's +0x10 record; otherwise object+0x1f8.
   The method takes the receiver in ECX (one-parameter __fastcall, the C spelling of a thiscall). */
struct receiver_924050;
typedef int (__fastcall *index_fn)(struct receiver_924050 *self);
struct receiver_924050 {
	index_fn *vtable;
};
extern struct receiver_924050 *DAT_0215e5bc;
extern unsigned char *DAT_0215ded0;
extern unsigned char DAT_02fad1f8[];
extern unsigned char *DAT_02529634;
__declspec(noinline) int __fastcall FUN_00924050(unsigned char *object)
{
	int index;
	struct receiver_924050 *receiver = DAT_0215e5bc;
	if (receiver == 0) {
		index = -1;
	} else {
		index = receiver->vtable[5](receiver);
	}
	if (index == (int)(DAT_0215ded0 - DAT_02fad1f8) / 2000) {
		return **(int **)(*(unsigned char **)(DAT_02529634 + 0x10) + 0x24);
	}
	return *(int *)(object + 0x1f8);
}
