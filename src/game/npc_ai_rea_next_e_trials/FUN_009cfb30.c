/* FUN_009cfb30: runs five update steps, then FUN_009cf6c0(node, dt) for every node of the ring at DAT_0215ffc0
   (linked through +0x1160), then two more steps. Native: dt is a caller-cleaned stack float; FUN_009cf6c0 takes
   the node in ESI and dt on the stack. */
void FUN_009cfa20(void);
void FUN_004010e0(void);
void FUN_00401610(void);
void FUN_0099e270(void);
void FUN_009cdac0(void);
void FUN_009cf6c0(int node, float dt);
void FUN_009ccf20(void);
void FUN_009cd2b0(void);
extern int DAT_0215ffc0;

__declspec(noinline) void FUN_009cfb30(float dt)
{
	int node;
	FUN_009cfa20();
	FUN_004010e0();
	FUN_00401610();
	FUN_0099e270();
	FUN_009cdac0();
	node = DAT_0215ffc0;
	while (node != 0) {
		FUN_009cf6c0(node, dt);
		node = *(int *)(node + 0x1160);
		if (node == DAT_0215ffc0)
			break;
	}
	FUN_009ccf20();
	FUN_009cd2b0();
}
