#include "player_movement_readable_switches.c"
/* Readable C for private register interfaces selected by VC8 /GL + /LTCG.
 * Whole native bodies are verified in two linked images. No native COFF claim.
 * Address normalization requires individually audited PE HIGHLOW destinations.
 * Offset names identify binary evidence; semantic field names remain unknown. */
#include <stddef.h>
typedef struct MovementModeValueView {
    unsigned char unknown_0000[0xe88];
    int field_0e88;
} MovementModeValueView;
typedef char verify_mode_value_offset[(offsetof(MovementModeValueView, field_0e88)==0xe88)?1:-1];
/* EXE: FUN_009b7450:009b7450..009b7468. EAX input, EAX result. */
__declspec(noinline) int __cdecl FUN_009b7450(const MovementModeValueView *source) {
    int value = source->field_0e88;
    if (value == 2 || value == 5) return 1;
    return 0;
}

/* EXE: FUN_00961830; complete body checked against original manifest. */
typedef struct ModeIndex {
    unsigned char pad[0x164];
    int value;
} ModeIndex;
typedef struct ModeIndexRoot {
    unsigned char pad[0x5e0];
    const ModeIndex *index;
} ModeIndexRoot;
__declspec(noinline) int __cdecl FUN_00961830(const ModeIndexRoot *source) {
    int value = source->index->value;
    if (value == 0x1ae || value == 0x1ad) return 1;
    return 0;
}

/* EXE: FUN_009636f0; complete body checked against original manifest. */
typedef struct FlagValue {
    unsigned char pad[0x3c];
    unsigned char flags;
} FlagValue;
typedef struct FlagRoot {
    unsigned char pad[0xd4];
    const FlagValue *value;
} FlagRoot;
__declspec(noinline) int __cdecl FUN_009636f0(const FlagRoot *source) {
    if (source && source->value && (source->value->flags & 0x10)) return 1;
    return 0;
}

/* EXE: FUN_00968cf0; complete body checked against original manifest. */
typedef struct StateIndex {
    unsigned char pad[12];
    int value;
} StateIndex;
typedef struct StateRoot {
    unsigned char pad[0x3cc];
    unsigned char kind;
    unsigned char gap[0x213];
    const StateIndex *index;
    unsigned char gap2[0xb54];
    int value;
} StateRoot;
__declspec(noinline) int __cdecl FUN_00968cf0(const StateRoot *source) {
    if (source->index->value && source->kind != 1) return 0x1f;
    return source->value;
}

typedef struct PropertyMode {
    unsigned char pad[0x34];
    int kind;
} PropertyMode;
typedef struct PropertyDetail {
    unsigned char pad[8];
    const PropertyMode *mode;
    unsigned char gap[0x20];
    int value_2c;
} PropertyDetail;
typedef struct PropertyLink {
    unsigned char pad[0xc4];
    const PropertyDetail *detail;
} PropertyLink;
typedef struct PropertyRoot {
    unsigned char pad[0x10cc];
    const PropertyLink *link;
} PropertyRoot;

/* EXE: FUN_009c4ff0; original instruction export. */
__declspec(noinline) unsigned char __cdecl FUN_009c4ff0(const PropertyRoot *source) {
    if (source && source->link && source->link->detail &&
        source->link->detail->value_2c >= 0) return 1;
    return 0;
}

/* EXE: FUN_009c60a0; original instruction export. */
__declspec(noinline) int __cdecl FUN_009c60a0(const PropertyRoot *source) {
    if (source && source->link && source->link->detail &&
        source->link->detail->mode) {
        int value = source->link->detail->mode->kind;
        if (value == 8 || value == 0x12) return 1;
    }
    return 0;
}

/* EXE: FUN_00971e10; original instruction export. */
__declspec(noinline) unsigned char __cdecl FUN_00971e10(const ModeIndexRoot *source) {
    if (source && source->index) {
        int value = source->index->value;
        if (value == 0x52c || value == 0x52a) return 1;
    }
    return 0;
}

typedef struct AttachmentFlag {
    unsigned char pad[0x178];
    unsigned char flag;
} AttachmentFlag;
typedef struct AttachmentRoot {
    unsigned char pad[0x3cc];
    unsigned char kind;
    unsigned char gap[0xdab];
    const AttachmentFlag *attachment;
} AttachmentRoot;

/* EXE: FUN_009635a0; original instruction export. */
__declspec(noinline) unsigned char __cdecl FUN_009635a0(const AttachmentRoot *source) {
    if (source && source->kind == 2 && source->attachment &&
        source->attachment->flag) return 1;
    return 0;
}

typedef struct ActiveValue {
    unsigned char pad[4];
    int value;
} ActiveValue;
typedef struct ActiveRoot {
    unsigned char pad[0x30];
    const ActiveValue *active;
} ActiveRoot;

/* EXE: FUN_00915990:00915990..009159a6, AL result. */
__declspec(noinline) unsigned char __cdecl FUN_00915990(const ActiveRoot *source) {
    if (source && source->active && source->active->value) return 1;
    return 0;
}

/* These checks constrain only the fields read by the verified bodies above. */
#define VERIFY_FIELD(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_FIELD(ModeIndex, value, 0x164);
VERIFY_FIELD(ModeIndexRoot, index, 0x5e0);
VERIFY_FIELD(FlagValue, flags, 0x3c);
VERIFY_FIELD(FlagRoot, value, 0xd4);
VERIFY_FIELD(StateIndex, value, 0xc);
VERIFY_FIELD(StateRoot, kind, 0x3cc);
VERIFY_FIELD(StateRoot, index, 0x5e0);
VERIFY_FIELD(StateRoot, value, 0x1138);
VERIFY_FIELD(PropertyMode, kind, 0x34);
VERIFY_FIELD(PropertyDetail, mode, 0x8);
VERIFY_FIELD(PropertyDetail, value_2c, 0x2c);
VERIFY_FIELD(PropertyLink, detail, 0xc4);
VERIFY_FIELD(PropertyRoot, link, 0x10cc);
VERIFY_FIELD(AttachmentFlag, flag, 0x178);
VERIFY_FIELD(AttachmentRoot, kind, 0x3cc);
VERIFY_FIELD(AttachmentRoot, attachment, 0x1178);
VERIFY_FIELD(ActiveValue, value, 0x4);
VERIFY_FIELD(ActiveRoot, active, 0x30);
#undef VERIFY_FIELD

typedef struct MovementRecord {
    unsigned char field_00;
    unsigned char pad_01[3];
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    float field_14;
    unsigned char field_18;
    unsigned char pad_19[3];
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    float field_34;
    float field_38;
    float field_3c;
} MovementRecord;

/* EXE: FUN_004fb0f0:004fb0f0..004fb150. */
__declspec(noinline) void __cdecl FUN_004fb0f0(const MovementRecord *source, MovementRecord *destination) {
    destination->field_00 = source->field_00;
    destination->field_04 = source->field_04;
    destination->field_08 = source->field_08;
    destination->field_0c = source->field_0c;
    destination->field_10 = source->field_10;
    destination->field_14 = source->field_14;
    destination->field_18 = source->field_18;
    destination->field_1c = source->field_1c;
    destination->field_20 = source->field_20;
    destination->field_24 = source->field_24;
    destination->field_28 = source->field_28;
    destination->field_2c = source->field_2c;
    destination->field_30 = source->field_30;
    destination->field_34 = source->field_34;
    destination->field_38 = source->field_38;
    destination->field_3c = source->field_3c;
}

extern const void *DAT_021703d4;
/* EXE: FUN_00926650; complete original body. */
__declspec(noinline) unsigned char __cdecl FUN_00926650(const void *source) {
    if (source && source == DAT_021703d4) return 1;
    return 0;
}

typedef struct IndexedState {
    unsigned char pad[0x48];
    unsigned int flags;
    unsigned char tail[0x28];
} IndexedState;
extern IndexedState *DAT_025296c4;
/* EXE: FUN_00980540; complete original body. */
__declspec(noinline) unsigned char __cdecl FUN_00980540(unsigned char index) {
    if (index == 0xff) return 0;
    return (DAT_025296c4[index].flags >> 12) & 1;
}

typedef struct LookupValue {
    unsigned char pad[0x10];
    int value;
} LookupValue;
typedef struct LookupEntry {
    const LookupValue *value;
    unsigned char tail[20];
} LookupEntry;
typedef struct LookupRoot {
    unsigned char pad[0x7c];
    int index;
} LookupRoot;
extern LookupEntry DAT_028f25c0[];
/* EXE: FUN_00935bd0; complete original body. */
__declspec(noinline) int __cdecl FUN_00935bd0(const LookupRoot *source) {
    int index = source->index;
    if (index != -1) {
        const LookupValue *value = DAT_028f25c0[index].value;
        if (value) return value->value;
    }
    return 0;
}

typedef struct MovementFreeNode {
    struct MovementFreeNode *next;
    struct MovementFreeNode *previous;
    int value;
} MovementFreeNode;
extern MovementFreeNode *DAT_02143fa0;
extern int DAT_025295c0;
/* EXE: FUN_0091bae0; complete original body. */
__declspec(noinline) void __cdecl FUN_0091bae0(MovementFreeNode *node) {
    MovementFreeNode *head = DAT_02143fa0;
    --DAT_025295c0;
    if (!head) {
        node->next = node;
        node->previous = node;
        DAT_02143fa0 = node;
        node->value = 0;
        return;
    }
    node->previous = head->previous;
    node->next = head;
    head->previous->next = node;
    head->previous = node;
    node->value = 0;
}

typedef struct AttachmentIndexView {
    unsigned char pad[0xb25];
    unsigned char index;
} AttachmentIndexView;
/* EXE: FUN_0097f550; complete original body. */
__declspec(noinline) unsigned char __cdecl FUN_0097f550(const AttachmentIndexView *source) {
 unsigned char index=source->index;    if (index == 0xff) return 0;
    return (DAT_025296c4[index].flags >> 12) & 1;
}

extern const double DAT_00e5c038;
extern const double DAT_00e5bf70;
/* EXE: FUN_009b7980:009b7980..009b79c0. */
__declspec(noinline) float __cdecl FUN_009b7980(unsigned char value) {
    if (value == 0x7f) return 1.0f;
    if (value < 0x7f) return (float)((double)value / DAT_00e5c038 + DAT_00e5bf70);
    {
        double scaled = (double)value / DAT_00e5c038;
        return (float)(scaled + scaled);
    }
}

#define VERIFY_FIELD(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_FIELD(MovementRecord, field_00, 0x00);
VERIFY_FIELD(MovementRecord, field_04, 0x04);
VERIFY_FIELD(MovementRecord, field_08, 0x08);
VERIFY_FIELD(MovementRecord, field_0c, 0x0c);
VERIFY_FIELD(MovementRecord, field_10, 0x10);
VERIFY_FIELD(MovementRecord, field_14, 0x14);
VERIFY_FIELD(MovementRecord, field_18, 0x18);
VERIFY_FIELD(MovementRecord, field_1c, 0x1c);
VERIFY_FIELD(MovementRecord, field_20, 0x20);
VERIFY_FIELD(MovementRecord, field_24, 0x24);
VERIFY_FIELD(MovementRecord, field_28, 0x28);
VERIFY_FIELD(MovementRecord, field_2c, 0x2c);
VERIFY_FIELD(MovementRecord, field_30, 0x30);
VERIFY_FIELD(MovementRecord, field_34, 0x34);
VERIFY_FIELD(MovementRecord, field_38, 0x38);
VERIFY_FIELD(MovementRecord, field_3c, 0x3c);
VERIFY_FIELD(IndexedState, flags, 0x48);
VERIFY_FIELD(LookupValue, value, 0x10);
VERIFY_FIELD(LookupEntry, value, 0x0);
VERIFY_FIELD(LookupRoot, index, 0x7c);
VERIFY_FIELD(MovementFreeNode, next, 0x0);
VERIFY_FIELD(MovementFreeNode, previous, 0x4);
VERIFY_FIELD(MovementFreeNode, value, 0x8);
VERIFY_FIELD(AttachmentIndexView, index, 0xb25);
typedef char verify_indexed_state_stride[(sizeof(IndexedState) == 0x74) ? 1 : -1];
typedef char verify_lookup_entry_stride[(sizeof(LookupEntry) == 0x18) ? 1 : -1];
#undef VERIFY_FIELD

/* EXE: FUN_0097b8c0; complete original body. */
__declspec(noinline) unsigned char __cdecl FUN_0097b8c0(const AttachmentIndexView *source) {
    unsigned char index = source->index;
    if (index == 0xff) return 0;
    return (DAT_025296c4[index].flags >> 13) & 1;
}

/* EXE: FUN_0097b8f0; complete original body. */
__declspec(noinline) unsigned char __cdecl FUN_0097b8f0(const AttachmentIndexView *source) {
    unsigned char index = source->index;
    if (index == 0xff) return 0;
    return (DAT_025296c4[index].flags >> 14) & 1;
}

typedef struct HandleValueView {
    unsigned char pad[0x44];
    unsigned int handle;
} HandleValueView;
typedef struct HandleEntryView {
    const HandleValueView *object;
    unsigned char tail[12];
} HandleEntryView;
typedef struct HandleFlagRoot {
    unsigned char pad[0xc0];
    unsigned int flags;
    unsigned char gap[0x2b0];
    unsigned int handle;
} HandleFlagRoot;
extern HandleEntryView DAT_02149c64[];
#include "player_movement_readable_relation_context.h"
/* EXE: FUN_009cbc60; complete original body. */
__declspec(noinline) int __cdecl FUN_009cbc60(const HandleFlagRoot *source) {
    if (source->flags & 0x40000) {
        unsigned int handle = source->handle;
        if (handle) {
            const HandleValueView *object = DAT_02149c64[handle & 0xfff].object;
            if (object && object->handle == handle) return 1;
        }
    }
    return 0;
}

typedef struct NestedFlagView {
    unsigned char pad[0x72];
    unsigned char flags;
} NestedFlagView;
typedef struct ComplexFlagRoot {
    unsigned char pad[0x101];
    unsigned char flags_101;
    unsigned char gap[0x2ca];
    unsigned char kind;
    unsigned char gap2[0xd3f];
    unsigned int flags_110c;
    unsigned char gap3[0x68];
    const NestedFlagView *nested;
} ComplexFlagRoot;
extern unsigned char DAT_02527c84;
/* EXE: FUN_00974600; complete original body. */
__declspec(noinline) unsigned char __cdecl FUN_00974600(const ComplexFlagRoot *source) {
    unsigned int flags = source->flags_110c;
    unsigned char first = (unsigned char)(flags >> 20) & 1;
    if (first) return 1;
    if ((unsigned char)(flags >> 24) & 1) return 1;
    if ((source->flags_101 & 1) && !DAT_02527c84) return 1;
    if (source->kind == 2 && source->nested && (source->nested->flags & 8)) return 1;
    return 0;
}

typedef struct Flags80Root {
    unsigned char pad[0x80];
    unsigned int flags;
} Flags80Root;
static __forceinline int shifted_flags_decision(const Flags80Root *source) {
    unsigned int flags = source->flags;
    if (((unsigned char)(flags >> 4) & 1) || !((unsigned char)(flags >> 5) & 1)) return 1;
    return 0;
}
/* EXE: FUN_00962f50; nullable byte result wrapping integer predicate. */
__declspec(noinline) unsigned char __cdecl FUN_00962f50(const Flags80Root *source) {
    if (!source) return 0;
    return shifted_flags_decision(source);
}

#define VERIFY_FIELD(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_FIELD(HandleValueView, handle, 0x44);
VERIFY_FIELD(HandleEntryView, object, 0x0);
VERIFY_FIELD(HandleFlagRoot, flags, 0xc0);
VERIFY_FIELD(HandleFlagRoot, handle, 0x374);
VERIFY_FIELD(NestedFlagView, flags, 0x72);
VERIFY_FIELD(ComplexFlagRoot, flags_101, 0x101);
VERIFY_FIELD(ComplexFlagRoot, kind, 0x3cc);
VERIFY_FIELD(ComplexFlagRoot, flags_110c, 0x110c);
VERIFY_FIELD(ComplexFlagRoot, nested, 0x1178);
VERIFY_FIELD(Flags80Root, flags, 0x80);
typedef char verify_handle_entry_stride[(sizeof(HandleEntryView) == 0x10) ? 1 : -1];
#undef VERIFY_FIELD

