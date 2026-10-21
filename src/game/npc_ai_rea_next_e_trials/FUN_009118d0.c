/* FUN_009118d0: validation code for an object (0 = ok): 1 when it, its owner (+4), one of its owner's +0x48 parts
   (+8.. array) or a part's +0x30 record is missing; 4 for an owner flagged 0x10 at +0x1c whose +0x50 record is
   absent or lacks flag 1 at +0x26; 0xc for an unregistered +2 id or a part whose +0x20 id is not a registered
   type-8 entry of DAT_00f7aae8; 0xe when a registered entry's +0x200 record is flagged 2 at +0x198 (otherwise the
   object gets flag 0x80 at +0x48); for parts whose owner slot (+0x38..) record has +0xcc == 3, the part position's
   FUN_004a9be0 id is checked the same way, and when it does not resolve, 0xd when FUN_004b19f0 finds the position
   and FUN_004b1720 gives that index a nonzero value; 5 when FUN_00910320 rejects the object; finally the owner's
   +0x34 bits under the mode's mask (mode 0: 0x1f, or 0x193 with flag 0x80; otherwise 0xffff, or 0x193) give
   FUN_0090dc00's code. */
extern int DAT_00f7aae8[];
unsigned short FUN_004a9be0(const float *position);
int FUN_004b19f0(const float *position, int zero);
int FUN_004b1720(int index);
unsigned char FUN_00910320(unsigned char *object);
unsigned int FUN_0090dc00(unsigned char *object, unsigned short mask);

static __inline int registered_entry(unsigned int id)
{
	if (id == 0xffff || id >= 0x866) {
		return 0;
	}
	return DAT_00f7aae8[id];
}

static __inline int mode_mask(unsigned char *object, char mode)
{
	if (mode != 0) {
		return (object[0x48] & 0x80) != 0 ? 0x193 : 0xffff;
	}
	return (object[0x48] & 0x80) != 0 ? 0x193 : 0x1f;
}

/* The two stack words (object, mode) as one struct by value, so that LTCG keeps native's stack interface. */
struct arguments_009118d0 {
	unsigned char *object;
	char mode;
};

__declspec(noinline) unsigned int FUN_009118d0(struct arguments_009118d0 arguments)
{
	unsigned char *object = arguments.object;
	char mode = arguments.mode;
	unsigned char *owner;
	unsigned char *part;
	unsigned char *target;
	unsigned int id;
	int index;
	int found;
	int entry;
	unsigned short mask;
	if (object == 0) {
		return 1;
	}
	owner = *(unsigned char **)(object + 4);
	if (owner == 0) {
		return 1;
	}
	if ((owner[0x1c] & 0x10) != 0 &&
	    (*(unsigned char **)(object + 0x50) == 0 || ((*(unsigned char **)(object + 0x50))[0x26] & 1) == 0)) {
		return 4;
	}
	if (*(unsigned short *)(object + 2) != 0xffff) {
		id = *(unsigned short *)(object + 2);
		entry = registered_entry(id);
		if (entry == 0) {
			return 0xc;
		}
		target = *(unsigned char **)(entry + 0x200);
		if (target != 0) {
			if ((target[0x198] & 2) != 0) {
				return 0xe;
			}
			object[0x48] |= 0x80;
		}
	}
	for (index = 0; index < owner[0x48]; index++) {
		part = ((unsigned char **)(object + 8))[index];
		if (part == 0 || *(int *)(part + 0x30) == 0 || *(int *)(*(int *)(part + 0x30) + 4) == 0) {
			return 1;
		}
		if (*(int *)(((unsigned char **)(owner + 0x38))[index] + 0xcc) == 3) {
			id = FUN_004a9be0((const float *)(part + 4));
			if (id == 0xffff || id >= 0x866 || DAT_00f7aae8[id] == 0 ||
			    (target = *(unsigned char **)(DAT_00f7aae8[id] + 0x200)) == 0) {
				found = FUN_004b19f0((const float *)(part + 4), 0);
				if (found != -1 && FUN_004b1720(found) != 0) {
					return 0xd;
				}
			} else {
				if ((target[0x198] & 2) != 0) {
					return 0xe;
				}
				object[0x48] |= 0x80;
			}
		}
		id = *(unsigned short *)(part + 0x20);
		entry = registered_entry(id);
		if (entry == 0 || *(int *)(entry + 0x20) != 8) {
			return 0xc;
		}
	}
	if (FUN_00910320(object) == 0) {
		return 5;
	}
	mask = mode_mask(object, mode);
	if ((*(unsigned short *)(owner + 0x34) & mask) != 0) {
		return FUN_0090dc00(owner, mask);
	}
	return 0;
}
