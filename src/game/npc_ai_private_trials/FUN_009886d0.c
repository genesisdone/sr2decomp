/* EXE: FUN_009886d0; complete body C trial. Concrete field identities remain unestablished. */
typedef unsigned char View;
typedef struct Node { struct Node *next,*previous; unsigned int value; unsigned char pad[8]; int slot; } Node;
__declspec(noinline) void __cdecl FUN_009886d0(Node *node,View *owner) {
    if (*(Node **)(owner+0xcf4)==node) {
        if (node->next==node) {
            node->next=0;node->previous=0;*(Node **)(owner+0xcf4)=0;return;
        }
        *(Node **)(owner+0xcf4)=node->next;
    }
    if (node->previous) node->previous->next=node->next;
    if (node->next) node->next->previous=node->previous;
    node->next=0;node->previous=0;
}
