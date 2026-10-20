#include "../cutscene_types.h"
#include "../cutscene_word_list_context.h"
/* Complete 006D7EC0..006D7F26. Public cdecl handler at DD293C+4,
 * kind 3. The existing 006D8A10 C trial is complete compiler context,
 * not helper coverage. Pending-list identity compares pointer words, not
 * string contents. The head reload after each compare follows from the call;
 * original source qualifiers/types are not established by these partial views.
 */
typedef struct CsCircularName { const char *name; } CsCircularName;
typedef struct CsCircularNode {
    unsigned char unknown_00[0x80];
    unsigned int flags;
    unsigned char unknown_84[0x30];
    struct CsCircularNode *next;
    unsigned char unknown_b8[0x18];
    CsCircularName *object;
} CsCircularNode;
typedef struct CsCircularRoot { unsigned char unknown_00[0x233c]; CsWordList pending; } CsCircularRoot;
typedef struct CsCircularOption { CsWord unknown_00,unknown_04; const char *name; } CsCircularOption;
typedef char cs_circular_next_offset[(offsetof(CsCircularNode,next)==0xb4)?1:-1];
typedef char cs_circular_object_offset[(offsetof(CsCircularNode,object)==0xd0)?1:-1];
extern CsCircularNode *DAT_00f9f684;
extern CsCircularRoot *DAT_02527d10;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) void __cdecl FUN_006d7ec0(const CsCircularOption *option)
{
    const char *const *value=&option->name;
    if (*value) {
        CsCircularNode *node=DAT_00f9f684;
        while (node) {
            if (FUN_00c99030(node->object->name,*value)==0) node->flags|=4;
            node=node->next;
            if (node==DAT_00f9f684) break;
        }
        FUN_006d8a10(&DAT_02527d10->pending,(const CsWord *)value);
    }
}
static const CsCircularOption *volatile option_input;
static CsWordList *volatile list_input;
static const CsWord *volatile value_input;
static void (__cdecl *volatile command_entry)(const CsCircularOption *)=FUN_006d7ec0;
static int volatile result;
void comparison_entry(void)
{
    command_entry(option_input);
    result=FUN_006d8a10(list_input,value_input);
}
