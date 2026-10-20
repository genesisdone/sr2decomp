#include "../cutscene_types.h"
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
void FUN_00926860(unsigned char *object, unsigned char first, unsigned char second, unsigned char skip);
unsigned char *FUN_00a52bb0(const char *name,unsigned char *found);
unsigned char *FUN_00a52c70(const char *name);
/* Inlined name lookup with the shape of native FUN_00a52ca0 (00A52CA0-00A52CC9): a NULL name gives 0; else
 * FUN_00a52bb0 with a cleared found flag and, when the flag stays clear, FUN_00a52c70. Keeping the
 * FUN_00a52c70 result in its own local reproduces the native double TEST EAX after that call. The helper
 * name describes the code; no original name is known. */
static unsigned char *find_object_by_name(const char *name, unsigned char *found)
{
    unsigned char *object;
    if (name==0) return 0;
    *found=0;
    object=FUN_00a52bb0(name,found);
    if (*found==0) {
        unsigned char *other=FUN_00a52c70(name);
        if (other==0) return 0;
        return other;
    }
    return object;
}
/* Whole name command 006CB6E0-006CB722: looks the named object up and calls FUN_00926860(object, 1, 1, 0). The lookup is the
 * inlined helper below; FUN_00a52bb0, FUN_00a52c70 and FUN_00926860 are /GL context stand-ins whose LTCG-chosen
 * interfaces are NOT claimed as native ABI bindings. Compiled with /GS for the cookie in the 00926860 stand-in. */
__declspec(noinline) void __cdecl FUN_006cb6e0(const CsNameCommandTrial *option)
{
    unsigned char found;
    unsigned char *object=find_object_by_name(option->name,&found);
    if (object!=0) FUN_00926860(object,1,1,0);
}
