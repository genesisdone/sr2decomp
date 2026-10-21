/* FUN_0093c210: tries to start the next job. Gives up (returns 0) when there is no job manager (DAT_0215e5bc), when
   FUN_00957660 refuses, or when the manager's slot (vtable +0x14) is outside 0..DAT_0252a0d8. Takes a limit
   (DAT_02528cf0 + 1 in mode DAT_02528b48 == 1 with DAT_02528b49 clear, else FUN_0093c1d0) and calls FUN_0093a8a0
   while DAT_0215d7a8 is at or above it, giving up when one fails; then needs FUN_009392e0(4). When the slot's kind
   (FUN_00ab51f0) is 1, needs the player's +0xf00 record with +0xa4 clear, FUN_0093b0a0 to fill a request and
   FUN_00939f30 to accept it. Otherwise asks FUN_00957860 for a plan (with FUN_009576a0's flag) and hands the plan's
   id, value and word to FUN_0093a2e0. Returns 1 on success. */
typedef struct request_0093c210 {
	int words[3];
} request_t;
typedef struct plan_0093c210 {
	int id;
	int words[3];
	float value;
	int word;
	int word_18;
} plan_t;
struct manager_0093c210;
typedef int (__fastcall *manager_slot)(struct manager_0093c210 *manager);
struct manager_0093c210 {
	manager_slot *vtable;
};
extern struct manager_0093c210 *DAT_0215e5bc;
extern int DAT_0252a0d8;
extern volatile char DAT_02528b48;
extern volatile char DAT_02528b49;
extern unsigned short DAT_02528cf0;
extern int DAT_0215d7a8;
extern unsigned char *DAT_021703d4;
char FUN_00957660(void);
int FUN_0093c1d0(void);
char FUN_0093a8a0(void);
unsigned char FUN_009392e0(int input);
unsigned char FUN_00ab51f0(int index);
char FUN_0093b0a0(request_t *request);
int FUN_00939f30(request_t *request, int flags);
char FUN_009576a0(void);
void FUN_00957860(int flags, plan_t *plan, unsigned char kind, char flag);
int FUN_0093a2e0(int id, float value, int word, int zero);

__declspec(noinline) char FUN_0093c210(void)
{
	request_t request;
	plan_t plan;
	int slot;
	int limit;
	char ready;
	char flag;
	unsigned char *record;
	if (DAT_0215e5bc == 0 || FUN_00957660() == 0 || DAT_0215e5bc == 0) {
		goto fail;
	}
	slot = DAT_0215e5bc->vtable[0x14 / 4](DAT_0215e5bc);
	if (slot < 0 || slot >= DAT_0252a0d8) {
		goto fail;
	}
	if (DAT_02528b48 == 1 && DAT_02528b49 == 0) {
		limit = DAT_02528cf0 + 1;
	} else {
		limit = FUN_0093c1d0();
	}
	while (DAT_0215d7a8 >= limit) {
		if (FUN_0093a8a0() == 0) {
			goto fail;
		}
	}
	if (FUN_009392e0(4) == 0) {
		goto fail;
	}
	ready = 0;
	record = *(unsigned char **)(DAT_021703d4 + 0xf00);
	if (record != 0 && *(int *)(record + 0xa4) == 0) {
		ready = 1;
	}
	if (FUN_00ab51f0(slot) == 1) {
		if (ready == 0) {
			goto fail;
		}
		if (FUN_0093b0a0(&request) == 0) {
			goto fail;
		}
		if (FUN_00939f30(&request, 0) == 0) {
			goto fail;
		}
		return 1;
	}
	flag = FUN_009576a0();
	FUN_00957860(0, &plan, FUN_00ab51f0(slot), flag);
	if (plan.id == 0) {
		goto fail;
	}
	if (FUN_0093a2e0(plan.id, plan.value, plan.word, 0) == 0) {
		goto fail;
	}
	return 1;
fail:
	return 0;
}