extern int DAT_00e843ac;
/* EXE: FUN_00bdd2a0:00bdd2a0..00bdd2e5;
integer wrap arithmetic. */
static __forceinline int wrapped_time_difference(const int *source) {
    int value = *source;
    if (value < 0) return 1800000000;
    if (value > DAT_00e843ac) {
        value -= DAT_00e843ac;
        if (value > 900000000) return value - 1800000000;
        return value;
    }
    {
        int difference = DAT_00e843ac - value;
        if (difference > 900000000) return (value - DAT_00e843ac) + 1800000000;
        return -difference;
    }
}
__declspec(noinline) int __cdecl FUN_00bdd2a0(const int *source) {
    return -wrapped_time_difference(source);
}
typedef struct FloatRecord9 {
    float field_00;
    float field_04;
    float field_08;
    float field_0c;
    float field_10;
    float field_14;
    float field_18;
    float field_1c;
    float field_20;
}
FloatRecord9;
typedef char verify_float_record_00[(offsetof(FloatRecord9, field_00) == 0x0) ? 1 : -1];
typedef char verify_float_record_04[(offsetof(FloatRecord9, field_04) == 0x4) ? 1 : -1];
typedef char verify_float_record_08[(offsetof(FloatRecord9, field_08) == 0x8) ? 1 : -1];
typedef char verify_float_record_0c[(offsetof(FloatRecord9, field_0c) == 0xc) ? 1 : -1];
typedef char verify_float_record_10[(offsetof(FloatRecord9, field_10) == 0x10) ? 1 : -1];
typedef char verify_float_record_14[(offsetof(FloatRecord9, field_14) == 0x14) ? 1 : -1];
typedef char verify_float_record_18[(offsetof(FloatRecord9, field_18) == 0x18) ? 1 : -1];
typedef char verify_float_record_1c[(offsetof(FloatRecord9, field_1c) == 0x1c) ? 1 : -1];
typedef char verify_float_record_20[(offsetof(FloatRecord9, field_20) == 0x20) ? 1 : -1];
typedef char verify_float_record_size[(sizeof(FloatRecord9) == 36) ? 1 : -1];
/* EXE: FUN_00be2c60:00be2c60..00be2c94. */
__declspec(noinline) void __cdecl FUN_00be2c60(const FloatRecord9 *source, FloatRecord9 *destination) {
    destination->field_00=source->field_00;
    destination->field_04=source->field_04;
    destination->field_08=source->field_08;
    destination->field_0c=source->field_0c;
    destination->field_10=source->field_10;
    destination->field_14=source->field_14;
    destination->field_18=source->field_18;
    destination->field_1c=source->field_1c;
    destination->field_20=source->field_20;
}
/* EXE: FUN_00963540:00963540..00963579;
complete matched original. */
typedef struct SubtypeHandleObject {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap[4];
    unsigned int kind;
    unsigned char gap_50[0x37c];
    unsigned char subtype;
}
SubtypeHandleObject;
__declspec(noinline) unsigned char __cdecl FUN_00963540(const HandleValueView *source) {
    unsigned int handle;
    const SubtypeHandleObject *object;
    if (!source) return 0;
    handle = source->handle;
    if (!handle) return 0;
    object = (const SubtypeHandleObject *)DAT_02149c64[handle & 0xfff].object;
    if (!object || object->handle != handle) return 0;
    if (object->kind != 1 || object->subtype != 1) return 0;
    return 1;
}
/* EXE: FUN_00bde570;
complete original candidate. */
typedef struct Vector3Transform {
    float x, y, z;
}
Vector3Transform;
__declspec(noinline) void __cdecl FUN_00bde570(Vector3Transform *vector, const FloatRecord9 *matrix) {
    float x = vector->x;
    float y = vector->y;
    float z = vector->z;
    vector->x = matrix->field_00*x + matrix->field_0c*y + matrix->field_18*z;
    vector->y = matrix->field_04*x + matrix->field_10*y + matrix->field_1c*z;
    vector->z = matrix->field_08*x + matrix->field_14*y + matrix->field_20*z;
}
/* EXE: FUN_008066c0;
complete original candidate. */
typedef struct ComparisonData {
    unsigned char kind;
    unsigned char pad[0x67b];
    unsigned char flags;
}
ComparisonData;
typedef struct ComparisonObject {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap[0x68];
    const ComparisonData *data;
}
ComparisonObject;
typedef struct CurrentKind {
    unsigned char pad[0x1b0];
    unsigned char kind;
}
CurrentKind;
typedef struct CurrentRoot {
    unsigned char pad[0x408];
    const CurrentKind *current;
}
CurrentRoot;
extern const CurrentRoot *DAT_02528c14;
__declspec(noinline) unsigned char __fastcall FUN_008066c0(unsigned int handle) {
    const ComparisonObject *object;
    const ComparisonData *data;
    const CurrentRoot *root;
    const CurrentKind *current;
    if (!handle) return 1;
    object = (const ComparisonObject *)DAT_02149c64[handle & 0xfff].object;
    if (!object || object->handle != handle) return 1;
    data = object->data;
    if (!data) return 1;
    root = DAT_02528c14;
    if (!root) return 1;
    current = root->current;
    if (!current) return 1;
    if (data->kind == current->kind && !(data->flags & 1)) return 1;
    return 0;
}
/* EXE: FUN_00bdea30;
complete original candidate. */
__declspec(noinline) float __cdecl FUN_00bdea30(const Vector3Transform *first, const Vector3Transform *second) {
    float difference = first->x - second->x;
    float result = difference*difference;
    difference = first->y - second->y;
    result += difference*difference;
    difference = first->z - second->z;
    result += difference*difference;
    return result;
}
/* EXE: FUN_00bdea80;
plain float locals after matched 00bdea30. */
typedef struct Position3 {
    float x;
    float y;
    float z;
}
Position3;
__declspec(noinline) float __cdecl FUN_00bdea80(const Position3 *first, const Position3 *second) {
    float x = first->x - second->x;
    float z = first->z - second->z;
    float squared = x*x + z*z;
    return squared;
}
/* Field offsets are read from the named original instructions and checked here. */
#define CHECK_LAYOUT(type, member, offset) \
typedef char check_##type##_##member[(offsetof(type, member) == offset) ? 1 : -1]
CHECK_LAYOUT(SubtypeHandleObject, handle, 0x44);
CHECK_LAYOUT(SubtypeHandleObject, kind, 0x4c);
CHECK_LAYOUT(SubtypeHandleObject, subtype, 0x3cc);
CHECK_LAYOUT(Vector3Transform, x, 0);
CHECK_LAYOUT(Vector3Transform, y, 4);
CHECK_LAYOUT(Vector3Transform, z, 8);
CHECK_LAYOUT(ComparisonData, kind, 0);
CHECK_LAYOUT(ComparisonData, flags, 0x67c);
CHECK_LAYOUT(ComparisonObject, handle, 0x44);
CHECK_LAYOUT(ComparisonObject, data, 0xb0);
CHECK_LAYOUT(CurrentKind, kind, 0x1b0);
CHECK_LAYOUT(CurrentRoot, current, 0x408);
CHECK_LAYOUT(Position3, x, 0);
CHECK_LAYOUT(Position3, y, 4);
CHECK_LAYOUT(Position3, z, 8);
#undef CHECK_LAYOUT
/* EXE: FUN_009d06a0;
inlined lookup boundary trial. */
static __forceinline const SubtypeHandleObject *lookup_handle_kind(unsigned int handle, unsigned int required_kind) {
    const SubtypeHandleObject *object;
    if (!handle) return 0;
    object = (const SubtypeHandleObject *)DAT_02149c64[handle & 0xfff].object;
    if (!object || object->handle != handle || object->kind != required_kind) return 0;
    return object;
}
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_009d06a0(unsigned int handle) {
    const SubtypeHandleObject *object = lookup_handle_kind(handle, 1);
    if (!object) return 0;
    return (const SubtypeHandleObject *)((unsigned int)object & ((unsigned int)(object->subtype != 2) - 1));
}
/* EXE: FUN_00ae28f0;
inlined lookup boundary trial. */
static __forceinline const SubtypeHandleObject *lookup_handle_untyped(unsigned int handle) {
    const SubtypeHandleObject *object;
    if (!handle) return 0;
    object = (const SubtypeHandleObject *)DAT_02149c64[handle & 0xfff].object;
    if (!object || object->handle != handle) return 0;
    return object;
}
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_00ae28f0(unsigned int handle) {
    const SubtypeHandleObject *object = lookup_handle_untyped(handle);
    if (!object) return 0;
    return (const SubtypeHandleObject *)((unsigned int)object & ((unsigned int)(object->kind != 5) - 1));
}
/* EXE: FUN_006efe30;
complete original candidate. */
typedef struct ActiveSlot34 {
    int value;
    unsigned int key;
    unsigned char gap[0x14];
    unsigned char flags;
    unsigned char tail[0x17];
}
ActiveSlot34;
typedef struct ActiveSlotRoot {
    unsigned char pad[0xc8];
    ActiveSlot34 slots[3];
}
ActiveSlotRoot;
__declspec(noinline) int __cdecl FUN_006efe30(const ActiveSlotRoot *root, int wanted) {
    int active = 0;
    int index = 0;
    const ActiveSlot34 *slot = root->slots;
    for (;
    index < 3;
    ++index, ++slot) {
        if ((slot->flags & 1) && slot->key != 0xffff) {
            if (active == wanted) return root->slots[index].value;
            ++active;
        }
    }
    return -1;
}
typedef char verify_active_slot_value[(offsetof(ActiveSlot34, value)==0)?1:-1];
typedef char verify_active_slot_key[(offsetof(ActiveSlot34, key)==4)?1:-1];
typedef char verify_active_slot_flags[(offsetof(ActiveSlot34, flags)==0x1c)?1:-1];
typedef char verify_active_slot_stride[(sizeof(ActiveSlot34)==0x34)?1:-1];
typedef char verify_active_slot_root[(offsetof(ActiveSlotRoot, slots)==0xc8)?1:-1];
/* EXE: FUN_0096f790;
complete original candidate. */
typedef struct NestedWord5E0 {
    unsigned char pad[0x5e0];
    unsigned int value;
}
NestedWord5E0;
extern int __cdecl FUN_006ef6a0(unsigned int, unsigned int, unsigned int);
__declspec(noinline) unsigned char __cdecl FUN_0096f790(unsigned int value, const NestedWord5E0 *root) {
    int result = FUN_006ef6a0(root->value, value, 0);
    return result != 0xffff;
}
typedef char verify_nested_word_5e0[(offsetof(NestedWord5E0,value)==0x5e0)?1:-1];
/* EXE: FUN_0069e1c0;
shared failure-exit trial. */
typedef struct KeyRecordE8 {
    unsigned int key;
    unsigned char tail[0xe4];
}
KeyRecordE8;
extern int DAT_01450384;
extern KeyRecordE8 DAT_027ac860[];
__declspec(noinline) KeyRecordE8 * __fastcall FUN_0069e1c0(const unsigned int *key) {
    int count = DAT_01450384;
    int index = 0;
    if (count > 0) {
        unsigned int value = *key;
        KeyRecordE8 *cursor = DAT_027ac860;
        do {
            if (cursor->key == value) goto found;
            ++index;
            ++cursor;
        }
        while (index < count);
    }
    return 0;
    found:
    return &DAT_027ac860[index];
}
typedef char verify_key_record_key[(offsetof(KeyRecordE8,key)==0)?1:-1];
typedef char verify_key_record_stride[(sizeof(KeyRecordE8)==0xe8)?1:-1];
/* EXE: FUN_0095cd20;
full caller with recovered C callee visible to LTCG. */
__declspec(noinline) int __fastcall FUN_0095cd20(const SwitchLink10CC *root) {
    const SwitchLinkC4 *first;
    const SwitchLink8 *second;
    const Switch34View *object;
    if ((unsigned char)FUN_009c4060(root)) {
        if (!root) return -1;
        first = root->nested;
        if (!first) return -1;
        second = first->nested;
        if (!second) return -1;
        object = second->object;
        if (!object) return -1;
        return object->kind;
    }
    return -1;
}
/* EXE: FUN_009c43b0;
nullable switch lookup followed by signed bounds. */
typedef struct SignedBounds24 {
    unsigned char pad[0x24];
    int first, second;
}
SignedBounds24;
typedef struct SwitchBoundsBC {
    unsigned char pad[0xbc];
    const SignedBounds24 *bounds;
}
SwitchBoundsBC;
static __forceinline int signed_bounds_nonnegative(const SignedBounds24 *bounds) {
    if (bounds->first < 0 || bounds->second < 0) return 0;
    return 1;
}
__declspec(noinline) unsigned char __cdecl FUN_009c43b0(const SwitchLink10CC *root) {
    if (root) {
        const SwitchLinkC4 *first = root->nested;
        if (first) {
            const SwitchLink8 *second = first->nested;
            if (second) {
                const Switch34View *object = second->object;
                if (object && FUN_00b72800(object)) {
                    return (unsigned char)signed_bounds_nonnegative(((const SwitchBoundsBC *)first)->bounds);
                }
            }
        }
    }
    return 0;
}
typedef char check_signed_bounds[(offsetof(SignedBounds24,first)==0x24 && offsetof(SignedBounds24,second)==0x28)?1:-1];
typedef char check_switch_bounds[(offsetof(SwitchBoundsBC,bounds)==0xbc)?1:-1];
/* EXE: FUN_009c4370;
full nested guards with recovered switch C. */
__declspec(noinline) int __cdecl FUN_009c4370(const SwitchLink10CC *root) {
    if (root) {
        const SwitchLinkC4 *first = root->nested;
        if (first) {
            const SwitchLink8 *second = first->nested;
            if (second) {
                const Switch34View *object = second->object;
                if (object && FUN_00b72800(object)) return 1;
            }
        }
    }
    return 0;
}
/* EXE: FUN_009cbb00;
complete handle and kind dispatch. */
typedef struct LinkedValue80 {
    unsigned char pad[0x80];
    int value;
}
LinkedValue80;
typedef struct LinkedSignedD0 {
    unsigned char pad[0xd0];
    signed char value;
}
LinkedSignedD0;
typedef struct LinkedSigned6C {
    unsigned char pad[0x6c];
    const LinkedSignedD0 *nested;
}
LinkedSigned6C;
typedef struct DispatchHandleObject {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned short sentinel;
    unsigned char gap[0x76];
    const LinkedValue80 *nested_c0;
    unsigned char gap2[0x60];
    int value124;
    unsigned char gap3[8];
    const LinkedSigned6C *nested130;
}
DispatchHandleObject;
typedef struct DispatchHandleRoot {
    unsigned char pad[0x374];
    unsigned int handle;
    int kind;
}
DispatchHandleRoot;
__declspec(noinline) int __fastcall FUN_009cbb00(void *unused, const DispatchHandleRoot *root) {
    const DispatchHandleObject *object = (const DispatchHandleObject *)lookup_handle_untyped(root->handle);
    int kind;
    if (!object) return -1;
    kind = root->kind;
    if (kind == 2) return object->nested_c0->value;
    if (kind == 3) {
        if (object->sentinel == 0xbeef) return 0;
        return object->nested130->nested->value;
    }
    if (kind == 12) return object->value124;
    return 1;
}
typedef char check_dispatch_object[(offsetof(DispatchHandleObject,handle)==0x44 && offsetof(DispatchHandleObject,sentinel)==0x48 && offsetof(DispatchHandleObject,nested_c0)==0xc0 && offsetof(DispatchHandleObject,value124)==0x124 && offsetof(DispatchHandleObject,nested130)==0x130)?1:-1];
typedef char check_dispatch_root[(offsetof(DispatchHandleRoot,handle)==0x374 && offsetof(DispatchHandleRoot,kind)==0x378)?1:-1];
/* EXE: FUN_009d7dd0;
full kind lookup and byte-sized subtype difference. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_009d7dd0(unsigned int handle) {
    const SubtypeHandleObject *object = lookup_handle_kind(handle, 1);
    unsigned char difference;
    if (!object) return 0;
    difference = (unsigned char)(object->subtype - 1);
    return difference ? 0 : object;
}
/* EXE: FUN_009cbb80;
complete kind-dependent flag lookup. */
typedef struct FlagsC8Value {
    unsigned char pad[0xc8];
    unsigned int flags;
}
FlagsC8Value;
typedef struct Flags6CLink {
    unsigned char pad[0x6c];
    const FlagsC8Value *nested;
}
Flags6CLink;
typedef struct FlagsHandleObject {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap[0xb8];
    const FlagsC8Value *data100;
    unsigned char gap2[0x2c];
    const Flags6CLink *data130;
}
FlagsHandleObject;
static __forceinline int nested_flags_bit15(const Flags6CLink *link) {
    if (link && (link->nested->flags & 0x8000)) return 1;
    return 0;
}
static __forceinline unsigned int direct_flags_bit15(const FlagsC8Value *value) {
    return (value->flags >> 15) & 1;
}
__declspec(noinline) unsigned char __fastcall FUN_009cbb80(void *unused, const DispatchHandleRoot *root) {
    unsigned int handle = root->handle;
    const FlagsHandleObject *object;
    int kind;
    if (!handle) return 0;
    object = (const FlagsHandleObject *)DAT_02149c64[handle & 0xfff].object;
    if (!object || object->handle != handle) return 0;
    kind = root->kind;
    if (kind == 3) return (unsigned char)nested_flags_bit15(object->data130);
    if (kind == 12) return (unsigned char)direct_flags_bit15(object->data100);
    return 0;
}
typedef char check_flags_handle[(offsetof(FlagsHandleObject,handle)==0x44 && offsetof(FlagsHandleObject,data100)==0x100 && offsetof(FlagsHandleObject,data130)==0x130)?1:-1];
typedef char check_flags_c8[(offsetof(FlagsC8Value,flags)==0xc8)?1:-1];
typedef char check_flags_link6c[(offsetof(Flags6CLink,nested)==0x6c)?1:-1];
typedef char check_dispatch_nested80[(offsetof(LinkedValue80,value)==0x80)?1:-1];
typedef char check_dispatch_signed_d0[(offsetof(LinkedSignedD0,value)==0xd0 && sizeof(((LinkedSignedD0 *)0)->value)==1)?1:-1];
typedef char check_dispatch_link6c[(offsetof(LinkedSigned6C,nested)==0x6c)?1:-1];
/* EXE: FUN_009a37a0;
whole removal and free-list insertion. */
typedef struct ReleasedNode {
    unsigned char pad[0xc];
    void *owned;
    struct ReleasedNode *previous, *next;
}
ReleasedNode;
typedef struct ReleasedRoot {
    unsigned char pad[0xd14];
    ReleasedNode *head;
}
ReleasedRoot;
extern ReleasedNode *DAT_0215effc;
extern void __fastcall FUN_009302a0(ReleasedNode *node);
__declspec(noinline) void __cdecl FUN_009a37a0(ReleasedRoot *root, ReleasedNode *node, unsigned char release_owned) {
    ReleasedNode *head;
    if (!root || !node) return;
    if (release_owned && node->owned) FUN_009302a0((ReleasedNode *)node->owned);
    if (root->head == node) {
        head = node->next;
        if (head == node) {
            node->next = 0;
            node->previous = 0;
            root->head = 0;
            goto insert;
        }
        root->head = head;
    }
    if (node->previous) node->previous->next = node->next;
    if (node->next) node->next->previous = node->previous;
    node->next = 0;
    node->previous = 0;
    insert:
    head = DAT_0215effc;
    if (!head) {
        node->next = node;
        node->previous = node;
        DAT_0215effc = node;
    }
    else {
        node->previous = head->previous;
        node->next = head;
        head->previous->next = node;
        head->previous = node;
    }
}
typedef char check_released_node[(offsetof(ReleasedNode,owned)==0xc && offsetof(ReleasedNode,previous)==0x10 && offsetof(ReleasedNode,next)==0x14)?1:-1];
typedef char check_released_root[(offsetof(ReleasedRoot,head)==0xd14)?1:-1];
/* EXE: FUN_00960d60:00960d60..00960d8f. */
__declspec(noinline) const SubtypeHandleObject * __cdecl FUN_00960d60(unsigned int handle) {
    const SubtypeHandleObject *object = lookup_handle_untyped(handle);
    if (!object) return 0;
    return (object->kind - 1) ? 0 : object;
}
typedef struct HandleRelationEA8 {
    unsigned char pad[0xea8];
    unsigned int first;
    unsigned int second;
}
HandleRelationEA8;
typedef struct HandleSource154 {
    unsigned char pad[0x149];
    unsigned char kind;
    unsigned char gap[0x154-0x14a];
    unsigned int handle;
}
HandleSource154;
typedef char verify_HandleRelationEA8_first[(offsetof(HandleRelationEA8, first) == 0xea8)?1:-1];
typedef char verify_HandleRelationEA8_second[(offsetof(HandleRelationEA8, second) == 0xeac)?1:-1];
typedef char verify_HandleSource154_kind[(offsetof(HandleSource154, kind) == 0x149)?1:-1];
typedef char verify_HandleSource154_handle[(offsetof(HandleSource154, handle) == 0x154)?1:-1];
/* EXE: FUN_009b3710:009b3710..009b3743. */
__declspec(noinline) unsigned char __cdecl FUN_009b3710(const HandleSource154 *source) {
    if (source && source->kind == 0x18) {
        const HandleRelationEA8 *object = (const HandleRelationEA8 *)FUN_00960d60(source->handle);
        if (object && object->first && !object->second) return 1;
    }
    return 0;
}
typedef struct LookupFlagsC8 {
    unsigned char pad[0x80];
    unsigned int flags80;
    unsigned char gap[0xc8-0x84];
    unsigned int flagsc8;
}
LookupFlagsC8;
extern unsigned char __cdecl FUN_00985630(const LookupFlagsC8 *source);
/* EXE: FUN_00438710:00438710..00438776. */
__declspec(noinline) const LookupFlagsC8 * __cdecl FUN_00438710(unsigned int handle, unsigned char check) {
    const LookupFlagsC8 *object=(const LookupFlagsC8 *)lookup_handle_kind(handle,1);
    unsigned int flags;
    if (!object) return 0;
    flags=object->flags80;
    if (!(flags & 0xb)) {
        if (check && FUN_00985630(object)) return 0;
        if (!((unsigned char)(flags >> 4) & 1) && (object->flagsc8 & 0x400000)) return object;
    }
    return 0;
}
/* EXE: FUN_0098e8a0:0098e8a0..0098e8f1. */
static __forceinline int relation_is_one(MovementHandleObjectView *object) {
    return object && object->field_004c == 1 && object->field_03cc == 1;
}
static __forceinline int related_one(MovementHandleObjectView *source) {
    if (!relation_is_one(FUN_0098e710(0,source))) {
        if (!relation_is_one(FUN_0098e750(0,source))) return 0;
    }
    return 1;
}
__declspec(noinline) unsigned char __fastcall FUN_0098e8a0(void *unused, MovementHandleObjectView *source) {
    if (!source) return 0;
    if (source->field_004c == 1 && source->field_03cc == 1) return 0;
    return related_one(source);
}
typedef struct RelationFlags101 {
    unsigned char pad[0x101];
    unsigned char flags;
}
RelationFlags101;
typedef struct RelationFlags1170 {
    unsigned char pad[0x1170];
    unsigned char flags;
}
RelationFlags1170;
typedef struct RelationFlags11C6 {
    unsigned char pad[0x11c6];
    unsigned char flags;
}
RelationFlags11C6;
/* EXE: FUN_009c3a90:009c3a90..009c3afe. Retains the original unguarded later reads. */
__declspec(noinline) unsigned char __fastcall FUN_009c3a90(void *unused, MovementHandleObjectView *source) {
    if (source) {
        const SubtypeHandleObject *object=lookup_handle_kind(source->field_0044,1);
        if (object && object->subtype == 1) return 0;
        if (source->field_03cc == 2 && (((RelationFlags1170 *)source)->flags & 0x80)) return 0;
    }
    if (((RelationFlags101 *)source)->flags & 1) return 0;
    if (FUN_0098e8a0(0,source)) return 0;
    if (source->field_03cc == 2 && (((RelationFlags11C6 *)source)->flags & 0x40)) return 0;
    return 1;
}
typedef char verify_current_LookupFlagsC8_flags80[(offsetof(LookupFlagsC8,flags80)==0x80)?1:-1];
typedef char verify_current_LookupFlagsC8_flagsc8[(offsetof(LookupFlagsC8,flagsc8)==0xc8)?1:-1];
typedef char verify_current_RelationFlags101_flags[(offsetof(RelationFlags101,flags)==0x101)?1:-1];
typedef char verify_current_RelationFlags1170_flags[(offsetof(RelationFlags1170,flags)==0x1170)?1:-1];
typedef char verify_current_RelationFlags11C6_flags[(offsetof(RelationFlags11C6,flags)==0x11c6)?1:-1];
typedef struct NewFlagsC {
    unsigned char pad[12];
    unsigned char flags;
}
NewFlagsC;
/* EXE: FUN_00b72eb0:00b72eb0..00b72ec2. */
__declspec(noinline) int __cdecl FUN_00b72eb0(const NewFlagsC *source) {
    if (source && (source->flags & 1)) return 1;
    return 0;
}
typedef struct NewKind34 {
    unsigned char pad[0x34];
    int kind;
}
NewKind34;
/* EXE: FUN_00b72ed0:00b72ed0..00b72ee2. */
__declspec(noinline) int __cdecl FUN_00b72ed0(const NewKind34 *source) {
    if (source && source->kind == 0x15) return 1;
    return 0;
}
typedef struct NewNested9C {
    unsigned char pad[0x9c];
    int value;
}
NewNested9C;
typedef struct NewRoot84E4 {
    unsigned char pad[0x84e4];
    const NewNested9C *nested;
}
NewRoot84E4;
/* EXE: FUN_00ab53c0:00ab53c0..00ab53d4. */
__declspec(noinline) int __cdecl FUN_00ab53c0(const NewRoot84E4 *source) {
    if (!source) return -1;
    return source->nested->value;
}
typedef struct NewLookupStride40 {
    unsigned int value;
    unsigned char gap[36];
}
NewLookupStride40;
extern const NewLookupStride40 DAT_0290faa0[];
/* EXE: FUN_00705420:00705420..00705434. */
__declspec(noinline) unsigned int __cdecl FUN_00705420(unsigned int index) {
    if(index>=5000) return 0;
    return DAT_0290faa0[index].value;
}
typedef struct NewRecord54 {
    unsigned char bytes[0x54];
}
NewRecord54;
extern int DAT_02527d6c;
extern NewRecord54 DAT_015b8800[];
/* EXE: FUN_006e9340:006e9340..006e9357. */
__declspec(noinline) NewRecord54 * __cdecl FUN_006e9340(int index) {
    if(index<0 || index>=DAT_02527d6c) return 0;
    return &DAT_015b8800[index];
}
typedef char verify_new_NewFlagsC_flags[(offsetof(NewFlagsC,flags)==0xc)?1:-1];
typedef char verify_new_NewKind34_kind[(offsetof(NewKind34,kind)==0x34)?1:-1];
typedef char verify_new_NewNested9C_value[(offsetof(NewNested9C,value)==0x9c)?1:-1];
typedef char verify_new_NewRoot84E4_nested[(offsetof(NewRoot84E4,nested)==0x84e4)?1:-1];
typedef char verify_NewLookupStride40[(sizeof(NewLookupStride40)==40)?1:-1];
typedef char verify_NewRecord54[(sizeof(NewRecord54)==0x54)?1:-1];
/* EXE: FUN_006122d0:006122d0..006122ea. */
__declspec(noinline) int __cdecl FUN_006122d0(void) {
    return ((const ModeIndexRoot *)DAT_021703d4)->index->value == 0x33f;
}
typedef struct NewFlags1162 {
    unsigned char pad[0x1162];
    unsigned char flags;
}
NewFlags1162;
extern int DAT_00e8dd90;
/* EXE: FUN_00782e60:00782e60..00782e7a. */
__declspec(noinline) void __cdecl FUN_00782e60(void) {
    NewFlags1162 *source=(NewFlags1162 *)DAT_021703d4;
    DAT_00e8dd90=-1;
    if(source) source->flags &= 0xf8;
}
typedef struct NewFlagAFF {
    unsigned char pad[0xaff];
    unsigned char flag;
}
NewFlagAFF;
extern unsigned char DAT_02527d14;
extern const NewFlagAFF *DAT_02527d10;
/* EXE: FUN_006c6d90:006c6d90..006c6daf. */
__declspec(noinline) int __cdecl FUN_006c6d90(void) {
    if(DAT_02527d14 && !DAT_02527d10->flag) return 1;
    return 0;
}
typedef struct NewMode1134 {
    unsigned char pad[0xc0];
    unsigned int flags;
    unsigned char gap[0x148-0xc4];
    unsigned char kind;
    unsigned char gap149[0x1134-0x149];
    unsigned int value;
}
NewMode1134;
/* EXE: FUN_004181a0:004181a0..004181c1. */
__declspec(noinline) unsigned int __cdecl FUN_004181a0(const NewMode1134 *source) {
    if(source->kind==0x56 && !(source->flags & 0x20000)) return 0x1aa;
    return source->value;
}
typedef struct NewGroupSlot36 {
    unsigned int first, second, unknown08, fourth;
    unsigned char tail[20];
}
NewGroupSlot36;
typedef struct NewGroupRoot {
    unsigned char pad[0x6ce8];
    int count;
    unsigned char gap[0x84d8-0x6cec];
    unsigned char kind;
    unsigned char gap84d9[0x8ab0-0x84d9];
    NewGroupSlot36 slots[8];
}
NewGroupRoot;
/* EXE: FUN_00aa7460;
complete original 52-byte body, including signed index comparison. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_00aa7460(const NewGroupRoot *source, int index) {
    int count;
    if(!source) return 0;
    if(source->kind!=1) count=8;
    else {
        count=source->count;
        if(!count) return 0;
    }
    if(index>=count) return 0;
    return FUN_00960d60(source->slots[index].first);
}
/* EXE: FUN_00aa7500;
complete original 52-byte body, including signed index comparison. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_00aa7500(const NewGroupRoot *source, int index) {
    int count;
    if(!source) return 0;
    if(source->kind!=1) count=8;
    else {
        count=source->count;
        if(!count) return 0;
    }
    if(index>=count) return 0;
    return FUN_00960d60(source->slots[index].second);
}
/* EXE: FUN_00aa7380;
complete original 52-byte body, including signed index comparison. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_00aa7380(const NewGroupRoot *source, int index) {
    int count;
    if(!source) return 0;
    if(source->kind!=1) count=8;
    else {
        count=source->count;
        if(!count) return 0;
    }
    if(index>=count) return 0;
    return FUN_00960d60(source->slots[index].fourth);
}
/* EXE: FUN_00bdd100:00bdd100..00bdd12a. */
__declspec(noinline) void __cdecl FUN_00bdd100(int delay,int *destination) {
    int now=DAT_00e843ac;
    if(delay>=0) {
        int value=delay+now;
        *destination=value;
        if(value>1800000000) *destination=value-1800000000;
    }
    else {
        int value=delay+now;
        *destination=value;
        if(value<0) *destination=value+1800000000;
    }
}
typedef struct NewRoot8C28 {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap[0x8c28-0x48];
    int count;
}
NewRoot8C28;
/* EXE: FUN_00aab370:00aab370..00aab3ac. */
__declspec(noinline) int __fastcall FUN_00aab370(void *unused,const NewRoot8C28 *source)  {
    if(source)  {
        const SubtypeHandleObject *object=lookup_handle_untyped(source->handle);
        if(object==(const SubtypeHandleObject *)source && source->count>0) return 0;
    }
    return 1;
}
/* EXE: FUN_0045a830:0045a830..0045a86e. */
__declspec(noinline) const SubtypeHandleObject * __cdecl FUN_0045a830(const HandleSource154 *source) {
    const SubtypeHandleObject *object;
    if(source->kind!=0x18) return 0;
    object=lookup_handle_untyped(source->handle);
    if(!object) return 0;
    return (object->kind-1)?0:object;
}
typedef struct NewEnabledC4 {
    unsigned char pad[0xc4];
    unsigned char enabled;
}
NewEnabledC4;
extern const NewEnabledC4 *DAT_02527d04;
extern const NewEnabledC4 *DAT_02527d08;
extern const NewEnabledC4 *DAT_02527d0c;
/* EXE: FUN_006bcff0:006bcff0..006bd03a. */
__declspec(noinline) int __cdecl FUN_006bcff0(void)  {
    if(!DAT_02527d04 || !DAT_02527d04->enabled) return 0;
    if(!DAT_02527d08 || !DAT_02527d08->enabled) return 1;
    if(!DAT_02527d0c || !DAT_02527d0c->enabled) return 2;
    return 3;
}
typedef struct NewFlagSlot48 {
    unsigned char flags;
    unsigned char gap[0x47];
}
NewFlagSlot48;
extern int DAT_02223cb4;
extern const NewFlagSlot48 DAT_02f3528c[];
/* EXE: FUN_00a669d0:00a669d0..00a669fd. */
__declspec(noinline) unsigned char __cdecl FUN_00a669d0(void)  {
    int count=DAT_02223cb4;
    int index;
    for(index=0;
    index<count;
    ++index)  {
        unsigned char flags=DAT_02f3528c[index].flags;
        if((flags & 4) && (flags & 0x20)) return 1;
    }
    return 0;
}
typedef char verify_leaf_NewFlags1162_flags[(offsetof(NewFlags1162,flags)==0x1162)?1:-1];
typedef char verify_leaf_NewFlagAFF_flag[(offsetof(NewFlagAFF,flag)==0xaff)?1:-1];
typedef char verify_leaf_NewMode1134_flags[(offsetof(NewMode1134,flags)==0xc0)?1:-1];
typedef char verify_leaf_NewMode1134_kind[(offsetof(NewMode1134,kind)==0x148)?1:-1];
typedef char verify_leaf_NewMode1134_value[(offsetof(NewMode1134,value)==0x1134)?1:-1];
typedef char verify_leaf_NewGroupRoot_count[(offsetof(NewGroupRoot,count)==0x6ce8)?1:-1];
typedef char verify_leaf_NewGroupRoot_kind[(offsetof(NewGroupRoot,kind)==0x84d8)?1:-1];
typedef char verify_leaf_NewGroupRoot_slots[(offsetof(NewGroupRoot,slots)==0x8ab0)?1:-1];
typedef char verify_leaf_NewGroupSlot36_first[(offsetof(NewGroupSlot36,first)==0x0)?1:-1];
typedef char verify_leaf_NewGroupSlot36_second[(offsetof(NewGroupSlot36,second)==0x4)?1:-1];
typedef char verify_leaf_NewGroupSlot36_fourth[(offsetof(NewGroupSlot36,fourth)==0xc)?1:-1];
typedef char verify_leaf_NewRoot8C28_handle[(offsetof(NewRoot8C28,handle)==0x44)?1:-1];
typedef char verify_leaf_NewRoot8C28_count[(offsetof(NewRoot8C28,count)==0x8c28)?1:-1];
typedef char verify_leaf_NewEnabledC4_enabled[(offsetof(NewEnabledC4,enabled)==0xc4)?1:-1];
typedef char verify_leaf_size_NewGroupSlot36[(sizeof(NewGroupSlot36)==36)?1:-1];
typedef char verify_leaf_size_NewFlagSlot48[(sizeof(NewFlagSlot48)==72)?1:-1];
/* EXE: FUN_00b72c40:00b72c40..00b72c52. */
__declspec(noinline) unsigned char __cdecl FUN_00b72c40(const NewKind34 *source)  {
    if(!source) return 0;
    return source->kind==5;
}
typedef struct NewKind32C {
    unsigned char pad[0x149];
    unsigned char kind;
    unsigned char gap[0x32c-0x14a];
    int value;
}
NewKind32C;
/* EXE: FUN_0043f9c0:0043f9c0..0043f9da. */
__declspec(noinline) unsigned char __cdecl FUN_0043f9c0(const NewKind32C *source)  {
    if(source->kind) return 0;
    return source->value!=-1;
}
/* EXE: FUN_00ab5190:00ab5190..00ab51ab. */
__declspec(noinline) unsigned char __cdecl FUN_00ab5190(const NewRoot84E4 *source)  {
    if(!source) return 0;
    return source->nested->value==3;
}
/* EXE: FUN_00ab51b0:00ab51b0..00ab51cb. */
__declspec(noinline) unsigned char __cdecl FUN_00ab51b0(const NewRoot84E4 *source)  {
    if(!source) return 0;
    return source->nested->value==1;
}
typedef struct NewRatio1120 {
    unsigned char pad[0x1120];
    int count;
    float value;
}
NewRatio1120;
/* EXE: FUN_004067b0:004067b0..004067d8. */
__declspec(noinline) float __cdecl FUN_004067b0(const NewRatio1120 *source)  {
    float result;
    if(source->count>0) result=source->value/source->count;
    else result=0.0f;
    return result;
}
extern unsigned char DAT_00f8549b;
extern float DAT_025f5ca4;
extern float DAT_025f5c8c;
/* EXE: FUN_0049d320:0049d320..0049d34c. */
__declspec(noinline) void __cdecl FUN_0049d320(float value)  {
    if(DAT_00f8549b & 4)  {
        DAT_025f5ca4=-value*DAT_025f5c8c;
        return;
    }
    DAT_025f5ca4=DAT_025f5c8c*value;
}
typedef struct NewIndex48 {
    unsigned char pad[0x48];
    unsigned short index;
    unsigned char gap[0x13c-0x4a];
    unsigned int value;
}
NewIndex48;
extern const void *DAT_00f7aae8[];
/* EXE: FUN_00a00050:00a00050..00a0007e. */
__declspec(noinline) unsigned int __cdecl FUN_00a00050(const NewIndex48 *source)  {
    unsigned int index;
    if(source->index==0xbeef) return 0;
    index=source->index;
    if(index==0xffff || index>=0x866 || !DAT_00f7aae8[index]) return 0;
    return source->value;
}
typedef struct NewFloat30 {
    unsigned char pad[0x30];
    float value;
}
NewFloat30;
extern const double DAT_00e5bfa0;
extern const double DAT_00e5c188;
/* EXE: FUN_00ac0290:00ac0290..00ac02c7. */
__declspec(noinline) unsigned char __cdecl FUN_00ac0290(const NewFloat30 *source)  {
    float difference=(float)(source->value-DAT_00e5bfa0);
    if(DAT_00e5c188>difference && -difference<DAT_00e5c188) return 1;
    return 0;
}
/* EXE: FUN_00404a20:00404a20..00404a66. */
__declspec(noinline) float __cdecl FUN_00404a20(const Position3 *first,const Position3 *second)  {
    float difference=first->x-second->x;
    float result=difference*difference;
    difference=first->y-second->y;
    result+=difference*difference;
    difference=first->z-second->z;
    result+=difference*difference;
    return result;
}
extern const unsigned char *DAT_022d7bcc;
extern int DAT_022d7bd0;
/* EXE: FUN_00b73b70:00b73b70..00b73ba8. */
__declspec(noinline) unsigned char __cdecl FUN_00b73b70(const unsigned char *source)  {
    if(!source || (unsigned int)source<(unsigned int)DAT_022d7bcc || (unsigned int)source>=(unsigned int)DAT_022d7bcc+DAT_022d7bd0*0x498) return 0xff;
    return (int)((unsigned int)source-(unsigned int)DAT_022d7bcc)/0x498;
}
typedef struct NewListNode {
    struct NewListNode *next,*previous;
}
NewListNode;
extern NewListNode *DAT_021fc19c;
/* EXE: FUN_00a15b20:00a15b20..00a15b8a. */
__declspec(noinline) void __cdecl FUN_00a15b20(NewListNode *node,NewListNode **head)  {
    if(*head==node)  {
        if(node->next==node)  {
            node->next=0;
            node->previous=0;
            *head=0;
            goto insert;
        }
        *head=node->next;
    }
    if(node->previous) node->previous->next=node->next;
    if(node->next) node->next->previous=node->previous;
    node->next=0;
    node->previous=0;
    insert: if(!DAT_021fc19c)  {
        node->next=node;
        node->previous=node;
        DAT_021fc19c=node;
        return;
    }
    node->previous=DAT_021fc19c->previous;
    node->next=DAT_021fc19c;
    DAT_021fc19c->previous->next=node;
    DAT_021fc19c->previous=node;
}
typedef char verify_more_NewKind32C_kind[(offsetof(NewKind32C,kind)==0x149)?1:-1];
typedef char verify_more_NewKind32C_value[(offsetof(NewKind32C,value)==0x32c)?1:-1];
typedef char verify_more_NewRatio1120_count[(offsetof(NewRatio1120,count)==0x1120)?1:-1];
typedef char verify_more_NewRatio1120_value[(offsetof(NewRatio1120,value)==0x1124)?1:-1];
typedef char verify_more_NewIndex48_index[(offsetof(NewIndex48,index)==0x48)?1:-1];
typedef char verify_more_NewIndex48_value[(offsetof(NewIndex48,value)==0x13c)?1:-1];
typedef char verify_more_NewFloat30_value[(offsetof(NewFloat30,value)==0x30)?1:-1];
typedef char verify_more_NewListNode_next[(offsetof(NewListNode,next)==0x0)?1:-1];
typedef char verify_more_NewListNode_previous[(offsetof(NewListNode,previous)==0x4)?1:-1];
typedef struct NewFlag8 {
    unsigned char pad[8];
    unsigned char flags;
}
NewFlag8;
typedef struct NewControlObject {
    unsigned char pad[0xd4];
    const NewFlag8 *flag;
}
NewControlObject;
typedef struct NewControlRoot {
    unsigned char pad[0xc0];
    unsigned int flags;
    unsigned char gap[0x10cc-0xc4];
    const SwitchLinkC4 *link;
    unsigned char gap10d0[0x139c-0x10d0];
    int control139c,control13a0,control13a4,control13a8,control13ac;
}
NewControlRoot;
/* EXE: FUN_004f6800:004f6800..004f68a1. */
__declspec(noinline) void __cdecl FUN_004f6800(NewControlRoot *source)  {
    source->control13a4=4;
    if(source->flags & 0x800000) source->control139c=0;
    else  {
        const SwitchLinkC4 *first=source->link;
        const Switch34View *object=0;
        source->control139c=3;
        if(first && first->nested) object=first->nested->object;
        if(!object || FUN_00b72740(object)) source->control13a4=0xc4;
        else  {
            const NewFlag8 *flag=((const NewControlObject *)object)->flag;
            if(flag) source->control13a4=(flag->flags & 2)?0x204:0x1c;
        }
    }
    source->control13a0=0;
    source->control13a8=0;
    source->control13ac=0;
}
typedef char verify_control_NewControlRoot_flags[(offsetof(NewControlRoot,flags)==0xc0)?1:-1];
typedef char verify_control_NewControlRoot_link[(offsetof(NewControlRoot,link)==0x10cc)?1:-1];
typedef char verify_control_NewControlRoot_control139c[(offsetof(NewControlRoot,control139c)==0x139c)?1:-1];
typedef char verify_control_NewControlRoot_control13a0[(offsetof(NewControlRoot,control13a0)==0x13a0)?1:-1];
typedef char verify_control_NewControlRoot_control13a4[(offsetof(NewControlRoot,control13a4)==0x13a4)?1:-1];
typedef char verify_control_NewControlRoot_control13a8[(offsetof(NewControlRoot,control13a8)==0x13a8)?1:-1];
typedef char verify_control_NewControlRoot_control13ac[(offsetof(NewControlRoot,control13ac)==0x13ac)?1:-1];
typedef char verify_control_NewControlObject_flag[(offsetof(NewControlObject,flag)==0xd4)?1:-1];
typedef char verify_control_NewFlag8_flags[(offsetof(NewFlag8,flags)==0x8)?1:-1];
/* EXE: FUN_00925010:00925010..00925025. */
__declspec(noinline) int __cdecl FUN_00925010(const Flags80Root *source) {
    if(!source || (source->flags & 0xb)) return 1;
    return 0;
}
/* EXE: FUN_0047b860:0047b860..0047b875. */
__declspec(noinline) int __cdecl FUN_0047b860(const unsigned int *key) {
    if((unsigned char)*key==0xff || !(*key & 0xffffff00)) return 0;
    return 1;
}
/* EXE: FUN_009266b0:009266b0..009266c8. */
__declspec(noinline) unsigned char __cdecl FUN_009266b0(const MovementHandleObjectView *source) {
    if(source && source->field_004c==1 && source->field_03cc==2) return 1;
    return 0;
}
/* EXE: FUN_00963580:00963580..0096359b. */
__declspec(noinline) unsigned char __cdecl FUN_00963580(const AttachmentRoot *source) {
    if(source && source->kind==2 && source->attachment) return 1;
    return 0;
}
/* EXE: FUN_009635d0:009635d0..009635eb. */
__declspec(noinline) unsigned char __cdecl FUN_009635d0(const MovementHandleObjectView *source) {
    if(source && source->field_03cc==2 && (((const RelationFlags1170 *)source)->flags & 0x80)) return 1;
    return 0;
}
typedef struct DeepGlobal8 {
    unsigned char pad[8];
    int value;
}
DeepGlobal8;
extern int DAT_0212b160;
/* EXE: FUN_007fca90:007fca90..007fcaa2. */
__declspec(noinline) int __cdecl FUN_007fca90(void) {
    if(DAT_02528c14) return ((const DeepGlobal8 *)DAT_02528c14)->value;
    return DAT_0212b160;
}
typedef struct DeepIndex10 {
    unsigned char pad[0x10];
    unsigned int index;
}
DeepIndex10;
typedef struct DeepFloat28 {
    unsigned char pad[0x28];
    float value;
}
DeepFloat28;
extern const DeepFloat28 *DAT_00ee9178[];
extern const double DAT_00e5c400;
/* EXE: FUN_00479d10:00479d10..00479d31. */
__declspec(noinline) float __cdecl FUN_00479d10(const DeepIndex10 *source) {
    float result=DAT_00ee9178[source->index & 0xfff]->value*DAT_00e5c400;
    return result;
}
/* EXE: FUN_00479710:00479710..00479731. */
__declspec(noinline) float __cdecl FUN_00479710(const DeepIndex10 *source) {
    float result=DAT_00ee9178[source->index & 0xfff]->value*DAT_00e5c400;
    return result;
}
typedef struct DeepDeadline8FFC {
    unsigned char pad[0x8ffc];
    int deadline;
}
DeepDeadline8FFC;
/* EXE: FUN_00ab4af0:00ab4af0..00ab4b12. */
__declspec(noinline) void __cdecl FUN_00ab4af0(DeepDeadline8FFC *source) {
    int value=DAT_00e843ac+300;
    source->deadline=value;
    if(value>1800000000) source->deadline=value-1800000000;
}
typedef struct DeepSignedFA8 {
    unsigned char pad[0xfa8];
    signed char index;
}
DeepSignedFA8;
extern int DAT_0213ccd8;
extern const float DAT_00eb43fc;
/* EXE: FUN_008c9df0:008c9df0..008c9e17. */
__declspec(noinline) float __cdecl FUN_008c9df0(const DeepSignedFA8 *source) {
    float result;
    if(DAT_0213ccd8==source->index) result=DAT_00eb43fc;
    else result=1.0f;
    return result;
}
typedef struct DeepMode84 {
    unsigned char pad[4];
    int mode;
    unsigned char gap08[0x28-8];
    int value28;
    unsigned char gap2c[0x60-0x2c];
    int value60;
    unsigned char gap64[0x84-0x64];
    int value84;
}
DeepMode84;
/* EXE: FUN_00b07e30:00b07e30..00b07e58. */
__declspec(noinline) int __cdecl FUN_00b07e30(const DeepMode84 *source) {
    int mode=source->mode;
    if(mode==1) return source->value60;
    if(mode==2) {
        int value=source->value84;
        if(value!=-1) return value;
        return source->value28;
    }
    if(mode==3) return source->value28;
    return -1;
}
/* EXE: FUN_0079d330:0079d330..0079d358. */
__declspec(noinline) void __cdecl FUN_0079d330(NewListNode *node,NewListNode **head) {
    if(!node) return;
    if(!*head) {
        node->next=node;
        node->previous=node;
        *head=node;
        return;
    }
    node->previous=(*head)->previous;
    node->next=*head;
    (*head)->previous->next=node;
    (*head)->previous=node;
}
typedef struct DeepIdNode {
    const struct DeepIdNode *next;
    unsigned char gap[0x10-4];
    unsigned short id;
}
DeepIdNode;
extern const DeepIdNode *DAT_0140c85c;
/* EXE: FUN_00683d20:00683d20..00683d43. */
__declspec(noinline) const DeepIdNode * __fastcall FUN_00683d20(void *unused,unsigned short id) {
    const DeepIdNode *head,*node;
    if(!id) return 0;
    head=DAT_0140c85c;
    node=head;
    if(!node) return 0;
    do {
        if(node->id==id) return node;
        node=node->next;
        if(node==head) return 0;
    }
    while(node);
    return 0;
}
typedef struct DeepPlayerD74 {
    unsigned char pad[0x5e0];
    const ModeIndex *index;
    unsigned char gap[0xd74-0x5e4];
    unsigned int handle;
}
DeepPlayerD74;
extern unsigned int DAT_025f5bb0;
/* EXE: FUN_004998e0:004998e0..0049990a. */
__declspec(noinline) unsigned char __cdecl FUN_004998e0(void) {
    const DeepPlayerD74 *player=(const DeepPlayerD74 *)DAT_021703d4;
    if(DAT_025f5bb0==player->handle && player->index->value==0x441) return 1;
    return 0;
}
extern const unsigned short DAT_02526af0;
extern const unsigned int *DAT_00ee5558[];
/* EXE: FUN_00479a50:00479a50..00479a7c. */
__declspec(noinline) unsigned short __fastcall FUN_00479a50(void *unused,const unsigned int *target) {
    unsigned short index=0;
    for(;
    index<DAT_02526af0;
    ++index) {
        if(*DAT_00ee5558[index]==*target) return index;
    }
    return 0xffff;
}
typedef struct DeepFlags8D88 {
    unsigned char pad[0x8d88];
    unsigned short flags;
}
DeepFlags8D88;
/* EXE: FUN_004892e0:004892e0..0048930c. */
__declspec(noinline) void __fastcall FUN_004892e0(unsigned int handle) {
    const SubtypeHandleObject *object=lookup_handle_kind(handle,5);
    if(object) ((DeepFlags8D88 *)object)->flags &= 0xffe7;
}
typedef struct DeepTimer5EC {
    unsigned char pad[0x5ec];
    int period,deadline;
}
DeepTimer5EC;
/* EXE: FUN_0098aa80:0098aa80..0098aaac. */
__declspec(noinline) void __cdecl FUN_0098aa80(DeepTimer5EC *source) {
    int value=DAT_00e843ac+1000;
    source->period=500;
    source->deadline=value;
    if(value>1800000000) source->deadline=value-1800000000;
}
/* Layout checks for the two-level call-path recoveries. */
typedef char verify_deep_DeepGlobal8_value[(offsetof(DeepGlobal8,value)==0x8)?1:-1];
typedef char verify_deep_DeepIndex10_index[(offsetof(DeepIndex10,index)==0x10)?1:-1];
typedef char verify_deep_DeepFloat28_value[(offsetof(DeepFloat28,value)==0x28)?1:-1];
typedef char verify_deep_DeepDeadline8FFC_deadline[(offsetof(DeepDeadline8FFC,deadline)==0x8ffc)?1:-1];
typedef char verify_deep_DeepSignedFA8_index[(offsetof(DeepSignedFA8,index)==0xfa8)?1:-1];
typedef char verify_deep_DeepMode84_mode[(offsetof(DeepMode84,mode)==0x4)?1:-1];
typedef char verify_deep_DeepMode84_value28[(offsetof(DeepMode84,value28)==0x28)?1:-1];
typedef char verify_deep_DeepMode84_value60[(offsetof(DeepMode84,value60)==0x60)?1:-1];
typedef char verify_deep_DeepMode84_value84[(offsetof(DeepMode84,value84)==0x84)?1:-1];
typedef char verify_deep_DeepIdNode_next[(offsetof(DeepIdNode,next)==0x0)?1:-1];
typedef char verify_deep_DeepIdNode_id[(offsetof(DeepIdNode,id)==0x10)?1:-1];
typedef char verify_deep_DeepPlayerD74_index[(offsetof(DeepPlayerD74,index)==0x5e0)?1:-1];
typedef char verify_deep_DeepPlayerD74_handle[(offsetof(DeepPlayerD74,handle)==0xd74)?1:-1];
typedef char verify_deep_DeepFlags8D88_flags[(offsetof(DeepFlags8D88,flags)==0x8d88)?1:-1];
typedef char verify_deep_DeepTimer5EC_period[(offsetof(DeepTimer5EC,period)==0x5ec)?1:-1];
typedef char verify_deep_DeepTimer5EC_deadline[(offsetof(DeepTimer5EC,deadline)==0x5f0)?1:-1];
extern const unsigned char DAT_02fad1f8;
extern int DAT_0252a0d8;
/* EXE: FUN_00aa8340:00aa8340..00aa836e. */
__declspec(noinline) int __cdecl FUN_00aa8340(const NewRoot84E4 *source) {
    int index;
    if(!source) return -1;
    index=(int)((unsigned int)source->nested-(unsigned int)&DAT_02fad1f8)/2000;
    if(index<0 || index>=DAT_0252a0d8) return -1;
    return index;
}
typedef struct DeepFloatE4 {
    unsigned char pad[0xe4];
    float value;
}
DeepFloatE4;
extern const float DAT_00e5c110;
/* EXE: FUN_00b71a60:00b71a60..00b71a90. */
__declspec(noinline) float __cdecl FUN_00b71a60(const DeepFloatE4 *source) {
    float value,result;
    if(source) value=source->value;
    else value=DAT_00e5c110;
    result=value*value;
    return result;
}
typedef struct DeepOwner1AC DeepOwner1AC;
typedef struct DeepOwner404 {
    unsigned char pad[0x404];
    const DeepOwner1AC *current;
}
DeepOwner404;
struct DeepOwner1AC {
    unsigned char pad[0x1ac];
    const DeepOwner404 *owner;
}
;
typedef struct DeepKindC {
    unsigned char pad[0xc];
    int kind;
}
DeepKindC;
/* EXE: FUN_00814b00:00814b00..00814b35. */
__declspec(noinline) unsigned char __cdecl FUN_00814b00(const DeepKindC *source,const DeepOwner1AC *object) {
    int kind=source->kind;
    if(!kind) {
        if(object && object==object->owner->current) return 1;
        return 0;
    }
    if(kind==1 && object && object==object->owner->current) return 0;
    return 1;
}
/* EXE: FUN_00479a80:00479a80..00479ab5. */
__declspec(noinline) float __cdecl FUN_00479a80(unsigned short index) {
    const DeepIndex10 *source;
    float result;
    if(index==0xffff) return 0.0f;
    source=(const DeepIndex10 *)DAT_00ee5558[index];
    result=DAT_00ee9178[source->index & 0xfff]->value*DAT_00e5c400;
    return result;
}
typedef struct DeepInt12 {
    int value;
    unsigned char tail[8];
}
DeepInt12;
extern const DeepInt12 DAT_00e90e44[];
/* EXE: FUN_006ef770:006ef770..006ef782. */
__declspec(noinline) int __cdecl FUN_006ef770(int index) {
    if(index==-1) return index;
    return DAT_00e90e44[index].value;
}
typedef struct DeepResetB71 {
    unsigned char pad[0xc4];
    unsigned int flags;
    unsigned char gapc8[0xaf8-0xc8];
    unsigned int field_af8;
    float value;
    unsigned int field_b00;
    unsigned char gapb04[0xb24-0xb04];
    unsigned char byte_b24;
    unsigned char gapb25[0xb71-0xb25];
    unsigned char flags_b71;
}
DeepResetB71;
/* EXE: FUN_00981dc0:00981dc0..00981dfc. */
__declspec(noinline) void __cdecl FUN_00981dc0(DeepResetB71 *source) {
    unsigned int zero=0;
    if(source!=(void *)zero) {
        unsigned int flags=source->flags;
        if(flags & 3) {
            source->value=0.0f;
            flags &= 0xfffffffc;
            source->flags=flags;
            source->field_af8=zero;
        }
        source->flags_b71 &= 0xfe;
        source->field_b00=zero;
        source->byte_b24=0xff;
    }
}
typedef char verify_more_deep_DeepFloatE4_value[(offsetof(DeepFloatE4,value)==0xe4)?1:-1];
typedef char verify_more_deep_DeepOwner1AC_owner[(offsetof(DeepOwner1AC,owner)==0x1ac)?1:-1];
typedef char verify_more_deep_DeepOwner404_current[(offsetof(DeepOwner404,current)==0x404)?1:-1];
typedef char verify_more_deep_DeepKindC_kind[(offsetof(DeepKindC,kind)==0xc)?1:-1];
typedef char verify_more_deep_DeepInt12_value[(offsetof(DeepInt12,value)==0x0)?1:-1];
typedef char verify_more_deep_DeepResetB71_flags[(offsetof(DeepResetB71,flags)==0xc4)?1:-1];
typedef char verify_more_deep_DeepResetB71_field_af8[(offsetof(DeepResetB71,field_af8)==0xaf8)?1:-1];
typedef char verify_more_deep_DeepResetB71_value[(offsetof(DeepResetB71,value)==0xafc)?1:-1];
typedef char verify_more_deep_DeepResetB71_field_b00[(offsetof(DeepResetB71,field_b00)==0xb00)?1:-1];
typedef char verify_more_deep_DeepResetB71_byte_b24[(offsetof(DeepResetB71,byte_b24)==0xb24)?1:-1];
typedef char verify_more_deep_DeepResetB71_flags_b71[(offsetof(DeepResetB71,flags_b71)==0xb71)?1:-1];
typedef char verify_deep_DeepInt12_stride[(sizeof(DeepInt12)==12)?1:-1];
typedef struct DeepHandleEA8 {
    unsigned char pad[0x149];
    unsigned char kind;
    unsigned char gap14a[0x154-0x14a];
    unsigned int fallback;
    unsigned char gap158[0xea8-0x158];
    unsigned int primary;
}
DeepHandleEA8;
/* EXE: FUN_009b3980:009b3980..009b39c8. */
__declspec(noinline) unsigned int __cdecl FUN_009b3980(const DeepHandleEA8 *source)  {
    unsigned int handle=source->primary;
    const SubtypeHandleObject *object;
    if(!handle)  {
        if(source->kind!=0x22) return 0;
        handle=source->fallback;
        if(!handle) return 0;
    }
    object=lookup_handle_kind(handle,1);
    if(!object || ((const HandleSource154 *)object)->kind!=0x18) return 0;
    return handle;
}
typedef struct DeepValueNode8C {
    struct DeepValueNode8C *next;
    unsigned char gap[0x8c-4];
    float value;
}
DeepValueNode8C;
typedef struct DeepListC4 {
    unsigned char pad[0xc4];
    DeepValueNode8C *head;
}
DeepListC4;
/* EXE: FUN_0050ede0:0050ede0..0050ee28. */
__declspec(noinline) void __cdecl FUN_0050ede0(unsigned int handle,float value)  {
    const SubtypeHandleObject *object=lookup_handle_kind(handle,6);
    if(object)  {
        DeepValueNode8C *node=((const DeepListC4 *)object)->head;
        if(node)  {
            do  {
                node->value=value;
                node=node->next;
                if(node==((const DeepListC4 *)object)->head) break;
            }
            while(node);
        }
    }
}
typedef struct DeepFlag3F8 {
    unsigned char pad[0x3f8];
    unsigned char flag;
}
DeepFlag3F8;
typedef struct DeepValue20 {
    unsigned int value;
    unsigned char tail[0x1c];
}
DeepValue20;
extern unsigned char DAT_02527cf5;
extern unsigned char DAT_02528b56;
extern unsigned char DAT_02528b2b;
extern DeepValue20 DAT_027daea4[];
/* EXE: FUN_006b71b0:006b71b0..006b71fd. */
__declspec(noinline) void __cdecl FUN_006b71b0(unsigned int index)  {
    if(DAT_02527cf5) return;
    if(DAT_02528c14)  {
        if(DAT_02528b56 && !DAT_02528b2b) return;
        if(!((const DeepFlag3F8 *)DAT_02528c14)->flag) return;
    }
    if(index>0x85) return;
    if(!DAT_027daea4[index].value) DAT_027daea4[index].value=1;
}
typedef struct DeepToggle64 {
    unsigned char pad[0x10];
    int count;
    unsigned char gap14[0x24-0x14];
    unsigned char enabled;
    unsigned char gap25[0x44-0x25];
    float zero44,zero48,zero4c;
    unsigned int current50,current54,current58,saved5c,saved60,saved64;
}
DeepToggle64;
extern unsigned int DAT_0252a6d0;
extern unsigned int DAT_0252a6d4;
extern unsigned int DAT_0252a6d8;
/* EXE: FUN_0056bb30:0056bb30..0056bb81. */
__declspec(noinline) void __cdecl FUN_0056bb30(DeepToggle64 *source,unsigned char enabled)  {
    if(!source->enabled && enabled)  {
        source->saved5c=DAT_0252a6d0;
        source->saved60=DAT_0252a6d4;
        source->saved64=DAT_0252a6d8;
        source->current50=source->saved5c;
        source->current54=source->saved60;
        source->current58=source->saved64;
    }
    source->enabled=enabled;
    if(!enabled)  {
        source->count=0;
        return;
    }
    source->zero44=0.0f;
    source->zero48=0.0f;
    source->zero4c=0.0f;
}
typedef struct DeepMatchNode10 {
    struct DeepMatchNode10 *next;
    unsigned int unknown4,key,value1,value2;
}
DeepMatchNode10;
extern DeepMatchNode10 *DAT_02526a00;
extern DeepMatchNode10 *DAT_02526a04;
/* EXE: FUN_004020f0:004020f0..00402156. */
__declspec(noinline) unsigned char __cdecl FUN_004020f0(unsigned int key,unsigned int optional1,unsigned int optional2)  {
    DeepMatchNode10 *head=DAT_02526a00,*node=head;
    if(node)  {
        do  {
            if(node->key==key && (!optional1 || node->value1==optional1) && (!optional2 || node->value2==optional2)) return 1;
            node=node->next;
            if(node==head) break;
        }
        while(node);
    }
    head=DAT_02526a04;
    node=head;
    if(node)  {
        do  {
            if(node->key==key && (!optional1 || node->value1==optional1) && (!optional2 || node->value2==optional2)) return 1;
            node=node->next;
            if(node==head) break;
        }
        while(node);
    }
    return 0;
}
/* Field offsets read by the complete original bodies above. */
typedef char verify_deep_batch_DeepHandleEA8_kind[(offsetof(DeepHandleEA8,kind)==0x149)?1:-1];
typedef char verify_deep_batch_DeepHandleEA8_fallback[(offsetof(DeepHandleEA8,fallback)==0x154)?1:-1];
typedef char verify_deep_batch_DeepHandleEA8_primary[(offsetof(DeepHandleEA8,primary)==0xea8)?1:-1];
typedef char verify_deep_batch_DeepValueNode8C_next[(offsetof(DeepValueNode8C,next)==0x0)?1:-1];
typedef char verify_deep_batch_DeepValueNode8C_value[(offsetof(DeepValueNode8C,value)==0x8c)?1:-1];
typedef char verify_deep_batch_DeepListC4_head[(offsetof(DeepListC4,head)==0xc4)?1:-1];
typedef char verify_deep_batch_DeepFlag3F8_flag[(offsetof(DeepFlag3F8,flag)==0x3f8)?1:-1];
typedef char verify_deep_batch_DeepValue20_value[(offsetof(DeepValue20,value)==0x0)?1:-1];
typedef char verify_deep_batch_DeepToggle64_count[(offsetof(DeepToggle64,count)==0x10)?1:-1];
typedef char verify_deep_batch_DeepToggle64_enabled[(offsetof(DeepToggle64,enabled)==0x24)?1:-1];
typedef char verify_deep_batch_DeepToggle64_zero44[(offsetof(DeepToggle64,zero44)==0x44)?1:-1];
typedef char verify_deep_batch_DeepToggle64_zero48[(offsetof(DeepToggle64,zero48)==0x48)?1:-1];
typedef char verify_deep_batch_DeepToggle64_zero4c[(offsetof(DeepToggle64,zero4c)==0x4c)?1:-1];
typedef char verify_deep_batch_DeepToggle64_current50[(offsetof(DeepToggle64,current50)==0x50)?1:-1];
typedef char verify_deep_batch_DeepToggle64_current54[(offsetof(DeepToggle64,current54)==0x54)?1:-1];
typedef char verify_deep_batch_DeepToggle64_current58[(offsetof(DeepToggle64,current58)==0x58)?1:-1];
typedef char verify_deep_batch_DeepToggle64_saved5c[(offsetof(DeepToggle64,saved5c)==0x5c)?1:-1];
typedef char verify_deep_batch_DeepToggle64_saved60[(offsetof(DeepToggle64,saved60)==0x60)?1:-1];
typedef char verify_deep_batch_DeepToggle64_saved64[(offsetof(DeepToggle64,saved64)==0x64)?1:-1];
typedef char verify_deep_batch_DeepMatchNode10_next[(offsetof(DeepMatchNode10,next)==0x0)?1:-1];
typedef char verify_deep_batch_DeepMatchNode10_key[(offsetof(DeepMatchNode10,key)==0x8)?1:-1];
typedef char verify_deep_batch_DeepMatchNode10_value1[(offsetof(DeepMatchNode10,value1)==0xc)?1:-1];
typedef char verify_deep_batch_DeepMatchNode10_value2[(offsetof(DeepMatchNode10,value2)==0x10)?1:-1];
typedef char verify_deep_batch_DeepValue20_stride[(sizeof(DeepValue20)==0x20)?1:-1];
/* EXE: FUN_00bde500:00bde500..00bde56e. */
__declspec(noinline) void __cdecl FUN_00bde500(float *vector, const float *matrix) {
    float x = vector[0], y = vector[1], z = vector[2];
    vector[0] = y * matrix[1] + x * matrix[0] + z * matrix[2];
    vector[1] = matrix[4] * y + matrix[3] * x + matrix[5] * z;
    vector[2] = matrix[7] * y + matrix[6] * x + z * matrix[8];
}
typedef struct ThirdValue28  {
    unsigned int value;
    unsigned char tail[36];
}
ThirdValue28;
extern ThirdValue28 DAT_0290fa9c[];
/* EXE: FUN_00705460:00705460..00705474. */
__declspec(noinline) unsigned int __cdecl FUN_00705460(unsigned int index)  {
    if(index>=5000) return 0;
    return DAT_0290fa9c[index].value;
}
typedef struct ThirdGlobal90  {
    unsigned char pad[0x3c];
    unsigned int kind;
    unsigned char gap40[0x90-0x40];
    unsigned int value;
}
ThirdGlobal90;
extern const ThirdGlobal90 *DAT_027b3c60;
/* EXE: FUN_006a8ca0:006a8ca0..006a8cb8. */
__declspec(noinline) unsigned int __cdecl FUN_006a8ca0(void)  {
    const ThirdGlobal90 *source=DAT_027b3c60;
    if(!source || source->kind!=1) return 0;
    return source->value;
}
typedef struct ThirdValue3C  {
    unsigned char pad[0x3c];
    unsigned int value;
}
ThirdValue3C;
typedef struct ThirdOwner8  {
    unsigned char pad[8];
    const ThirdValue3C *object;
}
ThirdOwner8;
typedef struct ThirdRootC4  {
    unsigned char pad[0xc4];
    const ThirdOwner8 *owner;
}
ThirdRootC4;
typedef struct ThirdOuter8  {
    unsigned char pad[8];
    const ThirdRootC4 *object;
}
ThirdOuter8;
/* EXE: FUN_00558d90:00558d90..00558daa. */
__declspec(noinline) unsigned int __cdecl FUN_00558d90(const ThirdOuter8 *source)  {
    const ThirdRootC4 *object=source->object;
    if(!object || !object->owner) return 0;
    return object->owner->object->value;
}
typedef struct ThirdValueB8  {
    unsigned char pad[0xb8];
    unsigned int value;
}
ThirdValueB8;
typedef struct ThirdRoot1178  {
    unsigned char pad[0x1178];
    const ThirdValueB8 *object;
}
ThirdRoot1178;
/* EXE: FUN_009f58d0:009f58d0..009f58eb. */
__declspec(noinline) int __cdecl FUN_009f58d0(const ThirdRoot1178 *source)  {
    const ThirdValueB8 *object=source->object;
    if(object && object->value) return 1;
    return 0;
}
/* EXE: FUN_00925030:00925030..0092504f. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_00925030(unsigned int handle)  {
    const SubtypeHandleObject *object;
    if(!handle) return 0;
    object=(const SubtypeHandleObject *)DAT_02149c64[handle&0xfff].object;
    if(!object || object->handle!=handle) return 0;
    return object;
}
extern float DAT_025f5ba8;
extern float DAT_025f632c;
extern float DAT_00f539d8;
/* EXE: FUN_009c2f40:009c2f40..009c2f60. */
__declspec(noinline) float __cdecl FUN_009c2f40(void)  {
    float result=DAT_025f5ba8/DAT_025f632c;
    result=result*DAT_00f539d8;
    return result;
}
/* EXE: FUN_0050a890:0050a890..0050a8b5. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_0050a890(unsigned int handle)  {
    return lookup_handle_kind(handle,6);
}
typedef struct ThirdVehicle84D8  {
    unsigned char pad[0x53c];
    unsigned int value;
    unsigned char gap540[0x84d8-0x540];
    unsigned char flag;
}
ThirdVehicle84D8;
/* EXE: FUN_00ab1740:00ab1740..00ab1771. */
__declspec(noinline) unsigned int __fastcall FUN_00ab1740(unsigned int handle)  {
    const SubtypeHandleObject *object;
    if(!handle) object=0;
    else  {
        object=(const SubtypeHandleObject *)DAT_02149c64[handle&0xfff].object;
        if(!object || object->handle!=handle) object=0;
    }
    if(((const ThirdVehicle84D8 *)object)->flag!=1) return 0;
    return ((const ThirdVehicle84D8 *)object)->value;
}
typedef struct ThirdLargeC84  {
    unsigned int key;
    unsigned char tail[0xc80];
}
ThirdLargeC84;
extern ThirdLargeC84 DAT_031492b8[];
extern unsigned char DAT_03162338;
/* EXE: FUN_00b16980:00b16980..00b169aa. */
__declspec(noinline) ThirdLargeC84 * __fastcall FUN_00b16980(unsigned int dummy,unsigned int key)  {
    int index=0;
    ThirdLargeC84 *entry=DAT_031492b8;
    do  {
        if(entry->key==key) return &DAT_031492b8[index];
        ++entry;
        ++index;
    }
    while((int)entry<(int)&DAT_03162338);
    return 0;
}
typedef struct ThirdReset30  {
    unsigned int field0;
    unsigned char gap4[8];
    unsigned int fieldc;
    unsigned char gap10[4];
    unsigned int field14;
    unsigned char flags;
    unsigned char gap19[3];
    float value1c;
    unsigned int field20;
    unsigned char byte24;
    unsigned char gap25[3];
    float value28,value2c,value30;
}
ThirdReset30;
extern float DAT_00e87998;
/* EXE: FUN_0056c270:0056c270..0056c2a2. */
__declspec(noinline) void __cdecl FUN_0056c270(ThirdReset30 *source)  {
    source->value28=0.0f;
    source->value2c=0.0f;
    source->value30=1.0f;
    source->field0=0;
    source->fieldc=0;
    source->value1c=DAT_00e87998;
    source->field14=0;
    source->flags=(source->flags&0xfb)|3;
    source->field20=0;
    source->byte24=0;
}
/* EXE field offsets used in the third-level dependency bodies above. */
typedef char verify_third_ThirdValue28_value[(offsetof(ThirdValue28,value)==0x0)?1:-1];
typedef char verify_third_ThirdGlobal90_kind[(offsetof(ThirdGlobal90,kind)==0x3c)?1:-1];
typedef char verify_third_ThirdGlobal90_value[(offsetof(ThirdGlobal90,value)==0x90)?1:-1];
typedef char verify_third_ThirdValue3C_value[(offsetof(ThirdValue3C,value)==0x3c)?1:-1];
typedef char verify_third_ThirdOwner8_object[(offsetof(ThirdOwner8,object)==0x8)?1:-1];
typedef char verify_third_ThirdRootC4_owner[(offsetof(ThirdRootC4,owner)==0xc4)?1:-1];
typedef char verify_third_ThirdOuter8_object[(offsetof(ThirdOuter8,object)==0x8)?1:-1];
typedef char verify_third_ThirdValueB8_value[(offsetof(ThirdValueB8,value)==0xb8)?1:-1];
typedef char verify_third_ThirdRoot1178_object[(offsetof(ThirdRoot1178,object)==0x1178)?1:-1];
typedef char verify_third_ThirdVehicle84D8_value[(offsetof(ThirdVehicle84D8,value)==0x53c)?1:-1];
typedef char verify_third_ThirdVehicle84D8_flag[(offsetof(ThirdVehicle84D8,flag)==0x84d8)?1:-1];
typedef char verify_third_ThirdLargeC84_key[(offsetof(ThirdLargeC84,key)==0x0)?1:-1];
typedef char verify_third_ThirdReset30_field0[(offsetof(ThirdReset30,field0)==0x0)?1:-1];
typedef char verify_third_ThirdReset30_fieldc[(offsetof(ThirdReset30,fieldc)==0xc)?1:-1];
typedef char verify_third_ThirdReset30_field14[(offsetof(ThirdReset30,field14)==0x14)?1:-1];
typedef char verify_third_ThirdReset30_flags[(offsetof(ThirdReset30,flags)==0x18)?1:-1];
typedef char verify_third_ThirdReset30_value1c[(offsetof(ThirdReset30,value1c)==0x1c)?1:-1];
typedef char verify_third_ThirdReset30_field20[(offsetof(ThirdReset30,field20)==0x20)?1:-1];
typedef char verify_third_ThirdReset30_byte24[(offsetof(ThirdReset30,byte24)==0x24)?1:-1];
typedef char verify_third_ThirdReset30_value28[(offsetof(ThirdReset30,value28)==0x28)?1:-1];
typedef char verify_third_ThirdReset30_value2c[(offsetof(ThirdReset30,value2c)==0x2c)?1:-1];
typedef char verify_third_ThirdReset30_value30[(offsetof(ThirdReset30,value30)==0x30)?1:-1];
typedef char verify_third_ThirdValue28_stride[(sizeof(ThirdValue28)==0x28)?1:-1];
typedef char verify_third_ThirdLargeC84_stride[(sizeof(ThirdLargeC84)==0xc84)?1:-1];
typedef struct ThirdId2  {
    unsigned short unknown0,id;
}
ThirdId2;
typedef struct ThirdRoot1171  {
    unsigned char pad[0x4c];
    unsigned int kind;
    unsigned char gap50[0x80-0x50];
    unsigned char flags80;
    unsigned char gap81[0xb0-0x81];
    const ThirdId2 *object;
    unsigned char gapb4[0x3cc-0xb4];
    unsigned char subtype;
    unsigned char gap3cd[0x1171-0x3cd];
    unsigned char flags1171;
}
ThirdRoot1171;
static __forceinline unsigned short third_optional_id(const ThirdId2 *object)  {
    if(!object) return 0xffff;
    return object->id;
}
/* EXE: FUN_00828a00:00828a00..00828a51. */
__declspec(noinline) unsigned char __cdecl FUN_00828a00(const ThirdRoot1171 *source)  {
    if(!source || source->kind!=1 || source->subtype!=2 || !(source->flags1171&4) || (source->flags80&0x80)) return 0;
    return third_optional_id(source->object)==0xffff;
}
/* EXE: member offsets used by the complete recovered bodies above. */
typedef char verify_recent_ThirdId2_id[(offsetof(ThirdId2,id)==0x2)?1:-1];
typedef char verify_recent_ThirdRoot1171_kind[(offsetof(ThirdRoot1171,kind)==0x4c)?1:-1];
typedef char verify_recent_ThirdRoot1171_flags80[(offsetof(ThirdRoot1171,flags80)==0x80)?1:-1];
typedef char verify_recent_ThirdRoot1171_object[(offsetof(ThirdRoot1171,object)==0xb0)?1:-1];
typedef char verify_recent_ThirdRoot1171_subtype[(offsetof(ThirdRoot1171,subtype)==0x3cc)?1:-1];
typedef char verify_recent_ThirdRoot1171_flags1171[(offsetof(ThirdRoot1171,flags1171)==0x1171)?1:-1];
typedef struct FourthPair {
    int first;
    int second;
}
FourthPair;
/* EXE: FUN_007027c0:007027c0..007027d3. */
__declspec(noinline) int __cdecl FUN_007027c0(const FourthPair *source) {
    if(source->first==-1 || source->second==-1) return 0;
    return 1;
}
typedef char verify_FourthPair_second[(offsetof(FourthPair,second)==4)?1:-1];
typedef struct ThirdBlend19C {
    unsigned char pad[0x1c];
    float value1c;
    unsigned char gap20[0xa8-0x20];
    float rateA8;
    unsigned char gapAC[0xc4-0xac];
    float zeroC4;
    unsigned char gapC8[0x196-0xc8];
    unsigned short flags;
    unsigned char tail[4];
}
ThirdBlend19C;
extern ThirdBlend19C DAT_00eeb8f8[];
/* EXE: FUN_0047ced0:0047ced0..0047cf29. */
__declspec(noinline) void __cdecl FUN_0047ced0(int index,int duration,float value) {
    ThirdBlend19C *entry=&DAT_00eeb8f8[index];
    unsigned int flags=entry->flags;
    if(flags&0x100) return;
    flags=(flags&0xff7f)|0x100;
    entry->value1c=value;
    entry->flags=(unsigned short)flags;
    entry->zeroC4=0.0f;
    entry->rateA8=(1.0f-value)/(duration/32);
}
typedef char verify_ThirdBlend19C_value1c[(offsetof(ThirdBlend19C,value1c)==0x1c)?1:-1];
typedef char verify_ThirdBlend19C_rateA8[(offsetof(ThirdBlend19C,rateA8)==0xa8)?1:-1];
typedef char verify_ThirdBlend19C_zeroC4[(offsetof(ThirdBlend19C,zeroC4)==0xc4)?1:-1];
typedef char verify_ThirdBlend19C_flags[(offsetof(ThirdBlend19C,flags)==0x196)?1:-1];
typedef char verify_ThirdBlend19C_stride[(sizeof(ThirdBlend19C)==0x19c)?1:-1];
typedef struct FourthHandleNode {
    struct FourthHandleNode *next, *previous;
    unsigned int index, payload;
}
FourthHandleNode;
typedef struct FourthNodeStride10 {
    FourthHandleNode *node;
    unsigned char pad[12];
}
FourthNodeStride10;
typedef struct FourthTag1B0 {
    unsigned char pad[0x1b0];
    unsigned char tag;
}
FourthTag1B0;
typedef struct FourthTagRoot408 {
    unsigned char pad[0x408];
    const FourthTag1B0 *object;
}
FourthTagRoot408;
extern FourthHandleNode *DAT_02149c44;
extern unsigned short DAT_02149c54;
extern FourthNodeStride10 DAT_02149c58[];
extern FourthNodeStride10 DAT_02149c5c[];
static __forceinline unsigned char fourth_optional_tag(const FourthTagRoot408 *root) {
    if(!root) return 0;
    return root->object->tag;
}
/* EXE: FUN_00924db0:00924db0..00924e53. */
__declspec(noinline) unsigned int __cdecl FUN_00924db0(unsigned int payload) {
    FourthHandleNode *node=DAT_02149c44;
    unsigned int index,tag,result;
    unsigned short serial;
    if(node==(FourthHandleNode *)&DAT_02149c44) return 0;
    index=node->index;
    tag=fourth_optional_tag((const FourthTagRoot408 *)DAT_02528c14);
    serial=DAT_02149c54;
    result=(((unsigned int)serial<<4)|(tag&15))<<12;
    result|=index&0xfff;
    ++DAT_02149c54;
    if(!DAT_02149c54) DAT_02149c54=1;
    node->payload=payload;
    DAT_02149c5c[index].node->next=DAT_02149c58[index].node;
    DAT_02149c58[index].node->previous=DAT_02149c5c[index].node;
    DAT_02149c58[index].node=0;
    DAT_02149c5c[index].node=0;
    return result;
}
typedef char verify_FourthHandleNode_next[(offsetof(FourthHandleNode,next)==0x0)?1:-1];
typedef char verify_FourthHandleNode_previous[(offsetof(FourthHandleNode,previous)==0x4)?1:-1];
typedef char verify_FourthHandleNode_index[(offsetof(FourthHandleNode,index)==0x8)?1:-1];
typedef char verify_FourthHandleNode_payload[(offsetof(FourthHandleNode,payload)==0xc)?1:-1];
typedef char verify_FourthTag1B0_tag[(offsetof(FourthTag1B0,tag)==0x1b0)?1:-1];
typedef char verify_FourthTagRoot408_object[(offsetof(FourthTagRoot408,object)==0x408)?1:-1];
typedef char verify_FourthNodeStride10_stride[(sizeof(FourthNodeStride10)==16)?1:-1];
typedef struct ThirdCode2E {
    unsigned char pad[0x2e];
    unsigned short code;
}
ThirdCode2E;
typedef struct ThirdCodeFallback10 {
    unsigned char pad[0x10];
    const ThirdCode2E *descriptor;
}
ThirdCodeFallback10;
typedef struct ThirdCodeObject {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap48[4];
    unsigned int kind;
    unsigned char gap50[0x554-0x50];
    const ThirdCode2E *descriptor;
    unsigned char gap558[0x84d8-0x558];
    unsigned char flag84d8;
}
ThirdCodeObject;
typedef struct ThirdCodeRootD74 {
    unsigned char pad[0x4c];
    unsigned int kind;
    unsigned char gap50[0x3cc-0x50];
    unsigned char subtype;
    unsigned char gap3cd[0x570-0x3cd];
    const ThirdCodeFallback10 *fallback;
    unsigned char gap574[0xd74-0x574];
    unsigned int handle;
}
ThirdCodeRootD74;
/* EXE: FUN_0094c130:0094c130..0094c19f. */
__declspec(noinline) unsigned int __cdecl FUN_0094c130(const ThirdCodeRootD74 *source) {
    const ThirdCodeObject *object;
    unsigned int handle;
    if(!source || source->kind!=1 || source->subtype!=1) return 0x90044;
    handle=source->handle;
    if(handle) {
        object=(const ThirdCodeObject *)DAT_02149c64[handle&0xfff].object;
        if(object && object->handle==handle && object->kind==5) {
            if(object->flag84d8!=1) return 0x90044;
            return ((unsigned int)object->descriptor->code<<16)|0x45;
        }
    }
    return ((unsigned int)source->fallback->descriptor->code<<16)|0x44;
}
typedef char verify_ThirdCode2E_code[(offsetof(ThirdCode2E,code)==0x2e)?1:-1];
typedef char verify_ThirdCodeFallback10_descriptor[(offsetof(ThirdCodeFallback10,descriptor)==0x10)?1:-1];
typedef char verify_ThirdCodeObject_handle[(offsetof(ThirdCodeObject,handle)==0x44)?1:-1];
typedef char verify_ThirdCodeObject_kind[(offsetof(ThirdCodeObject,kind)==0x4c)?1:-1];
typedef char verify_ThirdCodeObject_descriptor[(offsetof(ThirdCodeObject,descriptor)==0x554)?1:-1];
typedef char verify_ThirdCodeObject_flag84d8[(offsetof(ThirdCodeObject,flag84d8)==0x84d8)?1:-1];
typedef char verify_ThirdCodeRootD74_kind[(offsetof(ThirdCodeRootD74,kind)==0x4c)?1:-1];
typedef char verify_ThirdCodeRootD74_subtype[(offsetof(ThirdCodeRootD74,subtype)==0x3cc)?1:-1];
typedef char verify_ThirdCodeRootD74_fallback[(offsetof(ThirdCodeRootD74,fallback)==0x570)?1:-1];
typedef char verify_ThirdCodeRootD74_handle[(offsetof(ThirdCodeRootD74,handle)==0xd74)?1:-1];
typedef struct OwnerSlotA8 {
    unsigned int handle;
    unsigned char tail[0xa4];
}
OwnerSlotA8;
typedef struct OwnerSlotList {
    unsigned char pad[0x34c];
    OwnerSlotA8 entries[8];
}
OwnerSlotList;
typedef struct OwnerSlotObject {
    unsigned char pad[0x10e0];
    OwnerSlotList *list;
}
OwnerSlotObject;
static __forceinline OwnerSlotList *owner_slot_list(unsigned int handle) {
    if(handle) {
        const SubtypeHandleObject *object=(const SubtypeHandleObject *)DAT_02149c64[handle&0xfff].object;
        if(object && object->handle==handle && object->kind==1) return ((const OwnerSlotObject *)object)->list;
    }
    return 0;
}
static __forceinline int owner_slot_index(const OwnerSlotList *list,unsigned int handle) {
    int index=0;
    const OwnerSlotA8 *cursor=list->entries;
    for(;
    index<8;
    ++index,++cursor) {
        if(cursor->handle==handle) return index;
    }
    return -1;
}
/* EXE: FUN_00b07a30:00b07a30..00b07a8f. */
__declspec(noinline) OwnerSlotA8 * __cdecl FUN_00b07a30(unsigned int handle) {
    OwnerSlotList *list=owner_slot_list(handle);
    int index;
    if(!list) return 0;
    index=owner_slot_index(list,handle);
    if(index==-1) return 0;
    return &list->entries[index];
}
typedef struct OwnerCallerRoot9350 {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap48[0xd78-0x48];
    int mode;
}
OwnerCallerRoot9350;
typedef struct OwnerCallerKind9350 {
    unsigned int handle;
    int kind;
}
OwnerCallerKind9350;
static __forceinline int owner_caller_kind_9350(unsigned int handle) {
    const OwnerCallerKind9350 *slot=(const OwnerCallerKind9350 *)FUN_00b07a30(handle);
    if(!slot) return (int)slot;
    return slot->kind;
}
/* EXE: FUN_009b9350:009b9350..009b937a. */
__declspec(noinline) unsigned char __cdecl FUN_009b9350(const OwnerCallerRoot9350 *source) {
    return owner_caller_kind_9350(source->handle)==2;
}
typedef struct OwnerCallerRoot9320 {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap48[0xd78-0x48];
    int mode;
}
OwnerCallerRoot9320;
typedef struct OwnerCallerKind9320 {
    unsigned int handle;
    int kind;
}
OwnerCallerKind9320;
static __forceinline int owner_caller_kind_9320(unsigned int handle) {
    const OwnerCallerKind9320 *slot=(const OwnerCallerKind9320 *)FUN_00b07a30(handle);
    if(!slot) return (int)slot;
    return slot->kind;
}
/* EXE: FUN_009b9320:009b9320..009b934a. */
__declspec(noinline) unsigned char __cdecl FUN_009b9320(const OwnerCallerRoot9320 *source) {
    return owner_caller_kind_9320(source->handle)==1;
}
typedef struct OwnerCallerRoot9030 {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap48[0xd78-0x48];
    int mode;
}
OwnerCallerRoot9030;
typedef struct OwnerCallerKind9030 {
    unsigned int handle;
    int kind;
}
OwnerCallerKind9030;
/* EXE: FUN_009b9030:009b9030..009b9061. */
__declspec(noinline) int __cdecl FUN_009b9030(const OwnerCallerRoot9030 *source) {
    const OwnerCallerKind9030 *slot;
    if(!source->handle) return 0;
    slot=(const OwnerCallerKind9030 *)FUN_00b07a30(source->handle);
    if(!slot || slot->kind!=3 || source->mode!=0) return 0;
    return 1;
}
typedef struct OwnerCallerRoot9070 {
    unsigned char pad[0x44];
    unsigned int handle;
    unsigned char gap48[0xd78-0x48];
    int mode;
}
OwnerCallerRoot9070;
typedef struct OwnerCallerKind9070 {
    unsigned int handle;
    int kind;
}
OwnerCallerKind9070;
/* EXE: FUN_009b9070:009b9070..009b90a1. */
__declspec(noinline) int __cdecl FUN_009b9070(const OwnerCallerRoot9070 *source) {
    const OwnerCallerKind9070 *slot;
    if(!source->handle) return 0;
    slot=(const OwnerCallerKind9070 *)FUN_00b07a30(source->handle);
    if(!slot || slot->kind!=3 || source->mode==0) return 0;
    return 1;
}
typedef char verify_OwnerSlotA8_handle[(offsetof(OwnerSlotA8,handle)==0x0)?1:-1];
typedef char verify_OwnerSlotList_entries[(offsetof(OwnerSlotList,entries)==0x34c)?1:-1];
typedef char verify_OwnerSlotObject_list[(offsetof(OwnerSlotObject,list)==0x10e0)?1:-1];
typedef char verify_OwnerCallerRoot9350_handle[(offsetof(OwnerCallerRoot9350,handle)==0x44)?1:-1];
typedef char verify_OwnerCallerRoot9350_mode[(offsetof(OwnerCallerRoot9350,mode)==0xd78)?1:-1];
typedef char verify_OwnerCallerKind9350_kind[(offsetof(OwnerCallerKind9350,kind)==0x4)?1:-1];
typedef char verify_OwnerCallerRoot9320_handle[(offsetof(OwnerCallerRoot9320,handle)==0x44)?1:-1];
typedef char verify_OwnerCallerRoot9320_mode[(offsetof(OwnerCallerRoot9320,mode)==0xd78)?1:-1];
typedef char verify_OwnerCallerKind9320_kind[(offsetof(OwnerCallerKind9320,kind)==0x4)?1:-1];
typedef char verify_OwnerCallerRoot9030_handle[(offsetof(OwnerCallerRoot9030,handle)==0x44)?1:-1];
typedef char verify_OwnerCallerRoot9030_mode[(offsetof(OwnerCallerRoot9030,mode)==0xd78)?1:-1];
typedef char verify_OwnerCallerKind9030_kind[(offsetof(OwnerCallerKind9030,kind)==0x4)?1:-1];
typedef char verify_OwnerCallerRoot9070_handle[(offsetof(OwnerCallerRoot9070,handle)==0x44)?1:-1];
typedef char verify_OwnerCallerRoot9070_mode[(offsetof(OwnerCallerRoot9070,mode)==0xd78)?1:-1];
typedef char verify_OwnerCallerKind9070_kind[(offsetof(OwnerCallerKind9070,kind)==0x4)?1:-1];
typedef char verify_OwnerSlotA8_stride[(sizeof(OwnerSlotA8)==0xa8)?1:-1];
typedef struct SixthBranchValue {
    unsigned char pad[0x48];
    unsigned int value;
}
SixthBranchValue;
typedef struct SixthBranchRoot {
    unsigned char pad[0xb4];
    const SixthBranchValue *first,*second;
    unsigned char gapbc[0x11c-0xbc];
    unsigned int flags;
}
SixthBranchRoot;
typedef char verify_sixth_branch_first[(offsetof(SixthBranchRoot,first)==0xb4)?1:-1];
typedef char verify_sixth_branch_second[(offsetof(SixthBranchRoot,second)==0xb8)?1:-1];
typedef char verify_sixth_branch_flags[(offsetof(SixthBranchRoot,flags)==0x11c)?1:-1];
typedef char verify_sixth_branch_value[(offsetof(SixthBranchValue,value)==0x48)?1:-1];
/* EXE: FUN_00a058a0:00a058a0..00a058bf. */
__declspec(noinline) unsigned int __cdecl FUN_00a058a0(const SixthBranchRoot *source) {
    if(source->flags&0x2000) return source->second->value;
    return source->first->value;
}
typedef struct SixthPoolRoot {
    unsigned char pad[0x2f8];
    unsigned int handle;
}
SixthPoolRoot;
typedef struct SixthPoolStatus {
    unsigned int first,active;
}
SixthPoolStatus;
typedef struct SixthPoolValue {
    unsigned char pad[0x10];
    int value10,value14;
}
SixthPoolValue;
typedef struct SixthPoolSlot {
    unsigned char pad[0x1c];
    unsigned int handle;
    unsigned char gap20[0x10];
    const SixthPoolStatus *status;
    const SixthPoolValue *value;
    unsigned char gap38[0x6c-0x38];
}
SixthPoolSlot;
extern SixthPoolSlot DAT_02a4e508[];
typedef char verify_sixth_pool_stride[(sizeof(SixthPoolSlot)==0x6c)?1:-1];
static __forceinline const SixthPoolSlot *sixth_pool_slot(unsigned int handle) {
    int index;
    const SixthPoolSlot *slot;
    if(!handle) return 0;
    index=handle&0xffff;
    if(index>=0x960) return 0;
    slot=(const SixthPoolSlot *)((unsigned int)DAT_02a4e508+index*0x6c);
    if(!slot || !slot->status || !slot->status->active || slot->handle!=handle) return 0;
    return slot;
}
/* EXE: FUN_00914df0:00914df0..00914e2e. */
__declspec(noinline) int __cdecl FUN_00914df0(const SixthPoolRoot *source) {
    const SixthPoolSlot *slot=sixth_pool_slot(source->handle);
    if(!slot) return -1;
    return slot->value->value14;
}
/* EXE: FUN_00914e30:00914e30..00914e6e. */
__declspec(noinline) int __cdecl FUN_00914e30(const SixthPoolRoot *source) {
    const SixthPoolSlot *slot=sixth_pool_slot(source->handle);
    if(!slot) return -1;
    return slot->value->value10;
}
typedef char verify_SixthPoolRoot_handle[(offsetof(SixthPoolRoot,handle)==0x2f8)?1:-1];
typedef char verify_SixthPoolStatus_active[(offsetof(SixthPoolStatus,active)==0x4)?1:-1];
typedef char verify_SixthPoolValue_value10[(offsetof(SixthPoolValue,value10)==0x10)?1:-1];
typedef char verify_SixthPoolValue_value14[(offsetof(SixthPoolValue,value14)==0x14)?1:-1];
typedef char verify_SixthPoolSlot_handle[(offsetof(SixthPoolSlot,handle)==0x1c)?1:-1];
typedef char verify_SixthPoolSlot_status[(offsetof(SixthPoolSlot,status)==0x30)?1:-1];
typedef char verify_SixthPoolSlot_value[(offsetof(SixthPoolSlot,value)==0x34)?1:-1];
/* EXE: FUN_009c19e0:009c19e0..009c1a2b. */
__declspec(noinline) unsigned char __cdecl FUN_009c19e0(int value) {
    switch(value) {
        case 0x8d:
        case 0x203:
        case 0x204:
        case 0x205:
        case 0x207:
        case 0x208:
        case 0x209:
        case 0x20c:
        case 0x20d:
        case 0x20e:
        case 0x20f:
        case 0x211:
        case 0x218:
        case 0x219:
        case 0x21a:
        case 0x21b:
        return 1;
        default: return 0;
    }
}
typedef struct BroadPoolNode {
    unsigned char pad[0x1c];
    struct BroadPoolNode *next,*previous;
    unsigned char gap24[0xc];
    unsigned char flags;
    unsigned char gap31[3];
}
BroadPoolNode;
extern unsigned char DAT_02e400d0;
extern BroadPoolNode *DAT_02203ab8;
static __forceinline void broad_pool_unlink(BroadPoolNode **head,BroadPoolNode *node) {
    if(*head==node) {
        if(node->next==node) {
            node->next=0;
            node->previous=0;
            *head=0;
            return;
        }
        *head=node->next;
    }
    if(node->previous) node->previous->next=node->next;
    if(node->next) node->next->previous=node->previous;
    node->next=0;
    node->previous=0;
}
/* EXE: FUN_00a18460:00a18460..00a184ff. */
__declspec(noinline) void __cdecl FUN_00a18460(BroadPoolNode *node,BroadPoolNode **head) {
    int offset=(int)((unsigned int)node-(unsigned int)&DAT_02e400d0);
    BroadPoolNode *free_head;
    if(offset<0 || (unsigned int)offset>=0x6800 || (unsigned int)offset%0x34!=0 || !(node->flags&0x20)) return;
    broad_pool_unlink(head,node);
    free_head=DAT_02203ab8;
    if(!free_head) {
        node->flags&=0xdf;
        node->next=node;
        node->previous=node;
        DAT_02203ab8=node;
        return;
    }
    node->previous=free_head->previous;
    node->next=free_head;
    free_head->previous->next=node;
    free_head->previous=node;
    node->flags&=0xdf;
}
typedef char verify_broad_pool_next[(offsetof(BroadPoolNode,next)==0x1c)?1:-1];
typedef char verify_broad_pool_previous[(offsetof(BroadPoolNode,previous)==0x20)?1:-1];
typedef char verify_broad_pool_flags[(offsetof(BroadPoolNode,flags)==0x30)?1:-1];
typedef char verify_broad_pool_stride[(sizeof(BroadPoolNode)==0x34)?1:-1];
extern int DAT_00e843ac;
extern int DAT_00eab788;
/* EXE: FUN_006abbd0:006abbd0..006abbf0. */
__declspec(noinline) void __cdecl FUN_006abbd0(void) {
    DAT_00eab788=DAT_00e843ac+250;
    if(DAT_00eab788>0x6b49d200) DAT_00eab788-=0x6b49d200;
}
typedef struct ThirdBroadListNode {
    struct ThirdBroadListNode *next;
    unsigned char pad4[8];
    int key;
    unsigned char pad10[0x205-0x10];
    unsigned char flags;
}
ThirdBroadListNode;
typedef struct ThirdBroadList {
    unsigned char pad[0xc4];
    ThirdBroadListNode *head;
}
ThirdBroadList;
typedef char verify_third_list_head[(offsetof(ThirdBroadList,head)==0xc4)?1:-1];
typedef char verify_third_list_key[(offsetof(ThirdBroadListNode,key)==0xc)?1:-1];
typedef char verify_third_list_flags[(offsetof(ThirdBroadListNode,flags)==0x205)?1:-1];
/* EXE: FUN_0050ab00:0050ab00..0050ab2e. */
__declspec(noinline) void __cdecl FUN_0050ab00(ThirdBroadList *root, int key) {
    ThirdBroadListNode *node;
    if(!root) return;
    node=root->head;
    if(!node) return;
    do {
        if(node->key==key || key==0) node->flags|=2;
        node=node->next;
    }
    while(node!=root->head && node);
}
typedef struct ThirdBroadMode {
    unsigned char pad[0x10bc];
    unsigned int kind;
}
ThirdBroadMode;
typedef char verify_third_mode_kind[(offsetof(ThirdBroadMode,kind)==0x10bc)?1:-1];
extern const unsigned char DAT_0215fef8[];
/* EXE: FUN_009cc540:009cc540..009cc5b7. */
__declspec(noinline) unsigned char __cdecl FUN_009cc540(const ThirdBroadMode *source, unsigned int mode, unsigned char alternate) {
    unsigned int kind=source->kind;
    unsigned int index;
    if(alternate) {
        switch(mode) {
            case 0:index=7;
            break;
            case 1:index=8;
            break;
            case 2:index=9;
            break;
            default:index=7;
            break;
        }
    }
    else {
        switch(mode) {
            case 0:index=10;
            break;
            case 1:index=11;
            break;
            case 2:index=12;
            break;
            default:index=7;
            break;
        }
    }
    if(kind>3 || index>20) return DAT_0215fef8[0];
    return DAT_0215fef8[kind*48+index];
}

