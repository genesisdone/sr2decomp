/* FUN_00567760: picks the object's +0x1fc or +0x200 kind by the flag, asks FUN_009445b0 for a (value, extra) pair
   of that kind, then fills a ten-word block (the pair's value, up to four FUN_009435f0(kind, 0) results, four
   zeros) into object+0x2c, stores extra at +0x234, the flag at +0x204, and sets the bytes +0x54 and +0x230. */
struct pick { int value; int extra; };
struct block { int first; int items[8]; int last; };
char FUN_009445b0(int kind, struct pick *out);
int FUN_009435f0(int kind, int zero);

__declspec(noinline) char __stdcall FUN_00567760(int object, int flag)
{
	int kind;
	struct pick pick;
	struct block block;
	int i;
	int result;
	if (flag != 0) {
		kind = *(int *)(object + 0x200);
	} else {
		kind = *(int *)(object + 0x1fc);
	}
	if (FUN_009445b0(kind, &pick) == 0) {
		return 0;
	}
	block.first = pick.value;
	*(int *)(object + 0x234) = pick.extra;
	i = 0;
	do {
		if (i < 4) {
			result = FUN_009435f0(kind, 0);
			if (result != 0) {
				block.items[i] = result;
			}
		} else {
			block.items[i] = 0;
		}
		i++;
	} while (i < 8);
	*(struct block *)(object + 0x2c) = block;
	*(int *)(object + 0x204) = flag;
	*(char *)(object + 0x54) = 1;
	*(char *)(object + 0x230) = 1;
	return 1;
}
