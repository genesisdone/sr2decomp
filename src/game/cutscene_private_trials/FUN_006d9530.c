#include "../cutscene_types.h"
#include <string.h>
/* Whole 006d9530..006d9601. Native UTF-16 input=EDI; float result=ST0.
 * Character tests deliberately use only each UTF-16 word's low byte, as at
 * 006D9560/006D9580. Empty-input indexing is not given an invented guard.
 * 006D953E..006D9552 is VC8's inline wcslen expansion (/O2 implies /Oi);
 * the length is formed directly in the index register, then decremented.
 */
extern float DAT_00e38ae0;
extern double DAT_00e5c0d8;
extern int __cdecl FUN_00c9a551(int character);
extern int __cdecl FUN_00c9a45a(int character);
extern int __cdecl FUN_00c9ac9a(const unsigned short *text);
__declspec(noinline) float __cdecl FUN_006d9530(const wchar_t *text)
{
    int index;
    if (!text)
        return DAT_00e38ae0;
    index = (int)wcslen(text);
    for (--index; index > 0; --index)
        if (!FUN_00c9a551((unsigned char)text[index]))
            break;
    while (index > 0 && FUN_00c9a45a((unsigned char)text[index]))
        --index;
    if (text[index] == 10) {
        int duration = FUN_00c9ac9a(text + index + 1);
        return (float)(duration / DAT_00e5c0d8);
    }
    if (text[index] == 'n' && text[index - 1] == '\\') {
        int duration = FUN_00c9ac9a(text + index + 1);
        return (float)(duration / DAT_00e5c0d8);
    }
    return DAT_00e38ae0;
}
static const unsigned short *volatile text_input;
static float volatile result_output;
void comparison_entry(void) { result_output = FUN_006d9530(text_input); }