typedef struct ThirdMediumBlock {
    unsigned int words[15];
}
ThirdMediumBlock;
typedef struct ThirdMediumCopy {
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    unsigned int field4;
    unsigned int field5;
    unsigned int field6;
    unsigned int field7;
    unsigned int field8;
    unsigned int field9;
    unsigned int field10;
    unsigned int field11;
    unsigned int field12;
    unsigned int field13;
    unsigned int field14;
    unsigned int field15;
    unsigned int field16;
    unsigned char flag;
    unsigned char padding[3];
    ThirdMediumBlock block;
    unsigned int after0,after1;
    float x,y,z;
    unsigned int tail0,tail1,tail2;
    unsigned short short_flag;
    unsigned char byte_flag;
}
ThirdMediumCopy;
typedef char verify_third_copy_flag[(offsetof(ThirdMediumCopy,flag)==0x44)?1:-1];
typedef char verify_third_copy_block[(offsetof(ThirdMediumCopy,block)==0x48)?1:-1];
typedef char verify_third_copy_after0[(offsetof(ThirdMediumCopy,after0)==0x84)?1:-1];
typedef char verify_third_copy_x[(offsetof(ThirdMediumCopy,x)==0x8c)?1:-1];
typedef char verify_third_copy_short_flag[(offsetof(ThirdMediumCopy,short_flag)==0xa4)?1:-1];
typedef char verify_third_copy_byte_flag[(offsetof(ThirdMediumCopy,byte_flag)==0xa6)?1:-1];
/* EXE: FUN_00b0a670:00b0a670..00b0a765. */
__declspec(noinline) void __cdecl FUN_00b0a670(const ThirdMediumCopy *source, ThirdMediumCopy *dest) {
    dest->field0=source->field0;
    dest->field1=source->field1;
    dest->field2=source->field2;
    dest->field3=source->field3;
    dest->field4=source->field4;
    dest->field5=source->field5;
    dest->field6=source->field6;
    dest->field7=source->field7;
    dest->field8=source->field8;
    dest->field9=source->field9;
    dest->field10=source->field10;
    dest->field11=source->field11;
    dest->field12=source->field12;
    dest->field13=source->field13;
    dest->field14=source->field14;
    dest->field15=source->field15;
    dest->field16=source->field16;
    dest->flag=source->flag;
    dest->block=source->block;
    dest->after0=source->after0;
    dest->after1=source->after1;
    dest->x=source->x;
    dest->y=source->y;
    dest->z=source->z;
    dest->tail0=source->tail0;
    dest->tail1=source->tail1;
    dest->tail2=source->tail2;
    dest->short_flag=source->short_flag;
    dest->byte_flag=source->byte_flag;
}
typedef struct ThirdBroadCopy {
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    float f5;
    float f6;
    float f7;
    float f8;
    float f9;
    unsigned int u0;
    unsigned int u1;
    unsigned int u2;
    unsigned int u3;
    unsigned int u4;
}
ThirdBroadCopy;
typedef char verify_third_copy_size[(sizeof(ThirdBroadCopy)==0x3c)?1:-1];
/* EXE: FUN_009b0860:009b0860..009b08b8. */
__declspec(noinline) void __cdecl FUN_009b0860(const ThirdBroadCopy *source, ThirdBroadCopy *dest) {
    dest->f0=source->f0;
    dest->f1=source->f1;
    dest->f2=source->f2;
    dest->f3=source->f3;
    dest->f4=source->f4;
    dest->f5=source->f5;
    dest->f6=source->f6;
    dest->f7=source->f7;
    dest->f8=source->f8;
    dest->f9=source->f9;
    dest->u0=source->u0;
    dest->u1=source->u1;
    dest->u2=source->u2;
    dest->u3=source->u3;
    dest->u4=source->u4;
}
typedef char verify_third_broad_copy_f0[(offsetof(ThirdBroadCopy,f0)==0x0)?1:-1];
typedef char verify_third_broad_copy_f1[(offsetof(ThirdBroadCopy,f1)==0x4)?1:-1];
typedef char verify_third_broad_copy_f2[(offsetof(ThirdBroadCopy,f2)==0x8)?1:-1];
typedef char verify_third_broad_copy_f3[(offsetof(ThirdBroadCopy,f3)==0xc)?1:-1];
typedef char verify_third_broad_copy_f4[(offsetof(ThirdBroadCopy,f4)==0x10)?1:-1];
typedef char verify_third_broad_copy_f5[(offsetof(ThirdBroadCopy,f5)==0x14)?1:-1];
typedef char verify_third_broad_copy_f6[(offsetof(ThirdBroadCopy,f6)==0x18)?1:-1];
typedef char verify_third_broad_copy_f7[(offsetof(ThirdBroadCopy,f7)==0x1c)?1:-1];
typedef char verify_third_broad_copy_f8[(offsetof(ThirdBroadCopy,f8)==0x20)?1:-1];
typedef char verify_third_broad_copy_f9[(offsetof(ThirdBroadCopy,f9)==0x24)?1:-1];
typedef char verify_third_broad_copy_u0[(offsetof(ThirdBroadCopy,u0)==0x28)?1:-1];
typedef char verify_third_broad_copy_u1[(offsetof(ThirdBroadCopy,u1)==0x2c)?1:-1];
typedef char verify_third_broad_copy_u2[(offsetof(ThirdBroadCopy,u2)==0x30)?1:-1];
typedef char verify_third_broad_copy_u3[(offsetof(ThirdBroadCopy,u3)==0x34)?1:-1];
typedef char verify_third_broad_copy_u4[(offsetof(ThirdBroadCopy,u4)==0x38)?1:-1];
typedef char verify_third_medium_copy_field0[(offsetof(ThirdMediumCopy,field0)==0x0)?1:-1];
typedef char verify_third_medium_copy_field1[(offsetof(ThirdMediumCopy,field1)==0x4)?1:-1];
typedef char verify_third_medium_copy_field2[(offsetof(ThirdMediumCopy,field2)==0x8)?1:-1];
typedef char verify_third_medium_copy_field3[(offsetof(ThirdMediumCopy,field3)==0xc)?1:-1];
typedef char verify_third_medium_copy_field4[(offsetof(ThirdMediumCopy,field4)==0x10)?1:-1];
typedef char verify_third_medium_copy_field5[(offsetof(ThirdMediumCopy,field5)==0x14)?1:-1];
typedef char verify_third_medium_copy_field6[(offsetof(ThirdMediumCopy,field6)==0x18)?1:-1];
typedef char verify_third_medium_copy_field7[(offsetof(ThirdMediumCopy,field7)==0x1c)?1:-1];
typedef char verify_third_medium_copy_field8[(offsetof(ThirdMediumCopy,field8)==0x20)?1:-1];
typedef char verify_third_medium_copy_field9[(offsetof(ThirdMediumCopy,field9)==0x24)?1:-1];
typedef char verify_third_medium_copy_field10[(offsetof(ThirdMediumCopy,field10)==0x28)?1:-1];
typedef char verify_third_medium_copy_field11[(offsetof(ThirdMediumCopy,field11)==0x2c)?1:-1];
typedef char verify_third_medium_copy_field12[(offsetof(ThirdMediumCopy,field12)==0x30)?1:-1];
typedef char verify_third_medium_copy_field13[(offsetof(ThirdMediumCopy,field13)==0x34)?1:-1];
typedef char verify_third_medium_copy_field14[(offsetof(ThirdMediumCopy,field14)==0x38)?1:-1];
typedef char verify_third_medium_copy_field15[(offsetof(ThirdMediumCopy,field15)==0x3c)?1:-1];
typedef char verify_third_medium_copy_field16[(offsetof(ThirdMediumCopy,field16)==0x40)?1:-1];
typedef char verify_third_medium_copy_after1[(offsetof(ThirdMediumCopy,after1)==0x88)?1:-1];
typedef char verify_third_medium_copy_y[(offsetof(ThirdMediumCopy,y)==0x90)?1:-1];
typedef char verify_third_medium_copy_z[(offsetof(ThirdMediumCopy,z)==0x94)?1:-1];
typedef char verify_third_medium_copy_tail0[(offsetof(ThirdMediumCopy,tail0)==0x98)?1:-1];
typedef char verify_third_medium_copy_tail1[(offsetof(ThirdMediumCopy,tail1)==0x9c)?1:-1];
typedef char verify_third_medium_copy_tail2[(offsetof(ThirdMediumCopy,tail2)==0xa0)?1:-1];

