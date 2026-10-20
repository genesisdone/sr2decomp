/* FUN_00a72c70: whole 153-byte body, pool rings and signed wrapped address difference. */
typedef struct Node {unsigned int value;struct Node *next,*previous;} Node;
typedef struct Pool {unsigned int count,capacity;Node *base,*used,*free;} Pool;
__declspec(noinline) int __fastcall FUN_00a72c70(Pool *pool,unsigned int unused,unsigned int value) {
 Node *node;int difference;
 if(pool->count==pool->capacity)return -1;
 node=pool->free;
 if(node->next==node) {node->next=0;node->previous=0;pool->free=0;}
 else {
  pool->free=node->next;
  if(node->previous)node->previous->next=node->next;
  if(node->next)node->next->previous=node->previous;
  node->next=0;node->previous=0;
 }
 if(!pool->used) {node->next=node;node->previous=node;pool->used=node;}
 else {
  node->previous=pool->used->previous;node->next=pool->used;
  pool->used->previous->next=node;pool->used->previous=node;
 }
 node->value=value;difference=(int)((unsigned int)node-(unsigned int)pool->base);++pool->count;
 return difference/12;
}
