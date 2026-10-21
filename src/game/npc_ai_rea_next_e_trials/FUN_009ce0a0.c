/* FUN_009ce0a0: may `viewer` (native ECX) perceive/engage `npc` (native EAX)? Returns 0 when npc is null or the
   viewer itself, when the DAT_02528b48 mode (== 1 with DAT_02528b49 clear) requires the 0x80 flag on both and one
   lacks it, when npc's +0x80 flags have any of 0xb, when FUN_00985630 / FUN_00962f50 reject npc, when npc lacks the
   +0xc8 0x400000 flag, for the FUN_00926600 / FUN_0053c4d0 mode checks, for kind-2 (+0x3cc) npcs with the +0x1171
   flag, kind 3/0x39, or team (+0x111c) 5-6 rules through FUN_009f58d0, when FUN_009636f0(viewer) holds and the
   squared distance (FUN_00404a20) exceeds DAT_00e5c688, when FUN_0095e700 holds, for kind 0x18 with +0x595 clear,
   the FUN_00926600 / +0x1160 / FUN_00406680 rule, and when either side's team (FUN_0055f620) is flagged by
   FUN_0055fe00 (viewer's team when FUN_00963540 or FUN_0098e8a0 holds for npc or npc's team is 0; npc's team
   when FUN_0098e8a0 holds for the viewer). Otherwise 1. Field meanings are unconfirmed. The two mode bytes are
   read as volatile, which gives native's load-then-compare. */
struct word_009ce0a0 {
	int npc;
};
extern volatile unsigned char DAT_02528b48;
extern volatile unsigned char DAT_02528b49;
extern double DAT_00e5c688;
char FUN_00985630(int npc);
char FUN_00962f50(int npc);
char __fastcall FUN_00926600(int npc);
int FUN_0053c4d0(void);
char FUN_005de330(int npc);
char FUN_005eeb20(int npc);
char FUN_009f58d0(int npc);
char FUN_009636f0(int npc);
float FUN_00404a20(float *to, float *from);
char FUN_0095e700(struct word_009ce0a0 word, int viewer);
char FUN_00406680(int viewer, int npc);
char FUN_00963540(int npc);
char FUN_0098e8a0(int npc);
int FUN_0055f620(int team);
char FUN_0055fe00(int index);

static __forceinline int is_team_5_or_6(int team)
{
	switch (team) {
	case 5:
	case 6:
		return 1;
	}
	return 0;
}

__declspec(noinline) char FUN_009ce0a0(int viewer, int npc)
{
	struct word_009ce0a0 word;
	char kind;
	char flag;
	if (npc == 0 || npc == viewer) {
		return 0;
	}
	if (DAT_02528b48 == 1 && DAT_02528b49 == 0) {
		if ((*(unsigned char *)(viewer + 0x80) & 0x80) == 0 || (*(unsigned char *)(npc + 0x80) & 0x80) == 0) {
			return 0;
		}
	}
	if ((*(unsigned char *)(npc + 0x80) & 0xb) != 0) {
		return 0;
	}
	if (FUN_00985630(npc)) {
		return 0;
	}
	if (FUN_00962f50(npc)) {
		return 0;
	}
	if ((*(unsigned int *)(npc + 0xc8) & 0x400000) == 0) {
		return 0;
	}
	if (FUN_00926600(npc)) {
		if (FUN_0053c4d0() == 3 && FUN_005de330(npc)) {
			return 0;
		}
		if (FUN_0053c4d0() == 0 && FUN_005eeb20(npc)) {
			return 0;
		}
	}
	if (*(char *)(npc + 0x3cc) == 2) {
		if ((*(unsigned char *)(npc + 0x1171) & 2) != 0) {
			return 0;
		}
		if (*(char *)(npc + 0x149) == 3 && *(char *)(npc + 0x148) == 0x39) {
			return 0;
		}
		if (is_team_5_or_6(*(signed char *)(viewer + 0x111c)) && FUN_009f58d0(npc)) {
			return 0;
		}
		if (FUN_009f58d0(viewer) && is_team_5_or_6(*(signed char *)(npc + 0x111c))) {
			return 0;
		}
	}
	if (FUN_009636f0(viewer) && FUN_00404a20((float *)(npc + 0x14), (float *)(viewer + 0x14)) > DAT_00e5c688) {
		return 0;
	}
	word.npc = npc;
	if (FUN_0095e700(word, viewer)) {
		return 0;
	}
	kind = *(char *)(npc + 0x149);
	if (kind == 0x18 && *(char *)(npc + 0x595) == 0) {
		return 0;
	}
	if (FUN_00926600(npc)) {
		if ((*(unsigned char *)(npc + 0x1160) & 2) != 0) {
			return 0;
		}
		if (viewer != 0) {
			flag = FUN_00406680(viewer, npc);
		} else {
			flag = (*(unsigned char *)(npc + 0x1163) >> 6) & 1;
		}
		if (flag) {
			return 0;
		}
	} else if (kind == 3) {
		return 0;
	}
	if (FUN_00963540(npc) || FUN_0098e8a0(npc) || *(char *)(npc + 0x111c) == 0) {
		if (FUN_0055fe00(FUN_0055f620(*(signed char *)(viewer + 0x111c)))) {
			return 0;
		}
	}
	if (FUN_0098e8a0(viewer) && FUN_0055fe00(FUN_0055f620(*(signed char *)(npc + 0x111c)))) {
		return 0;
	}
	return 1;
}
