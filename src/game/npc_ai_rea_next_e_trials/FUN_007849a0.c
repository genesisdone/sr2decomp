/* FUN_007849a0 (moved from gate npc-ai-rea-a-named-data): for each tracked entry of DAT_021703d4 (count +0xc3c,
   0x18-byte entries from +0xc40) resolves the handle to its type-1 object whose +0x3cc byte is 2 (else 0) and
   sets bit 25 of that object's +0xc8 flags to the input's low bit; a failed lookup writes through address
   0 + 0xc8 as native does. Entry fields past the handle are not established. */
struct tracked {
	unsigned int handle;
	int rest[5];
};
struct manager {
	unsigned char pad[0xc3c];
	unsigned int count;
	struct tracked entries[1];
};
extern struct manager *DAT_021703d4;
extern int DAT_02149c64[];
static __forceinline int object_of_type(unsigned int handle, int type)
{
	int object;
	if (handle == 0) {
		return 0;
	}
	object = DAT_02149c64[(handle & 0xfff) * 4];
	if (object == 0 || *(unsigned int *)(object + 0x44) != handle || *(int *)(object + 0x4c) != type) {
		return 0;
	}
	return object;
}

static __forceinline int mode_2_human(unsigned int handle)
{
	int object = object_of_type(handle, 1);
	if (object == 0) {
		return 0;
	}
	return *(char *)(object + 0x3cc) == 2 ? object : 0;
}

__declspec(noinline) void FUN_007849a0(unsigned int input)
{
	unsigned int i;
	int object;
	for (i = 0; i < DAT_021703d4->count; i++) {
		object = mode_2_human(DAT_021703d4->entries[i].handle);
		*(unsigned int *)(object + 0xc8) = (*(unsigned int *)(object + 0xc8) & 0xfdffffff) | ((input & 1) << 25);
	}
}
