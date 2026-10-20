extern float DAT_00e888ac;
float FUN_00cdc250(int index, int state);

__declspec(noinline) int FUN_00a45670(int *state)
{
	int count = (state[2] - state[3]) >> 4;
	int **keep_state = &state; /* Native reads its sole input from [esp+4]. */
	(void)keep_state;
	if (count >= 1) count = 1;
	DAT_00e888ac = FUN_00cdc250(-count, (int)state);
	return 0;
}
