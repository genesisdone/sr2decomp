/* FUN_008595e0: forwards (first, second+0x40, 0, fourth+0x40) to vtable slot 0 of the object's embedded subobject at
   +4 (runtime target unknown, certified only as the audited literal call chain), calls FUN_008517a0(0, fourth) and
   sets fourth's +0x3c byte. Native is a thiscall with four callee-popped stack words (the third unused), written
   as __fastcall with an unused EDX word; the subobject's method gets the first argument as its EDX word, which is
   what native holds in EDX at that call. */
struct sub_8595e0;
typedef void (__fastcall *forward_fn)(struct sub_8595e0 *self, int unused, int first, unsigned char *second, int flags,
                                      unsigned char *fourth);
struct sub_8595e0 {
	forward_fn *vtable;
};
struct object_8595e0 {
	int pad_00;
	struct sub_8595e0 sub;
};
void FUN_008517a0(int value, unsigned char *record);

__declspec(noinline) void __fastcall FUN_008595e0(struct object_8595e0 *object, int unused, int first, unsigned char *second,
                                                  int third, unsigned char *fourth)
{
	forward_fn method = object->sub.vtable[0];
	method(&object->sub, first, first, second + 0x40, 0, fourth + 0x40);
	FUN_008517a0(0, fourth);
	fourth[0x3c] = 1;
}
