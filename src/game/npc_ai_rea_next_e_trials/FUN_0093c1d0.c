/* FUN_0093c1d0: 0x20 - DAT_0252a0d4, minus 4 more when FUN_009d7bd0() is nonzero; the multiplayer pair
   DAT_02528b48 == 1 && DAT_02528b49 == 0 returns early without the call. Moved from batch D (deferred there).
   The two mode bytes are declared volatile because native loads each into a register before comparing
   (`mov al,[g]; cmp al,1`, `mov cl,[g]; test cl,cl`), which VC8 emits for volatile bytes; whether SR2 declared them
   volatile is an unconfirmed hypothesis. The pair test is written as an inline helper. */
extern volatile char DAT_02528b48;
extern volatile char DAT_02528b49;
extern int DAT_0252a0d4;
int FUN_009d7bd0(void);

static __forceinline int multiplayer_client(void)
{
	return DAT_02528b48 == 1 && DAT_02528b49 == 0;
}

__declspec(noinline) int FUN_0093c1d0(void)
{
	int value = 0x20 - DAT_0252a0d4;
	if (multiplayer_client()) {
		return value;
	}
	return FUN_009d7bd0() == 0 ? value : value - 4;
}
