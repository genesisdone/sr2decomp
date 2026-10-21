/* FUN_004211e0: lets two characters notice each other. Nothing happens when either is excluded by FUN_00985630,
   when they are the same, or when both resolve (FUN_0098e7c0) to the same owner. A type-2 character with bit 0
   of +0x11c7 set blocks it when the other passes FUN_00926600 or FUN_0098e8a0. Then, if second's owner is
   non-null and first's type (+0x3cc) is 1, or 2 with FUN_009ce0a0(FUN_009d06a0(first+0x44), owner) true,
   FUN_0041dad0(first, owner, flag); and the same for first's owner against second, where type 2 also calls
   FUN_00421760(owner) when the resolved handle has bit 3 of +0x11c6 set and the owner passes FUN_00926600. */
char FUN_00985630(int node);
int FUN_0098e7c0(int npc);
char __fastcall FUN_00926600(int npc);
char FUN_0098e8a0(int npc);
int __fastcall FUN_009d06a0(int handle);
char FUN_009ce0a0(int target, int npc);
void FUN_0041dad0(int target, int npc, char flag);
void FUN_00421760(int npc);

__declspec(noinline) void FUN_004211e0(int first, int second, char flag)
{
	int second_owner;
	int first_owner;
	int resolved;
	char seen;
	if (FUN_00985630(first)) {
		return;
	}
	if (FUN_00985630(second)) {
		return;
	}
	if (second == first) {
		return;
	}
	second_owner = FUN_0098e7c0(second);
	first_owner = FUN_0098e7c0(first);
	if (second_owner == first_owner) {
		return;
	}
	if (*(char *)(second + 0x3cc) == 2 && (*(unsigned char *)(second + 0x11c7) & 1) != 0) {
		if (FUN_00926600(first)) {
			return;
		}
		if (FUN_0098e8a0(first)) {
			return;
		}
	}
	if (*(char *)(first + 0x3cc) == 2 && (*(unsigned char *)(first + 0x11c7) & 1) != 0) {
		if (FUN_00926600(second)) {
			return;
		}
		if (FUN_0098e8a0(second)) {
			return;
		}
	}
	if (second_owner != 0) {
		switch (*(char *)(first + 0x3cc)) {
		case 2:
			if (!FUN_009ce0a0(FUN_009d06a0(*(int *)(first + 0x44)), second_owner)) {
				break;
			}
		case 1:
			FUN_0041dad0(first, second_owner, flag);
			break;
		}
	}
	if (first_owner == 0) {
		return;
	}
	switch (*(char *)(second + 0x3cc)) {
	case 2:
		resolved = FUN_009d06a0(*(int *)(second + 0x44));
		seen = FUN_009ce0a0(resolved, first_owner);
		if ((*(unsigned char *)(resolved + 0x11c6) & 8) != 0 && FUN_00926600(first_owner)) {
			FUN_00421760(first_owner);
		}
		if (!seen) {
			return;
		}
	case 1:
		FUN_0041dad0(second, first_owner, flag);
		break;
	}
}
