/* FUN_00567740 (moved from gate npc-ai-rea-unregistered): true when the state word at object+0x1f0 is 2, 3 or 4 (one unsigned range compare). */
__declspec(noinline) unsigned char __fastcall FUN_00567740(unsigned char *object)
{
	int state = *(int *)(object + 0x1f0);
	if (state >= 2 && state <= 4) {
		return 1;
	}
	return 0;
}
