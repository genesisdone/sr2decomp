#include "../cutscene_types.h"
typedef struct CsNameTextValueCommandTrial { unsigned char unknown_00[8]; const char *name; const char *text; const char *value; } CsNameTextValueCommandTrial;
unsigned int *__stdcall FUN_00bdca30(unsigned int *output, unsigned int seed, const char *text);
unsigned char *FUN_00a5eb50(const unsigned int *key);
double __cdecl FUN_00c984f5(const char *text);
void FUN_00a3c9a0(unsigned char *object, int duration, const char *target, float scale);
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
__declspec(noinline) void __cdecl FUN_006cb090(const CsNameTextValueCommandTrial *option)
{
    /* One scratch word, as native (006CB0A4, 006CB0CE, 006CB0E9): the found flag, the hash key, then the rounded scale. */
    union { unsigned char found; unsigned int key; float scale; } scratch;
    unsigned char *object=find_object_by_name(option->name,&scratch.found);
    if (object!=0 && option->text!=0) {
        unsigned char *marker=FUN_00a5eb50(FUN_00bdca30(&scratch.key,0,option->text));
        if (marker!=0) {
            scratch.scale=(float)FUN_00c984f5(option->value);
            FUN_00a3c9a0(object,1000,option->text,scratch.scale);
        }
    }
}
