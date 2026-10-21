/* FUN_00b81840 (same shape as FUN_00b7dc00, links at +0x34): returns a node to its pool. Unless the pool is enabled (+0x20) with no storage (+0x14), and for a
   non-null node, inside the pool's critical section (+0x30; import slots DAT_00db80cc EnterCriticalSection,
   DAT_00db80d0 LeaveCriticalSection) moves the node from the used list (+0xc) to the tail of the free list (+0x10),
   links at +0x34 / +0x38. The list operations are inline helpers taking the list head by pointer; the import
   calls are audited literal import-table CALLs. */
struct node_b81840 {
	unsigned char pad[0x34];
	struct node_b81840 *next;
	struct node_b81840 *prev;
};
struct pool_b81840 {
	unsigned char pad_00[0xc];
	struct node_b81840 *used;
	struct node_b81840 *free;
	void *storage;
	unsigned char pad_18[8];
	unsigned char enabled;
	unsigned char pad_21[0xf];
	unsigned char lock[24];
};
typedef void (__stdcall *critical_section_call)(void *section);
extern critical_section_call DAT_00db80cc;
extern critical_section_call DAT_00db80d0;

static __forceinline void list_remove(struct node_b81840 **list, struct node_b81840 *node)
{
	if (*list == node && node->next == node) {
		node->next = 0;
		node->prev = 0;
		*list = 0;
		return;
	}
	if (*list == node) {
		*list = node->next;
	}
	if (node->prev != 0) {
		node->prev->next = node->next;
	}
	if (node->next != 0) {
		node->next->prev = node->prev;
	}
	node->next = 0;
	node->prev = 0;
}

static __forceinline void list_append(struct node_b81840 **list, struct node_b81840 *node)
{
	if (*list == 0) {
		node->next = node;
		node->prev = node;
		*list = node;
		return;
	}
	(*list)->prev->next = node;
	node->prev = (*list)->prev;
	(*list)->prev = node;
	node->next = *list;
	*list = node;
}

__declspec(noinline) void FUN_00b81840(struct pool_b81840 *pool, struct node_b81840 *node)
{
	if ((pool->enabled != 0 && pool->storage == 0) || node == 0) {
		return;
	}
	DAT_00db80cc(pool->lock);
	list_remove(&pool->used, node);
	list_append(&pool->free, node);
	DAT_00db80d0(pool->lock);
}
