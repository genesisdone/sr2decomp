#include "../cutscene_types.h"
typedef struct CsXmlNode { const char *name; struct CsXmlNode *next,*children; const char *value; } CsXmlNode;
extern const char DAT_00e0d134[],DAT_00e0d360[],DAT_00ddab70[],DAT_00e0d36c[],DAT_00e0d378[],DAT_00e0cda0[],DAT_00e0cdac[],DAT_00e0d384[];
CsXmlNode *FUN_00bfbee0(CsXmlNode *root, const char *name);
void FUN_00b75050(const char *tag, unsigned char *output, CsXmlNode *node);
void FUN_00b74910(int *output, const char *tag, CsXmlNode *node);
void FUN_006cee30(CsXmlNode *root, const char *tag, CsWords6 *output);
void FUN_006d7170(CsTweenSix *out, const CsWords6 *value);
void __stdcall FUN_006d71d0(CsWords6 *start, CsWords6 *end, CsTweenSix *out, float start_time, float end_time);
void FUN_006d7230(CsBlendView *record, const char *name);
/* Whole six-value tween XML reader 006D6EB0-006D6FC1 for the tag at E0D134: like 006D6C70 with six-word values and
 * no use_value guard. Native root EAX, output on the stack (keep). All callees are /GL context stand-ins; the frame
 * divisor 30.0 is the double at E5BF68. */
__declspec(noinline) void __cdecl FUN_006d6eb0(CsXmlNode *root, CsTweenSix *output)
{
    CsTweenSix **keep=&output;
    CsXmlNode *field,*blend;
    unsigned char tweened;
    CsWords6 start,end;
    int start_frame,end_frame;
    field=FUN_00bfbee0(root,DAT_00e0d134);
    if (field==0) return;
    tweened=0;
    FUN_00b75050(DAT_00e0d360,&tweened,field);
    if (tweened==0) {
        FUN_006cee30(field,DAT_00ddab70,&end);
        FUN_006d7170(output,&end);
        return;
    }
    FUN_006cee30(field,DAT_00e0d36c,&start);
    FUN_006cee30(field,DAT_00e0d378,&end);
    FUN_00b74910(&start_frame,DAT_00e0cda0,field);
    FUN_00b74910(&end_frame,DAT_00e0cdac,field);
    FUN_006d71d0(&start,&end,output,(float)(start_frame/30.0),(float)(end_frame/30.0));
    blend=FUN_00bfbee0(field,DAT_00e0d384);
    FUN_006d7230((CsBlendView *)output,blend==0?0:blend->value);
    (void)keep;
}
