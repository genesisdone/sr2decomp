/* Whole native zero initializer. Offsets 0/+4 are zero words; original
 * declared types are unknown. Volatile is a recovery ordering device,
 * not a claim about the original declaration. */
typedef struct CsTwoZeroWords { volatile unsigned int first,second; } CsTwoZeroWords;
__declspec(noinline) void __fastcall FUN_006c9da0(CsTwoZeroWords *record)
{
    record->first=0u;
    record->second=0u;
}