extern const unsigned char DAT_00ee1835;
extern const unsigned char DAT_00ee1836;
extern const unsigned char DAT_00ee1834;
extern const unsigned char DAT_00ee1833;
extern const unsigned char DAT_00ee1832;
extern const unsigned char DAT_00ee1831;
extern const unsigned char DAT_00ee1830;
extern const unsigned char DAT_00ee182f;
extern const unsigned char DAT_00ee182e;
extern const unsigned char DAT_00ee182d;
extern const unsigned char DAT_00ee182c;
extern const unsigned char DAT_00ee182b;
extern const unsigned char DAT_00ee182a;
extern const unsigned char DAT_00ee1829;
extern const unsigned char DAT_00ee1828;
extern const unsigned char DAT_00ee1303;
extern const unsigned char DAT_00ee1302;
/* EXE: FUN_00427300:00427300..004273d6. */
__declspec(noinline) int __cdecl FUN_00427300(unsigned char value) { if(value==DAT_00ee1835) return 0x375;
if(value==DAT_00ee1836 || value==DAT_00ee1834) return 0x377;
if(value==DAT_00ee1833) return 0x37c;
if(value==DAT_00ee1832) return 0x37d;
if(value==DAT_00ee1831) return -1;
if(value==DAT_00ee1830) return -1;
if(value==DAT_00ee182f) return -1;
if(value==DAT_00ee182e) return -1;
if(value==DAT_00ee182d) return -1;
if(value==DAT_00ee182c) return -1;
if(value==DAT_00ee182b) return 0x3a4;
if(value==DAT_00ee182a) return 0x3a6;
if(value==DAT_00ee1829) return 0x3a8;
if(value==DAT_00ee1828) return 0x3aa;
if(value==DAT_00ee1303) return 0x3ae;
if(value==DAT_00ee1302) return 0x3ac;
return -1; }

