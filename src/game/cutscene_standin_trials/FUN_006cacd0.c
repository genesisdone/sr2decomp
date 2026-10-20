#include "../cutscene_types.h"
/* Whole command handler 006CACD0-006CAD1E: looks the named object up and passes it to FUN_009847a0 with the
 * time DAT_00E87998, discarding the float that call leaves in ST0 (006CAD18). FUN_00a52bb0, FUN_00a52c70 and
 * FUN_009847a0 are /GL context stand-ins; the interfaces LTCG chooses for them are NOT claimed as native ABI
 * bindings. This trial compiles with /GS: the cookie in the FUN_009847a0 stand-in is what moves its first two
 * inputs to ECX/EDX, as native 009847A0 takes them (009847C8/009847D2) while its cookie occupies EAX. */
typedef struct CsNameCommandTrial { unsigned char unknown_00[8]; const char *name; } CsNameCommandTrial;
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
float FUN_009847a0(void *first, void *second, void *object, float time, int flag0, int flag1);
extern float DAT_00e87998;
__declspec(noinline) void __cdecl FUN_006cacd0(const CsNameCommandTrial *option)
{
    unsigned char found;
    void *object=find_object_by_name(option->name,&found);
    if (object==0) return;
    FUN_009847a0(0,0,object,DAT_00e87998,0,0);
}
