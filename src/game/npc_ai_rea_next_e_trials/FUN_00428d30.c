/* FUN_00428d30 (moved from gate npc-ai-rea-next-b): true when the list at +8 (count) / +0xc (handles) has at most
   one entry or none of its handles resolves to an alert human (type 1, flags +0x80 clear of 0xb and bit 4,
   FUN_00985630 false, +0xc8 bit 0x400000 set); false when at least one does. */
extern int DAT_02149c64[];
unsigned char FUN_00985630(int object);
static __forceinline int alert_human_from_handle(unsigned int handle)
{
	int object;
	unsigned int flags;
	if (handle == 0) {
		return 0;
	}
	object = DAT_02149c64[(handle & 0xfff) * 4];
	if (object == 0 || *(unsigned int *)(object + 0x44) != handle || *(int *)(object + 0x4c) != 1) {
		return 0;
	}
	flags = *(unsigned int *)(object + 0x80);
	if ((flags & 0xb) != 0 || FUN_00985630(object) || ((unsigned char)(flags >> 4) & 1) != 0 ||
	    (*(unsigned int *)(object + 0xc8) & 0x400000) == 0) {
		return 0;
	}
	return object;
}

__declspec(noinline) unsigned char __fastcall FUN_00428d30(unsigned char *list)
{
	int total = *(int *)(list + 8);
	unsigned int *handle;
	int count;
	int i;
	if (total <= 1) {
		return 1;
	}
	count = 0;
	handle = (unsigned int *)(list + 0xc);
	for (i = 0; i < total; i++) {
		if (alert_human_from_handle(*handle) != 0) {
			count++;
		}
		handle++;
	}
	if (count <= 0) {
		return 1;
	}
	return 0;
}