typedef struct FourthKind4Value {unsigned char pad[0x9c];int kind;} FourthKind4Value;
typedef struct FourthKind4Root {unsigned char pad[0x84e4];const FourthKind4Value *link;} FourthKind4Root;
typedef char verify_FourthKind4_link[(offsetof(FourthKind4Root,link)==0x84e4)?1:-1];
typedef char verify_FourthKind4_kind[(offsetof(FourthKind4Value,kind)==0x9c)?1:-1];
/* EXE: FUN_00ab51d0:00ab51d0..00ab51eb. */
__declspec(noinline) unsigned char __cdecl FUN_00ab51d0(const FourthKind4Root *source) { if(!source) return 0;
return (int)(source->link->kind==4); }

typedef struct FourthKind2Value {unsigned char pad[0x9c];int kind;} FourthKind2Value;
typedef struct FourthKind2Root {unsigned char pad[0x84e4];const FourthKind2Value *link;} FourthKind2Root;
typedef char verify_FourthKind2_link[(offsetof(FourthKind2Root,link)==0x84e4)?1:-1];
typedef char verify_FourthKind2_kind[(offsetof(FourthKind2Value,kind)==0x9c)?1:-1];
/* EXE: FUN_00ab5140:00ab5140..00ab515b. */
__declspec(noinline) unsigned char __cdecl FUN_00ab5140(const FourthKind2Root *source) { if(!source) return 0;
return (int)(source->link->kind==2); }

