/* FUN_00a60a50: unless the object's vtable slot 11 (+0x2c; runtime target unknown, certified only as the audited
   literal call chain) reports it handled, runs FUN_00a60530 and FUN_00a60610 on it; when byte +0x178 is set, sends
   message 0x19b to its +0x174 human (FUN_009695f0) and calls FUN_0096cb70(human, 0, 0, 0, 1); when bit 3 of byte
   +0x72 is set, passes bit 7 of the DAT_021703d4 player's +0x110c flags to FUN_00966720 for the human. The method
   takes the object in ECX (one-parameter __fastcall, the C spelling of a thiscall); FUN_009695f0 is a thiscall
   with one stack word, written as __fastcall taking that word in a one-member struct (a struct argument goes on
   the stack under __fastcall, so EDX is left alone as in the thiscall). */
struct object_a60a50;
typedef unsigned char (__fastcall *handled_fn)(struct object_a60a50 *self);
struct object_a60a50 {
	handled_fn *vtable;
	unsigned char pad_04[0x6e];
	unsigned char flags_72;
	unsigned char pad_73[0x101];
	int human;
	unsigned char notify;
};
extern unsigned char *DAT_021703d4;
void FUN_00a60530(struct object_a60a50 *object);
void __stdcall FUN_00a60610(struct object_a60a50 *object);
struct message_arg_a60a50 {
	int *message;
};
void __fastcall FUN_009695f0(int human, struct message_arg_a60a50 argument);
void FUN_0096cb70(int human, int a, int b, int c, int d);
void __stdcall FUN_00966720(int human, unsigned char flag);

__declspec(noinline) void __fastcall FUN_00a60a50(struct object_a60a50 *object)
{
	int message;
	struct message_arg_a60a50 argument;
	if (object->vtable[11](object)) {
		return;
	}
	FUN_00a60530(object);
	FUN_00a60610(object);
	if (object->notify != 0) {
		message = 0x19b;
		argument.message = &message;
		FUN_009695f0(object->human, argument);
		FUN_0096cb70(object->human, 0, 0, 0, 1);
	}
	if ((object->flags_72 & 8) != 0) {
		FUN_00966720(object->human, (unsigned char)(*(unsigned int *)(DAT_021703d4 + 0x110c) >> 7) & 1);
	}
}
