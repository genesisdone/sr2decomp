/* Whole XML child lookup dependency: 00bfbee0..00bfbf0f (47-byte span).
 * Native EAX=root, EDI=name. Includes four internal alignment bytes.
 * Node +0 name, +4 next, +8 children, +c value: observed accesses only. */
#include "../cutscene_types.h"
typedef struct CsXmlNode {
    const char *name;
    struct CsXmlNode *next,*children;
    const char *value;
} CsXmlNode;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) CsXmlNode * __cdecl FUN_00bfbee0(CsXmlNode *root, const char *name)
{
    CsXmlNode *node;
    if (root!=0) {
        for (node=root->children; node!=0; node=node->next) {
            if (FUN_00c99030(node->name,name)==0)
                return node;
        }
    }
    return 0;
}
static CsXmlNode *volatile root_input;
static const char *volatile name_input;
static CsXmlNode *volatile result;
void comparison_entry(void) { result=FUN_00bfbee0(root_input,name_input); }
