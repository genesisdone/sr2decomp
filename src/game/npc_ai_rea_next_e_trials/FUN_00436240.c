/* FUN_00436240: whether an npc is eligible. It must be nonzero, without the 0xb bits of its +0x80 flags,
   FUN_00985630-clear, without flag bit 4 and with bit 5, carry 0x400000 at +0xc8, pass FUN_00806720, pass
   FUN_00421430 when FUN_0098e880 holds, fail FUN_00828a00, pass FUN_006c6e80 when FUN_006c6d20 holds, and have bit
   8 of +0x103, bit 0x4000 of +0xc0 and the +0x108 word all clear. Then by its +0x149 kind (an audited byte-indexed
   local jump table): kinds 2, 4, 5, 6, 8, 11, 13 and 15 qualify; kind 20 qualifies when +0x148 is 0x97; kind 0
   qualifies unless its +0x13c byte is 1 or 2, its +0x141 byte is 1, or it is a 0x11 at +0x148 whose FUN_009149a0
   record (from the +0x2f8 handle) has bits 0x84 of its +0x34 record's +0x94 byte set; other kinds do not. */
char FUN_00985630(unsigned char *npc);
char FUN_00806720(unsigned char *npc);
char FUN_0098e880(unsigned char *npc);
unsigned char FUN_00421430(unsigned char *npc);
char FUN_00828a00(unsigned char *npc);
char FUN_006c6d20(void);
char FUN_006c6e80(int npc);
int FUN_009149a0(int handle);

__declspec(noinline) unsigned char FUN_00436240(unsigned char *npc)
{
	unsigned int flags;
	int record;
	int mode;
	if (npc != 0 && ((flags = *(unsigned int *)(npc + 0x80)) & 0xb) == 0 && FUN_00985630(npc) == 0 &&
	    ((unsigned char)(flags >> 4) & 1) == 0 && ((unsigned char)(flags >> 5) & 1) != 0 &&
	    (*(unsigned int *)(npc + 0xc8) & 0x400000) != 0 && FUN_00806720(npc) != 0 &&
	    (FUN_0098e880(npc) == 0 || FUN_00421430(npc) != 0) && FUN_00828a00(npc) == 0 &&
	    (FUN_006c6d20() == 0 || FUN_006c6e80((int)npc) != 0) && (npc[0x103] & 8) == 0 &&
	    (*(unsigned int *)(npc + 0xc0) & 0x4000) == 0 && *(int *)(npc + 0x108) == 0) {
		switch (*(signed char *)(npc + 0x149)) {
		case 2:
		case 4:
		case 5:
		case 6:
		case 8:
		case 11:
		case 13:
		case 15:
			return 1;
		case 20:
			return (unsigned char)(npc[0x148] == 0x97);
		case 0:
			mode = *(signed char *)(npc + 0x13c);
			switch (mode) {
			case 1:
			case 2:
				return 0;
			}
			if (npc[0x141] == 1) {
				return 0;
			}
			if (npc[0x148] != 0x11) {
				return 1;
			}
			record = FUN_009149a0(*(int *)(npc + 0x2f8));
			if (record == 0 || (*(unsigned char *)(*(int *)(record + 0x34) + 0x94) & 0x84) == 0) {
				return 1;
			}
			break;
		}
	}
	return 0;
}
