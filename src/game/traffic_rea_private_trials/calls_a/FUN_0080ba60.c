/* FUN_0080ba60: sums FUN_007fb080(node) over the circular list whose head is at +0x400 of
   DAT_02528c14 (next pointer at +0x22cc), divides by an eighth of the unsigned count at +0x1dc4 of
   the record at +0x408, and returns whether that ratio exceeds 0.05f widened to double (native
   compares against the qword 0x3fa99999a0000000). */
extern unsigned char *DAT_02528c14;
unsigned int FUN_007fb080(unsigned char *node);
__declspec(noinline) unsigned char FUN_0080ba60(void)
{
    unsigned char **head;
    unsigned char *node;
    unsigned int count;
    unsigned int total;
    float ratio;
    count = *(unsigned int *)(*(unsigned char **)(DAT_02528c14 + 0x408) + 0x1dc4);
    node = *(unsigned char **)(DAT_02528c14 + 0x400);
    head = (unsigned char **)(DAT_02528c14 + 0x400);
    total = 0;
    if (node != 0) {
        do {
            total = total + FUN_007fb080(node);
            node = *(unsigned char **)(node + 0x22cc);
            if (node == *head) {
                break;
            }
        } while (node != 0);
    }
    ratio = (float)total / (float)(count >> 3);
    if (ratio > (double)0.05f) {
        return 1;
    }
    return 0;
}
