/* FUN_009cedf0: shuts an npc down, once (bit 0 of +0x80 already set: nothing). Sets bit 1 of +0x80; tells its
   +0x1178 controller (vtable slot +0x20, with the argument); frees its DAT_00ee29a8 slot (+0x2e0, then -1); when
   FUN_0098e710 maps it to another object, calls FUN_0098f1b0(that object, npc); when +0x11b0 is 1 and the +0xd74
   handle is a live vehicle (+0x4c == 5) whose first seat (FUN_00aa7380) is this npc, sets bit 28 of the vehicle's
   +0x8f50; resets the +0xf8 pair (FUN_00436af0 with -1, -1); releases the +0xc88 value from list 4 (FUN_007a1b10)
   and clears it; releases the +0xc8c handle's 0x3c-byte DAT_029e6c28 entry (FUN_0079d1b0 mode 3) when the entry
   still holds it, and clears it; then FUN_00960240 with the argument. The method is a thiscall with one stack word;
   it is written as __fastcall with the EDX word native holds there (the argument). */
struct controller_009cedf0;
typedef void (__fastcall *controller_notify)(struct controller_009cedf0 *controller, int edx_value, int argument);
struct controller_009cedf0 {
	controller_notify *vtable;
};
typedef struct entry_009cedf0 {
	unsigned char pad[0x20];
	int handle;
	unsigned char pad24[0x18];
} entry_t;
extern int DAT_00ee29a8[];
extern int DAT_02149c64[];
extern entry_t DAT_029e6c28[];
unsigned char *FUN_0098e710(unsigned char *object);
void FUN_0098f1b0(unsigned char *owner, unsigned char *npc);
unsigned char *__fastcall FUN_00aa7380(unsigned char *vehicle, int index);
void __stdcall FUN_00436af0(int *pair, int first, int second);
void FUN_007a1b10(int kind, unsigned int value);
void FUN_0079d1b0(entry_t *entry, int mode);
void __fastcall FUN_00960240(unsigned char *npc, int edx_value, int argument);

__declspec(noinline) void __fastcall FUN_009cedf0(unsigned char *npc, int edx_value, int argument)
{
	unsigned int flags;
	struct controller_009cedf0 *controller;
	unsigned char *owner;
	unsigned char *vehicle;
	int handle;
	int index;
	entry_t *entry;
	flags = *(unsigned int *)(npc + 0x80);
	if ((flags & 1) != 0) {
		return;
	}
	controller = *(struct controller_009cedf0 **)(npc + 0x1178);
	*(unsigned int *)(npc + 0x80) = flags | 2;
	if (controller != 0) {
		controller->vtable[0x20 / 4](controller, argument, argument);
	}
	if (*(int *)(npc + 0x2e0) >= 0) {
		DAT_00ee29a8[*(int *)(npc + 0x2e0)] = 0;
		*(int *)(npc + 0x2e0) = -1;
	}
	owner = FUN_0098e710(npc);
	if (npc != owner) {
		FUN_0098f1b0(owner, npc);
	}
	if (*(int *)(npc + 0x11b0) == 1) {
		handle = *(int *)(npc + 0xd74);
		if (handle != 0) {
			vehicle = (unsigned char *)DAT_02149c64[(handle & 0xfff) * 4];
			if (vehicle != 0 && *(int *)(vehicle + 0x44) == handle && *(int *)(vehicle + 0x4c) == 5 &&
			    npc == FUN_00aa7380(vehicle, 0)) {
				*(unsigned int *)(vehicle + 0x8f50) |= 0x10000000;
			}
		}
	}
	FUN_00436af0((int *)(npc + 0xf8), -1, -1);
	if (*(unsigned int *)(npc + 0xc88) != 0) {
		FUN_007a1b10(4, *(unsigned int *)(npc + 0xc88));
		*(unsigned int *)(npc + 0xc88) = 0;
	}
	handle = *(int *)(npc + 0xc8c);
	if (handle != 0) {
		index = handle & 0x1fff;
		if (index < 0x3c) {
			entry = &DAT_029e6c28[index];
			if (entry->handle == handle) {
				FUN_0079d1b0(entry, 3);
			}
		}
		*(int *)(npc + 0xc8c) = 0;
	}
	FUN_00960240(npc, argument, argument);
}
