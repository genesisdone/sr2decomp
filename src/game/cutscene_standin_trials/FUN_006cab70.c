#include "../cutscene_types.h"
/* Whole command handler: looks the object up by name, hashes the text option with FUN_00bdca30, looks the
 * marker up with FUN_00a5eb50, stores 7 in DAT_02527d28 and calls FUN_006ca560(object, marker, 2).
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsNameTextCommandTrial { unsigned char unknown_00[8]; const char *name; const char *text; } CsNameTextCommandTrial;
unsigned int *__stdcall FUN_00bdca30(unsigned int *output, unsigned int seed, const char *text);
unsigned char *FUN_00a5eb50(const unsigned int *key);
void FUN_006ca560(unsigned char *object, unsigned char *marker, int flag);
extern CsWord DAT_02527d28;
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
__declspec(noinline) void __cdecl FUN_006cab70(const CsNameTextCommandTrial *option)
{
    /* One scratch word, as native (006CAB13, 006CAB39): first the found flag, then the hash key. */
    union { unsigned char found; unsigned int key; } scratch;
    unsigned char *object=find_object_by_name(option->name,&scratch.found);
    if (object!=0) {
        unsigned char *marker=FUN_00a5eb50(FUN_00bdca30(&scratch.key,0,option->text));
        if (marker!=0) {
            DAT_02527d28=7;
            FUN_006ca560(object,marker,2);
        }
    }
}
