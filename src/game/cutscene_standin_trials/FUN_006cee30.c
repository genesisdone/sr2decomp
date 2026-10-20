#include "../cutscene_types.h"
typedef struct CsXmlNode { const char *name; struct CsXmlNode *next,*children; const char *value; } CsXmlNode;
typedef struct CsDofXmlValues { float max_coc_radius,preblur_radius,near_value,ideal_near,ideal_far,far_value; } CsDofXmlValues;
typedef char cs_dof_xml_size[(sizeof(CsDofXmlValues)==24)?1:-1];
CsXmlNode *FUN_00bfbee0(CsXmlNode *root, const char *name);
void FUN_00b74ef0(float *output, const char *tag, CsXmlNode *node);
extern const char DAT_00e0cb9c[],DAT_00e0cbac[],DAT_00e0cbbc[],DAT_00e0cbc4[],DAT_00e0cbd0[],DAT_00e0cbdc[];
/* Whole six-value DOF XML reader 006CEE30-006CEE9A: finds the tag's child node and reads six floats from it;
 * no node guard in this original. Native root EAX, tag ECX, output on the stack (kept there by keep). Field
 * names follow the tags read and are analyst names. Stand-ins and /GS as in FUN_006ced90. */
__declspec(noinline) void __cdecl FUN_006cee30(CsXmlNode *root, const char *tag, CsDofXmlValues *output)
{
    CsDofXmlValues **keep=&output;
    CsXmlNode *node=FUN_00bfbee0(root,tag);
    FUN_00b74ef0(&output->max_coc_radius,DAT_00e0cb9c,node);
    FUN_00b74ef0(&output->preblur_radius,DAT_00e0cbac,node);
    FUN_00b74ef0(&output->near_value,DAT_00e0cbbc,node);
    FUN_00b74ef0(&output->ideal_near,DAT_00e0cbc4,node);
    FUN_00b74ef0(&output->ideal_far,DAT_00e0cbd0,node);
    FUN_00b74ef0(&output->far_value,DAT_00e0cbdc,node);
    (void)keep;
}
