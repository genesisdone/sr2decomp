#include "../cutscene_types.h"
typedef struct CsXmlNode { const char *name; struct CsXmlNode *next,*children; const char *value; } CsXmlNode;
extern const char DAT_00e0d360[],DAT_00ddab70[],DAT_00e0d36c[],DAT_00e0d378[],DAT_00e0cda0[],DAT_00e0cdac[],DAT_00e0d384[];
CsXmlNode *FUN_00bfbee0(CsXmlNode *root, const char *name);
void FUN_00b75050(const char *tag, unsigned char *output, CsXmlNode *node);
void FUN_00b74910(int *output, const char *tag, CsXmlNode *node);
void FUN_006ced90(CsXmlNode *root, const char *tag, CsWords3 *output);
void FUN_006cdb50(CsTweenVector *out, const CsWords3 *value);
void __stdcall FUN_006cdb80(CsWords3 *start, CsWords3 *end, CsTweenVector *out, float start_time, float end_time);
void FUN_006cdbc0(CsBlendView *record, const char *name);
/* Whole vector tween XML reader 006D6C70-006D6D92: under the tag's child node, an untweened value (read only when
 * use_value is 1) sets start=end; a tweened one reads start, end, two frame counts (converted at 30 frames per
 * second) and the blend name. Native root EAX, tag ECX (-> EDI), output and use_value on the stack; keep holds the
 * output a stack word. All callees are /GL context stand-ins; the frame divisor 30.0 is the double at E5BF68. */
__declspec(noinline) void __cdecl FUN_006d6c70(CsXmlNode *root, const char *tag, CsTweenVector *output, unsigned char use_value)
{
    CsTweenVector **keep=&output;
    CsXmlNode *field,*blend;
    unsigned char tweened;
    CsWords3 start,end;
    int start_frame,end_frame;
    if (tag==0) return;
    field=FUN_00bfbee0(root,tag);
    if (field==0) return;
    tweened=0;
    FUN_00b75050(DAT_00e0d360,&tweened,field);
    if (tweened==0) {
        if (use_value==1) {
            FUN_006ced90(field,DAT_00ddab70,&end);
            FUN_006cdb50(output,&end);
        }
        return;
    }
    FUN_006ced90(field,DAT_00e0d36c,&start);
    FUN_006ced90(field,DAT_00e0d378,&end);
    FUN_00b74910(&start_frame,DAT_00e0cda0,field);
    FUN_00b74910(&end_frame,DAT_00e0cdac,field);
    FUN_006cdb80(&start,&end,output,(float)(start_frame/30.0),(float)(end_frame/30.0));
    blend=FUN_00bfbee0(field,DAT_00e0d384);
    FUN_006cdbc0((CsBlendView *)output,blend==0?0:blend->value);
    (void)keep;
}
