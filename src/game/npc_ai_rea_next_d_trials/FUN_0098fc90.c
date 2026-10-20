/* FUN_0098fc90: static initializer of one tweak/event-category record at DAT_02c29518 (vtable PTR_LAB_00e3b8fc,
   name "party hookups", group "multiplayer", count 10, critical section at +0x30), registered with
   FUN_007f6a10. The import slot DAT_00db80d4 is InitializeCriticalSection. */
typedef void (__stdcall *initialize_critical_section)(void *section);
extern initialize_critical_section DAT_00db80d4;
extern char s_party_hookups_00e3b8a0[];
extern char s_multiplayer_00e06b50[];
extern void *PTR_LAB_00e3b8fc;
extern unsigned char DAT_00fa23a8;
extern void *DAT_02c29518;
extern char *DAT_02c2951c;
extern char *DAT_02c29520;
extern int DAT_02c2952c;
extern int DAT_02c29530;
extern int DAT_02c29534;
extern char DAT_02c29538;
extern char DAT_02c2953a;
extern int DAT_02c2953c;
extern int DAT_02c29540;
extern void *DAT_02c29544;
extern unsigned char DAT_02c29548[24];
extern int DAT_02c29560;
void FUN_007f6a10(void *record);

__declspec(noinline) void *FUN_0098fc90(void)
{
	DAT_02c29518 = &PTR_LAB_00e3b8fc;
	DAT_00db80d4(DAT_02c29548);
	DAT_02c29560 = 0;
	DAT_02c29530 = 10;
	DAT_02c2951c = s_party_hookups_00e3b8a0;
	DAT_02c29520 = s_multiplayer_00e06b50;
	DAT_02c29538 = 1;
	DAT_02c29534 = 0;
	DAT_02c2953a = 0;
	DAT_02c2953c = 0;
	DAT_02c29540 = 1;
	DAT_02c29544 = &DAT_00fa23a8;
	DAT_02c2952c = 0;
	FUN_007f6a10(&DAT_02c29518);
	return &DAT_02c29518;
}
