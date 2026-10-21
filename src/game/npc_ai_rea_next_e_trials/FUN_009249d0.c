/* FUN_009249d0: parses notoriety_spawn.xtbl (FUN_00b743f0 with the default loader), and for each of the 14 entries
   finds the table named by DAT_00e88ba0[i] (FUN_009221c0) and loads it into the object PTR_PTR_00e88b68[i]
   (FUN_00922280); then releases the parse through the loader DAT_00e87138 (vtable slot +0x34 with the handle
   DAT_00e87134) and clears the handle to -1. The method is a thiscall with one stack word, written as __fastcall
   with an unused EDX word (the loaded method pointer). */
struct loader_009249d0;
typedef void (__fastcall *loader_release)(struct loader_009249d0 *loader, int unused, int handle);
struct loader_009249d0 {
	loader_release *vtable;
};
extern const char s_notoriety_spawn_xtbl_00e39784[];
extern const char *DAT_00e88ba0[14];
extern void *PTR_PTR_00e88b68[14];
extern struct loader_009249d0 *DAT_00e87138;
extern int DAT_00e87134;
void *FUN_00b743f0(const char *name, struct loader_009249d0 *loader);
void *FUN_009221c0(void *root, const char *wanted);
void FUN_00922280(void *table, void *object);

__declspec(noinline) void FUN_009249d0(void)
{
	void *root;
	void *table;
	unsigned int index;
	loader_release release;
	root = FUN_00b743f0(s_notoriety_spawn_xtbl_00e39784, 0);
	for (index = 0; index < 14; index++) {
		table = FUN_009221c0(root, DAT_00e88ba0[index]);
		FUN_00922280(table, PTR_PTR_00e88b68[index]);
	}
	release = DAT_00e87138->vtable[0x34 / 4];
	release(DAT_00e87138, (int)release, DAT_00e87134);
	DAT_00e87134 = -1;
}
