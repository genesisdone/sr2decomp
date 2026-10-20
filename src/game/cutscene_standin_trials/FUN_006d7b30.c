#include "../cutscene_types.h"
/* Whole record-flag toggle 006D7B30-006D7C12: hashes the name (FUN_00bdc9b0; 0 matches every record) and, in
 * every container's records whose hash matches, sets (flag 0) or clears bits 4-5 of the 64-bit flags at +30 and
 * of the chosen target's +5C bit 22. The flags field is 64 bits: native rewrites the high word (006D7B86/91) and
 * tests bit 16 as a 64-bit AND (006D7BAA-B2). The target is +48 when present with bit 16 set, else +40. Field names
 * are offset views. Native name ECX, flag on the stack. */
typedef struct CsToggleTarget { unsigned char unknown_00[0x58]; int field_58; unsigned int flags_5c; } CsToggleTarget;
typedef struct CsToggleRecord {
    unsigned char unknown_00[0x24];
    unsigned int name_hash;
    CsWord unknown_28,unknown_2c;
    unsigned __int64 flags_30;
    CsWord unknown_38,unknown_3c;
    CsToggleTarget *target_40;
    CsWord unknown_44;
    CsToggleTarget *target_48;
    CsWord unknown_4c;
} CsToggleRecord;
typedef struct CsToggleContainer { unsigned char unknown_00[0x48]; int count; CsToggleRecord *items; } CsToggleContainer;
typedef char cs_toggle_record_stride[(sizeof(CsToggleRecord)==0x50)?1:-1];
typedef char cs_toggle_target_offset[(offsetof(CsToggleRecord,target_48)==0x48 && offsetof(CsToggleRecord,flags_30)==0x30)?1:-1];
extern int DAT_00f6fbc4;
extern CsToggleContainer *DAT_00f6fbd8[];
extern unsigned int __fastcall FUN_00bdc9b0(const char *text);
__declspec(noinline) void __cdecl FUN_006d7b30(const char *name,unsigned char flag)
{
    unsigned int hash=FUN_00bdc9b0(name);
    int container_index=0;
    while (container_index<DAT_00f6fbc4) {
        int index=0;
        while (index<DAT_00f6fbd8[container_index]->count) {
            if (hash==0 || hash==DAT_00f6fbd8[container_index]->items[index].name_hash) {
                CsToggleRecord *record=&DAT_00f6fbd8[container_index]->items[index];
                CsToggleTarget *target;
                if (!flag) record->flags_30|=0x30;
                else record->flags_30&=~(unsigned __int64)0x30;
                if (record->target_48!=0 && (record->flags_30&0x10000)!=0) target=record->target_48;
                else target=record->target_40;
                if (target) {
                    if (!flag) target->flags_5c|=0x400000;
                    else if (target->field_58) target->flags_5c&=0xffbfffff;
                }
            }
            ++index;
        }
        ++container_index;
    }
}
