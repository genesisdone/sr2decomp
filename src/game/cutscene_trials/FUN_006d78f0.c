/* Framebuffer Tint: entire 006d78f0..006d79da (234 bytes).
 * Native payload RGB bytes +0/+1/+2, intensity float +4, then floats +8/+c/+10.
 * A nine-word packet is copied to instance+155c. Byte padding +5..+7 in the
 * temporary is not initialized in the original, so this trial does not invent
 * zero stores there. No visual or numerical parity claim without matching.
 * The scaled RGB is staged in its own three-float temporary and copied into
 * the packet as words (006D7967..006D7997); the trailing three floats re-read
 * option->value (006D7997). */
#include "../cutscene_types.h"
typedef struct CsTintValue {
    unsigned char red,green,blue,unknown_03;
    float intensity,field_08,field_0c,field_10;
} CsTintValue;
typedef struct CsTintOption { CsWord unknown_00,unknown_04; const CsTintValue *value; } CsTintOption;
typedef struct CsTintColor { float red,green,blue; } CsTintColor;
typedef struct CsTintPacket {
    CsWord kind;
    unsigned char active,unknown_05[3];
    CsTintColor color;
    float alpha,field_18,field_1c,field_20;
} CsTintPacket;
typedef struct CsTintInstanceView {
    unsigned char unknown_0000[0x155c];
    CsTintPacket tint;
} CsTintInstanceView;
typedef char check_tint_packet[(sizeof(CsTintPacket)==36)?1:-1];
extern CsTintInstanceView *DAT_02527d10;
extern double DAT_00e5c038;
__declspec(noinline) void __cdecl FUN_006d78f0(const CsTintOption *option)
{
    if (option->value->red!=0 || option->value->green!=0 || option->value->blue!=0) {
        const CsTintValue *value=option->value;
        float intensity=value->intensity;
        float red=(float)((double)value->red/DAT_00e5c038);
        float green=(float)((double)value->green/DAT_00e5c038);
        float blue=(float)((double)value->blue/DAT_00e5c038);
        CsTintPacket packet;
        CsTintColor color;
        packet.active=1;
        packet.kind=3;
        color.red=intensity*red;
        color.green=green*intensity;
        color.blue=intensity*blue;
        packet.color=color;
        packet.alpha=1.0f;
        packet.field_18=option->value->field_0c;
        packet.field_1c=option->value->field_08;
        packet.field_20=option->value->field_10;
        DAT_02527d10->tint=packet;
    }
}
