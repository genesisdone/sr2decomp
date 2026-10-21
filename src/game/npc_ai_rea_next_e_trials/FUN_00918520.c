/* FUN_00918520: hashes the name with FUN_00bdcb30 (seed 0, case-folded CRC-style table hash), then returns the
   first 0xd0-byte record in the table at 0x02ad7040 (count DAT_025295bc) whose +4 word equals the hash, or NULL.
   Native takes the name in ECX and forwards it. */
unsigned int * __stdcall FUN_00bdcb30(const char *string, unsigned int seed, unsigned int *out);
extern unsigned char DAT_02ad7040[];
extern int DAT_025295bc;

__declspec(noinline) unsigned char *FUN_00918520(const char *name)
{
	unsigned int hash;
	unsigned char *record;
	int index;
	FUN_00bdcb30(name, 0, &hash);
	index = 0;
	if (0 < DAT_025295bc) {
		record = DAT_02ad7040;
		do {
			if (*(unsigned int *)(record + 4) == hash) {
				return record;
			}
			index = index + 1;
			record = record + 0xd0;
		} while (index < DAT_025295bc);
	}
	return 0;
}
