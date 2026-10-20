#include "../cutscene_types.h"
typedef struct CsXmlNode { const char *name; struct CsXmlNode *next,*children; const char *value; } CsXmlNode;
CsXmlNode *FUN_00bfbee0(CsXmlNode *root, const char *name);
void FUN_00b74ef0(const char *tag,float *output,CsXmlNode *node);
extern const char DAT_00ddfc8c[],DAT_00de7228[],DAT_00e45544[];
/* Whole vector XML reader 006CED90-006CEDD4: finds the tag's child node and reads three floats from it.
 * Native root EAX, tag ECX (moved to EDI, 006CED96), output on the stack. Taking the output parameter's address
 * (keep, otherwise unused) keeps it a stack word under /LTCG, as natively. FUN_00bfbee0 and FUN_00b74ef0 are
 * /GL context stand-ins; their LTCG-chosen interfaces are NOT claimed as native ABI bindings. Compiled with /GS
 * for the cookie in the FUN_00b74ef0 stand-in (native 00B74EF0 carries one). */
__declspec(noinline) void __cdecl FUN_006ced90(CsXmlNode *root, const char *tag, float *output)
{
    float **keep=&output;
    CsXmlNode *node=FUN_00bfbee0(root,tag);
    if (node!=0) {
        FUN_00b74ef0(output,DAT_00ddfc8c,node);
        FUN_00b74ef0(output+1,DAT_00de7228,node);
        FUN_00b74ef0(output+2,DAT_00e45544,node);
    }
    (void)keep;
}
