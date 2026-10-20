#include "../cutscene_types.h"
/* Whole camera-state reset 006cb5e0..006cb674. Offset views only.
 * Word vectors retain MOV copies; time fields retain x87 float stores. */
typedef struct CsMatrix9 { CsWord words[9]; } CsMatrix9;
typedef struct CsMatrixTween {
    unsigned char active,unknown_01[3];
    CsWord blend;
    float start_time;
    CsMatrix9 start;
    float end_time;
    CsMatrix9 end;
} CsMatrixTween;
typedef struct CsShotCameraResetView {
    unsigned char unknown_00[0x1c];
    CsTweenVector camera;
} CsShotCameraResetView;
typedef struct CsInstanceCameraResetView {
    unsigned char unknown_0000[0x1540];
    CsShotCameraResetView *shot;
    unsigned char unknown_1544[0x3c];
    CsMatrixTween matrix;
} CsInstanceCameraResetView;
typedef char cs_reset_matrix_offset[(offsetof(CsInstanceCameraResetView,matrix)==0x1580 && offsetof(CsMatrixTween,end_time)==0x30)?1:-1];
extern CsInstanceCameraResetView *DAT_02527d10;
extern CsWord DAT_025f5b20,DAT_025f5b24,DAT_025f5b28;
extern CsMatrix9 DAT_025f5b5c;
__declspec(noinline) void __cdecl FUN_006cb5e0(void)
{
    CsInstanceCameraResetView *instance=DAT_02527d10;
    if (instance!=0) {
        CsTweenVector *camera=&instance->shot->camera;
        camera->active=0;
        camera->start.x=DAT_025f5b20;
        camera->start.y=DAT_025f5b24;
        camera->start.z=DAT_025f5b28;
        camera->end.x=DAT_025f5b20;
        camera->end.y=DAT_025f5b24;
        camera->end.z=DAT_025f5b28;
        camera->end_time=0.0f;
        camera->start_time=0.0f;
        instance->matrix.active=0;
        instance->matrix.start=DAT_025f5b5c;
        instance->matrix.end=DAT_025f5b5c;
        instance->matrix.end_time=0.0f;
        instance->matrix.start_time=0.0f;
    }
}
