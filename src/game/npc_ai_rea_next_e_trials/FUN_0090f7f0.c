/* FUN_0090f7f0: for each of the (object[+4])+0x48 entries of the array at object+8, FUN_0090f390(entry, 1). */
void FUN_0090f390(int entry, char forced);

/* The stack word (object) as a one-member struct by value, so that LTCG keeps it on the stack as natively. */
struct word_0090f7f0 {
	int object;
};

__declspec(noinline) void FUN_0090f7f0(struct word_0090f7f0 word)
{
	int object = word.object;
	unsigned int index;
	for (index = 0; index < *(unsigned char *)(*(int *)(object + 4) + 0x48); index++) {
		FUN_0090f390(((int *)(object + 8))[index], 1);
	}
}
