/* FUN_006afd80 (moved from gate npc-ai-rea-next-a): free bytes of a pool allocator: its vtable slot 1 (+4)
   total less slot 3 (+0xc) used count times the element size at +0x18 (runtime targets unknown, certified only as
   the audited literal call chains). Methods take the receiver in ECX (one-parameter __fastcall, the C spelling of
   a thiscall). */
struct allocator_6afd80;
typedef int (__fastcall *size_fn)(struct allocator_6afd80 *self);
struct allocator_6afd80 {
	size_fn *vtable;
	int pad[5];
	int element_size;
};
__declspec(noinline) int __fastcall FUN_006afd80(struct allocator_6afd80 *allocator)
{
	int used = allocator->vtable[3](allocator) * allocator->element_size;
	return allocator->vtable[1](allocator) - used;
}
