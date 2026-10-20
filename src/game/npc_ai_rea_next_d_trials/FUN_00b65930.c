/* FUN_00b65930: static initializer of the record at DAT_03179a70 (vtable PTR_LAB_00e49670, name "plane ai packets",
   group "multiplayer", count 0x20, critical section at +0x30), registered with FUN_007f6a10.
   The import slot DAT_00db80d4 is InitializeCriticalSection. */
typedef void (__stdcall *initialize_critical_section)(void *section);
extern initialize_critical_section DAT_00db80d4;
extern char s_plane_ai_packets_00e49658[];
extern char s_multiplayer_00e06b50[];
extern void *PTR_LAB_00e49670;
extern unsigned char DAT_00fa23a8;
extern void *DAT_03179a70;
extern char *DAT_03179a74;
extern char *DAT_03179a78;
extern int DAT_03179a84;
extern int DAT_03179a88;
extern void *DAT_03179a8c;
extern char DAT_03179a90;
extern char DAT_03179a92;
extern void *DAT_03179a94;
extern int DAT_03179a98;
extern void *DAT_03179a9c;
extern unsigned char DAT_03179aa0[24];
extern int DAT_03179ab8;
void FUN_007f6a10(void *record);

__declspec(noinline) void *FUN_00b65930(void)
{
	DAT_03179a70 = &PTR_LAB_00e49670;
	DAT_00db80d4(DAT_03179aa0);
	DAT_03179ab8 = 0;
	DAT_03179a88 = 0x20;
	DAT_03179a74 = s_plane_ai_packets_00e49658;
	DAT_03179a78 = s_multiplayer_00e06b50;
	DAT_03179a90 = 1;
	DAT_03179a8c = 0;
	DAT_03179a92 = 0;
	DAT_03179a94 = 0;
	DAT_03179a98 = 1;
	DAT_03179a9c = &DAT_00fa23a8;
	DAT_03179a84 = 0;
	FUN_007f6a10(&DAT_03179a70);
	return &DAT_03179a70;
}
