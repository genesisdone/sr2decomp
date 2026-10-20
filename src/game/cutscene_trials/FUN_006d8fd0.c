/* Whole current-shot duration selection: 006d8fd0..006d902a.
 * CSC path subtracts start from end. Definition path converts an unsigned
 * frame word via signed FILD plus 2^32 correction, then divides by the exact
 * double at E5BF68. No premature float rounding is introduced. */
#include "../cutscene_types.h"
typedef struct CsDurationCameraShot { float start,end; unsigned char unknown_08[0x60]; } CsDurationCameraShot;
typedef struct CsDurationCameraFile { unsigned short unknown_00,count; CsDurationCameraShot *shots; } CsDurationCameraFile;
typedef struct CsDurationShot {
    unsigned char unknown_000[0x15c];
    int frame_bits;
    unsigned char unknown_160[0x10];
} CsDurationShot;
typedef struct CsDurationInstance {
    unsigned char unknown_0000[0x1534];
    CsDurationShot *shots;
} CsDurationInstance;
extern CsDurationCameraFile *DAT_025f6248;
extern CsDurationInstance *DAT_02527d10;
extern int DAT_027e670c;
extern float DAT_027e6714,DAT_00e5bfd8;
extern double DAT_00e5bf68;
__declspec(noinline) void __cdecl FUN_006d8fd0(void)
{
    CsDurationCameraFile *camera=DAT_025f6248;
    int index=DAT_027e670c;
    int frame_bits;
    double frames;
    if (camera!=0) {
        CsDurationCameraShot *shot=camera->shots+index;
        DAT_027e6714=shot->end-shot->start;
        return;
    }
    frame_bits=DAT_02527d10->shots[index].frame_bits;
    frames=(double)frame_bits;
    if (frame_bits<0)
        frames+=(double)DAT_00e5bfd8;
    DAT_027e6714=(float)(frames/DAT_00e5bf68);
}