typedef struct FourthPresence {unsigned char pad[0x9060];int value;} FourthPresence;
typedef char verify_fourth_presence_value[(offsetof(FourthPresence,value)==0x9060)?1:-1];
/* EXE: FUN_00ab6a50:00ab6a50..00ab6a64. */
__declspec(noinline) unsigned char __cdecl FUN_00ab6a50(const FourthPresence *source) { if(!source) return 0;
return (int)(source->value!=0); }

typedef struct FourthActionCode {unsigned char pad[0x1130];unsigned int code;} FourthActionCode;
typedef char verify_fourth_action_code[(offsetof(FourthActionCode,code)==0x1130)?1:-1];
/* EXE: FUN_007357f0:007357f0..00735809. */
__declspec(noinline) unsigned char __cdecl FUN_007357f0(const FourthActionCode *source) { unsigned int code=source->code;
if(code==0x1b9 || code==0x285) return 1;
return 0; }

typedef struct FourthLinkedValue {unsigned char pad[0x164];unsigned int code;} FourthLinkedValue;
typedef struct FourthLinkedCode {unsigned char pad[0x5e0];const FourthLinkedValue *link;} FourthLinkedCode;
typedef char verify_fourth_linked_code[(offsetof(FourthLinkedValue,code)==0x164)?1:-1];
typedef char verify_fourth_linked_link[(offsetof(FourthLinkedCode,link)==0x5e0)?1:-1];
/* EXE: FUN_007357d0:007357d0..007357ef. */
__declspec(noinline) unsigned char __cdecl FUN_007357d0(const FourthLinkedCode *source) { unsigned int code=source->link->code;
if(code==0xdc || code==0x387) return 1;
return 0; }

