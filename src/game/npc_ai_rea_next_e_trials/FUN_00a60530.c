/* FUN_00a60530: unless DAT_02528b48 is 1 with DAT_02528b49 clear, for an object whose +0x6c record has a +8 item
   (no bit 2 at +0x60, +0x48 not 7, +8 name not "placeholder" by FUN_00bf2770), record word +0x3c without bit
   0x800, FUN_006c6d20() not 1 and neither DAT_00e8cf80 nor DAT_00e8cf7c 3: with no +0x114 handle, a record +0x20
   of 0..3 replaces +0x6c with FUN_009435f0(+0x20, 0); with a handle, a record +0x20 of 0 replaces +0x6c with
   FUN_004a5b70(0, item+0x50, record+0x24 byte +8) and sets +0x114 to FUN_006e4660(new, 0, -1), +0x118 to 0. */
/* The mode bytes are declared volatile because native loads them into a register before comparing; whether SR2
   declared them volatile is an unconfirmed hypothesis. */
extern volatile char DAT_02528b48;
extern volatile char DAT_02528b49;
extern int DAT_00e8cf80;
extern int DAT_00e8cf7c;
extern char s_placeholder_00dda808[];
int FUN_00bf2770(char *a, char *b);
char FUN_006c6d20(void);
int FUN_009435f0(int kind, int zero);
int FUN_004a5b70(int kind, int value, unsigned char flag);
int FUN_006e4660(int record, int zero, int minus_one);

__declspec(noinline) void FUN_00a60530(int object)
{
	int item;
	int record;
	int value;
	if (DAT_02528b48 == 1 && DAT_02528b49 == 0) {
		return;
	}
	record = *(int *)(object + 0x6c);
	item = *(int *)(record + 8);
	if (item == 0 || (*(unsigned char *)(item + 0x60) & 2) != 0 || *(int *)(item + 0x48) == 7) {
		return;
	}
	if (FUN_00bf2770(*(char **)(item + 8), s_placeholder_00dda808) != 0) {
		return;
	}
	record = *(int *)(object + 0x6c);
	if ((*(unsigned short *)(record + 0x3c) & 0x800) != 0) {
		return;
	}
	if (FUN_006c6d20() == 1 || DAT_00e8cf80 == 3 || DAT_00e8cf7c == 3) {
		return;
	}
	if (*(int *)(object + 0x114) != 0) {
		if (*(int *)(record + 0x20) == 0) {
			value = *(int *)(*(int *)(record + 8) + 0x50);
			record = FUN_004a5b70(0, value, *(unsigned char *)(*(int *)(record + 0x24) + 8));
			*(int *)(object + 0x6c) = record;
			*(int *)(object + 0x114) = FUN_006e4660(record, 0, -1);
			*(int *)(object + 0x118) = 0;
		}
	} else if (*(unsigned int *)(record + 0x20) <= 3) {
		*(int *)(object + 0x6c) = FUN_009435f0(*(int *)(record + 0x20), 0);
	}
}
