/* FUN_00924be0: unless the three flags/handle at DAT_02528b48/49/c14 are set and FUN_0080fcf0 rejects the handle,
   stores FUN_00922130() and FUN_009220d0() into two globals, then for each of the 14 objects in the table at
   PTR_PTR_00e88b68 calls vtable slot +0x74 and stores the returned byte at +0x2a4 when it differs; if any differed,
   calls FUN_00924c70. */
/* The mode bytes are declared volatile because native loads them into a register before comparing; whether SR2
   declared them volatile is an unconfirmed hypothesis. */
typedef char (__fastcall *byte_getter)(void *object);
struct object_00924be0 {
	byte_getter *vtable;
	char pad[0x2a0];
	char cached;
};
extern volatile char DAT_02528b48;
extern volatile char DAT_02528b49;
extern int DAT_02528c14;
extern int DAT_00e88be4;
extern int DAT_025295e4;
extern struct object_00924be0 *PTR_PTR_00e88b68[14];
char __stdcall FUN_0080fcf0(int handle);
int FUN_00922130(void);
int FUN_009220d0(void);
void FUN_00924c70(void);

__declspec(noinline) void FUN_00924be0(void)
{
	struct object_00924be0 **entry;
	struct object_00924be0 *object;
	int count;
	char changed;
	char value;

	if (DAT_02528b48 == 1 && DAT_02528b49 == 1 && DAT_02528c14 != 0 && FUN_0080fcf0(DAT_02528c14) == 0) {
		return;
	}
	DAT_00e88be4 = FUN_00922130();
	DAT_025295e4 = FUN_009220d0();
	changed = 0;
	entry = PTR_PTR_00e88b68;
	count = 14;
	do {
		object = *entry;
		value = object->vtable[0x74 / 4](object);
		if (value != object->cached) {
			object->cached = value;
			changed = 1;
		}
		entry++;
		count--;
	} while (count != 0);
	if (changed) {
		FUN_00924c70();
	}
}
