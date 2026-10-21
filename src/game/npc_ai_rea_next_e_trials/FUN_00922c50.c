/* FUN_00922c50: the limits entry of a crew kind at a level: kinds 1, 2, 3, 5, 6 select the pools at DAT_00eb5ba0,
   DAT_00eb5e58, DAT_00eb6110, DAT_00eb5378 and DAT_00eb6eb8 (kind 4 has none); the level must lie within the pool's
   +0x200 .. +0x204 bounds, and the entry is +0x208 table + (level - minimum) * 0x20. 0 otherwise. The switch is an
   audited local jump table. */
struct limits_922c50 {
	int words[8];
};
struct pool_922c50 {
	unsigned char pad[0x200];
	int minimum;
	int maximum;
	struct limits_922c50 *table;
};
extern struct pool_922c50 DAT_00eb5ba0, DAT_00eb5e58, DAT_00eb6110, DAT_00eb5378, DAT_00eb6eb8;

__declspec(noinline) struct limits_922c50 *FUN_00922c50(int kind, int level)
{
	struct pool_922c50 *pool;
	switch (kind) {
	case 5:
		pool = &DAT_00eb5378;
		break;
	case 6:
		pool = &DAT_00eb6eb8;
		break;
	case 1:
		pool = &DAT_00eb5ba0;
		break;
	case 2:
		pool = &DAT_00eb5e58;
		break;
	case 3:
		pool = &DAT_00eb6110;
		break;
	default:
		return 0;
	}
	if (level < pool->minimum || level > pool->maximum) {
		return 0;
	}
	return pool->table + (level - pool->minimum);
}
