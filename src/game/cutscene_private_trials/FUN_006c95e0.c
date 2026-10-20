/* Whole 0x4c-record append: 006c95e0..006c964d. Native EAX=list, EDX=value.
 * The final 36 bytes are copied as one aggregate (REP MOVSD in original). */
#include "../cutscene_types.h"
typedef struct CsWordBlock9 { CsWord words[9]; } CsWordBlock9;
typedef struct CsRecord4c {
    CsWord field_00,field_04;
    unsigned char field_08,unknown_09[3];
    CsWord field_0c,field_10,field_14,field_18,field_1c,field_20;
    float field_24;
    CsWordBlock9 field_28;
} CsRecord4c;
typedef struct CsRecord4cList { CsRecord4c *items; int capacity,count; } CsRecord4cList;
typedef char check_record_size[(sizeof(CsRecord4c)==0x4c)?1:-1];
__declspec(noinline) int __cdecl FUN_006c95e0(CsRecord4cList *list, const CsRecord4c *value)
{
    int index = list->count;
    CsRecord4c *destination;
    if (index+1 > list->capacity)
        return -1;
    list->count = index+1;
    destination = list->items+index;
    destination->field_00 = value->field_00;
    destination->field_04 = value->field_04;
    destination->field_08 = value->field_08;
    destination->field_0c = value->field_0c;
    destination->field_10 = value->field_10;
    destination->field_14 = value->field_14;
    destination->field_18 = value->field_18;
    destination->field_1c = value->field_1c;
    destination->field_20 = value->field_20;
    destination->field_24 = value->field_24;
    destination->field_28 = value->field_28;
    return index;
}
static CsRecord4cList *volatile output;
static const CsRecord4c *volatile input;
static volatile int result;
void comparison_entry(void) { result=FUN_006c95e0(output,input); }
