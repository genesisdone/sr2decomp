/* FUN_0090dc00: the DAT_00e88c64 value for the first of nine bits (0..8) set both in mask and in the object's
   +0x34 word, or 0 when none is. Native takes the object in ESI and the mask in EDX. */
extern unsigned int DAT_00e88c64[];

__declspec(noinline) unsigned int FUN_0090dc00(unsigned char *object, unsigned short mask)
{
	unsigned short index;
	unsigned short bit;
	for (index = 0; index < 9; index++) {
		bit = (unsigned short)(1 << (unsigned char)index);
		if ((bit & mask) != 0 && (*(unsigned short *)(object + 0x34) & bit) != 0) {
			return DAT_00e88c64[index];
		}
	}
	return 0;
}
