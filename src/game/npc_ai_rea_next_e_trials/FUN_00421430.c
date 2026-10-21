/* FUN_00421430: true for a person flagged 0x10 at +0x104, otherwise whether its distance measure to its owner
   (FUN_0098e7c0; 0 when it is its own owner, else FUN_00bdea30 on the two +0x14 positions) is within the product of
   two range factors - each DAT_00dd0740 while the DAT_027b3c60 state is active (+0x3c == 1) and its +0x90
   receiver's vtable slot 1 (+4; runtime target unknown, certified only as the audited literal call chain) reports
   13, else DAT_00e1d904. The method takes the receiver in ECX: __fastcall with an unused EDX word (the loaded
   vtable pointer), the usual C spelling of a thiscall. */
struct receiver_421430;
typedef int (__fastcall *mode_fn)(struct receiver_421430 *self, int unused);
struct receiver_421430 {
	mode_fn *vtable;
};
extern unsigned char *DAT_027b3c60;
extern float DAT_00dd0740;
extern float DAT_00e1d904;
int FUN_0098e7c0(int npc);
float FUN_00bdea30(float *to, float *from);

static __forceinline int in_mode_13(void)
{
	unsigned char *state = DAT_027b3c60;
	if (state != 0 && *(int *)(state + 0x3c) == 1) {
		struct receiver_421430 *receiver = *(struct receiver_421430 **)(state + 0x90);
		mode_fn *vtable = receiver->vtable;
		if (vtable[1](receiver, (int)vtable) == 13) {
			return 1;
		}
	}
	return 0;
}

__declspec(noinline) unsigned char FUN_00421430(unsigned char *person)
{
	int owner;
	float distance;
	float first;
	float second;
	if ((person[0x104] & 0x10) == 0) {
		owner = FUN_0098e7c0((int)person);
		if (owner != (int)person) {
			distance = FUN_00bdea30((float *)(person + 0x14), (float *)(owner + 0x14));
		} else {
			distance = 0.0f;
		}
		first = !in_mode_13() ? DAT_00e1d904 : DAT_00dd0740;
		second = !in_mode_13() ? DAT_00e1d904 : DAT_00dd0740;
		if (distance > second * first) {
			return 0;
		}
	}
	return 1;
}
