#include "../cutscene_types.h"
/* Whole command handler: looks the object up by name, hashes the value option with FUN_00bdcb30, finds its
 * index with FUN_006abce0 and, when found, calls FUN_006ae420(object, index, 0xFFFF) and FUN_006abc10(object).
 * Callee stand-ins live in the context file; their interfaces are not claimed as native ABI bindings. */
typedef struct CsNameValueCommandTrial { unsigned char unknown_00[8]; const char *name; CsWord unknown_0c; const char *value; } CsNameValueCommandTrial;
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
int FUN_006abce0(const unsigned int *key);
void FUN_006ae420(unsigned char *object, int id, int mask);
int FUN_006abc10(unsigned char *object);
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
__declspec(noinline) void __cdecl FUN_006cbde0(const CsNameValueCommandTrial *option)
{
    /* One scratch word, as native (006CBDF4, 006CBE1B): first the found flag, then the hash key. */
    union { unsigned char found; unsigned int key; } scratch;
    unsigned char *object=find_object_by_name(option->name,&scratch.found);
    if (object!=0 && option->value!=0) {
        int id;
        FUN_00bdcb30(option->value,0,&scratch.key);
        id=FUN_006abce0(&scratch.key);
        if (id!=-1) {
            FUN_006ae420(object,id,0xffff);
            FUN_006abc10(object);
        }
    }
}
