/* Compiler context only. The complete included initializer is NOT certified
 * here; its independently deferred source remains the authority. Never run. */
#ifndef SR2_CUTSCENE_CONSTRUCTOR_CONTEXT_H
#define SR2_CUTSCENE_CONSTRUCTOR_CONTEXT_H
/* Complete camera/tween option initializer: 006ce1f0..006ce2b6.
 * Native destination in EAX. Partial record names describe observed layouts.
 * The original copies zero float vector bits from a stack temporary; the
 * union makes that representation explicit without pointer aliasing tricks.
 * NOT MATCHED unless the complete private gate certifies this source. */
typedef struct CsScalarTween {
    unsigned char active,unknown_01[3];
    CsWord blend;
    float start_time,start,end_time,end;
} CsScalarTween;
typedef struct CsCameraTweenOptions {
    CsTweenVector first,second;
    CsScalarTween third,fourth;
    unsigned char field_80,unknown_81[3];
    float field_84,field_88,field_8c,field_90;
    CsWord field_94,field_98;
} CsCameraTweenOptions;
typedef union CsVectorBits {
    struct { float x,y,z; } values;
    CsWords3 words;
} CsVectorBits;
typedef char check_options_size[(sizeof(CsCameraTweenOptions)==0x9c)?1:-1];
typedef char check_options_offsets[(offsetof(CsCameraTweenOptions,field_80)==0x80 && offsetof(CsCameraTweenOptions,third)==0x50)?1:-1];
__declspec(noinline) void __cdecl FUN_006ce1f0(CsCameraTweenOptions *out)
{
    CsVectorBits zero;
    out->first.blend=0;
    out->second.blend=0;
    out->third.blend=0;
    out->fourth.blend=0;
    zero.values.x=0.0f;
    zero.values.y=0.0f;
    zero.values.z=0.0f;
    out->first.end_time=0.0f;
    out->first.start_time=0.0f;
    out->first.start.x=zero.words.x;
    out->first.end.x=zero.words.x;
    out->first.active=0;
    out->first.start.y=zero.words.y;
    out->first.end.y=zero.words.y;
    out->first.start.z=zero.words.z;
    out->first.end.z=zero.words.z;
    zero.values.x=0.0f;
    zero.values.y=0.0f;
    zero.values.z=0.0f;
    out->second.end_time=0.0f;
    out->second.start_time=0.0f;
    out->second.start.x=zero.words.x;
    out->second.end.x=zero.words.x;
    out->second.start.y=zero.words.y;
    out->second.end.y=zero.words.y;
    out->second.start.z=zero.words.z;
    out->second.end.z=zero.words.z;
    out->second.active=0;
    out->third.start=0.0f;
    out->third.end=0.0f;
    out->third.active=0;
    out->third.end_time=0.0f;
    out->third.start_time=0.0f;
    out->fourth.active=0;
    out->fourth.start=0.0f;
    out->fourth.end=0.0f;
    out->fourth.end_time=0.0f;
    out->fourth.start_time=0.0f;
    out->field_94=0;
    out->field_98=0;
    out->field_84=1.0f;
    out->field_80=0;
    out->field_88=1.0f;
    out->field_8c=0.0f;
    out->field_90=0.0f;
}
#endif
