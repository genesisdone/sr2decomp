/* Moved from gate npc-ai-rea-next-d; the vtable slot 11 call is an audited literal virtual CALL. FUN_00679010: if the object's virtual slot +0x2c answers nonzero and object[0x77] < count object[0xa9],
   computes how many timers object[0xa1 ..] should be armed (count - object[0x77], one fewer when DAT_027a5eac
   is set and DAT_027a5ec4 is 1 or 2, minus the timers already non-negative). A positive shortfall arms that
   many negative timers at clock DAT_00e843ac + object[0xaa], wrapped into 0..1,800,000,000; a negative one
   disarms (sets -1) the first non-negative timer. */
typedef char (__fastcall *object_test)(int *object);
extern int DAT_00e843ac;
extern int DAT_027a5eac;
extern int DAT_027a5ec4;

static __forceinline void timer_set(int *timer, int ms)
{
	int value;
	if (ms >= 0) {
		value = DAT_00e843ac + ms;
		*timer = value;
		if (value > 1800000000) {
			*timer = value - 1800000000;
		}
	} else {
		value = DAT_00e843ac + ms;
		*timer = value;
		if (value < 0) {
			*timer = value + 1800000000;
		}
	}
}

__declspec(noinline) void __fastcall FUN_00679010(int *object)
{
	int count;
	int wanted;
	int armed;
	int shortfall;
	int index;
	int *timer;
	int when;
	if (((object_test)(*(int **)object)[0xb])(object) == 0) {
		return;
	}
	count = object[0xa9];
	if (object[0x77] >= count) {
		return;
	}
	wanted = count - object[0x77];
	if (DAT_027a5eac != 0 && (DAT_027a5ec4 == 1 || DAT_027a5ec4 == 2)) {
		wanted = wanted - 1;
	}
	armed = 0;
	if (count > 0) {
		timer = object + 0xa1;
		index = count;
		do {
			if (*timer >= 0) {
				armed = armed + 1;
			}
			timer = timer + 1;
			index = index - 1;
		} while (index != 0);
	}
	shortfall = wanted - armed;
	if (shortfall > 0) {
		index = 0;
		if (count > 0) {
			timer = object + 0xa1;
			do {
				if (*timer < 0) {
					timer_set(timer, object[0xaa]);
					shortfall = shortfall - 1;
					if (shortfall == 0) {
						return;
					}
				}
				index = index + 1;
				timer = timer + 1;
			} while (index < object[0xa9]);
		}
	} else if (shortfall < 0) {
		for (index = 0; index < count; index = index + 1) {
			if (object[index + 0xa1] >= 0) {
				object[index + 0xa1] = -1;
				return;
			}
		}
	}
}
