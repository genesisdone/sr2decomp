/* FUN_0090d110: returns 1 while fewer than the limit of the six counters DAT_0213f82c..DAT_0213f854 (stride 8) are
   positive; the limit is 6, or 3 when both mode bytes are 1 and DAT_021603cc is 2. Moved from gate npc-ai-rea-a
   (deferred there). */
/* The mode bytes are declared volatile because native loads them into a register before comparing; whether SR2
   declared them volatile is an unconfirmed hypothesis. */
extern int DAT_0213f82c, DAT_0213f834, DAT_0213f83c;
extern int DAT_0213f844, DAT_0213f84c, DAT_0213f854, DAT_021603cc;
extern volatile unsigned char DAT_02528b48, DAT_02528b49;
__declspec(noinline) unsigned char FUN_0090d110(void) {
    int count = 0;
    int limit;
    if (DAT_0213f82c > 0) count = 1;
    if (DAT_0213f834 > 0) count = count + 1;
    if (DAT_0213f83c > 0) count = count + 1;
    if (DAT_0213f844 > 0) count = count + 1;
    if (DAT_0213f84c > 0) count = count + 1;
    if (DAT_0213f854 > 0) count = count + 1;
    limit = 6;
    if (DAT_02528b48 == 1 && DAT_02528b49 == 1 && DAT_021603cc == 2) limit = 3;
    return (unsigned char)(count < limit);
}
