#include "../cutscene_types.h"
/* Whole four-slot lookup 006bf300..006bf335. Native EDI=slots,
 * name on stack, AL=result. The zero flag is required after a name match. */
typedef struct CsFourNameSlots { const char *names[4]; int flags[4]; } CsFourNameSlots;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) unsigned char __cdecl FUN_006bf300(const CsFourNameSlots *slots, const char *name)
{
    /* Address taken only so /LTCG keeps the name a stack argument, as natively. */
    const char **keep=&name;
    unsigned int index=0;
    (void)keep;
    do {
        const char *entry=slots->names[index];
        if (entry!=0 && FUN_00c99030(name,entry)==0 && slots->flags[index]==0)
            return 1;
        ++index;
    } while (index<4);
    return 0;
}
static const CsFourNameSlots *volatile slots_input;
static const char *volatile name_input;
static unsigned char volatile result;
void comparison_entry(void) { result=FUN_006bf300(slots_input,name_input); }
