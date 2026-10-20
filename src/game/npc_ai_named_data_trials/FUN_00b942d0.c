/* EXE: FUN_00b942d0; full 163-byte C trial. Logical inputs, fields and partial-byte returns follow native instructions; not yet certified. */
typedef unsigned char View;
typedef struct Node {struct Node *previous,*next;} Node;
extern View DAT_031a96f0[];
__declspec(noinline) unsigned char __cdecl FUN_00b942d0(View *pool,unsigned int handle) {
 unsigned int index;View *record;Node *node;
 if(!handle)return 0;index=handle&0xffff;if(index>=0x80)return 0;
 record=DAT_031a96f0+index*0x22cu;node=(Node *)record;
 if(*(unsigned int *)(record+0x224)!=handle || *(View **)(record+0x21c)!=pool)return 0;
 if(*(Node **)(pool+0xc)==node) {if(node->next==node) {node->next=0;node->previous=0;*(Node **)(pool+0xc)=0;goto release;}*(Node **)(pool+0xc)=node->next;}
 node->previous->next=node->next;node->next->previous=node->previous;node->next=0;node->previous=0;
release:
 if(!*(Node **)(pool+0x10)) {node->next=node;node->previous=node;*(Node **)(pool+0x10)=node;return 1;}
 node->previous=(*(Node **)(pool+0x10))->previous;node->next=*(Node **)(pool+0x10);
 (*(Node **)(pool+0x10))->previous->next=node;(*(Node **)(pool+0x10))->previous=node;return 1;
}
