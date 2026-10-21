/* FUN_00784010: puts an NPC into a vehicle as a passenger (hypothesis, unconfirmed). The vehicle handle must
   resolve through the handle table DAT_02149c64 to an object of type 5 and the NPC handle to a type-1 object
   whose +0x3cc kind is 2. The NPC goes through FUN_00968010, FUN_009d2150 and FUN_009d1c40 (each with 1) and,
   unless bit 6 of +0x1170 is set, its +0xf8 block through FUN_004406a0, FUN_00440a60, FUN_00440ce0 and
   FUN_00441e60. When the owner's state +0x230 is 11 the owner records the NPC handle (+0x1f8) and the vehicle
   handle (+0x1f4) and FUN_00783e30 runs with the owner's +0x234 byte; otherwise FUN_007a1ea0 is told
   (10, vehicle handle, 2, -1, 0.0, 0), the owner records the handle of the vehicle's seat-0 object
   (FUN_00aa7380) and the vehicle handle, and FUN_00783ed0 runs. Then the vehicle gets FUN_00ab4bf0 with
   DAT_00dd04f4 and FUN_00ab4dc0 with DAT_00dd071c and the owner's +0x200 becomes 3.
   Native takes the NPC handle in EAX and the owner and vehicle handle as callee-popped stack words. The owner word
   is spelled as a volatile one-member struct so that it stays a stack word loaded at entry, as native loads it;
   that the original declared it so is unconfirmed. */
typedef struct owner_00784010 {
	char pad_000[0x1f4];
	int vehicle_handle;
	int npc_handle;
	char pad_1fc[0x200 - 0x1fc];
	int stage;
	char pad_204[0x230 - 0x204];
	int state;
	unsigned char seat;
} owner_t;
typedef struct owner_word_00784010 {
	owner_t *owner;
} owner_word_t;
extern char *DAT_02149c64[];
extern float DAT_00dd04f4;
extern float DAT_00dd071c;
void __stdcall FUN_00968010(char *npc, int value);
void __stdcall FUN_009d2150(char *npc, int value);
void __stdcall FUN_009d1c40(char *npc, int value);
void __stdcall FUN_004406a0(char *block, int value);
void __stdcall FUN_00440a60(char *block, int value);
void __stdcall FUN_00440ce0(char *block, int value);
void __stdcall FUN_00441e60(char *block, int value);
void FUN_00783e30(char *vehicle, unsigned char seat, char flag);
void __cdecl FUN_007a1ea0(int kind, int handle, int mode, int index, float delay, int extra);
char *__fastcall FUN_00aa7380(char *vehicle, int seat);
void FUN_00783ed0(char *vehicle);
void FUN_00ab4bf0(char *vehicle, float value);
void FUN_00ab4dc0(char *vehicle, float value);

static __forceinline char *resolve(int handle)
{
	char *object = DAT_02149c64[(handle & 0xfff) * 4];
	if (object == 0 || *(int *)(object + 0x44) != handle) {
		return 0;
	}
	return object;
}

__declspec(noinline) void __stdcall FUN_00784010(int npc_handle, volatile owner_word_t word, int vehicle_handle)
{
	owner_t *owner = word.owner;
	char *vehicle;
	char *npc;
	char *block;
	if (vehicle_handle == 0) {
		return;
	}
	vehicle = resolve(vehicle_handle);
	if (vehicle == 0 || *(int *)(vehicle + 0x4c) != 5) {
		return;
	}
	if (npc_handle == 0) {
		return;
	}
	npc = resolve(npc_handle);
	if (npc == 0 || *(int *)(npc + 0x4c) != 1 || *(char *)(npc + 0x3cc) != 2) {
		return;
	}
	FUN_00968010(npc, 1);
	FUN_009d2150(npc, 1);
	FUN_009d1c40(npc, 1);
	if ((*(unsigned char *)(npc + 0x1170) & 0x40) == 0) {
		block = npc + 0xf8;
		FUN_004406a0(block, 1);
		FUN_00440a60(block, 1);
		FUN_00440ce0(block, 1);
		FUN_00441e60(block, 1);
	}
	if (owner->state == 11) {
		owner->npc_handle = *(int *)(npc + 0x44);
		owner->vehicle_handle = vehicle_handle;
		FUN_00783e30(vehicle, owner->seat, 1);
	} else {
		FUN_007a1ea0(10, *(int *)(vehicle + 0x44), 2, -1, 0.0f, 0);
		owner->npc_handle = *(int *)(FUN_00aa7380(vehicle, 0) + 0x44);
		owner->vehicle_handle = vehicle_handle;
		FUN_00783ed0(vehicle);
	}
	FUN_00ab4bf0(vehicle, DAT_00dd04f4);
	FUN_00ab4dc0(vehicle, DAT_00dd071c);
	owner->stage = 3;
}
