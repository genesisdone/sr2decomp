/* FUN_008599d0: sum of vtable slot 3 (+0xc) of the object's two embedded subobjects at +4 and +0x24 for the same
   argument (runtime targets unknown, certified only as the audited literal call chains). Native is a thiscall with
   one callee-popped stack word, written as __fastcall with an unused EDX word; each subobject method is a thiscall
   with one stack word and gets the loaded method pointer as its EDX word, as native holds at those calls. */
struct sub_8599d0;
typedef int (__fastcall *count_fn)(struct sub_8599d0 *self, int unused, int argument);
struct sub_8599d0 {
	count_fn *vtable;
	int pad[7];
};
struct object_8599d0 {
	int pad_00;
	struct sub_8599d0 first;
	struct sub_8599d0 second;
};

__declspec(noinline) int __fastcall FUN_008599d0(struct object_8599d0 *object, int unused, int argument)
{
	struct sub_8599d0 *second = &object->second;
	count_fn method = object->first.vtable[3];
	int total = method(&object->first, (int)method, argument);
	{
		count_fn *vtable = second->vtable;
		return vtable[3](second, (int)vtable[3], argument) + total;
	}
}
