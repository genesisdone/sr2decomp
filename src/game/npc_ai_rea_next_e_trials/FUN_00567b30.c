/* FUN_00567b30: when the timer object+0x1e4 has been reached on the ms clock DAT_00e843ac and byte +0x1f4 is 1, or
   when byte +0x1f5 is 1: if FUN_00567900(object) is 1 or byte +0x1f5 is 1, calls FUN_005679c0(object) unless the
   state +0x1f0 is 2; otherwise re-arms the timer 300,000 ms ahead. Native takes the object in ESI. */
extern int DAT_00e843ac;
char __stdcall FUN_00567900(int object);
void FUN_005679c0(int object);

__declspec(noinline) void FUN_00567b30(int object)
{
	int now = DAT_00e843ac;
	int when = *(int *)(object + 0x1e4);
	if (when >= 0) {
		if (when > now) {
			if (when - now < 900000000) {
				goto check;
			}
			goto reached;
		} else if (now - when < 900000000) {
			goto reached;
		}
	}
	goto check;
reached:
	if (*(char *)(object + 0x1f4) == 1) {
		goto act;
	}
check:
	if (*(char *)(object + 0x1f5) != 1) {
		return;
	}
act:
	if (FUN_00567900(object) == 1 || *(char *)(object + 0x1f5) == 1) {
		if (*(int *)(object + 0x1f0) != 2) {
			FUN_005679c0(object);
		}
		return;
	}
	when = now + 300000;
	*(int *)(object + 0x1e4) = when;
	if (when > 1800000000) {
		*(int *)(object + 0x1e4) = when - 1800000000;
	}
}
