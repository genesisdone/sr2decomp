/* FUN_0085a910: static initializer of the record at DAT_02a476f0 (vtable PTR_LAB_00e2aef4, name "npc_creation_data",
   group "multiplayer", count 0x4b, critical section at +0x30), registered with FUN_007f6a10.
   The import slot DAT_00db80d4 is InitializeCriticalSection. */
typedef void (__stdcall *initialize_critical_section)(void *section);
extern initialize_critical_section DAT_00db80d4;
extern char s_npc_creation_data_00e2ada4[];
extern char s_multiplayer_00e06b50[];
extern void *PTR_LAB_00e2aef4;
extern unsigned char DAT_00e8c43c;
extern unsigned char DAT_00fa23a8;
extern void *DAT_02a476f0;
extern char *DAT_02a476f4;
extern char *DAT_02a476f8;
extern int DAT_02a47704;
extern int DAT_02a47708;
extern void *DAT_02a4770c;
extern char DAT_02a47710;
extern char DAT_02a47712;
extern void *DAT_02a47714;
extern int DAT_02a47718;
extern void *DAT_02a4771c;
extern unsigned char DAT_02a47720[24];
extern int DAT_02a47738;
void FUN_007f6a10(void *record);

__declspec(noinline) void *FUN_0085a910(void)
{
	DAT_02a476f0 = &PTR_LAB_00e2aef4;
	DAT_00db80d4(DAT_02a47720);
	DAT_02a47738 = 0;
	DAT_02a47708 = 0x4b;
	DAT_02a476f4 = s_npc_creation_data_00e2ada4;
	DAT_02a476f8 = s_multiplayer_00e06b50;
	DAT_02a47710 = 1;
	DAT_02a4770c = 0;
	DAT_02a47712 = 0;
	DAT_02a47714 = &DAT_00e8c43c;
	DAT_02a47718 = 1;
	DAT_02a4771c = &DAT_00fa23a8;
	DAT_02a47704 = 0;
	FUN_007f6a10(&DAT_02a476f0);
	return &DAT_02a476f0;
}
