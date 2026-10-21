/* FUN_00956690 (moved from gate npc-ai-rea-unregistered): index of the 2000-byte record that object+0x2c points
   at, within the array at DAT_02fad1f8. */
extern unsigned char DAT_02fad1f8[];
__declspec(noinline) int __fastcall FUN_00956690(unsigned char *object)
{
	return (int)(*(unsigned char **)(object + 0x2c) - DAT_02fad1f8) / 2000;
}
