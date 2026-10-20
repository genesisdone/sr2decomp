#include "../cutscene_types.h"
/* Whole command handler: looks the object up by name, calls FUN_006fc610(object, 20, 0), sets bit 1 of the
 * attachment byte +0x130 when an attachment exists, and sets bit 0x400000 of the object word +0xCC.
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
void FUN_006fc610(unsigned char *object, CsWord value, unsigned char notify);
void *FUN_00a52bb0(const char *name,unsigned char *found);
void *FUN_00a52c70(const char *name);
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
__declspec(noinline) void __cdecl FUN_006cb780(const CsNameCommandTrial *option)
{
    unsigned char found;
    unsigned char *object=find_object_by_name(option->name,&found);
    if (object!=0) {
        unsigned char *attachment;
        FUN_006fc610(object,20,0);
        attachment=*(unsigned char **)(object+0x570);
        if (attachment!=0) attachment[0x130]|=2;
        *(CsWord *)(object+0xcc)|=0x400000;
    }
}
