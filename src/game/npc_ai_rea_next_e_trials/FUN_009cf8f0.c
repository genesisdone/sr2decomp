/* FUN_009cf8f0: unless bit 4 of the human's +0x80 flags is set, runs FUN_009a9010 and FUN_009c1b90 on it; then, for
   a human with flag 4 of byte +0x1170 and without bit 0x800 of +0xc8: when FUN_00806720 rejects it, calls
   FUN_00926860(human, 1, 1, 1); otherwise, when bit 1 of byte +0x11c7 is set, arms the timer +0x11a4 with
   FUN_00bdd100 for its duration +0x11cc (900,000 ms when that is -1), or when bit 2 is set arms it 600,000 ms
   ahead (wrapping at 1,800,000,000), and calls FUN_00926860(human, 1, 1, 0); when neither bit is set, a human with
   +0x1178 set calls FUN_00926860(human, 1, 1, 0) and FUN_00559d40(human + 0x10c4, 0), any other calls its vtable
   slot 4 (+0x10) with 0. The slot-4 call passes the vtable pointer as the unused EDX word, as native loads it
   there. Native takes the human in ESI. The slot-4 method is a thiscall with one stack word,
   written as __fastcall with an unused EDX word; FUN_00559d40 pops its one stack word (declared __stdcall). */
struct human_009cf8f0;
typedef void (__fastcall *human_method)(struct human_009cf8f0 *human, int unused, int value);
struct human_009cf8f0 {
	human_method *vtable;
	char pad04[0x7c];
	unsigned int flags80;
};
extern int DAT_00e843ac;
void FUN_009a9010(struct human_009cf8f0 *human);
void FUN_009c1b90(struct human_009cf8f0 *human);
char FUN_00806720(struct human_009cf8f0 *human);
void FUN_00926860(struct human_009cf8f0 *human, unsigned char first, unsigned char second, unsigned char skip);
void FUN_00bdd100(int *timer, int duration);
void __stdcall FUN_00559d40(void *self, unsigned char value);

#define HUMAN_BYTE(h, o) (*((unsigned char *)(h) + (o)))
#define HUMAN_WORD(h, o) (*(int *)((unsigned char *)(h) + (o)))

static char human_is_inactive(struct human_009cf8f0 *human)
{
	return (char)((human->flags80 >> 4) & 1);
}

__declspec(noinline) void FUN_009cf8f0(struct human_009cf8f0 *human)
{
	unsigned char flags;
	int duration;
	int when;
	human_method method;
	if (human_is_inactive(human)) {
		return;
	}
	FUN_009a9010(human);
	FUN_009c1b90(human);
	if ((HUMAN_BYTE(human, 0x1170) & 4) == 0 || (HUMAN_WORD(human, 0xc8) & 0x800) != 0) {
		return;
	}
	if (FUN_00806720(human) == 0) {
		FUN_00926860(human, 1, 1, 1);
		return;
	}
	flags = HUMAN_BYTE(human, 0x11c7);
	if ((flags & 2) != 0) {
		duration = HUMAN_WORD(human, 0x11cc);
		if (duration == -1) {
			duration = 900000;
		}
		FUN_00bdd100(&HUMAN_WORD(human, 0x11a4), duration);
	} else if ((flags & 4) != 0) {
		when = DAT_00e843ac + 600000;
		HUMAN_WORD(human, 0x11a4) = when;
		if (when > 1800000000) {
			HUMAN_WORD(human, 0x11a4) = when - 1800000000;
		}
	} else {
		if (HUMAN_WORD(human, 0x1178) != 0) {
			FUN_00926860(human, 1, 1, 0);
			FUN_00559d40((unsigned char *)human + 0x10c4, 0);
			return;
		}
		method = human->vtable[0x10 / 4];
		method(human, (int)human->vtable, 0);
		return;
	}
	FUN_00926860(human, 1, 1, 0);
}
