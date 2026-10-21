/* FUN_00a63140 (same shape as FUN_00a67190): finds, in the circular list at DAT_02f30b5c (next +0x120, prev +0x124), the entry whose +0xc id equals
   the key's, moves it to the tail of the list at DAT_02f30b58 and calls its vtable slot 1 (+4; runtime target
   unknown, certified only as the audited literal call chain) with 0. Nothing happens for a null key, an empty list
   or no match. Native takes the key in EDX: written as __fastcall with an unused ECX word (not a recovered
   parameter). The method takes the entry in ECX and one stack word: __fastcall with an unused EDX word (the
   loaded vtable pointer), the usual C spelling of a thiscall. */
struct entry_a63140;
typedef void (__fastcall *moved_fn)(struct entry_a63140 *self, int unused, int value);
struct entry_a63140 {
	moved_fn *vtable;
	int pad_04[2];
	int id;
	int pad_10[0x44];
	struct entry_a63140 *next;
	struct entry_a63140 *prev;
};
extern struct entry_a63140 *DAT_02f30b5c;
extern struct entry_a63140 *DAT_02f30b58;

static __forceinline void list_remove(struct entry_a63140 **list, struct entry_a63140 *entry)
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

static __forceinline void list_append(struct entry_a63140 **list, struct entry_a63140 *entry)
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

__declspec(noinline) void __fastcall FUN_00a63140(int unused, struct entry_a63140 *key)
{
	struct entry_a63140 *entry;
	struct entry_a63140 *first;
	if (key == 0) {
		return;
	}
	first = DAT_02f30b5c;
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
	list_remove(&DAT_02f30b5c, entry);
	list_append(&DAT_02f30b58, entry);
	{
		moved_fn *vtable = entry->vtable;
		vtable[1](entry, (int)vtable, 0);
	}
}
