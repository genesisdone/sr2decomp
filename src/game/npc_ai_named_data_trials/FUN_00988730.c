/* EXE: FUN_00988730; complete body C trial. Concrete field identities remain unestablished. */
typedef unsigned char View;
typedef struct Node { struct Node *next,*previous; unsigned int value; unsigned char pad[8]; int slot; } Node;
extern Node *DAT_02143fa0;
extern int DAT_025295c0;
__declspec(noinline) void __cdecl FUN_00988730(Node *node,View *owner) {
    Node *free_head;
    if (*(Node **)(owner+0xcf4)==node) {
        if (node->next==node) {
            node->next=0;node->previous=0;*(Node **)(owner+0xcf4)=0;
            goto release;
        }
        *(Node **)(owner+0xcf4)=node->next;
    }
    if (node->previous) node->previous->next=node->next;
    if (node->next) node->next->previous=node->previous;
    node->next=0;node->previous=0;
release:
    free_head=DAT_02143fa0;--DAT_025295c0;
    if (!free_head) {
        node->value=0;node->next=node;node->previous=node;DAT_02143fa0=node;return;
    }
    node->previous=free_head->previous;node->next=free_head;
    free_head->previous->next=node;free_head->previous=node;node->value=0;
}
