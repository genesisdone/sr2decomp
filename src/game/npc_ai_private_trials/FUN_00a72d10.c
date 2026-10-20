/* EXE: FUN_00a72d10; complete 132-byte logical C trial. No byte-match claim before the gate. */
typedef unsigned char View;
typedef struct Node {unsigned int value;struct Node *next,*previous;} Node;
__declspec(noinline) unsigned int __cdecl FUN_00a72d10(int index,View *pool) {
 Node *node=(Node *)((unsigned int)*(Node **)(pool+8)+(unsigned int)index*12u);unsigned int value=node->value;
 node->value=0;
 if(*(Node **)(pool+0xc)==node) {if(node->next==node) {node->next=0;node->previous=0;*(Node **)(pool+0xc)=0;goto release;}*(Node **)(pool+0xc)=node->next;}
 if(node->previous)node->previous->next=node->next;if(node->next)node->next->previous=node->previous;
 node->next=0;node->previous=0;
release:
 if(!*(Node **)(pool+0x10)) {node->next=node;node->previous=node;--*(int *)pool;*(Node **)(pool+0x10)=node;return value;}
 node->previous=(*(Node **)(pool+0x10))->previous;node->next=*(Node **)(pool+0x10);
 (*(Node **)(pool+0x10))->previous->next=node;(*(Node **)(pool+0x10))->previous=node;--*(int *)pool;return value;
}
