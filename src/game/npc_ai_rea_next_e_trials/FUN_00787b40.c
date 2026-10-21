/* FUN_00787b40: for slot `index` of the 0x3ac-byte table at DAT_029dc238. When `queued` is 0 the slot's state
   (+0xd8) must be 2 and becomes 3; then FUN_00968010(object, 1). When `queued` is 0 the object's byte +0x1170
   gets bit 0x80 and the slot's +0xc4 takes object[+0x44]; otherwise object[+0x44] is appended to the slot's list
   at +0xc8 (count +0xd4). object[+0xd8] takes FUN_00787450(index) if it differs; then FUN_00a61a70(object, 0).
   Native takes the object in EAX and `queued`, `index` as cdecl stack words. */
extern char DAT_029dc238[];
void __stdcall FUN_00968010(int object, char flag);
int __fastcall FUN_00787450(int index);
int FUN_00a61a70(int object, char force);

/* The two stack words (queued, index) as one struct by value, so that LTCG keeps them on the stack as natively. */
struct words_00787b40 {
	int queued;
	int index;
};

__declspec(noinline) void FUN_00787b40(int object, struct words_00787b40 words)
{
	int queued = words.queued;
	int index = words.index;
	char *slot = DAT_029dc238 + index * 0x3ac;
	int level;
	if (queued == 0) {
		if (*(int *)(slot + 0xd8) != 2) {
			return;
		}
		*(int *)(slot + 0xd8) = 3;
	}
	FUN_00968010(object, 1);
	if (queued == 0) {
		*(unsigned char *)(object + 0x1170) |= 0x80;
		*(int *)(slot + 0xc4) = *(int *)(object + 0x44);
	} else {
		*(int *)(slot + 0xc8 + *(int *)(slot + 0xd4) * 4) = *(int *)(object + 0x44);
		*(int *)(slot + 0xd4) += 1;
	}
	level = FUN_00787450(index);
	if (level != *(int *)(object + 0xd8)) {
		*(int *)(object + 0xd8) = level;
	}
	FUN_00a61a70(object, 0);
}
