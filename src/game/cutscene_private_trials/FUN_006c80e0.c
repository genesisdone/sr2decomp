/* Entire guarded instance-list membership predicate: 006c80e0..006c8124.
 * Native input ESI; authoritative return AL. Instance list begins +b10.
 * No claimed public meaning for the flag at +aff or the stored word identity. */
#include "../cutscene_types.h"
typedef struct CsMembershipView {
    unsigned char unknown_000[0xaff];
    unsigned char field_aff;
    unsigned char unknown_b00[0x10];
    CsWordList list;
} CsMembershipView;
typedef char check_membership_list[(offsetof(CsMembershipView,list)==0xb10)?1:-1];
extern CsMembershipView *DAT_02527d10;
extern unsigned char DAT_02527d14;
__declspec(noinline) unsigned char __cdecl FUN_006c80e0(CsWord value)
{
    if (DAT_02527d14!=0 && DAT_02527d10->field_aff==0) {
        int count=DAT_02527d10->list.count;
        int index=0;
        if (count>0) {
            const CsWord *item=DAT_02527d10->list.items;
            do {
                if (*item==value)
                    return 1;
                ++index;
                ++item;
            } while (index<count);
        }
    }
    return 0;
}
static volatile CsWord input;
static volatile unsigned char result;
void comparison_entry(void) { result=FUN_006c80e0(input); }
