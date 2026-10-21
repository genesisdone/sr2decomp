/* FUN_00a67190: finds, in the circular list at DAT_02f369d4 (next +0x44, prev +0x48), the entry whose +0xc id equals
   the key's, moves it to the tail of the list at DAT_02f369d0 and calls its vtable slot 1 (+4; runtime target
   unknown, certified only as the audited literal call chain) with 0. Nothing happens for a null key, an empty list
   or no match. Native takes the key in EDX: written as __fastcall with an unused ECX word (not a recovered
   parameter). The method takes the entry in ECX and one stack word: __fastcall with an unused EDX word (the
   loaded vtable pointer), the usual C spelling of a thiscall. */
struct entry_a67190;
typedef void (__fastcall *moved_fn)(struct entry_a67190 *self, int unused, int value);
struct entry_a67190 {
	moved_fn *vtable;
	int pad_04[2];
	int id;
	int pad_10[13];
	struct entry_a67190 *next;
	struct entry_a67190 *prev;
};
extern struct entry_a67190 *DAT_02f369d4;
extern struct entry_a67190 *DAT_02f369d0;

static __forceinline void list_remove(struct entry_a67190 **list, struct entry_a67190 *entry)
{
	if (*list == entry && entry->next == entry) {
		entry->next = 0;
		entry->prev = 0;
		*list = 0;
		return;
	}
	if (*list == entry) {
		*list = entry->next;
	}
	if (entry->prev != 0) {
		entry->prev->next = entry->next;
	}
	if (entry->next != 0) {
		entry->next->prev = entry->prev;
	}
	entry->next = 0;
	entry->prev = 0;
}

static __forceinline void list_append(struct entry_a67190 **list, struct entry_a67190 *entry)
{
	if (*list == 0) {
		entry->next = entry;
		entry->prev = entry;
		*list = entry;
		return;
	}
	entry->prev = (*list)->prev;
	entry->next = *list;
	(*list)->prev->next = entry;
	(*list)->prev = entry;
}

__declspec(noinline) void __fastcall FUN_00a67190(int unused, struct entry_a67190 *key)
{
	struct entry_a67190 *entry;
	struct entry_a67190 *first;
	if (key == 0) {
		return;
	}
	first = DAT_02f369d4;
	entry = first;
	while (entry != 0) {
		if (entry->id == key->id) {
			break;
		}
		entry = entry->next;
		if (entry == first) {
			return;
		}
	}
	if (entry == 0) {
		return;
	}
	list_remove(&DAT_02f369d4, entry);
	list_append(&DAT_02f369d0, entry);
	{
		moved_fn *vtable = entry->vtable;
		vtable[1](entry, (int)vtable, 0);
	}
}
