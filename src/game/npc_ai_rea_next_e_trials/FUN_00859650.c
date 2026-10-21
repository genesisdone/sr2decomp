/* FUN_00859650: returns 1 when DAT_0252922c is set, the first record is active (+0x3c == 1) and the second is
   missing, inactive, or differs from it at any of the four 2D points at +0x48..+0x64 by a squared distance of at
   least DAT_00e5cb58; returns 0 when DAT_0252922c is clear or the first record is missing or inactive, or all four
   points agree. The per-point test is an inline helper. Moved from gate npc-ai-rea-next-leaf (deferred there). */
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

__declspec(noinline) U8 __stdcall FUN_00859650(U8 *first, U8 *second) {
 if (!DAT_0252922c || !first || first[0x3c]!=1) return 0;
 if (!second || second[0x3c]!=1) return 1;
 if (far_apart(first+0x48, second+0x48) || far_apart(first+0x50, second+0x50) ||
     far_apart(first+0x58, second+0x58) || far_apart(first+0x60, second+0x60)) return 1;
 return 0;
}
