/* FUN_0093eb00: returns 1 when bit 1 of the player's (DAT_021703d4) +0x1164 flags is clear, or when the value lies
   within 6 of DAT_025f5b18 (fabs of the difference, rounded to a float); otherwise 0. Moved from gate
   npc-ai-rea-a (deferred there, with the comparison's sense inverted). */
double fabs(double value);
extern unsigned char *DAT_021703d4;
extern float DAT_025f5b18;

__declspec(noinline) unsigned char FUN_0093eb00(float value)
{
	float difference;
	if ((DAT_021703d4[0x1164] & 2) == 0) {
		return 1;
	}
	difference = (float)fabs(value - DAT_025f5b18);
	if (difference < 6.0f) {
		return 1;
	}
	return 0;
}
