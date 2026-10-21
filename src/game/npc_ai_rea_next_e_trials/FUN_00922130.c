/* FUN_00922130: walks the circular list at DAT_0217043c (next at +0x1294); returns 5
   when a node has no +0xf00 record or that record's +0x4c type is not 6, else 6. */
extern unsigned char *DAT_0217043c;
static __forceinline unsigned int crew_kind(void)
{
	unsigned char *first = DAT_0217043c;
	unsigned char *node = DAT_0217043c;
	unsigned char *record;
	while (node != 0) {
		record = *(unsigned char **)(node + 0xf00);
		if (record == 0 || *(int *)(record + 0x4c) != 6) {
			return 5;
		}
		node = *(unsigned char **)(node + 0x1294);
		if (node == first) {
			break;
		}
	}
	return 6;
}

__declspec(noinline) unsigned int __cdecl FUN_00922130(void)
{
	return crew_kind();
}
