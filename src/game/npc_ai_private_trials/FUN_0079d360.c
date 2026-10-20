/* EXE: FUN_0079d360; complete 73-byte logical C trial. Partial AL returns retain native upper EAX where present; private ABI uncertified. */
typedef struct Node {struct Node *next,*previous;} Node;
__declspec(noinline) void __cdecl FUN_0079d360(Node *node,Node **head) {
 if(node) {if(*head==node) {if(node->next==node) {node->next=0;node->previous=0;*head=0;return;}*head=node->next;}
 if(node->previous)node->previous->next=node->next;
 if(node->next)node->next->previous=node->previous;
 node->next=0;node->previous=0;}
}
