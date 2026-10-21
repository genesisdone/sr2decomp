/* FUN_00957460: loads the notoriety spawn tables (FUN_009249d0), fills the 17-entry object table DAT_0215e578 with
   its objects and calls each one's vtable slot +0x1c, then stores the item records of "pipe_bomb" and "molotov"
   (FUN_00b716e0) in DAT_025295dc and DAT_025295d8. The method is a thiscall without stack arguments, written as
   one-parameter __fastcall. */
struct object_00957460;
typedef void (__fastcall *object_method)(struct object_00957460 *object);
struct object_00957460 {
	object_method *vtable;
};
extern struct object_00957460 DAT_00eb5378;
extern struct object_00957460 DAT_00eb5630;
extern struct object_00957460 DAT_00eb63c8;
extern struct object_00957460 DAT_00eb6688;
extern struct object_00957460 DAT_00eb6948;
extern struct object_00957460 DAT_00eb6c00;
extern struct object_00957460 DAT_00eb6eb8;
extern struct object_00957460 DAT_00eb7170;
extern struct object_00957460 DAT_00eb76e0;
extern struct object_00957460 DAT_00eb5ba0;
extern struct object_00957460 DAT_00eb5e58;
extern struct object_00957460 DAT_00eb6110;
extern struct object_00957460 DAT_027a5a18;
extern struct object_00957460 DAT_027a5cc8;
extern struct object_00957460 DAT_027a5368;
extern struct object_00957460 DAT_029dbfe8;
extern struct object_00957460 DAT_0279ab50;
extern struct object_00957460 *DAT_0215e578[17];
extern const char s_pipe_bomb_00dd78c0[];
extern const char s_molotov_00dea9d8[];
extern void *DAT_025295dc;
extern void *DAT_025295d8;
void FUN_009249d0(void);
void *FUN_00b716e0(const char *name);

__declspec(noinline) void FUN_00957460(void)
{
	int index;
	FUN_009249d0();
	DAT_0215e578[0] = &DAT_00eb5378;
	DAT_0215e578[1] = &DAT_00eb5630;
	DAT_0215e578[2] = &DAT_00eb63c8;
	DAT_0215e578[3] = &DAT_00eb6688;
	DAT_0215e578[4] = &DAT_00eb6948;
	DAT_0215e578[5] = &DAT_00eb6c00;
	DAT_0215e578[6] = &DAT_00eb6eb8;
	DAT_0215e578[7] = &DAT_00eb7170;
	DAT_0215e578[8] = &DAT_00eb76e0;
	DAT_0215e578[9] = &DAT_00eb5ba0;
	DAT_0215e578[10] = &DAT_00eb5e58;
	DAT_0215e578[11] = &DAT_00eb6110;
	DAT_0215e578[12] = &DAT_027a5a18;
	DAT_0215e578[13] = &DAT_027a5cc8;
	DAT_0215e578[14] = &DAT_027a5368;
	DAT_0215e578[15] = &DAT_029dbfe8;
	DAT_0215e578[16] = &DAT_0279ab50;
	for (index = 0; index < 17; index++) {
		DAT_0215e578[index]->vtable[0x1c / 4](DAT_0215e578[index]);
	}
	DAT_025295dc = FUN_00b716e0(s_pipe_bomb_00dd78c0);
	DAT_025295d8 = FUN_00b716e0(s_molotov_00dea9d8);
}
