/* SR2 binary-only partial views. Field offsets, not recovered original type names.
 * Evidence: FUN_006eb730, FUN_006cdb80, FUN_006d71d0, FUN_006d5dd0,
 * FUN_006d7030, FUN_006c70d0. No SR4 source is used here. */
#ifndef SR2_CUTSCENE_TYPES_H
#define SR2_CUTSCENE_TYPES_H
#include <stddef.h>
typedef unsigned int CsWord;
typedef struct CsFloatTrack {
    unsigned short count;
    unsigned short unknown_02;
    float *values;
    float *times;
} CsFloatTrack;
typedef struct CsWords3 { CsWord x,y,z; } CsWords3;
typedef struct CsWords6 { CsWord a,b,c,d,e,f; } CsWords6;

/* Shared prefix only: blend parsers read/write +4 for vector, scalar and
 * six-word records (006cdbc0, 006d7100, 006d7230). */
typedef struct CsBlendView {
    unsigned char unknown_00[4];
    CsWord blend;
} CsBlendView;
typedef struct CsTweenVector {
    unsigned char active;
    unsigned char unknown_01[3];
    CsWord blend;
    float start_time;
    CsWords3 start;
    float end_time;
    CsWords3 end;
} CsTweenVector;
typedef struct CsTweenSix {
    unsigned char active;
    unsigned char unknown_01[3];
    CsWord blend;
    float start_time;
    CsWords6 start;
    float end_time;
    CsWords6 end;
} CsTweenSix;
typedef struct CsWordList { CsWord *items; int capacity,count; } CsWordList;
typedef struct CsActorShotView {
    CsWord field_00,field_04,field_08,field_0c;
    unsigned char field_10,field_11;
    unsigned char unknown_12[2];
} CsActorShotView;
typedef struct CsAnimationOptionView {
    CsActorShotView base;
    CsWord field_14;
    float field_18;
    unsigned char field_1c;
} CsAnimationOptionView;
typedef struct CsCameraOptionView {
    unsigned char unknown_00[0x20];
    CsWord field_20,field_24,field_28;
} CsCameraOptionView;
typedef struct CsInstanceSlateView {
    unsigned char unknown_00[0x10c];
    CsWords3 field_10c,field_118;
} CsInstanceSlateView;

/* Effect dispatch option payload accesses: FUN_006d7590, 006d76b0,
 * 006d7600, 006d8200. Only payload offset +8 is established here. */
typedef struct CsEffectBoolOption {
    CsWord unknown_00,unknown_04;
    unsigned char value;
} CsEffectBoolOption;
typedef struct CsEffectFloatOption {
    CsWord unknown_00,unknown_04;
    float value;
} CsEffectFloatOption;
typedef struct CsEffectVectorOption {
    CsWord unknown_00,unknown_04;
    const CsWords3 *value;
} CsEffectVectorOption;
typedef struct CsEffectPairOption {
    CsWord unknown_00,unknown_04;
    const float *value;
} CsEffectPairOption;

typedef struct CsCurrentShotFadeView {
    unsigned char unknown_000[0x164];
    float field_164,field_168;
    unsigned char field_16c;
} CsCurrentShotFadeView;
typedef struct CsCurrentShotInstanceView {
    unsigned char unknown_0000[0x1540];
    CsCurrentShotFadeView *current_shot;
} CsCurrentShotInstanceView;
typedef struct CsScriptResultView {
    CsWord field_00,unknown_04,field_08,unknown_0c;
} CsScriptResultView;
typedef struct CsScriptContextView {
    CsWord unknown_00,unknown_04;
    CsScriptResultView *top;
} CsScriptContextView;
typedef char cs_effect_payload_offset[(offsetof(CsEffectFloatOption,value)==8 && offsetof(CsEffectBoolOption,value)==8)?1:-1];
typedef char cs_track_size[(sizeof(CsFloatTrack)==12)?1:-1];
typedef char cs_tween_vector_size[(sizeof(CsTweenVector)==0x28)?1:-1];
typedef char cs_tween_six_size[(sizeof(CsTweenSix)==0x40)?1:-1];
typedef char cs_tween_end_offset[(offsetof(CsTweenVector,end)==0x1c)?1:-1];
typedef char cs_six_end_offset[(offsetof(CsTweenSix,end)==0x28)?1:-1];
typedef char cs_slate_offset[(offsetof(CsInstanceSlateView,field_118)==0x118)?1:-1];
#endif
