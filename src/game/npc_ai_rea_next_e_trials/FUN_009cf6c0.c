/* FUN_009cf6c0: a per-frame update of an npc (dt is the frame's float). Clears bit 20 of +0xc8; an npc with bit 4
   of +0x80 set stops there. While +0x1194 is positive and bit 2 of +0x1172 is clear it counts down by
   DAT_00e8437c * DAT_00e5c130 and is clamped (FUN_00417120) to [0, +0x1120]. With bit 1 of +0x1170: unless the
   FUN_006ac360 entry of the 0x18-byte table at DAT_027d83c8 has kind 0x1e7 or 0x1ce, an unarmed timer +0x11a0
   (negative) is armed 500 ms ahead and FUN_00440f60(npc + 0xf8, 1) runs; once an armed timer is due (more than
   900,000,000 ms of wrap distance not yet reached) it is disarmed (when +0x1178 is set and bit 2 of +0x1172),
   FUN_00427460 picks message 10 for the +0x1178 object, which, when found, gets the object's +0x10 and the player's
   FUN_00a61c60 value written to it (FUN_00ce01b0); then FUN_00440f60(npc + 0xf8, 0). With bit 3 of +0x1171, an npc
   that has a handle, is not the DAT_00ebce9c object in a DAT_00ebcea0 state other than 7/8, is not rejected by
   FUN_009b92e0, whose +0xd74 handle resolves (FUN_00ae28f0) and whose type-5 +0xd74 object FUN_00aa6820 rejects,
   gets a fresh FUN_00433190 record sent through FUN_00b072f0 and the bit cleared. Finally FUN_009a7df0(npc, dt).
   Hypothesis, unconfirmed: +0x1194 is a cooldown and the +0x11a0 timer a network sync. */
extern unsigned char DAT_02149c64[];
extern unsigned char *DAT_00ebce9c;
extern int DAT_00ebcea0;
extern int DAT_021703d4;
extern int DAT_00e843ac;
extern float DAT_00e8437c;
extern double DAT_00e5c130;
extern int DAT_027d83cc[];
void FUN_00417120(float *value, float low, float high);
int __fastcall FUN_006ac360(int npc);
void __stdcall FUN_00440f60(int object, char flag);
int __fastcall FUN_00427460(int object, int *id);
void FUN_00ce01b0(int stream, int value);
int FUN_00a61c60(int player);
char FUN_009b92e0(int object);
int __fastcall FUN_00ae28f0(unsigned int handle);
int __fastcall FUN_00aa6820(int vehicle);
void FUN_00433190(int *record);
void FUN_00b072f0(int npc, int *record);
void FUN_009a7df0(int npc, float dt);

static __forceinline char npc_is_inactive(int npc)
{
	return (char)((*(unsigned int *)(npc + 0x80) >> 4) & 1);
}

static __forceinline int object_from_handle(unsigned int handle)
{
	int object;
	if (handle == 0) {
		return 0;
	}
	object = *(int *)(DAT_02149c64 + (handle & 0xfff) * 16);
	if (object == 0 || *(unsigned int *)(object + 0x44) != handle) {
		return 0;
	}
	return object;
}

static __forceinline int vehicle_from_handle(unsigned int handle)
{
	int object = object_from_handle(handle);
	if (object == 0) {
		return 0;
	}
	return object & ((*(int *)(object + 0x4c) != 5) - 1);
}

static __forceinline char npc_in_vehicle(int npc)
{
	if (FUN_009b92e0(npc) == 0) {
		return FUN_00ae28f0(*(unsigned int *)(npc + 0xd74)) != 0;
	}
	return 0;
}

static __forceinline int timer_due(int timer)
{
	int now = DAT_00e843ac;
	if (timer > now) {
		if (timer - now < 900000000) {
			return 0;
		}
	} else if (now - timer >= 900000000) {
		return 0;
	}
	return 1;
}

__declspec(noinline) void FUN_009cf6c0(int npc, float dt)
{
	float *cooldown;
	int entry;
	int kind;
	int when;
	int stream;
	int id;
	int vehicle;
	int record[9];
	*(unsigned int *)(npc + 0xc8) &= 0xffefffff;
	if (npc_is_inactive(npc)) {
		return;
	}
	cooldown = (float *)(npc + 0x1194);
	if (*cooldown > 0.0f && (*(unsigned char *)(npc + 0x1172) & 4) == 0) {
		*cooldown = *cooldown - DAT_00e8437c * DAT_00e5c130;
		FUN_00417120(cooldown, 0.0f, (float)*(int *)(npc + 0x1120));
	}
	if ((*(unsigned char *)(npc + 0x1170) & 2) != 0) {
		entry = FUN_006ac360(npc);
		if (entry < 0 || ((kind = DAT_027d83cc[entry * 6]) != 0x1e7 && kind != 0x1ce)) {
			if (*(int *)(npc + 0x11a0) < 0) {
				when = DAT_00e843ac + 500;
				*(int *)(npc + 0x11a0) = when;
				if (when > 1800000000) {
					*(int *)(npc + 0x11a0) = when - 1800000000;
				}
				FUN_00440f60(npc + 0xf8, 1);
			}
		}
		when = *(int *)(npc + 0x11a0);
		if (when >= 0 && timer_due(when)) {
			if (*(int *)(npc + 0x1178) != 0 && (*(unsigned char *)(npc + 0x1172) & 4) != 0) {
				*(int *)(npc + 0x11a0) = -1;
				id = 10;
				stream = FUN_00427460(*(int *)(npc + 0x1178) + 0xbc, &id);
				if (stream != 0) {
					FUN_00ce01b0(stream, *(int *)(*(int *)(npc + 0x1178) + 0x10));
					FUN_00ce01b0(stream, FUN_00a61c60(DAT_021703d4));
				}
			}
			FUN_00440f60(npc + 0xf8, 0);
		}
	}
	if ((*(unsigned char *)(npc + 0x1171) & 8) != 0) {
		vehicle = vehicle_from_handle(*(unsigned int *)(npc + 0xd74));
		if (*(int *)(npc + 0x44) != 0 &&
		    (DAT_00ebce9c == 0 || *(int *)(npc + 0x44) != *(int *)(DAT_00ebce9c + 0x44) || DAT_00ebcea0 == 7 ||
		     DAT_00ebcea0 == 8) &&
		    npc_in_vehicle(npc) && FUN_00aa6820(vehicle) == 0) {
			FUN_00433190(record);
			FUN_00b072f0(npc, record);
			*(unsigned char *)(npc + 0x1171) &= 0xf7;
		}
	}
	FUN_009a7df0(npc, dt);
}
