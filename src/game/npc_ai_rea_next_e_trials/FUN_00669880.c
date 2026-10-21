/* FUN_00669880 (moved from gate npc-ai-rea-next-d; the vtable slot 11 call is an audited literal virtual CALL): when vtable slot +0x2c returns nonzero and the count at +0x1dc is below the slot count at +0x204,
   counts the non-negative entries of the int array at +0x1e4. If (slots - count_1dc - used) is positive, that many
   negative entries are set to DAT_00e843ac + 30000 (wrapped by 1800000000); if it is negative, the first
   non-negative entry is set to -1. */
struct object_00669880;
typedef char (__fastcall *check_fn)(struct object_00669880 *object);
struct object_00669880 {
	check_fn *vtable;
	char pad[0x1d8];
	int reserved;
	int pad2;
	int slots[8];
	int slot_count;
};
extern int DAT_00e843ac;

__declspec(noinline) void __fastcall FUN_00669880(struct object_00669880 *object)
{
	int count;
	int used;
	int excess;
	int remaining;
	int i;
	int value;

	if (object->vtable[0x2c / 4](object) == 0) {
		return;
	}
	count = object->slot_count;
	if (object->reserved >= count) {
		return;
	}
	excess = count - object->reserved;
	used = 0;
	for (i = 0; i < count; i++) {
		if (object->slots[i] >= 0) {
			used++;
		}
	}
	remaining = excess - used;
	if (remaining > 0) {
		for (i = 0; i < object->slot_count; i++) {
			if (object->slots[i] < 0) {
				value = DAT_00e843ac + 30000;
				object->slots[i] = value;
				if (value > 1800000000) {
					object->slots[i] = value - 1800000000;
				}
				remaining--;
				if (remaining == 0) {
					return;
				}
			}
		}
	} else if (remaining < 0) {
		for (i = 0; i < count; i++) {
			if (object->slots[i] >= 0) {
				object->slots[i] = -1;
				return;
			}
		}
	}
}
