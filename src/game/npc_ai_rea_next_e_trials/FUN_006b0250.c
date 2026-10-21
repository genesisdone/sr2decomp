/* FUN_006b0250 (the allocator call is an audited literal virtual CALL; same shape as FUN_006b0250): when the pool is enabled (+0x20) and has no block yet (+0x14), takes its capacity (+0x18) from
   *(+0x24) * (+0x28) and its allocator (+0x1c) from *(+0x2c) when those are set, allocates capacity * 0x18 bytes
   through allocator vtable slot +0x1c (size, 0), clears +0xc and +0x10, links every 0x18-byte node into a circular
   list through its +0x10/+0x14 fields with +0x10 as the tail, and sets the ready flag at +0x21.
   The allocator call is a thiscall with two stack arguments; it is written as __fastcall with the called function
   pointer passed for the EDX slot, which is the register native calls through. */
struct node_006b0250 {
	char pad[0x10];
	struct node_006b0250 *prev;
	struct node_006b0250 *next;
};
struct allocator_006b0250;
typedef char *(__fastcall *allocate_fn)(struct allocator_006b0250 *allocator, void *edx_value, int size, int flags);
struct allocator_006b0250 {
	allocate_fn *vtable;
};
struct pool_006b0250 {
	char pad[0xc];
	int used;
	struct node_006b0250 *tail;
	char *block;
	unsigned int capacity;
	struct allocator_006b0250 *allocator;
	char enabled;
	char ready;
	char pad2[2];
	int *count_source;
	int multiplier;
	struct allocator_006b0250 **allocator_source;
};

__declspec(noinline) void __fastcall FUN_006b0250(struct pool_006b0250 *pool)
{
	unsigned int i;
	int offset;
	int capacity;
	struct node_006b0250 *node;

	if (pool->enabled == 0 || pool->block != 0) {
		return;
	}
	if (pool->count_source != 0) {
		pool->capacity = pool->multiplier * *pool->count_source;
	}
	if (pool->allocator_source != 0 && *pool->allocator_source != 0) {
		pool->allocator = *pool->allocator_source;
	}
	capacity = pool->capacity;
	{
		allocate_fn allocate = pool->allocator->vtable[0x1c / 4];
		pool->block = allocate(pool->allocator, (void *)allocate, capacity * 0x18, 0);
	}
	pool->used = 0;
	pool->tail = 0;
	for (i = 0; i < pool->capacity; i++) {
		offset = i * 0x18;
		if (pool->tail == 0) {
			node = (struct node_006b0250 *)(pool->block + offset);
			node->prev = node;
			node = (struct node_006b0250 *)(pool->block + offset);
			node->next = node;
		} else {
			pool->tail->next->prev = (struct node_006b0250 *)(pool->block + offset);
			((struct node_006b0250 *)(pool->block + offset))->next = pool->tail->next;
			pool->tail->next = (struct node_006b0250 *)(pool->block + offset);
			((struct node_006b0250 *)(pool->block + offset))->prev = pool->tail;
		}
		pool->tail = (struct node_006b0250 *)(pool->block + offset);
	}
	pool->ready = 1;
}
