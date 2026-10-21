/* FUN_00806b40: for a non-null object whose +0xb0 record is absent, or no player record exists at
   DAT_02528c14->+0x408, or the record's first byte equals that player's +0x1b0 byte with bit 1 of +0x67c clear:
   if FUN_00806d50(object) succeeds, FUN_00806910(object, argument, 0). */
extern int DAT_02528c14;
char FUN_00806d50(int object);
void FUN_00806910(int object, int argument, int zero);

__declspec(noinline) void FUN_00806b40(int object, int argument)
{
	char *record;
	int player;
	if (object == 0) {
		return;
	}
	record = *(char **)(object + 0xb0);
	if (record != 0 && DAT_02528c14 != 0) {
		player = *(int *)(DAT_02528c14 + 0x408);
		if (player != 0) {
			if (*record != *(char *)(player + 0x1b0)) {
				return;
			}
			if ((record[0x67c] & 1) != 0) {
				return;
			}
		}
	}
	if (FUN_00806d50(object) != 0) {
		FUN_00806910(object, argument, 0);
	}
}
