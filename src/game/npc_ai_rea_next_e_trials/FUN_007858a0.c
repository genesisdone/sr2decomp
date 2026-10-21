/* FUN_007858a0: acts on the object's state +0x200. State 3: unless the target's +0x8554 is 9 with +0x8578 0, the
   target's XZ offset from DAT_021703d4+0x14 must have a squared length below DAT_00e5c190; then FUN_00784630(target),
   a record (-1, 0, the DAT_0252a6d0 vector, -1, -1, word 0, bit 0 clear, bit 1 set) goes to FUN_00b072f0(npc,
   record) and the state becomes 5. States 5 and 6: unless FUN_009b9350(npc), runs FUN_00439430(npc),
   FUN_00441460(npc+0xf8, 1), clears bit 2 of npc+0x1171, FUN_004429a0, FUN_00447cd0, FUN_00440a60,
   FUN_0041b9d0(npc, DAT_021703d4->+0x44, 0) and FUN_00783a70(object). Native: object EAX, npc EDI, target ECX. */
struct record_007858a0 {
	int a;
	int b;
	int v[3];
	int c;
	int d;
	int e;
	short w;
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
};
extern unsigned char *DAT_021703d4;
extern double DAT_00e5c190;
extern int DAT_0252a6d0;
extern int DAT_0252a6d4;
extern int DAT_0252a6d8;
char FUN_009b9350(unsigned char *npc);
void FUN_00439430(unsigned char *npc);
void __stdcall FUN_00441460(unsigned char *part, char flag);
void __stdcall FUN_004429a0(unsigned char *part, char flag);
void FUN_00447cd0(unsigned char *npc, int a, int b);
void __stdcall FUN_00440a60(unsigned char *part, char flag);
void FUN_0041b9d0(unsigned char *npc, int handle, int zero);
void FUN_00783a70(unsigned char *object);
void FUN_00784630(unsigned char *target);
void FUN_00b072f0(unsigned char *npc, struct record_007858a0 *record);

__declspec(noinline) void FUN_007858a0(unsigned char *object, unsigned char *npc, unsigned char *target)
{
	struct record_007858a0 record;
	float dx;
	float dz;
	float d2;
	int state;
	state = *(int *)(object + 0x200);
	if (state != 3) {
		if ((unsigned int)(state - 5) > 1) {
			return;
		}
		if (FUN_009b9350(npc) != 0) {
			return;
		}
		FUN_00439430(npc);
		FUN_00441460(npc + 0xf8, 1);
		npc[0x1171] &= 0xfb;
		FUN_004429a0(npc + 0xf8, 0);
		FUN_00447cd0(npc, 0, 0);
		FUN_00440a60(npc + 0xf8, 0);
		FUN_0041b9d0(npc, *(int *)(DAT_021703d4 + 0x44), 0);
		FUN_00783a70(object);
		return;
	}
	if (*(int *)(target + 0x8554) != 9 || *(int *)(target + 0x8578) != 0) {
		dx = *(float *)(target + 0x14) - *(float *)(DAT_021703d4 + 0x14);
		dz = *(float *)(target + 0x1c) - *(float *)(DAT_021703d4 + 0x1c);
		d2 = dx * dx + dz * dz;
		if (!(d2 < DAT_00e5c190)) {
			return;
		}
	}
	FUN_00784630(target);
	record.b = 0;
	record.a = -1;
	record.v[0] = DAT_0252a6d0;
	record.v[1] = DAT_0252a6d4;
	record.v[2] = DAT_0252a6d8;
	record.c = -1;
	record.d = -1;
	record.w = 0;
	record.bit0 = 0;
	record.bit1 = 1;
	FUN_00b072f0(npc, &record);
	*(int *)(object + 0x200) = 5;
}
