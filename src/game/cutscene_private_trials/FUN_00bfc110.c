/* Whole XML matching-child count dependency: 00bfc110..00bfc149.
 * Native EAX=root, name=[ESP+4]. Return counts all matching siblings. */
#include "../cutscene_types.h"
typedef struct CsXmlNode {
    const char *name;
    struct CsXmlNode *next,*children;
    const char *value;
} CsXmlNode;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) int __cdecl FUN_00bfc110(CsXmlNode *root, const char *name)
{
    /* Address taken only so /LTCG keeps the name an incoming stack word, as natively. */
    const char **keep=&name;
    int count=0;
    CsXmlNode *node;
    (void)keep;
    if (root!=0) {
        for (node=root->children; node!=0; node=node->next) {
            if (FUN_00c99030(node->name,name)==0)
                ++count;
        }
    }
    return count;
}
static CsXmlNode *volatile root_input;
static const char *volatile name_input;
static volatile int result;
void comparison_entry(void) { result=FUN_00bfc110(root_input,name_input); }
