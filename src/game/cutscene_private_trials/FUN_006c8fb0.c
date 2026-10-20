#include "../cutscene_types.h"
/* Whole 006c8fb0..006c9032. Guarded vector/matrix update, native vector EDX,
 * matrix on stack. No partial guard, null check or matrix copy is omitted. */
typedef struct CsFloat3 { float x,y,z; } CsFloat3;
typedef struct CsMatrix9 { CsWord words[9]; } CsMatrix9;
typedef union CsVector3Bits { CsFloat3 floats; CsWords3 words; } CsVector3Bits;
typedef struct CsInstanceVectorMatrixView {
    unsigned char unknown_0000[0x1610];
    CsVector3Bits vector;
    CsMatrix9 matrix;
} CsInstanceVectorMatrixView;
extern unsigned char DAT_02527d23;
extern CsInstanceVectorMatrixView *DAT_02527d10;
extern float DAT_0252a6d0,DAT_0252a6d4,DAT_0252a6d8;
__declspec(noinline) void __cdecl FUN_006c8fb0(const CsWords3 *vector, const CsMatrix9 *matrix)
{
    if (DAT_02527d23!=1) {
        CsInstanceVectorMatrixView *instance=DAT_02527d10;
        if (instance!=0 && instance->vector.floats.x==DAT_0252a6d0 &&
            instance->vector.floats.y==DAT_0252a6d4 && instance->vector.floats.z==DAT_0252a6d8) {
            instance->vector.words.x=vector->x;
            instance->vector.words.y=vector->y;
            instance->vector.words.z=vector->z;
            instance->matrix=*matrix;
        }
    }
}
static const CsWords3 *volatile vector_input;
static const CsMatrix9 *volatile matrix_input;
void comparison_entry(void) { FUN_006c8fb0(vector_input,matrix_input); }
