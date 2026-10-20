/* FUN_006afed0: static initializer of one tweak/event-category record at DAT_027d8718 (vtable PTR_LAB_00e06c7c,
   name "Persona override sim events", group "multiplayer", count 0x18, critical section at +0x30), registered with
   FUN_007f6a10. The import slot DAT_00db80d4 is InitializeCriticalSection. */
typedef void (__stdcall *initialize_critical_section)(void *section);
extern initialize_critical_section DAT_00db80d4;
extern char s_Persona_override_sim_events_00e06b5c[];
extern char s_multiplayer_00e06b50[];
extern void *PTR_LAB_00e06c7c;
extern unsigned char DAT_00fa23a8;
extern void *DAT_027d8718;
extern char *DAT_027d871c;
extern char *DAT_027d8720;
extern int DAT_027d872c;
extern int DAT_027d8730;
extern int DAT_027d8734;
extern char DAT_027d8738;
extern char DAT_027d873a;
extern int DAT_027d873c;
extern int DAT_027d8740;
extern void *DAT_027d8744;
extern unsigned char DAT_027d8748[24];
extern int DAT_027d8760;
void FUN_007f6a10(void *record);

__declspec(noinline) void *FUN_006afed0(void)
{
	DAT_027d8718 = &PTR_LAB_00e06c7c;
	DAT_00db80d4(DAT_027d8748);
	DAT_027d8760 = 0;
	DAT_027d8730 = 0x18;
	DAT_027d871c = s_Persona_override_sim_events_00e06b5c;
	DAT_027d8720 = s_multiplayer_00e06b50;
	DAT_027d8738 = 1;
	DAT_027d8734 = 0;
	DAT_027d873a = 0;
	DAT_027d873c = 0;
	DAT_027d8740 = 1;
	DAT_027d8744 = &DAT_00fa23a8;
	DAT_027d872c = 0;
	FUN_007f6a10(&DAT_027d8718);
	return &DAT_027d8718;
}
