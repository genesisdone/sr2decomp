/* FUN_008598a0: returns 1 when DAT_0252922c is set, both records are present and active (+0x3c non-zero) and all
   four 2D points at +0x48..+0x64 lie within a squared distance DAT_00e5cb58 of each other; otherwise 0. The sibling
   of FUN_00859650, with the same inline per-point test. Moved from gate npc-ai-rea-next-leaf (deferred there). */
typedef unsigned char U8;
typedef struct { float x, y; } vec2_t;
extern U8 DAT_0252922c;
extern double DAT_00e5cb58;
static __forceinline int far_apart(U8 *a, U8 *b) {
 vec2_t delta;
 float squared;
 delta.x=*(float *)a-*(float *)b;
 delta.y=*(float *)(a+4)-*(float *)(b+4);
 squared=delta.x*delta.x+delta.y*delta.y;
 return !(squared<DAT_00e5cb58);
}

__declspec(noinline) U8 __stdcall FUN_008598a0(U8 *first, U8 *second) {
 if (!DAT_0252922c || !second || !first || !second[0x3c] || !first[0x3c]) return 0;
 if (far_apart(first+0x48, second+0x48) || far_apart(first+0x50, second+0x50) ||
     far_apart(first+0x58, second+0x58) || far_apart(first+0x60, second+0x60)) return 0;
 return 1;
}
