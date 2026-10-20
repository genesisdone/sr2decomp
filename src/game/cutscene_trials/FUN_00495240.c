#include "../cutscene_types.h"
/* Whole initializer, native final E9 to 00493C80 with ECX=5.
 * Tail edge is individually pinned, with wrong-opcode rejection required. */
extern void __cdecl FUN_004a0fb0(void);
extern void __fastcall FUN_00493c80(int mode);
extern CsWord DAT_025f624c;
extern float DAT_025f6250,DAT_025f6254,DAT_025f6258,DAT_025f625c,DAT_025f6260,DAT_025f6264,DAT_025f6268,DAT_025f626c,DAT_025f6270,DAT_025f6274,DAT_025f6278,DAT_025f627c;
__declspec(noinline) void __cdecl FUN_00495240(void)
{
    FUN_004a0fb0();DAT_025f6250=0.0f;DAT_025f624c=0;DAT_025f6254=0.0f;DAT_025f6258=0.0f;
    DAT_025f625c=1.0f;DAT_025f626c=1.0f;DAT_025f627c=1.0f;
    DAT_025f6260=0.0f;DAT_025f6264=0.0f;DAT_025f6268=0.0f;DAT_025f6270=0.0f;DAT_025f6274=0.0f;DAT_025f6278=0.0f;
    FUN_00493c80(5);
}
