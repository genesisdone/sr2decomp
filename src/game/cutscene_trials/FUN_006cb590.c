/* Complete AL-result predicate 006cb590..006cb5d7.
 * Native x87 comparison accepts ordered less/equal and rejects greater/unordered:
 * 006cb5b7 TEST AH,41 / JNP, after comparing shot time against global time.
 * The native code forms a pointer to the shot's +1C block (ADD EAX,1C) and
 * reads its byte at +0 and float at +18, so that block is a nested view here.
 * Field names describe offsets only; their gameplay meaning is not established.
 */
#include "../cutscene_types.h"
typedef struct CsShotPredicateSub {
    unsigned char flag_00;
    unsigned char unknown_01[0x17];
    float time_18;
} CsShotPredicateSub;
typedef struct CsShotPredicateView {
    unsigned char unknown_00[0x1c];
    CsShotPredicateSub sub_1c;
} CsShotPredicateView;
typedef struct CsPredicateInstanceView {
    unsigned char unknown_00[0x1540];
    CsShotPredicateView *shot;
} CsPredicateInstanceView;
extern CsPredicateInstanceView *DAT_02527d10;
extern float DAT_027e6710;
static __forceinline int cs_sub_ok(const CsShotPredicateSub *sub)
{
    if (sub->flag_00) return DAT_027e6710 >= sub->time_18;
    return 1;
}
__declspec(noinline) unsigned char __cdecl FUN_006cb590(void)
{
    if (!DAT_02527d10) return 1;
    return (unsigned char)cs_sub_ok(&DAT_02527d10->shot->sub_1c) == 1;
}
