/* FUN_004350e0: true when the person is flagged 0x18 at +0x11c6, its +0xd4 record has flag 0x10 at +0x3c, it is
   flagged 0x50 at +0x100, or its +0x141 kind is 3..9 or 11; false for kinds 0..2, 10 and anything else. The switch
   is an audited local jump table with a byte index table. */
__declspec(noinline) unsigned char FUN_004350e0(unsigned char *person)
{
	unsigned char *record;
	if ((person[0x11c6] & 0x18) == 0) {
		record = *(unsigned char **)(person + 0xd4);
		if (record == 0 || (record[0x3c] & 0x10) == 0) {
			if ((person[0x100] & 0x50) == 0) {
				switch ((signed char)person[0x141]) {
				case 0: case 1: case 2: case 10:
					return 0;
				case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 11:
					break;
				default:
					return 0;
				}
			}
		}
	}
	return 1;
}
