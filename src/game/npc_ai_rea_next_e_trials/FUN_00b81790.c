/* FUN_00b81790 (same shape as FUN_00b7db50, links at +0x34): takes a node from its pool. Returns 0 while the pool is enabled (+0x20) with no storage (+0x14);
   otherwise, inside the pool's critical section (+0x30; import slots DAT_00db80cc EnterCriticalSection,
   DAT_00db80d0 LeaveCriticalSection), moves the free list's (+0x10) head to the tail of the used list (+0xc),
   links at +0x34 / +0x38, and returns it (0 when the free list is empty). The list operations are inline helpers
   taking the list head by pointer; the import calls are audited literal import-table CALLs. */
struct node_b81790 {
	unsigned char pad[0x34];
	struct node_b81790 *next;
	struct node_b81790 *prev;
};
struct pool_b81790 {
	unsigned char pad_00[0xc];
	struct node_b81790 *used;
	struct node_b81790 *free;
	void *storage;
	unsigned char pad_18[8];
	unsigned char enabled;
	unsigned char pad_21[0xf];
	unsigned char lock[24];
};
typedef void (__stdcall *critical_section_call)(void *section);
extern critical_section_call DAT_00db80cc;
extern critical_section_call DAT_00db80d0;

static __forceinline void list_remove_head(struct node_b81790 **list, struct node_b81790 *node)
{
	if (node->next == node) {
		node->next = 0;
		node->prev = 0;
		*list = 0;
		return;
	}
	*list = node->next;
	if (node->prev != 0) {
		node->prev->next = node->next;
	}
	if (node->next != 0) {
		node->next->prev = node->prev;
	}
	node->next = 0;
	node->prev = 0;
}

static __forceinline void list_append(struct node_b81790 **list, struct node_b81790 *node)
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

__declspec(noinline) struct node_b81790 *FUN_00b81790(struct pool_b81790 *pool)
{
	struct node_b81790 *node;
	if (pool->enabled != 0 && pool->storage == 0) {
		return 0;
	}
	DAT_00db80cc(pool->lock);
	node = pool->free;
	if (node == 0) {
		DAT_00db80d0(pool->lock);
		return 0;
	}
	list_remove_head(&pool->free, node);
	list_append(&pool->used, node);
	DAT_00db80d0(pool->lock);
	return node;
}
