/* FUN_00923c10 (moved from gate npc-ai-rea-unregistered): index of the 2000-byte record that object+0x220 points
   at, within the array at DAT_02fad1f8. */
extern unsigned char DAT_02fad1f8[];
__declspec(noinline) int __fastcall FUN_00923c10(unsigned char *object)
{
	return (int)(*(unsigned char **)(object + 0x220) - DAT_02fad1f8) / 2000;
}
