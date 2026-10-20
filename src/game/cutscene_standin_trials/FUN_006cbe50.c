#include "../cutscene_types.h"
/* Whole command handler: looks the object up by name (inlined lookup below) and calls FUN_006abc10 on it.
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
int FUN_006abc10(unsigned char *object);
void *FUN_00a52bb0(const char *name,unsigned char *found);
void *FUN_00a52c70(const char *name);
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
__declspec(noinline) void __cdecl FUN_006cbe50(const CsNameCommandTrial *option)
{
    unsigned char found;
    unsigned char *object=find_object_by_name(option->name,&found);
    if (object!=0) FUN_006abc10(object);
}
