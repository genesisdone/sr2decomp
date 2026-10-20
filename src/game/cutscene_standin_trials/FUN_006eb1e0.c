#include "../cutscene_types.h"
/* Full packed-orientation component decoder: 006EB1E0..006EB23D.
 * Each signed 16-bit component is scaled by the double at E5C298 (bits 3F10004000000000, written here as
 * the shortest decimal that rounds to exactly those bits) and rounded through one four-byte stack
 * temporary before the store (006EB1F4/208/21D/232). The volatile temporary is what reproduces that
 * rounding round-trip; whether the original source spelled it this way is not known. */
typedef struct CsPackedOrientation { short x,y,z,w; } CsPackedOrientation;
typedef struct CsOrientation { float x,y,z,w; } CsOrientation;
__declspec(noinline) void __cdecl FUN_006eb1e0(CsOrientation *out, const CsPackedOrientation *packed)
{
    volatile float component;
    component=(float)(packed->x*6.103888154029846e-05);
    out->x=component;
    component=(float)(packed->y*6.103888154029846e-05);
    out->y=component;
    component=(float)(packed->z*6.103888154029846e-05);
    out->z=component;
    component=(float)(packed->w*6.103888154029846e-05);
    out->w=component;
}
