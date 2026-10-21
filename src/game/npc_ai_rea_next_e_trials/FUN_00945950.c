/* FUN_00945950 (moved from gate npc-ai-rea): counts the nodes of the circular list at DAT_0215ffc0 (next pointer at
   +0x1160) whose byte +0x1170 has bit 0x10 set. */
extern unsigned char *DAT_0215ffc0;
__declspec(noinline) unsigned int __cdecl FUN_00945950(void)
{
	unsigned char *first = DAT_0215ffc0;
	unsigned char *node = DAT_0215ffc0;
	unsigned int count = 0;
	while (node != 0) {
		if ((node[0x1170] & 0x10) != 0) {
			count = count + 1;
		}
		node = *(unsigned char **)(node + 0x1160);
		if (node == first) {
			break;
		}
	}
	return count;
}
