/* FUN_006afa00: static initializer of the record at DAT_027d86c8 (vtable PTR_LAB_00e06c50, name "Persona_overrides",
   group "always_allocated", count 0x84, critical section at +0x30), registered with FUN_007f6a10.
   The import slot DAT_00db80d4 is InitializeCriticalSection. */
typedef void (__stdcall *initialize_critical_section)(void *section);
extern initialize_critical_section DAT_00db80d4;
extern char s_Persona_overrides_00e06b3c[];
extern char s_always_allocated_00ddc8a8[];
extern void *PTR_LAB_00e06c50;
extern unsigned char DAT_02771278;
extern void *DAT_027d86c8;
extern char *DAT_027d86cc;
extern char *DAT_027d86d0;
extern int DAT_027d86dc;
extern int DAT_027d86e0;
extern void *DAT_027d86e4;
extern char DAT_027d86e8;
extern char DAT_027d86ea;
extern void *DAT_027d86ec;
extern int DAT_027d86f0;
extern void *DAT_027d86f4;
extern unsigned char DAT_027d86f8[24];
extern int DAT_027d8710;
void FUN_007f6a10(void *record);

__declspec(noinline) void *FUN_006afa00(void)
{
	DAT_027d86c8 = &PTR_LAB_00e06c50;
	DAT_00db80d4(DAT_027d86f8);
	DAT_027d8710 = 0;
	DAT_027d86e0 = 0x84;
	DAT_027d86cc = s_Persona_overrides_00e06b3c;
	DAT_027d86d0 = s_always_allocated_00ddc8a8;
	DAT_027d86e8 = 1;
	DAT_027d86e4 = &DAT_02771278;
	DAT_027d86ea = 1;
	DAT_027d86ec = 0;
	DAT_027d86f0 = 1;
	DAT_027d86f4 = 0;
	DAT_027d86dc = 0;
	FUN_007f6a10(&DAT_027d86c8);
	return &DAT_027d86c8;
}
