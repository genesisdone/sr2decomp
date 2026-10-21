/* FUN_00936a10: walks the ring of npcs at DAT_0215ffc0 (next at +0x1160); among those flagged 4 at +0x1171 that
   FUN_009368f0 accepts, picks the last one whose FUN_009dfbd0 measure at its +0x14 position (non-planar, flag 1)
   is at least the best so far (starting at 0). When one is found, calls its vtable slot 4 (+0x10) with 0 (runtime
   target unknown, certified only as the audited literal call chain) and returns 1; else returns 0. The method is a
   thiscall with one stack word, written as __fastcall with an unused EDX word (the loaded method pointer). */
struct npc_936a10;
typedef void (__fastcall *activate_fn)(struct npc_936a10 *self, int unused, int flag);
struct npc_936a10 {
	activate_fn *vtable;
};
extern unsigned char *DAT_0215ffc0;
char FUN_009368f0(unsigned char *npc);
float FUN_009dfbd0(float *position, char flat, volatile char from_camera);

__declspec(noinline) unsigned char FUN_00936a10(void)
{
	float best = 0.0f;
	float value;
	unsigned char *found = 0;
	unsigned char *npc = DAT_0215ffc0;
	activate_fn method;
	if (npc != 0) {
		do {
			if ((npc[0x1171] & 4) != 0 && FUN_009368f0(npc) != 0) {
				value = FUN_009dfbd0((float *)(npc + 0x14), 0, 1);
				if (!(value < best)) {
					best = value;
					found = npc;
				}
			}
			npc = *(unsigned char **)(npc + 0x1160);
		} while (npc != DAT_0215ffc0 && npc != 0);
		if (found != 0) {
			method = ((struct npc_936a10 *)found)->vtable[4];
			method((struct npc_936a10 *)found, (int)method, 0);
			return 1;
		}
	}
	return 0;
}
