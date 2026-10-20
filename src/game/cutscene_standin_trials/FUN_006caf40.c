#include "../cutscene_types.h"
typedef struct CsCommandOption { CsWord unknown_00[2]; const char *name; CsWord unknown_0c; const char *value; } CsCommandOption;
unsigned char *FUN_00a52bb0(const char *,unsigned char *);
unsigned char *FUN_00a52c70(const char *);
extern unsigned char *__cdecl FUN_00b716e0(const char *);
unsigned char *FUN_0055adf0(void *,CsWord);
void FUN_00559eb0(unsigned char *,void *);
void __stdcall FUN_00558fb0(void *,CsWord,int,int,int);
void __stdcall FUN_009661e0(void *,int);
extern CsWord __fastcall FUN_00931060(const char *);
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
/* Whole rule command 006CAF40-006CAFEE: looks the named object up and its rule by the option's value
 * (FUN_00b716e0). With a rule: clears +10C8, finds the slot's component for the rule's +3C id (FUN_0055adf0),
 * detaches it (FUN_00559eb0), applies the rule's +44 id to the slot (FUN_00558fb0) and refreshes the object
 * (FUN_009661e0). Without one: stores FUN_00931060(value) at +10A8 when nonzero. The lookup is the inlined
 * helper above. FUN_00b716e0 and FUN_00931060 are non-/GL stubs; the other callees are /GL context stand-ins
 * whose LTCG-chosen interfaces are NOT claimed as native ABI bindings. Compiled with /GS for the cookies in
 * the 00558FB0 / 009661E0 stand-ins (both natives carry one). */
__declspec(noinline) void __cdecl FUN_006caf40(const CsCommandOption *option)
{
    unsigned char found;
    unsigned char *object=find_object_by_name(option->name,&found);
    unsigned char *rule,*slot,*component;
    CsWord result;
    if (object==0 || option->value==0) return;
    rule=FUN_00b716e0(option->value);
    if (rule!=0) {
        object[0x10c8]=0;
        slot=object+0x10c4;
        component=FUN_0055adf0(slot,*(CsWord *)(rule+0x3c));
        if (component!=0) {
            *(CsWord *)(component+0xc0)=0;
            FUN_00559eb0(component,slot);
        }
        FUN_00558fb0(slot,*(CsWord *)(rule+0x44),1,0,0);
        FUN_009661e0(object,0);
        return;
    }
    result=FUN_00931060(option->value);
    if (result!=0) *(CsWord *)(object+0x10a8)=result;
}
