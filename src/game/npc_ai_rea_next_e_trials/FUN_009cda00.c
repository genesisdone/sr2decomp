/* FUN_009cda00: if the object's +0xd74 handle resolves (16-byte table at DAT_02149c64, entry +0x44 == handle) to
   a type-5 record (+0x4c), FUN_00926a10(object, flag) with flag = bit 5 of the record's +0x80 set and bit 4
   clear. Otherwise, when FUN_00a7c760(object's +0x48 id) gives an index below 0x866 whose DAT_00f7aae8 entry
   exists with bit 0 of its +0x1c clear: FUN_009cd8e0(object) unless bit 5 of object[+0x80] is set. In the
   remaining cases FUN_00926a10(object, 0) unless FUN_006c6e80(object). Native takes the object in EAX. */
extern int DAT_02149c64[];
extern int DAT_00f7aae8[];
void FUN_00926a10(int object, char on);
unsigned short FUN_00a7c760(unsigned short id);
char FUN_006c6e80(int object);
void FUN_009cd8e0(int object);

__declspec(noinline) void FUN_009cda00(int object)
{
	int handle = *(int *)(object + 0xd74);
	int record;
	unsigned int index;
	char flag;
	if (handle != 0 && (record = DAT_02149c64[(handle & 0xfff) * 4]) != 0 &&
	    *(int *)(record + 0x44) == handle && *(int *)(record + 0x4c) == 5) {
		unsigned int flags = *(unsigned int *)(record + 0x80);
		if (((unsigned char)(flags >> 5) & 1) != 0 && ((unsigned char)(flags >> 4) & 1) == 0) {
			flag = 1;
		} else {
			flag = 0;
		}
		FUN_00926a10(object, flag);
		return;
	}
	index = FUN_00a7c760(*(unsigned short *)(object + 0x48));
	if (index != 0xffff && index < 0x866 && DAT_00f7aae8[index] != 0 &&
	    (*(unsigned char *)(DAT_00f7aae8[index] + 0x1c) & 1) == 0) {
		if (((unsigned char)(*(unsigned int *)(object + 0x80) >> 5) & 1) == 0) {
			FUN_009cd8e0(object);
		}
		return;
	}
	if (FUN_006c6e80(object) == 0) {
		FUN_00926a10(object, 0);
	}
}
