/* FUN_0090fa40: true unless the object's byte +0x149 is clear, its byte +0x148 is 0x11, and either the other
   record's flags ((other[+0x34])+0x94 bit 0x80 or +0x95 bit 0x10) are set, or (float)object[+0x1120] <=
   object[+0x1124] with FUN_0096d990(object) false and byte +0x595 clear. Native takes the object in ESI and the
   other record as one stack word (caller cleans). */
char FUN_0096d990(int object);

__declspec(noinline) char FUN_0090fa40(int object, int other)
{
	int flags;
	if (*(char *)(object + 0x149) != 0) {
		return 1;
	}
	if (*(char *)(object + 0x148) != 0x11) {
		return 1;
	}
	flags = *(int *)(other + 0x34);
	if ((*(unsigned char *)(flags + 0x94) & 0x80) == 0 && (*(unsigned char *)(flags + 0x95) & 0x10) == 0) {
		if (*(float *)(object + 0x1124) < (float)*(int *)(object + 0x1120)) {
			return 1;
		}
		if (FUN_0096d990(object) != 0) {
			return 1;
		}
		if (*(char *)(object + 0x595) != 0) {
			return 1;
		}
	}
	return 0;
}
