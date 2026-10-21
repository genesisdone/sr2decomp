/* FUN_00859620: forwards (first, second+0x40, 0) to vtable slot 1 (+4) of the object's embedded subobject at +4
   (runtime target unknown, certified only as the audited literal call chain), then calls FUN_008517a0(0, second). Native
   is a thiscall with three callee-popped stack words (the third unused), written as __fastcall with an unused EDX
   word - the usual C spelling; the subobject's method is a thiscall with three stack words and gets the first
   argument as its EDX word, which is what native holds in EDX at that call. */
struct sub_859620;
typedef void (__fastcall *forward_fn)(struct sub_859620 *self, int unused, int first, unsigned char *second, int flags);
struct sub_859620 {
	forward_fn *vtable;
};
struct object_859620 {
	int pad_00;
	struct sub_859620 sub;
};
void FUN_008517a0(int value, unsigned char *record);

__declspec(noinline) void __fastcall FUN_00859620(struct object_859620 *object, int unused, int first, unsigned char *second, int third)
{
	forward_fn method = object->sub.vtable[1];
	method(&object->sub, first, first, second + 0x40, 0);
	FUN_008517a0(0, second);
}
