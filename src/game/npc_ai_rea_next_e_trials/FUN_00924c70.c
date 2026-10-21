/* FUN_00924c70: builds a 0x71 message holding the 14-bit mask of the PTR_PTR_00e88b68 objects whose +0x2a4 flag is
   set (after a one-byte gap when DAT_00e8bca4 is set), with its payload length at +1, and sends it with
   FUN_00814740 on the connection DAT_02528c14. Native keeps a /GS cookie for the message buffer. */
extern unsigned char *PTR_PTR_00e88b68[14];
extern char DAT_00e8bca4;
extern void *DAT_02528c14;
void FUN_00814740(void *connection, unsigned char *buffer, unsigned int length);

__declspec(noinline) void FUN_00924c70(void)
{
	unsigned char message[0x514];
	unsigned int mask;
	int index;
	unsigned short length;
	mask = 0;
	for (index = 0; index < 14; index++) {
		if (PTR_PTR_00e88b68[index][0x2a4] != 0) {
			mask |= 1 << index;
		}
	}
	message[0] = 0x71;
	length = 3;
	if (DAT_00e8bca4 != 0) {
		length = 4;
	}
	*(unsigned short *)(message + length) = (unsigned short)mask;
	length += 2;
	*(unsigned short *)(message + 1) = (unsigned short)(length - 3);
	FUN_00814740(DAT_02528c14, message, length);
}
