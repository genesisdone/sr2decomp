/* FUN_00678760: resets the object with FUN_00956080, then for each of eight 0x14-byte slots from +0x1e4 sets the
   +0x10 word to 0, the +0 word to 0xff and the +0xc word to -1, and clears the +0x2a4 word. Field purposes are
   unknown. Native is a thiscall without stack arguments, written as one-parameter __fastcall. */
struct slot_678760 {
	int id;
	int pad_04[2];
	int handle;
	int count;
};
void __fastcall FUN_00956080(unsigned char *object);

static __inline void slot_clear(struct slot_678760 *slot)
{
	slot->count = 0;
	slot->id = 0xff;
	slot->handle = -1;
}

__declspec(noinline) void __fastcall FUN_00678760(unsigned char *object)
{
	struct slot_678760 *slots;
	int i;
	FUN_00956080(object);
	slots = (struct slot_678760 *)(object + 0x1e4);
	for (i = 0; i < 8; i++) {
		slot_clear(&slots[i]);
	}
	*(int *)(object + 0x2a4) = 0;
}
