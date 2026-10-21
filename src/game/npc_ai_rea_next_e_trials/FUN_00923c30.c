/* FUN_00923c30: slot lookup. For index <= 8 takes the entry at object+0x224+index*4; returns 0 when the index is
   above 8 or the slot is empty, FUN_009435f0(object+0x1e4 word, 1) when FUN_00922170(object, entry) accepts the
   entry, and the entry itself otherwise. Native takes the object in ECX and pops the index (ret 4): written as fastcall
   with an unused EDX word, the usual C spelling of that interface; the unused word is not a recovered parameter. */
char FUN_00922170(unsigned char *object, int entry);
int FUN_009435f0(int owner, int flag);
__declspec(noinline) int __fastcall FUN_00923c30(unsigned char *object, int unused, int index)
{
	int entry;
	if (index > 8) {
		return 0;
	}
	entry = *(int *)(object + 0x224 + index * 4);
	if (entry == 0) {
		return 0;
	}
	if (FUN_00922170(object, entry) != 0) {
		return FUN_009435f0(*(int *)(object + 0x1e4), 1);
	}
	return entry;
}
