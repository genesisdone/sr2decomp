/* FUN_007fb080: total of the +0x202 counts of the entries in the object's circular list (+0x1718, next at +0x21c)
   whose first word is not 0xffff, taken inside the object's critical section (+8; import slots DAT_00db80cc
   EnterCriticalSection, DAT_00db80d0 LeaveCriticalSection) with +0x24 holding the DAT_00db8080 import's result
   (a thread or tick id) for the duration; 0 for a null object. The import calls are audited literal import-table
   CALLs. */
struct entry_7fb080 {
	unsigned short id;
	unsigned char pad_02[0x200];
	unsigned short count;
	unsigned char pad_204[0x18];
	struct entry_7fb080 *next;
};
struct object_7fb080 {
	unsigned char pad_00[8];
	unsigned char lock[24];
	unsigned char pad_20[4];
	int owner;
	unsigned char pad_28[0x16f0];
	struct entry_7fb080 *entries;
};
typedef void (__stdcall *critical_section_call)(void *section);
typedef int (__stdcall *thread_call)(void);
extern critical_section_call DAT_00db80cc;
extern critical_section_call DAT_00db80d0;
extern thread_call DAT_00db8080;

__declspec(noinline) int FUN_007fb080(struct object_7fb080 *object)
{
	struct entry_7fb080 *first;
	struct entry_7fb080 *entry;
	int total;
	if (object == 0) {
		return 0;
	}
	total = 0;
	DAT_00db80cc(object->lock);
	object->owner = DAT_00db8080();
	first = object->entries;
	entry = object->entries;
	while (entry != 0) {
		if (entry->id != 0xffff) {
			total += entry->count;
		}
		entry = entry->next;
		if (entry == first) {
			break;
		}
	}
	object->owner = 0;
	DAT_00db80d0(object->lock);
	return total;
}
