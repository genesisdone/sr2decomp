/* FUN_0045d2c0: whether npc may act on other: npc's +0xd74 handle must be 0 or other's +0x44 handle, its +0x595
   byte clear, and its +0x149 kind not 3, 7, 10, 19 or 24 (an audited byte-indexed local jump table); when owner is
   nonzero, a resolved FUN_0043a620 object must carry it at +0x44; finally the FUN_00bdea30 measure between the
   two +0x14 positions must not exceed DAT_00e5c190. */
extern double DAT_00e5c190;
unsigned char *FUN_0043a620(unsigned char *npc);
float FUN_00bdea30(float *to, float *from);

/* The stack word (other) as a one-member struct by value, so that LTCG keeps it on the stack as natively. */
struct word_0045d2c0 {
	unsigned char *other;
};

__declspec(noinline) unsigned char FUN_0045d2c0(unsigned char *npc, int owner, struct word_0045d2c0 word)
{
	unsigned char *other = word.other;
	unsigned char *resolved;
	if (*(int *)(npc + 0xd74) != 0 && *(int *)(npc + 0xd74) != *(int *)(other + 0x44)) {
		return 0;
	}
	if (npc[0x595] != 0) {
		return 0;
	}
	switch (*(signed char *)(npc + 0x149)) {
	case 3:
	case 7:
	case 10:
	case 19:
	case 24:
		return 0;
	}
	if (owner != 0) {
		resolved = FUN_0043a620(npc);
		if (resolved != 0 && *(int *)(resolved + 0x44) != owner) {
			return 0;
		}
	}
	if (FUN_00bdea30((float *)(other + 0x14), (float *)(npc + 0x14)) > DAT_00e5c190) {
		return 0;
	}
	return 1;
}