/* EXE: FUN_00a009c0:00a009c0..00a009e5. */
__declspec(noinline) const SubtypeHandleObject * __fastcall FUN_00a009c0(unsigned int handle) { const SubtypeHandleObject *object;
if(!handle) return 0;
object=(const SubtypeHandleObject *)DAT_02149c64[handle&0xfff].object;
if(!object || object->handle!=handle || object->kind!=3) return 0;
return object; }

typedef struct FourthLargeSlot {unsigned int value;unsigned char pad[0x3ac-4];} FourthLargeSlot;
typedef char verify_fourth_large_stride[(sizeof(FourthLargeSlot)==0x3ac)?1:-1];
extern int DAT_02528400;
extern const FourthLargeSlot DAT_029dc310[];
/* EXE: FUN_00787360:00787360..0078737b. */
__declspec(noinline) unsigned int __cdecl FUN_00787360(int index) { if(index<0 || index>=DAT_02528400) return 0;
return DAT_029dc310[index].value; }

typedef struct FourthCursor {unsigned char pad0[0x24];unsigned char current;unsigned char pad25[0x3c-0x25];unsigned char count;} FourthCursor;
typedef char verify_fourth_cursor_current[(offsetof(FourthCursor,current)==0x24)?1:-1];
typedef char verify_fourth_cursor_count[(offsetof(FourthCursor,count)==0x3c)?1:-1];
/* EXE: FUN_00a1f610:00a1f610..00a1f62a. */
__declspec(noinline) const void * __fastcall FUN_00a1f610(const FourthCursor *source) { if(source->count==0) return 0;
if(source->current>=source->count) return 0;
return (const unsigned char *)source+source->current*12; }

typedef struct FourthResumeTime {unsigned int deadline,remaining;} FourthResumeTime;
typedef char verify_fourth_resume_remaining[(offsetof(FourthResumeTime,remaining)==4)?1:-1];
/* EXE: FUN_0087f6c0:0087f6c0..0087f6f0. */
__declspec(noinline) void __cdecl FUN_0087f6c0(FourthResumeTime *source) { unsigned int now;
if(DAT_02528c14) now=((const DeepGlobal8 *)DAT_02528c14)->value;
else now=DAT_0212b160;
source->deadline=source->remaining+now;
source->remaining=0; }

typedef struct FourthLookupKind {unsigned char pad[0xd8];unsigned char kind;} FourthLookupKind;
typedef char verify_fourth_lookup_kind[(offsetof(FourthLookupKind,kind)==0xd8)?1:-1];
/* EXE: FUN_006fd1b0:006fd1b0..006fd1d3. */
__declspec(noinline) int __cdecl FUN_006fd1b0(unsigned int index) { const FourthLookupKind *value=(const FourthLookupKind *)DAT_028f25c0[index].value;
unsigned int kind=value->kind;
if(kind==6 || kind==7) return 0;
return 1; }

typedef struct RequestedFlagValue {unsigned char unknown_0[0x130]; unsigned char flags;} RequestedFlagValue;
typedef struct RequestedFlagRoot {unsigned char unknown_0[0x570]; const RequestedFlagValue *nested;} RequestedFlagRoot;
typedef char verify_requested_nested[(offsetof(RequestedFlagRoot,nested)==0x570)?1:-1];
typedef char verify_requested_flags[(offsetof(RequestedFlagValue,flags)==0x130)?1:-1];
/* EXE: FUN_009632e0:009632e0..009632ff. */
__declspec(noinline) unsigned char __cdecl FUN_009632e0(const RequestedFlagRoot *source) { if(source && source->nested) return ~(source->nested->flags>>1)&1;
return 0; }

#include "player_movement_readable_input_context.h"
extern float DAT_00f9ea20;
extern float DAT_00f9ea28;
extern float DAT_00f9ea1c;
extern float DAT_00f9ea24;
extern const double DAT_00e5bf50;
extern const double DAT_00dd50e8;
/* EXE: FUN_004f78c0:004f78c0..004f79aa. */
__declspec(noinline) void __cdecl FUN_004f78c0(void) { float forward=FUN_004ffe60(10);
float strafe=-FUN_004ffe60(3);
if(forward==0.0f && strafe==0.0f) {
    forward=(float)(DAT_00f9ea20*DAT_00e5bf70);
    strafe=(float)(DAT_00e5bf70*DAT_00f9ea1c);
    if(DAT_00e5bf50<forward && forward<DAT_00dd50e8) forward=0.0f;
    if(DAT_00e5bf50<strafe && strafe<DAT_00dd50e8) strafe=0.0f;
}
DAT_00f9ea20=forward;
DAT_00f9ea28=forward;
DAT_00f9ea1c=strafe;
DAT_00f9ea24=strafe; }

typedef struct RequestedCameraInputRoot {
    unsigned char unknown_0[0x344];
    unsigned char field_344;
    unsigned char unknown_345[0x1163-0x345];
    unsigned char flags_1163;
    unsigned char unknown_1164[0x18e8-0x1164];
    unsigned char flags_18e8;
} RequestedCameraInputRoot;
typedef char verify_requested_camera_344[(offsetof(RequestedCameraInputRoot,field_344)==0x344)?1:-1];
typedef char verify_requested_camera_1163[(offsetof(RequestedCameraInputRoot,flags_1163)==0x1163)?1:-1];
typedef char verify_requested_camera_18e8[(offsetof(RequestedCameraInputRoot,flags_18e8)==0x18e8)?1:-1];
extern unsigned int DAT_025f5be8;
extern int DAT_025f5ae8;
extern unsigned int DAT_025f5d40;
extern unsigned int DAT_025f5d44;
extern unsigned int DAT_025f5d48;
extern void __cdecl FUN_0049d300(float value);
extern void __cdecl FUN_0049d320(float value);
extern unsigned char __cdecl FUN_00bf0e00(float x, float y, float z);
/* EXE: FUN_004f7af0:004f7af0..004f7bbf. */
__declspec(noinline) void __cdecl FUN_004f7af0(void) { const RequestedCameraInputRoot *source=(const RequestedCameraInputRoot *)DAT_021703d4;
if(source->field_344==0 && !(source->flags_1163&0x20) && !(source->flags_18e8&2) && !(DAT_025f5be8&2)) {
    float first=FUN_004ffe60(0);
    float second=FUN_004ffe60(2);
    if(DAT_025f5ae8==0) {
        FUN_0049d300(-first);
        FUN_0049d320(second);
        if((source->flags_1163&0x10) && !FUN_00bf0e00(first,0.0f,1.0f)) {
            DAT_025f5d40=DAT_0252a6d0;
            DAT_025f5d44=DAT_0252a6d4;
            DAT_025f5d48=DAT_0252a6d8;
        }
    }
} }

typedef struct InventorySelectorValue { unsigned char gap00[0x3c];int selector; } InventorySelectorValue;
typedef struct InventorySelectorLink { unsigned char gap00[8];InventorySelectorValue *value; } InventorySelectorLink;
typedef struct InventorySelectorNode { unsigned char gap00[0xb4];struct InventorySelectorNode *next;unsigned char gapb8[0xc4-0xb8];InventorySelectorLink *link; } InventorySelectorNode;
/* EXE: FUN_0055adf0:0055adf0..0055ae22. */
__declspec(noinline) InventorySelectorNode * __cdecl FUN_0055adf0(InventorySelectorNode **root,int selector) {
    InventorySelectorNode *node=*root;
    for(;;) {
        if(!node)return 0;
        if(node->link && node->link->value->selector==selector)return node;
        node=node->next;
        if(node==*root)return 0;
    }
}

typedef struct LeafInventoryUseTrial { unsigned char prefix[8];const unsigned char *item;unsigned char gap[4];int first,second,third,fourth; } LeafInventoryUseTrial;

/* EXE: FUN_00b72ca0:00b72ca0..00b72cd4. */
__declspec(noinline) unsigned char __cdecl FUN_00b72ca0(const LeafInventoryUseTrial *source) {
    const unsigned char *item;
    if(source->first>0||source->second>0)return 1;
    item=source->item;
    if(item&&*(short *)(item+0xdc)==0)return 1;
    if((item[0x10]&0x20)&&(source->third>0||source->fourth>0))return 1;
    return 0;
}

typedef struct LeafAnimationSearchEntryTrial { unsigned int key;unsigned char tail[0x54]; } LeafAnimationSearchEntryTrial;
typedef struct LeafAnimationSearchTrial { unsigned char prefix[0x23c];int count;unsigned char gap[0x254-0x240];LeafAnimationSearchEntryTrial entries[1]; } LeafAnimationSearchTrial;

/* EXE: FUN_00c229b0:00c229b0..00c229da. */
__declspec(noinline) int __cdecl FUN_00c229b0(unsigned int identifier,const LeafAnimationSearchTrial *source) {
    unsigned int key=identifier>>4;
    int count=source->count,index=0;
    const LeafAnimationSearchEntryTrial *entry;
    if(count>0) {
        entry=source->entries;
        do {
            if(entry->key==key)return index;
            ++index;
            ++entry;
        }
        while(index<count);
    }
    return -1;
}

typedef struct LeafPositionChildTrial {unsigned char prefix[0x1c];unsigned int position[3];} LeafPositionChildTrial;
typedef struct LeafPositionRootTrial {unsigned char prefix[0x1c];const LeafPositionChildTrial *child;} LeafPositionRootTrial;

/* EXE: FUN_00ce2f70:00ce2f70..00ce2f9d. */
__declspec(noinline) void __cdecl FUN_00ce2f70(float *output,const LeafPositionRootTrial *source) {
    const LeafPositionChildTrial *child;
    output[0]=0;
    output[1]=0;
    output[2]=0;
    child=source->child;
    if(!child) {
        output[0]=0;
        output[1]=0;
        output[2]=0;
        return;
    }
    ((unsigned int *)output)[0]=child->position[0];
    ((unsigned int *)output)[1]=child->position[1];
    ((unsigned int *)output)[2]=child->position[2];
}

typedef struct AttachedValueChildTrial {unsigned char prefix[0x10];unsigned int value;} AttachedValueChildTrial;
typedef struct AttachedValueLeafTrial {unsigned char prefix[0xc4];const AttachedValueChildTrial *child;} AttachedValueLeafTrial;

/* EXE: FUN_00a5b7e0:00a5b7e0..00a5b7f0. */
__declspec(noinline) unsigned int __cdecl FUN_00a5b7e0(const AttachedValueLeafTrial *source) {
    const AttachedValueChildTrial *child=source->child;
    if(child)return child->value;
    return 0;
}

typedef struct InventoryFlagChildTrial {unsigned char prefix[8];unsigned char flags;} InventoryFlagChildTrial;
typedef struct InventoryFlagLeafTrial {unsigned char prefix[0xd4];const InventoryFlagChildTrial *child;} InventoryFlagLeafTrial;

/* EXE: FUN_00b72e90:00b72e90..00b72eac. */
__declspec(noinline) int __cdecl FUN_00b72e90(const InventoryFlagLeafTrial *source) {
    if(source&&source->child&&(source->child->flags&0x10))return 1;
    return 0;
}

#ifndef MOVEMENT_INDEX_LEAF_TRIAL
#define MOVEMENT_INDEX_LEAF_TRIAL
typedef struct IndexedMovementLeafTrial {unsigned char prefix[0x36];unsigned short first,second;} IndexedMovementLeafTrial;
typedef struct IndexTableLeafTrial {unsigned char prefix[4];unsigned char *base;} IndexTableLeafTrial;
extern IndexTableLeafTrial *DAT_02225b64;
#endif

/* EXE: FUN_005c2930:005c2930..005c2953. */
__declspec(noinline) unsigned char * __cdecl FUN_005c2930(const IndexedMovementLeafTrial *source) {
    unsigned short index=source->first;
    if(index==0xffff)return 0;
    return DAT_02225b64->base+index*0x3c;
}

