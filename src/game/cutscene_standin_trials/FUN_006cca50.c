#include "../cutscene_types.h"
typedef struct CsCommandOption { CsWord unknown_00[2]; const char *name; CsWord unknown_0c; const char *value; } CsCommandOption;
unsigned char *FUN_00a52bb0(const char *,unsigned char *);
unsigned char *FUN_00a52c70(const char *);
void FUN_00bff700(const char *,char *,CsWord);
extern char *__cdecl FUN_00c9a9e0(char *,int),*__cdecl FUN_00c990f0(char *,const char *,CsWord);
extern int __cdecl FUN_006ef510(const char *);
void __stdcall FUN_009695f0(unsigned char *,int *);
/* Inlined name lookup with the shape of native FUN_00a52ca0, as in the certified 006CB6E0 trial. The helper name
 * describes the code; no original name is known. */
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
/* Whole animation command 006CCA50-006CCB54: looks the named object up, cuts the option value's basename at its
 * first '.', resolves it (FUN_006ef510) and, when found, hands the object and the result's address to
 * FUN_009695f0. FUN_006ef510, FUN_00c9a9e0 and FUN_00c990f0 are non-/GL stubs; the other callees are /GL context
 * stand-ins whose LTCG-chosen interfaces are NOT claimed as native ABI bindings. Compiled with /GS (native carries
 * the cookie). */
__declspec(noinline) void __cdecl FUN_006cca50(const CsCommandOption *option)
{
    unsigned char found;
    unsigned char *object=find_object_by_name(option->name,&found);
    if (object!=0 && option->value!=0) {
        char path[260],*extension;
        CsWord length;
        int animation;
        FUN_00bff700(option->value,path,260);
        extension=FUN_00c9a9e0(path,'.');
        if(!extension){FUN_00c990f0(path,path,260);path[259]=0;}
        else{length=(CsWord)(extension-path);if(length>259)length=259;FUN_00c990f0(path,path,length);path[length]=0;}
        animation=FUN_006ef510(path);
        if(animation!=-1)FUN_009695f0(object,&animation);
    }
}
