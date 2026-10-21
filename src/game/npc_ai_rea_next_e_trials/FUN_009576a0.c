/* FUN_009576a0: returns 0 when there is no DAT_0215e5bc object, otherwise the result of its vtable slot +0x64. */
typedef char (__fastcall *object_query)(void *object);
struct object_009576a0 {
	object_query *vtable;
};
extern struct object_009576a0 *DAT_0215e5bc;

__declspec(noinline) char FUN_009576a0(void)
{
	if (DAT_0215e5bc == 0) {
		return 0;
	}
	return DAT_0215e5bc->vtable[0x64 / 4](DAT_0215e5bc);
}
