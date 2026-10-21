/* FUN_009220d0: for kinds 0..2 counts FUN_00922060(kind); returns the first kind whose count reaches its
   threshold (1 for kind DAT_025295e0, else DAT_021603cc); otherwise the first kind with a positive count, else 0. */
int FUN_00922060(int kind);
extern int DAT_025295e0;
extern int DAT_021603cc;

__declspec(noinline) int FUN_009220d0(void)
{
	int counts[3];
	int special = DAT_025295e0;
	int need = DAT_021603cc;
	int i;
	for (i = 0; i < 3; i++) {
		int count = FUN_00922060(i);
		int threshold;
		counts[i] = count;
		threshold = need;
		if (i == special)
			threshold = 1;
		if (count >= threshold)
			return i;
	}
	for (i = 0; i < 3; i++) {
		if (counts[i] > 0)
			return i;
	}
	return 0;
}
