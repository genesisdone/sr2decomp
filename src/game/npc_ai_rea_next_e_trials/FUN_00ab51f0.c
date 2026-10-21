/* FUN_00ab51f0: whether slot index is inside DAT_0252a0d8 slots and the 0x7d0-byte record at DAT_02fad294[index]
   has kind 4 at +0. Native takes the index in EAX. */
extern int DAT_0252a0d8;
extern unsigned char DAT_02fad294[];

static int slot_valid(int index)
{
	return index >= 0 && index < DAT_0252a0d8;
}

__declspec(noinline) unsigned char FUN_00ab51f0(int index)
{
	if (!slot_valid(index)) {
		return 0;
	}
	return *(int *)(DAT_02fad294 + index * 0x7d0) == 4;
}
