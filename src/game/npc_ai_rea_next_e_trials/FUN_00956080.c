/* FUN_00956080: clears the record: flag bytes +0x54..+0x56, the words +0x2c..+0x50 and +0x4..+0x28 and the
   0x180-byte block at +0x5c (FUN_00ca0bc0, memset; an address-only boundary). */
extern void * __cdecl FUN_00ca0bc0(void *destination, int byte_value, unsigned size);
struct record {
	int head;
	int words_a[9];
	int word_28;
	int words_b[10];
	unsigned char flag_54;
	unsigned char flag_55;
	unsigned char flag_56;
	unsigned char pad_57[5];
	unsigned char block[0x180];
};
__declspec(noinline) void __fastcall FUN_00956080(struct record *object)
{
	int i;
	object->flag_55 = 0;
	object->flag_56 = 0;
	object->flag_54 = 0;
	for (i = 0; i < 10; i++) {
		object->words_b[i] = 0;
	}
	for (i = 0; i < 9; i++) {
		object->words_a[i] = 0;
	}
	object->word_28 = 0;
	FUN_00ca0bc0(object->block, 0, 0x180);
}
