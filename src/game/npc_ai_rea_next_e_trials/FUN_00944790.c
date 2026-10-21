/* FUN_00944790: whether a request can be placed. The kind is 9 when the DAT_027b3c60 record is in state 1 (+0x3c)
   and its +0x90 object's vtable slot 1 reports 13, else 0; FUN_00929540(0, kind, 1) must allow it. Then a request is
   built (flags 1, 0, 0/1, 1/0, 0; words 0, 0, -1; and so on) whose third and fourth flags depend on the same state
   test, and handed to FUN_00942d00; returns whether it accepted. The slot-1 method is a thiscall without stack
   arguments, written as __fastcall with an unused EDX word (the loaded method pointer). */
struct object_00944790;
typedef int (__fastcall *query_fn)(struct object_00944790 *object, int unused);
struct object_00944790 {
	query_fn *vtable;
};
struct record_00944790 {
	char pad[0x3c];
	int state;
	char pad40[0x50];
	struct object_00944790 *object;
};
/* FUN_00942d00 takes the request in ECX (declared __fastcall). */
struct request_00944790 {
	unsigned char active;
	unsigned char flag1;
	unsigned char flag2;
	unsigned char flag3;
	unsigned char flag4;
	unsigned char pad5;
	unsigned short pad6;
	int word8;
	int wordc;
	int target;
	unsigned char flag14;
	unsigned char pad15;
	unsigned short pad16;
	int word18;
	unsigned char flag1c;
	unsigned char pad1d;
	unsigned short pad1e;
	int word20;
	int word24;
	int pad28;
	int pad2c;
	int pad30;
	int pad34;
	int word38;
	unsigned char pad3c;
	unsigned char flag3d;
	unsigned char flag3e;
	unsigned char flag3f;
};
extern struct record_00944790 *DAT_027b3c60;
char FUN_00929540(int kind, int slot, int amount);
int __fastcall FUN_00942d00(struct request_00944790 *request);

static int record_is_special(struct record_00944790 *record)
{
	if (record != 0 && record->state == 1) {
		struct object_00944790 *object = record->object;
		query_fn *vtable = object->vtable;
		query_fn method = vtable[1];
		if (method(object, (int)method) == 13) {
			return 1;
		}
	}
	return 0;
}

static int record_is_special_2(struct record_00944790 *record)
{
	if (record != 0 && record->state == 1) {
		struct object_00944790 *object = record->object;
		query_fn *vtable = object->vtable;
		if (vtable[1](object, (int)vtable[1]) == 13) {
			return 1;
		}
	}
	return 0;
}

__declspec(noinline) char FUN_00944790(void)
{
	struct request_00944790 request;
	int slot = 0;
	if (record_is_special(DAT_027b3c60)) {
		slot = 9;
	}
	if (FUN_00929540(0, slot, 1) == 0) {
		return 0;
	}
	request.flag1 = 0;
	request.flag2 = 0;
	request.flag3 = 1;
	request.flag4 = 0;
	request.word8 = 0;
	request.wordc = 0;
	request.target = -1;
	request.flag14 = 0;
	request.word18 = 0;
	request.flag1c = 0;
	request.word20 = 0;
	request.word24 = 0;
	request.word38 = 0;
	request.flag3e = 0;
	request.active = 1;
	request.flag3d = 1;
	if (!record_is_special_2(DAT_027b3c60)) {
		request.flag2 = 1;
	} else {
		request.flag3 = 0;
		request.flag4 = 1;
	}
	request.flag3f = 1;
	return (char)(FUN_00942d00(&request) != 0);
}
