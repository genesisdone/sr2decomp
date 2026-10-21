/* FUN_00a60110: builds a 0x6b message (after a one-byte gap when DAT_00e8bc14 is set) holding the byte 0x0c and the
   object's +0xc word, with its payload length at +1, and sends it with FUN_00814740 on the connection DAT_02528c14.
   Native keeps a /GS cookie for the message buffer. */
struct object_00a60110 {
	int pad[3];
	int id;
};
extern char DAT_00e8bc14;
extern void *DAT_02528c14;
void FUN_00814740(void *connection, unsigned char *buffer, unsigned int length);

__declspec(noinline) void FUN_00a60110(struct object_00a60110 *object)
{
	unsigned char message[0x514];
	unsigned short length;
	message[0] = 0x6b;
	length = 3;
	if (DAT_00e8bc14 != 0) {
		length = 4;
	}
	message[length] = 0x0c;
	length += 1;
	*(int *)(message + length) = object->id;
	length += 4;
	*(unsigned short *)(message + 1) = (unsigned short)(length - 3);
	FUN_00814740(DAT_02528c14, message, length);
}
