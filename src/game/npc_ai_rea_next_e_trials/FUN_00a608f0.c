/* FUN_00a608f0: virtual method (object in ECX, two stack words, ret 8). When the NPC's +0x4c type is 1 and its
   +0x3cc kind is 2, hands the NPC, the flag and the object to FUN_00a60920 (NPC in ECX, flag in AL, the object a stack word it
   pops). The unused EDX parameter stands in for
   the absent second register so that __fastcall gives native's ECX + stack interface. */
/* FUN_00a60920's one stack word (the object), as a struct by value so that LTCG keeps it on the stack. */
struct object_word_00a60920 {
	int object;
};
void __stdcall FUN_00a60920(int npc, char flag, struct object_word_00a60920 word);

__declspec(noinline) void __fastcall FUN_00a608f0(int object, int unused, int npc, char flag)
{
	struct object_word_00a60920 word;
	if (*(int *)(npc + 0x4c) == 1 && *(char *)(npc + 0x3cc) == 2) {
		word.object = object;
		FUN_00a60920(npc, flag, word);
	}
}
