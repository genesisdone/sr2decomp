/* FUN_0090f900: when the player DAT_021703d4 is within 3 units (squared distance below 9) of the object's position
   (+4) and is not already its target (+0x60), makes the player its target and calls FUN_0090f390(object, 0);
   otherwise the first human of the DAT_0215ffc0 ring (next at +0x1160) with flag 4 of byte +0x1171, kind (+0x148)
   other than 0x11 and not already the target, within that squared distance (FUN_00bdea30, at most 9), becomes the
   target the same way; when there is none, restarts the timer +0x54 with FUN_00bdd1b0 for 500 to 1000 ms. Native
   takes the object in EAX. */
struct object_0090f900 {
	int pad0;
	float position[3];
	char pad10[0x44];
	int timer;
	char pad58[8];
	int target;
};
extern unsigned char *DAT_021703d4;
extern unsigned char *DAT_0215ffc0;
float FUN_00bdea30(float *to, float *from);
void FUN_0090f390(struct object_0090f900 *object, char forced);
void __stdcall FUN_00bdd1b0(int *timer, int maximum, int minimum);

__declspec(noinline) void FUN_0090f900(struct object_0090f900 *object)
{
	unsigned char *player = DAT_021703d4;
	unsigned char *human;
	float *position;
	float d;
	float sum;
	int target;
	d = *(float *)(player + 0x14) - object->position[0];
	position = object->position;
	sum = d * d;
	d = *(float *)(player + 0x18) - position[1];
	sum = d * d + sum;
	d = *(float *)(player + 0x1c) - position[2];
	sum = d * d + sum;
	if (sum < 9.0f && *(int *)(player + 0x44) != object->target) {
		target = *(int *)(player + 0x44);
		goto found;
	}
	for (human = DAT_0215ffc0; human != 0; ) {
		if ((human[0x1171] & 4) != 0 && human[0x148] != 0x11 && *(int *)(human + 0x44) != object->target &&
		    !(FUN_00bdea30((float *)(human + 0x14), position) > 9.0f)) {
			target = *(int *)(human + 0x44);
			goto found;
		}
		human = *(unsigned char **)(human + 0x1160);
		if (human == DAT_0215ffc0) {
			break;
		}
	}
	FUN_00bdd1b0(&object->timer, 1000, 500);
	return;
found:
	object->target = target;
	FUN_0090f390(object, 0);
}
