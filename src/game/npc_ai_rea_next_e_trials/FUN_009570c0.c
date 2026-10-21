/* FUN_009570c0: if handle names a live entry of the DAT_02149c64 table (16-byte slots, index handle & 0xfff,
   entry +0x44 == handle) whose +0x4c is 1 and byte +0x3cc is 2: FUN_009d2520(entry, 1), then store handle in the
   first empty of the eight words at object+0xc. */
extern int DAT_02149c64[];
void __stdcall FUN_009d2520(int entry, int value);

__declspec(noinline) void FUN_009570c0(int handle, int object)
{
	int entry;
	int index;
	int *slot;
	if (handle == 0) {
		return;
	}
	entry = DAT_02149c64[(handle & 0xfff) * 4];
	if (entry == 0 || *(int *)(entry + 0x44) != handle || *(int *)(entry + 0x4c) != 1 ||
	    *(char *)(entry + 0x3cc) != 2) {
		return;
	}
	FUN_009d2520(entry, 1);
	index = 0;
	slot = (int *)(object + 0xc);
	do {
		if (*slot == 0) {
			*(int *)(object + 0xc + index * 4) = handle;
			return;
		}
		index++;
		slot++;
	} while (index < 8);
}
