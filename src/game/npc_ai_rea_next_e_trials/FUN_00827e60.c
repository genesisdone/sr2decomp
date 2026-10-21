/* FUN_00827e60: for a non-NULL object, builds a 0x77 message (after a one-byte gap when DAT_00e8bd34 is set) holding
   the byte 1 and the 16-bit value, with its payload length at +1, and sends it to that peer with FUN_00814670. Native
   takes the object in ECX and the value as a caller-cleaned stack word, and keeps a /GS cookie for the message
   buffer. */
extern char DAT_00e8bd34;
void FUN_00814670(void *peer, unsigned char *buffer, unsigned int length, int a, int b);

__declspec(noinline) void FUN_00827e60(void *object, unsigned short value)
{
	unsigned char message[0x514];
	unsigned short length;
	if (object == 0) {
		return;
	}
	message[0] = 0x77;
	length = 3;
	if (DAT_00e8bd34 != 0) {
		length = 4;
	}
	message[length] = 1;
	length += 1;
	*(unsigned short *)(message + length) = value;
	length += 2;
	*(unsigned short *)(message + 1) = (unsigned short)(length - 3);
	FUN_00814670(object, message, length, 0, 0);
}
