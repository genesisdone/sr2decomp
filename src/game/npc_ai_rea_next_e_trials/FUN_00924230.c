/* FUN_00924230: returns 1 when the object's team (+0x1e4) is the DAT_00e9e3f4 record's +0x50 while DAT_00e9e3f8 is
   1 or 2, or is the team of the DAT_021703d4 player, or (when the bytes DAT_02528b48 and DAT_02528b49 are both 1)
   the team of the FUN_009d7bd0 player; otherwise the object's byte +0x2b0. A player's team is DAT_00e985d4 when
   set, else FUN_005600b0() when FUN_0055f670 of it is at least 2, else the player's +0xf00 record's +0x4c or -1. */
extern int DAT_00e9e3f8;
extern int DAT_00e9e3f4;
extern int DAT_021703d4;
extern int DAT_00e985d4;
/* The mode bytes are declared volatile because native loads them into registers before comparing; whether SR2
   declared them volatile is an unconfirmed hypothesis. */
extern volatile char DAT_02528b48;
extern volatile char DAT_02528b49;
int FUN_005600b0(void);
int FUN_0055f670(int team);
int FUN_009d7bd0(void);

__declspec(noinline) char __fastcall FUN_00924230(int object)
{
	int player;
	int team;
	int t;
	if ((DAT_00e9e3f8 == 1 || DAT_00e9e3f8 == 2) && DAT_00e9e3f4 != 0 &&
	    *(int *)(object + 0x1e4) == *(int *)(DAT_00e9e3f4 + 0x50)) {
		return 1;
	}
	player = DAT_021703d4;
	if (player == 0) {
		team = -1;
	} else {
		team = DAT_00e985d4;
		if (team == -1) {
			t = FUN_005600b0();
			if (FUN_0055f670(t) < 2) {
				if (*(int *)(player + 0xf00) != 0) {
					team = *(int *)(*(int *)(player + 0xf00) + 0x4c);
				} else {
					team = -1;
				}
			} else {
				team = t;
			}
		}
	}
	if (team == *(int *)(object + 0x1e4)) {
		return 1;
	}
	if (DAT_02528b48 == 1 && DAT_02528b49 == 1) {
		player = FUN_009d7bd0();
		if (player != 0) {
			team = DAT_00e985d4;
			if (team == -1) {
				t = FUN_005600b0();
				if (FUN_0055f670(t) < 2) {
					if (*(int *)(player + 0xf00) != 0) {
						team = *(int *)(*(int *)(player + 0xf00) + 0x4c);
					} else {
						team = -1;
					}
				} else {
					team = t;
				}
			}
			if (team == *(int *)(object + 0x1e4)) {
				return 1;
			}
		}
	}
	return *(char *)(object + 0x2b0);
}