#ifndef MOVEMENT_INDEX_LEAF_TRIAL
#define MOVEMENT_INDEX_LEAF_TRIAL
typedef struct IndexedMovementLeafTrial {unsigned char prefix[0x36];unsigned short first,second;} IndexedMovementLeafTrial;
typedef struct IndexTableLeafTrial {unsigned char prefix[4];unsigned char *base;} IndexTableLeafTrial;
extern IndexTableLeafTrial *DAT_02225b64;
#endif

/* EXE: FUN_005c2960:005c2960..005c2983. */
__declspec(noinline) unsigned char * __cdecl FUN_005c2960(const IndexedMovementLeafTrial *source) {
    unsigned short index=source->second;
    if(index==0xffff)return 0;
    return DAT_02225b64->base+index*0x3c;
}

typedef struct MovementCompactArrayTrial {void **entries;int count;} MovementCompactArrayTrial;

/* EXE: FUN_00d53180:00d53180..00d531bf. */
__declspec(noinline) void __cdecl FUN_00d53180(MovementCompactArrayTrial *source) {
    int index=source->count;
    int next;
    while(--index>=0) {
        if(!source->entries[index]) {
            --source->count;
            next=index;
            while(next<source->count) {
                source->entries[next]=source->entries[next+1];
                ++next;
            }
        }
    }
}

typedef struct MovementSearchEntryTrial {unsigned int key;unsigned char reserved[0x54];} MovementSearchEntryTrial;
typedef struct MovementSearchRootTrial {unsigned char prefix[0x23c];int count;unsigned char gap[0x14];MovementSearchEntryTrial entries[1];} MovementSearchRootTrial;

/* EXE: FUN_00ce71b0:00ce71b0..00ce71e9. */
__declspec(noinline) MovementSearchEntryTrial * __cdecl FUN_00ce71b0(unsigned int identifier, MovementSearchRootTrial *source) {
    unsigned int key=identifier>>4;
    int count=source->count;
    int index=0;
    MovementSearchEntryTrial *entry;
    if(count>0) {
        entry=source->entries;
        do {
            if(entry->key==key) {
                if(index<0)return 0;
                return source->entries+index;
            }
            ++index;
            ++entry;
        }
        while(index<count);
    }
    return 0;
}


/* EXE: FUN_0040b790:0040b790..0040b7ae. */
__declspec(noinline) void __stdcall FUN_0040b790(float *vector, float factor) {
    vector[0] = factor * vector[0];
    vector[1] = vector[1] * factor;
    vector[2] = factor * vector[2];
}

#include <xmmintrin.h>

/* EXE: FUN_00d776d0:00d776d0..00d77716. */
__declspec(noinline) void __cdecl FUN_00d776d0(__m128 *matrix, const __m128 *scale) {
    __m128 scalar;
    scalar=*scale;
    matrix[0]=_mm_mul_ps(_mm_shuffle_ps(scalar,scalar,0),matrix[0]);
    scalar=*scale;
    matrix[1]=_mm_mul_ps(_mm_shuffle_ps(scalar,scalar,0),matrix[1]);
    scalar=*scale;
    matrix[2]=_mm_mul_ps(_mm_shuffle_ps(scalar,scalar,0),matrix[2]);
}

#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)

/* EXE: 009c6060..009c6092. Keep the byte comparison materialized before
 * the integer return branch (009c6083..009c6088). The compiler barrier is
 * a matching translation choice; original source is not established. */
static __forceinline unsigned char movement_action_kind_is_five(const PropertyMode *mode) {
    unsigned char matches;
    matches = (unsigned char)(mode->kind == 5);
    _ReadWriteBarrier();
    return matches;
}
__declspec(noinline) int __cdecl FUN_009c6060(const PropertyRoot *source) {
    const PropertyLink *link;
    const PropertyDetail *detail;
    const PropertyMode *mode;
    if (source && (link = source->link) &&
        (detail = link->detail) && (mode = detail->mode)) {
        if (movement_action_kind_is_five(mode)) return 1;
    }
    return 0;
}

/* EXE: 009b8a30..009b8a43. The compiler barrier preserves the two
 * signed comparisons; the original source's helper boundary is unknown. */
__declspec(noinline) unsigned char __cdecl FUN_009b8a30(int value) {
    if (value >= 0xa2) {
        _ReadWriteBarrier();
        if (value <= 0xa4) return 1;
    }
    return 0;
}

/* EXE: 0096dc20..0096dc6b. Preserve every signed interval test, including
 * overlapping intervals. Boundaries are a matching translation choice. */
__declspec(noinline) unsigned char __cdecl FUN_0096dc20(const ModeIndexRoot *source) {
    int value = source->index->value;
    if (value >= 0x6f) {
        _ReadWriteBarrier();
        if (value <= 0x77) return 1;
    }
    if (value >= 0xc1) {
        _ReadWriteBarrier();
        if (value <= 0xdf) return 1;
    }
    if (value >= 0x132) {
        _ReadWriteBarrier();
        if (value <= 0x139) return 1;
    }
    if (value >= 0x76) {
        _ReadWriteBarrier();
        if (value <= 0x78) return 1;
    }
    if (value >= 0x79) {
        _ReadWriteBarrier();
        if (value <= 0x7e) return 1;
    }
    return 0;
}

/* Animation flag records: native LEA index*3 and scale-four load establish
 * the 12-byte stride; only the first word is read by these functions. */
typedef struct IndexedMovementFlags {
    unsigned int flags;
    unsigned int unknown_0004;
    unsigned int unknown_0008;
} IndexedMovementFlags;
typedef char verify_indexed_flags_size[(sizeof(IndexedMovementFlags)==12)?1:-1];
extern IndexedMovementFlags DAT_00e90e48[];
extern int __cdecl FUN_0096f3a0(const ModeIndexRoot *source);

/* EXE: 0096d930..0096d950. Byte compound assignment retains native AND AL,1. */
__declspec(noinline) unsigned char __cdecl FUN_0096d930(const ModeIndexRoot *source) {
    int index = FUN_0096f3a0(source);
    unsigned char result;
    if (index == -1) return 0;
    result = (unsigned char)(DAT_00e90e48[index].flags >> 4);
    result &= 1;
    return result;
}

/* EXE: 0096d880..0096d8a0. Byte compound assignment retains native AND AL,1. */
__declspec(noinline) unsigned char __cdecl FUN_0096d880(const ModeIndexRoot *source) {
    int index = FUN_0096f3a0(source);
    unsigned char result;
    if (index == -1) return 0;
    result = (unsigned char)(DAT_00e90e48[index].flags >> 2);
    result &= 1;
    return result;
}

/* EXE: 0096d990..0096d9af. Byte compound assignment retains native AND AL,1. */
__declspec(noinline) unsigned char __cdecl FUN_0096d990(const ModeIndexRoot *source) {
    int index = FUN_0096f3a0(source);
    unsigned char result;
    if (index == -1) return 0;
    result = (unsigned char)(DAT_00e90e48[index].flags >> 1);
    result &= 1;
    return result;
}

/* EXE: 0096d900..0096d920. Same indexed record, bit ten. */
__declspec(noinline) unsigned char __cdecl FUN_0096d900(const ModeIndexRoot *source) {
    int index = FUN_0096f3a0(source);
    unsigned char result;
    if (index == -1) return 0;
    result = (unsigned char)(DAT_00e90e48[index].flags >> 10);
    result &= 1;
    return result;
}

extern IndexedMovementFlags DAT_00e8ee98[];

/* EXE: 006ef750..006ef765. Native index in EAX, mask in ECX. */
__declspec(noinline) unsigned char __cdecl FUN_006ef750(int index, unsigned int mask) {
    if (index == -1) return 0;
    if (DAT_00e90e48[index].flags & mask) return 1;
    return 0;
}

/* EXE: 006ef730..006ef745. Native index in EAX, mask in ECX. */
__declspec(noinline) unsigned char __cdecl FUN_006ef730(int index, unsigned int mask) {
    if (index == -1) return 0;
    if (DAT_00e8ee98[index].flags & mask) return 1;
    return 0;
}

typedef struct PrimaryActorPredicateView {
    unsigned char unknown_0000[0x4c];
    int field_004c;
    unsigned char unknown_0050[0x3cc-0x50];
    unsigned char field_03cc;
} PrimaryActorPredicateView;
typedef char verify_primary_kind_offset[(offsetof(PrimaryActorPredicateView,field_004c)==0x4c)?1:-1];
typedef char verify_primary_byte_offset[(offsetof(PrimaryActorPredicateView,field_03cc)==0x3cc)?1:-1];
/* EXE: 00926600..00926618. Preserve common value one and the false branch. */
__declspec(noinline) unsigned char __fastcall FUN_00926600(const PrimaryActorPredicateView *source) {
    int one = 1;
    if (!source) return 0;
    if (source->field_004c != one) return 0;
    if (source->field_03cc != one) {
        _ReadWriteBarrier();
        return 0;
    }
    return (unsigned char)one;
}

/* EXE: 0096da30..0096da72. Native flags bit seven, record code 0x552,
 * or index 0x2ed. The inline boundary is a matching C translation choice. */
static __forceinline unsigned char movement_indexed_flag_seven(unsigned int flags) {
    unsigned char result = (unsigned char)(flags >> 7);
    result &= 1;
    _ReadWriteBarrier();
    return result;
}
__declspec(noinline) int __cdecl FUN_0096da30(const ModeIndexRoot *source) {
    int index = FUN_0096f3a0(source);
    if (index == -1) goto no;
    if (movement_indexed_flag_seven(DAT_00e90e48[index].flags) ||
        DAT_00e90e44[index].value == 0x552 || index == 0x2ed) goto yes;
no:
    return 0;
yes:
    return 1;
}

typedef struct CountedMovementSlots {
    unsigned char unknown_0000[0xc4];
    int count;
    ActiveSlot34 slots[3];
} CountedMovementSlots;
typedef struct CountedMovementSlotRoot {
    unsigned char unknown_0000[0x5e0];
    const CountedMovementSlots *nested;
} CountedMovementSlotRoot;
static __forceinline unsigned char movement_indexed_flag_three(unsigned int flags) {
    unsigned char result=(unsigned char)(flags>>3);
    result &= 1;
    _ReadWriteBarrier();
    return result;
}
/* EXE: 0096d8b0..0096d8f6; complete active-slot scan. */
__declspec(noinline) unsigned char __cdecl FUN_0096d8b0(const CountedMovementSlotRoot *root) {
    const CountedMovementSlots *nested=root->nested;
    int count=nested->count;
    int index;
    for(index=0;index<count;++index) {
        int value=FUN_006efe30((const ActiveSlotRoot *)nested,index);
        if(value!=-1 && movement_indexed_flag_three(DAT_00e90e48[value].flags))return 1;
    }
    return 0;
}

#include "player_movement_readable_actor_predicate_context.h"
/* EXE: 00982380..009823c8. Complete requested movement predicate. */
__declspec(noinline) unsigned char __cdecl FUN_00982380(unsigned char *source) {
    if(source && (source[0xc4]&3))return 1;
    if(FUN_0096dcf0((const Switch5E0Root *)source))goto yes;
    if(!FUN_00981e30(source))return 0;
    if(FUN_0096dc20((const ModeIndexRoot *)source))goto yes;
    if(FUN_0096dac0(source,0))goto yes;
    return 0;
yes:
    return 1;
}


typedef struct MovementFloatLimitView {
    unsigned char unknown_0000[0xd34];
    int enabled;
    unsigned char unknown_0d38[4];
    float value;
} MovementFloatLimitView;
extern const float DAT_00dd09c0;
/* EXE: 009899c0..009899e5. Local profile reproduces x87 FCOMP and
 * native unordered comparison branch; original source/profile is unknown. */
#pragma float_control(precise,off,push)
__declspec(noinline) unsigned char __cdecl FUN_009899c0(const MovementFloatLimitView *source) {
    if(!source)return 0;
    if(source->enabled && source->value > DAT_00dd09c0)return 0;
    return 1;
}
#pragma float_control(pop)


typedef struct SearchKey { unsigned char pad[0x10]; unsigned int value; } SearchKey;
typedef struct SearchRoot { unsigned char pad[0x10]; const SearchKey *key; unsigned int entries[28]; } SearchRoot;
__declspec(noinline) int __fastcall FUN_00735fb0(const SearchRoot *root) {
    unsigned int value = root->key->value;
    int index = 0;
    const unsigned int *cursor;
    _ReadWriteBarrier();
    cursor = root->entries;
    for (; index < 28; ++index, ++cursor) {
        if (value == *cursor) return index;
    }
    return 28;
}

extern volatile unsigned char DAT_02528b48;
extern volatile unsigned char DAT_02528b49;
extern float DAT_0279749c;
extern float DAT_0279748c;
/* EXE: 0098e2a0..0098e2cf. Explicit byte reads and rounded float
 * store/reload reproduce the native accesses; original qualifiers unknown. */
__declspec(noinline) float __cdecl FUN_0098e2a0(void) {
    volatile float result;
    if(DAT_02528b48==1 && !DAT_02528b49) {
        result=DAT_0279749c;
        return result;
    }
    result=DAT_0279748c;
    return result;
}

extern int DAT_0213ccbc;
/* EXE: 008c9c30..008c9c4f. Complete sentinel remapping; no jump table. */
__declspec(noinline) int __cdecl FUN_008c9c30(void) {
    switch(DAT_0213ccbc) {
    case -1: return -1;
    case 0: return 1;
    case 1: return 0;
    default: return -1;
    }
}

/* EXE: 00bdd230..00bdd259. Signed deadline comparison; low-byte result. */
__declspec(noinline) unsigned char __cdecl FUN_00bdd230(const int *source) {
    int value = *source;
    int now;
    if (value < 0) return 0;
    now = DAT_00e843ac;
    if (value > now) return (unsigned char)(value - now >= 900000000);
    now -= value;
    return (unsigned char)(now < 900000000);
}

extern unsigned char DAT_02529726;
/* EXE: 009b38c0..009b3900. Complete deadline flag and elapsed-time query. */
__declspec(noinline) unsigned char __fastcall FUN_009b38c0(unsigned char *source) {
    const int *stamp = (const int *)(source + 0xeb0);
    if (*stamp < 0) return 0;
    if (source[0xed9]) {
        if (!DAT_02529726) return 0;
        if (FUN_00bdd2a0(stamp) > 1500) return 0;
        _ReadWriteBarrier();
        return 1;
    }
    return (unsigned char)(FUN_00bdd2a0(stamp) <= 300);
}

typedef struct MovementPairActorView {
    unsigned char pad0044[0x44];
    unsigned int handle;
    unsigned char gap0080[0x38];
    unsigned char flags;
} MovementPairActorView;
typedef char verify_pair_handle[(offsetof(MovementPairActorView,handle)==0x44)?1:-1];
typedef char verify_pair_flags[(offsetof(MovementPairActorView,flags)==0x80)?1:-1];
/* EXE: 00601930..0060196c. Complete actor-pair and local-player flag predicate. */
__declspec(noinline) unsigned char __cdecl FUN_00601930(
    const MovementPairActorView *source, const MovementPairActorView *other) {
    unsigned int handle;
    if (!source || !other) goto no;
    handle = other->handle;
    if (handle == source->handle ||
        handle != ((const MovementPairActorView *)DAT_021703d4)->handle) goto no;
    if (DAT_02528b48 == 1 && !DAT_02528b49 && !(source->flags & 0x80)) goto no;
    return 1;
no:
    return 0;
}

typedef struct MovementOwnerDetail {
    unsigned char identifier;
    unsigned char pad067c[0x67b];
    unsigned char flags;
} MovementOwnerDetail;
typedef struct MovementOwnerActor {
    unsigned char pad00b0[0xb0];
    const MovementOwnerDetail *detail;
} MovementOwnerActor;
typedef struct MovementOwnerPlayer {
    unsigned char pad01b0[0x1b0];
    unsigned char identifier;
} MovementOwnerPlayer;
typedef struct MovementOwnerWorld {
    unsigned char pad0408[0x408];
    const MovementOwnerPlayer *player;
} MovementOwnerWorld;
typedef char verify_owner_detail_flags[(offsetof(MovementOwnerDetail,flags)==0x67c)?1:-1];
typedef char verify_owner_actor_detail[(offsetof(MovementOwnerActor,detail)==0xb0)?1:-1];
typedef char verify_owner_player_id[(offsetof(MovementOwnerPlayer,identifier)==0x1b0)?1:-1];
typedef char verify_owner_world_player[(offsetof(MovementOwnerWorld,player)==0x408)?1:-1];
/* EXE: 00806720..0080675a. Complete owner-detail identifier and flag predicate. */
__declspec(noinline) unsigned char __cdecl FUN_00806720(const MovementOwnerActor *source) {
    const MovementOwnerDetail *detail;
    const MovementOwnerWorld *world;
    const MovementOwnerPlayer *player;
    unsigned char one;
    if (!source) goto no;
    detail = source->detail;
    if (detail) {
        world = (const MovementOwnerWorld *)DAT_02528c14;
        if (world) {
            player = world->player;
            if (player) {
                if (detail->identifier != player->identifier) goto no;
                one = 1;
                if (!(detail->flags & one)) return one;
                goto no;
            }
        }
    }
    return 1;
no:
    return 0;
}

extern unsigned char DAT_00e88155;
extern unsigned char DAT_00e88154;
typedef struct MovementAuxiliaryFlagView {
    unsigned char pad13a0[0x13a0];
    unsigned int flags;
} MovementAuxiliaryFlagView;
typedef char verify_aux_flags[(offsetof(MovementAuxiliaryFlagView,flags)==0x13a0)?1:-1];
/* EXE: 004f5750..004f5785. Complete auxiliary movement flag update. */
__declspec(noinline) void __cdecl FUN_004f5750(MovementAuxiliaryFlagView *source) {
    if (DAT_02528b48 != 1 || DAT_02528b49) {
        if (DAT_00e88155) source->flags |= 2;
        if (DAT_00e88154) source->flags |= 4;
    }
}

typedef struct MovementInvertedFlagView {
    unsigned char pad004c[0x4c];
    int kind;
    unsigned char gap00c8[0x78];
    unsigned int flags;
    unsigned char gap03cc[0x300];
    unsigned char subtype;
} MovementInvertedFlagView;
typedef char verify_inverse_kind[(offsetof(MovementInvertedFlagView,kind)==0x4c)?1:-1];
typedef char verify_inverse_flags[(offsetof(MovementInvertedFlagView,flags)==0xc8)?1:-1];
typedef char verify_inverse_subtype[(offsetof(MovementInvertedFlagView,subtype)==0x3cc)?1:-1];
/* EXE: 0096c370..0096c3aa. The later flags read is unguarded in the original. */
__declspec(noinline) unsigned char __cdecl FUN_0096c370(const MovementInvertedFlagView *source) {
    int one = 1;
    unsigned char result;
    if (DAT_02528b48 == one && !DAT_02528b49) return 0;
    if (source && source->kind == one && source->subtype == one) return 0;
    result = (unsigned char)(source->flags >> 9);
    result = (unsigned char)~result;
    result &= (unsigned char)one;
    return result;
}

typedef struct MovementPositiveSlotView {
    unsigned char pad0034[0x34];
    int value;
    unsigned char tail[0x1c];
} MovementPositiveSlotView;
typedef char verify_positive_slot_stride[(sizeof(MovementPositiveSlotView)==0x54)?1:-1];
typedef char verify_positive_slot_value[(offsetof(MovementPositiveSlotView,value)==0x34)?1:-1];
static __forceinline const MovementPositiveSlotView *movement_nullable_positive_slot(int index) {
    unsigned int address;
    if (index < 0 || index >= DAT_02527d6c) return 0;
    address = (unsigned int)DAT_015b8800 + (unsigned int)index * 84;
    _ReadWriteBarrier();
    return (const MovementPositiveSlotView *)address;
}
/* EXE: 0096c340..0096c366. Complete indexed positive-value predicate. */
__declspec(noinline) int __cdecl FUN_0096c340(int index) {
    const MovementPositiveSlotView *slot = movement_nullable_positive_slot(index);
    if (slot && slot->value > 0) {
        _ReadWriteBarrier();
        return 1;
    }
    return 0;
}
