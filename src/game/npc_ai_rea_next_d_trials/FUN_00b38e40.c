/* FUN_00b38e40: static initializer of the record at DAT_03168c88 (vtable PTR_LAB_00e495f4, name "heli ai packets",
   group "multiplayer", count 0x20, critical section at +0x30), registered with FUN_007f6a10.
   The import slot DAT_00db80d4 is InitializeCriticalSection. */
typedef void (__stdcall *initialize_critical_section)(void *section);
extern initialize_critical_section DAT_00db80d4;
extern char s_heli_ai_packets_00e495e0[];
extern char s_multiplayer_00e06b50[];
extern void *PTR_LAB_00e495f4;
extern unsigned char DAT_00fa23a8;
extern void *DAT_03168c88;
extern char *DAT_03168c8c;
extern char *DAT_03168c90;
extern int DAT_03168c9c;
extern int DAT_03168ca0;
extern void *DAT_03168ca4;
extern char DAT_03168ca8;
extern char DAT_03168caa;
extern void *DAT_03168cac;
extern int DAT_03168cb0;
extern void *DAT_03168cb4;
extern unsigned char DAT_03168cb8[24];
extern int DAT_03168cd0;
void FUN_007f6a10(void *record);

__declspec(noinline) void *FUN_00b38e40(void)
{
	DAT_03168c88 = &PTR_LAB_00e495f4;
	DAT_00db80d4(DAT_03168cb8);
	DAT_03168cd0 = 0;
	DAT_03168ca0 = 0x20;
	DAT_03168c8c = s_heli_ai_packets_00e495e0;
	DAT_03168c90 = s_multiplayer_00e06b50;
	DAT_03168ca8 = 1;
	DAT_03168ca4 = 0;
	DAT_03168caa = 0;
	DAT_03168cac = 0;
	DAT_03168cb0 = 1;
	DAT_03168cb4 = &DAT_00fa23a8;
	DAT_03168c9c = 0;
	FUN_007f6a10(&DAT_03168c88);
	return &DAT_03168c88;
}
