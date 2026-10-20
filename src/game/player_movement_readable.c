/* Readable C translations. Original field meanings remain unestablished.
 * Address-based names identify evidence, not recovered semantic names.
 * Compiled independently of the certified assembly reference. */

typedef struct MovementStateView {
    unsigned char unknown_0000[0x149];
    unsigned char field_0149;
} MovementStateView;

/* EXE: FUN_004fbd20:004fbd26; likewise each addressed predicate below. */
int __cdecl FUN_004fbd20(const MovementStateView *object) {
    return object->field_0149 == 0x22;
}
int __cdecl FUN_004fbd40(const MovementStateView *object) {
    return object->field_0149 == 0x18;
}
int __cdecl FUN_004fbd60(const MovementStateView *object) {
    return object->field_0149 == 0x09;
}
int __cdecl FUN_004fbd80(const MovementStateView *object) {
    return object->field_0149 == 0x16;
}
int __cdecl FUN_004fbda0(const MovementStateView *object) {
    return object->field_0149 == 0x19;
}
int __cdecl FUN_004fbdc0(const MovementStateView *object) {
    return object->field_0149 == 0x13;
}

typedef struct MovementFieldsView {
    unsigned char unknown_0000[0x148];
    unsigned char field_0148;
    unsigned char unknown_0149[0x139c-0x149];
    int field_139c;
    int field_13a0;
    int field_13a4;
    int field_13a8;
    int field_13ac;
} MovementFieldsView;
/* EXE: FUN_004f5fe0:004f5fe6..004f5ffe and FUN_004f6140:004f6146..004f615e. */
void __cdecl FUN_004f5fe0(MovementFieldsView *object) {
    object->field_139c = 0;
    object->field_13a0 = 0;
    object->field_13a4 = 0;
    object->field_13a8 = 0;
    object->field_13ac = 0;
}
void __cdecl FUN_004f6140(MovementFieldsView *object) {
    object->field_139c = 0;
    object->field_13a0 = 0;
    object->field_13a4 = 0;
    object->field_13a8 = 0;
    object->field_13ac = 0;
}
void __cdecl FUN_004f6760(MovementFieldsView *object) {
    object->field_139c = 1;
    object->field_13a0 = 0;
    object->field_13a4 = 0;
    object->field_13a8 = 0;
    object->field_13ac = 0;
}

typedef struct MovementFlagsView {
    unsigned char unknown_0000[0xc0];
    unsigned int field_00c0;
} MovementFlagsView;
/* EXE: FUN_0099f590:0099f594..0099f59d. */
unsigned int __cdecl FUN_0099f590(const MovementFlagsView *object) {
    return (object->field_00c0 >> 29) & 1;
}
typedef struct MovementLinkView {
    unsigned char unknown_0000[0x44];
    unsigned int field_0044;
    unsigned char unknown_0048[0x374-0x48];
    unsigned int field_0374;
} MovementLinkView;
/* EXE: FUN_009c9af0:009c9af8/009c9afd. */
int __cdecl FUN_009c9af0(unsigned int value, const MovementLinkView *object) {
    if (object->field_0044 == value || object->field_0374 == value) return 0;
    return 1;
}

typedef struct MovementFieldEA8View {
    unsigned char unknown_0000[0xea8];
    int field_0ea8;
} MovementFieldEA8View;
/* EXE: FUN_009b36f0:009b36f6. */
int __cdecl FUN_009b36f0(const MovementFieldEA8View *object) {
    return object->field_0ea8 != 0;
}

/* EXE: complete setters, original stores at entry+6 through terminal RET. */
void __cdecl FUN_004f68b0(MovementFieldsView *object) {
    object->field_139c = 4;
    object->field_13a0 = 0;
    object->field_13a4 = 0;
    object->field_13a8 = 0x40c0;
    object->field_13ac = 0;
}
void __cdecl FUN_004f6010(MovementFieldsView *object) {
    object->field_139c = 3;
    object->field_13a0 = 1;
    object->field_13a4 = 0x1000c0;
    object->field_13a8 = 0;
    object->field_13ac = 0;
}
void __cdecl FUN_004f60d0(MovementFieldsView *object) {
    object->field_139c = 1;
    object->field_13a0 = 0;
    object->field_13a4 = 0;
    object->field_13a8 = 0;
    object->field_13ac = 0x200;
}
void __cdecl FUN_004f6100(MovementFieldsView *object) {
    object->field_139c = 3;
    object->field_13a0 = 1;
    object->field_13a4 = 0;
    object->field_13a8 = 0;
    object->field_13ac = 0x100000;
}
void __cdecl FUN_004f66f0(MovementFieldsView *object) {
    object->field_139c = 3;
    object->field_13a0 = 1;
    object->field_13a4 = 0;
    object->field_13a8 = 0;
    object->field_13ac = 0;
}
void __cdecl FUN_004f6720(MovementFieldsView *object) {
    object->field_139c = 3;
    object->field_13a0 = 1;
    object->field_13a4 = 4;
    object->field_13a8 = 0;
    object->field_13ac = 0;
}

/* EXE: FUN_004f6790:004f6794..004f67f0, both complete branches. */
void __cdecl FUN_004f6790(MovementFieldsView *object) {
    if (object->field_0148 == 0x56) {
        object->field_139c = 3;
        object->field_13a0 = 1;
        object->field_13a4 = 0x800000;
        object->field_13a8 = 0;
        object->field_13ac = 0x1000;
    } else {
        object->field_139c = 0;
        object->field_13a0 = 0;
        object->field_13a4 = 0;
        object->field_13a8 = 0;
        object->field_13ac = 0;
    }
}

extern int DAT_00e96aa8;
extern int DAT_00e96aac;
extern int DAT_00e96ab0;
extern int DAT_027b3c60;
extern int DAT_021f2a88;
/* EXE: FUN_00a46320:00a46320..00a46334. */
int __cdecl FUN_00a46320(void) {
    DAT_00e96aa8 = -1;
    DAT_00e96aac = -1;
    DAT_00e96ab0 = -1;
    return 0;
}
/* EXE: FUN_009f1740:009f1740..009f1758. */
int __cdecl FUN_009f1740(void) {
    if (DAT_027b3c60 && DAT_00e96ab0 != -1) return DAT_00e96ab0;
    return DAT_021f2a88;
}

typedef struct MovementClearView {
    unsigned char unknown_0000[0xc4];
    unsigned int field_00c4;
    unsigned char unknown_00c8[0xaf8-0xc8];
    int field_0af8;
    float field_0afc;
} MovementClearView;
/* EXE: FUN_00981e00:00981e00..00981e29. ECX argument. */
void __fastcall FUN_00981e00(MovementClearView *object) {
    if (object && (object->field_00c4 & 3)) {
        unsigned int flags = object->field_00c4;
        object->field_0afc = 0.0f;
        object->field_00c4 = flags & ~3u;
        object->field_0af8 = 0;
    }
}
/* EXE: FUN_00926600:00926600..00926618. ECX argument, AL result. */

/* Compile-time layout checks: these are partial views, not full engine types. */
#include <stddef.h>
#define VERIFY_OFFSET(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_OFFSET(MovementStateView, field_0149, 0x149);
VERIFY_OFFSET(MovementFieldsView, field_0148, 0x148);
VERIFY_OFFSET(MovementFieldsView, field_139c, 0x139c);
VERIFY_OFFSET(MovementFieldsView, field_13a0, 0x13a0);
VERIFY_OFFSET(MovementFieldsView, field_13a4, 0x13a4);
VERIFY_OFFSET(MovementFieldsView, field_13a8, 0x13a8);
VERIFY_OFFSET(MovementFieldsView, field_13ac, 0x13ac);
VERIFY_OFFSET(MovementFlagsView, field_00c0, 0xc0);
VERIFY_OFFSET(MovementLinkView, field_0044, 0x44);
VERIFY_OFFSET(MovementLinkView, field_0374, 0x374);
VERIFY_OFFSET(MovementFieldEA8View, field_0ea8, 0xea8);
VERIFY_OFFSET(MovementClearView, field_00c4, 0xc4);
VERIFY_OFFSET(MovementClearView, field_0af8, 0xaf8);
VERIFY_OFFSET(MovementClearView, field_0afc, 0xafc);
#undef VERIFY_OFFSET

/* EXE: FUN_009654b0:009654b4..009654cb. */
int __cdecl FUN_009654b0(const MovementFlagsView *object) {
    return (object->field_00c0 & 0x400000u) == 0x400000u;
}

typedef struct MovementHandleObjectView {
    unsigned char unknown_0000[0x44];
    unsigned int field_0044;
    unsigned short field_0048;
    unsigned char unknown_004a[2];
    unsigned int field_004c;
    unsigned char unknown_0050[0x80-0x50];
    unsigned char field_0080;
    unsigned char unknown_0081[0x2a4-0x81];
    unsigned int field_02a4;
    unsigned int field_02a8;
    unsigned char unknown_02ac[0x3cc-0x2ac];
    unsigned char field_03cc;
    
} MovementHandleObjectView;
typedef struct MovementHandleSlotView {
    MovementHandleObjectView *object;
    unsigned char unknown_0004[12];
} MovementHandleSlotView;
extern MovementHandleSlotView DAT_02149c64[];
/* EXE: FUN_0094df70:0094df70..0094df95. */
MovementHandleObjectView * __fastcall FUN_0094df70(unsigned int handle) {
    MovementHandleObjectView *object;
    if (!handle) return 0;
    object = DAT_02149c64[handle & 0xfff].object;
    if (!object || object->field_0044 != handle || object->field_004c != 4) return 0;
    return object;
}

extern MovementHandleObjectView *DAT_021703d4;
/* EXE: FUN_00926620:00926620..0092664a. */
unsigned char __fastcall FUN_00926620(unsigned int handle) {
    MovementHandleObjectView *object;
    if (!handle) return 0;
    object = DAT_02149c64[handle & 0xfff].object;
    if (!object || object->field_0044 != handle || object != DAT_021703d4) return 0;
    return 1;
}

extern int DAT_00ea1020;
/* EXE: FUN_00634a30:00634a30..00634a6e. */
int __cdecl FUN_00634a30(const MovementHandleObjectView *source) {
    unsigned int handle = source->field_0044;
    MovementHandleObjectView *object;
    if (!handle) return 0;
    object = DAT_02149c64[handle & 0xfff].object;
    if (!object || object->field_0044 != handle) return 0;
    if (object != DAT_021703d4 || DAT_00ea1020 != 2) return 0;
    return 1;
}

extern int DAT_00e9dd80;
extern int DAT_00e9dd84;
/* EXE: FUN_00561db0:00561db0..00561ddd. */
int __cdecl FUN_00561db0(const MovementHandleObjectView *object) {
    if (object->field_0044 != DAT_021703d4->field_0044) return 0;
    if (DAT_00e9dd80 == -1 || DAT_00e9dd84 == -1) return 0;
    return 1;
}

typedef char verify_handle_field_0044[(offsetof(MovementHandleObjectView, field_0044)==0x44)?1:-1];
typedef char verify_handle_field_004c[(offsetof(MovementHandleObjectView, field_004c)==0x4c)?1:-1];
typedef char verify_handle_slot_stride[(sizeof(MovementHandleSlotView)==16)?1:-1];

/* EXE: FUN_009302a0:009302a0..009302ce. */
typedef struct MovementListNodeView {
    unsigned char unknown_0000[0xc];
    struct MovementListNodeView *field_000c;
    struct MovementListNodeView *field_0010;
} MovementListNodeView;
extern MovementListNodeView *DAT_02529610;
void __fastcall FUN_009302a0(MovementListNodeView *node) {
    MovementListNodeView *head;
    MovementListNodeView *saved;
    if (!node) return;
    head = DAT_02529610;
    if (!head) {
        DAT_02529610 = node;
        return;
    }
    head->field_0010->field_000c = node;
    node->field_0010->field_000c = head;
    saved = node->field_0010;
    node->field_0010 = head->field_0010;
    head->field_0010 = saved;
}

/* EXE: FUN_0098e710:0098e710..0098e74b. EDX input. */
MovementHandleObjectView * __fastcall FUN_0098e710(void *unused, MovementHandleObjectView *source) {
    unsigned int handle;
    MovementHandleObjectView *object;
    if (!source) return 0;
    handle = source->field_02a4;
    if (handle) {
        object = DAT_02149c64[handle & 0xfff].object;
        if (object && object->field_0044 == handle && object->field_004c == 1 &&
            !(object->field_0080 & 0xb)) return object;
    }
    return source;
}

/* EXE: FUN_0098e750:0098e750..0098e7bd. EDX input. */
MovementHandleObjectView * __fastcall FUN_0098e750(void *unused, MovementHandleObjectView *source) {
    unsigned int handle;
    MovementHandleObjectView *object;
    if (!source) return 0;
    handle = source->field_02a8;
    if (handle) {
        object = DAT_02149c64[handle & 0xfff].object;
        if (object && object->field_0044 == handle && object->field_004c == 1 &&
            !(object->field_0080 & 0xb)) return object;
    }
    handle = source->field_02a4;
    if (handle) {
        object = DAT_02149c64[handle & 0xfff].object;
        if (object && object->field_0044 == handle && object->field_004c == 1 &&
            !(object->field_0080 & 0xb)) return object;
    }
    return source;
}
typedef struct MovementRelationView {
    unsigned char unknown_0000[0xea8];
    unsigned int field_0ea8;
    int field_0eac;
} MovementRelationView;
/* EXE: FUN_009b3680:009b3680..009b36c3. EDX input, AL result. */
unsigned char __fastcall FUN_009b3680(void *unused, const MovementRelationView *source) {
    unsigned int handle = source->field_0ea8;
    MovementHandleObjectView *object;
    int value;
    if (!handle) return 0;
    object = DAT_02149c64[handle & 0xfff].object;
    if (!object || object->field_0044 != handle || object->field_004c != 1) return 0;
    value = source->field_0eac;
    if (value > 0 && (value <= 3 || value == 5)) return 1;
    return 0;
}

typedef struct MovementAttachmentView {
    unsigned char unknown_0000[0xc0];
    unsigned int field_00c0;
    unsigned char unknown_00c4[0x374-0xc4];
    unsigned int field_0374;
    unsigned char unknown_0378[0xb25-0x378];
    unsigned char field_0b25;
} MovementAttachmentView;
/* EXE: FUN_0096da80:0096da80..0096dabf. EDX input, AL result. */
unsigned char __fastcall FUN_0096da80(void *unused, const MovementAttachmentView *source) {
    unsigned int handle;
    MovementHandleObjectView *object;
    if (!(source->field_00c0 & 0x40000)) return 0;
    handle = source->field_0374;
    if (!handle) return 0;
    object = DAT_02149c64[handle & 0xfff].object;
    if (!object || object->field_0044 != handle) return 0;
    return source->field_0b25 != 0xff;
}

extern int DAT_00e96c00;
extern int DAT_021f2a8c;
extern int __cdecl FUN_0053e8b0(void);
/* EXE: FUN_009f1760:009f1760..009f179c. */
int __cdecl FUN_009f1760(void) {
    if (DAT_027b3c60 && (!DAT_00e96c00 ? FUN_0053e8b0() : DAT_00e96aac) != -1) {
        return !DAT_00e96c00 ? FUN_0053e8b0() : DAT_00e96aac;
    }
    return DAT_021f2a8c;
}

typedef struct MovementVirtualObjectView MovementVirtualObjectView;
typedef int (__fastcall *MovementVirtualQuery)(MovementVirtualObjectView *object);
typedef struct MovementVirtualTableView {
    MovementVirtualQuery field_0000;
    MovementVirtualQuery field_0004;
    MovementVirtualQuery field_0008;
} MovementVirtualTableView;
struct MovementVirtualObjectView { MovementVirtualTableView *field_0000; };
typedef struct MovementVirtualRootView {
    unsigned char unknown_0000[8];
    MovementVirtualObjectView *field_0008;
    unsigned char unknown_000c[4];
    int field_0010;
    unsigned char unknown_0014[8];
    unsigned char field_001c;
} MovementVirtualRootView;
extern MovementVirtualRootView *DAT_02527888;

/* EXE: FUN_005f7da0:005f7da0..005f7dd2. */
int __cdecl FUN_005f7da0(const MovementHandleObjectView *source) {
    MovementVirtualObjectView *object;
    int value;
    if (source == DAT_021703d4 && DAT_02527888) {
        object = DAT_02527888->field_0008;
        value = object->field_0000->field_0008(object);
        if (value == 1 && DAT_02527888->field_0010 == 1) return 1;
    }
    return 0;
}

typedef struct MovementIndexValueView {
    unsigned char unknown_0000[0x164];
    int field_0164;
} MovementIndexValueView;
typedef struct MovementIndexRootView {
    unsigned char unknown_0000[0x5e0];
    MovementIndexValueView *field_05e0;
} MovementIndexRootView;
/* EXE: FUN_006123c0:006123c0..00612410. */
int __cdecl FUN_006123c0(const void *source) {
    MovementVirtualObjectView *object;
    int value;
    if (source == DAT_021703d4 && DAT_02527888) {
        object = DAT_02527888->field_0008;
        value = object->field_0000->field_0008(object);
        if (value == 9 && (DAT_02527888->field_001c ||
            ((MovementIndexRootView *)DAT_021703d4)->field_05e0->field_0164 == 0x33f)) return 1;
    }
    return 0;
}

typedef struct MovementModeView {
    unsigned char unknown_0000[0x3c];
    int field_003c;
    unsigned char unknown_0040[0x90-0x40];
    MovementVirtualObjectView *field_0090;
} MovementModeView;
/* EXE: FUN_009f17a0:009f17a0..009f17c6. AL result. */
unsigned char __cdecl FUN_009f17a0(void) {
    MovementModeView *mode = (MovementModeView *)DAT_027b3c60;
    MovementVirtualObjectView *object;
    if (mode && mode->field_003c == 1) {
        object = mode->field_0090;
        if (object->field_0000->field_0004(object) == 7) return 1;
    }
    return 0;
}


/* Layout checks for complete C translations above; offset names are not semantic identifications. */
#define VERIFY_OFFSET(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_OFFSET(MovementHandleObjectView, field_0048, 0x0048);
VERIFY_OFFSET(MovementHandleObjectView, field_0080, 0x0080);
VERIFY_OFFSET(MovementHandleObjectView, field_02a4, 0x02a4);
VERIFY_OFFSET(MovementHandleObjectView, field_02a8, 0x02a8);
VERIFY_OFFSET(MovementHandleObjectView, field_03cc, 0x03cc);
VERIFY_OFFSET(MovementListNodeView, field_000c, 0x000c);
VERIFY_OFFSET(MovementListNodeView, field_0010, 0x0010);
VERIFY_OFFSET(MovementRelationView, field_0ea8, 0x0ea8);
VERIFY_OFFSET(MovementRelationView, field_0eac, 0x0eac);
VERIFY_OFFSET(MovementAttachmentView, field_00c0, 0x00c0);
VERIFY_OFFSET(MovementAttachmentView, field_0374, 0x0374);
VERIFY_OFFSET(MovementAttachmentView, field_0b25, 0x0b25);
VERIFY_OFFSET(MovementVirtualTableView, field_0000, 0x0000);
VERIFY_OFFSET(MovementVirtualTableView, field_0004, 0x0004);
VERIFY_OFFSET(MovementVirtualTableView, field_0008, 0x0008);
VERIFY_OFFSET(MovementVirtualObjectView, field_0000, 0x0000);
VERIFY_OFFSET(MovementVirtualRootView, field_0008, 0x0008);
VERIFY_OFFSET(MovementVirtualRootView, field_0010, 0x0010);
VERIFY_OFFSET(MovementVirtualRootView, field_001c, 0x001c);
VERIFY_OFFSET(MovementIndexValueView, field_0164, 0x0164);
VERIFY_OFFSET(MovementIndexRootView, field_05e0, 0x05e0);
VERIFY_OFFSET(MovementModeView, field_003c, 0x003c);
VERIFY_OFFSET(MovementModeView, field_0090, 0x0090);
#undef VERIFY_OFFSET






extern float DAT_02528504;
extern float DAT_0252850c;
extern void __cdecl FUN_00796620(MovementHandleObjectView *source);
/* EXE: FUN_007945e0:007945e0..007945f8. */
void __cdecl FUN_007945e0(void) {
    MovementHandleObjectView *source = DAT_021703d4;
    DAT_0252850c = DAT_02528504;
    FUN_00796620(source);
}



typedef struct MovementPropertyFlagsView {
    unsigned char unknown_0000[0xd];
    unsigned char field_000d;
} MovementPropertyFlagsView;
typedef struct MovementPropertyView {
    unsigned char unknown_0000[0xc4];
    MovementPropertyFlagsView *field_00c4;
} MovementPropertyView;
typedef struct MovementPropertyRootView {
    unsigned char unknown_0000[0x10cc];
    MovementPropertyView *field_10cc;
} MovementPropertyRootView;
extern unsigned char DAT_027a0840[];
extern unsigned char __fastcall FUN_005f9950(void *source);
/* EXE: FUN_004f6050:004f6050..004f60c4. */
void __cdecl FUN_004f6050(MovementFieldsView *source) {
    MovementPropertyView *property;
    source->field_139c = 3;
    source->field_13a0 = 1;
    source->field_13a4 = 0;
    source->field_13a8 = 0;
    source->field_13ac = 0x300;
    if (FUN_005f9950(DAT_027a0840)) source->field_13ac |= 0x80;
    property = ((MovementPropertyRootView *)source)->field_10cc;
    if (property && property->field_00c4 && (property->field_00c4->field_000d & 2))
        source->field_13a4 |= 0x200;
}

#define VERIFY_OFFSET(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_OFFSET(MovementPropertyFlagsView, field_000d, 0xd);
VERIFY_OFFSET(MovementPropertyView, field_00c4, 0xc4);
VERIFY_OFFSET(MovementPropertyRootView, field_10cc, 0x10cc);
#undef VERIFY_OFFSET




typedef struct MovementScaleValueView {
    unsigned char unknown_0000[0x48];
    float field_0048;
} MovementScaleValueView;
typedef struct MovementScaleLinkView {
    unsigned char unknown_0000[8];
    MovementScaleValueView *field_0008;
} MovementScaleLinkView;
typedef struct MovementScaleRootView {
    unsigned char unknown_0000[0xd34];
    MovementScaleLinkView *field_0d34;
    unsigned char unknown_0d38[0x1120-0xd38];
    int field_1120;
    float field_1124;
} MovementScaleRootView;
extern double DAT_00e5c190;
extern float DAT_00e8437c;
extern void __fastcall FUN_0096a0a0(MovementScaleRootView *source, MovementScaleLinkView *unused, float value);
/* EXE: FUN_00986e60:00986e60..00986eba. */
void __fastcall FUN_00986e60(MovementScaleRootView *source) {
    MovementScaleLinkView *property = source->field_0d34;
    float maximum;
    float value;
    if (property) {
        maximum = (float)source->field_1120;
        if (source->field_1124 < maximum) {
            value = (float)(property->field_0008->field_0048 / DAT_00e5c190 * maximum);
            value = value * DAT_00e8437c;
            FUN_0096a0a0(source, property, value);
        }
    }
}

#define VERIFY_OFFSET(type, field, offset) \
    typedef char verify_##type##_##field[(offsetof(type, field) == (offset)) ? 1 : -1]
VERIFY_OFFSET(MovementScaleValueView, field_0048, 0x48);
VERIFY_OFFSET(MovementScaleLinkView, field_0008, 8);
VERIFY_OFFSET(MovementScaleRootView, field_0d34, 0xd34);
VERIFY_OFFSET(MovementScaleRootView, field_1120, 0x1120);
VERIFY_OFFSET(MovementScaleRootView, field_1124, 0x1124);
#undef VERIFY_OFFSET



extern int DAT_021f2a94;
extern float DAT_021f2a90;
/* EXE: FUN_009f22e0:009f22e0..009f230c. */
int __cdecl FUN_009f22e0(void) {
    int value;
    if (DAT_027b3c60 && DAT_00e96aa8 != -1) value = DAT_00e96aa8;
    else value = DAT_021f2a94;
    return (int)(value * DAT_021f2a90);
}

extern unsigned char DAT_02527d14;
extern unsigned char DAT_02527cf7;
extern unsigned char DAT_02527d15;
/* EXE: FUN_006c6d20:006c6d20..006c6d43; direct movement dependency. */
int __cdecl FUN_006c6d20(void) {
    if ((!DAT_02527d14 || !DAT_02527cf7) && !DAT_02527d15) return 0;
    return 1;
}

typedef struct FlagC0View { unsigned char pad[0xc0]; unsigned int flags; } FlagC0View;
static __forceinline unsigned int bit10_value(const FlagC0View *source) { return (source->flags >> 10) & 1; }
/* EXE: FUN_0098e250:0098e250..0098e267. */
unsigned char __cdecl FUN_0098e250(const FlagC0View *source) {
    if (!source) return 0;
    return bit10_value(source);
}
typedef char verify_flag_c0[(offsetof(FlagC0View, flags) == 0xc0) ? 1 : -1];

/* EXE: FUN_0080fcf0:0080fcf0..0080fd13. */

typedef struct State3F8 { unsigned char pad[0x3f8]; unsigned char value; } State3F8;
extern unsigned char DAT_02528b56;
extern unsigned char DAT_02528b2b;
unsigned char __stdcall FUN_0080fcf0(const State3F8 *source) {
    if (DAT_02528b56 && !DAT_02528b2b) return 0;
    return source->value;
}

typedef char verify_state_3f8[(offsetof(State3F8, value)==0x3f8)?1:-1];

/* EXE: FUN_00625550; full nested state predicate. */
extern int DAT_027a3230;
extern unsigned char __cdecl FUN_006213c0(void);
int __cdecl FUN_00625550(const void *source) {
 if (source == DAT_021703d4) {
  int value = DAT_027a3230;
  if (value == 4 || value == 5 || value == 1 || value == 2 || value == 3 || FUN_006213c0())
   return 1;
 }
 return 0;
}

#include <xmmintrin.h>
typedef __m128 MovementAlignedVector;
/* EXE: FUN_00997300:00997300..00997326. ECX destination, stack source, RET 4. */
MovementAlignedVector * __fastcall FUN_00997300(MovementAlignedVector *destination, void *unused, const MovementAlignedVector *source) {
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    return destination;
}

/* EXE: FUN_00703350:00703350..0070337e. ECX destination, stack source, RET 4. */
MovementAlignedVector * __fastcall FUN_00703350(MovementAlignedVector *destination, void *unused, const MovementAlignedVector *source) {
    MovementAlignedVector v1 = source[1];
    MovementAlignedVector v2 = source[2];
    MovementAlignedVector v3 = source[3];
    MovementAlignedVector v0 = source[0];
    destination[0] = v0;
    destination[1] = v1;
    destination[2] = v2;
    destination[3] = v3;
    return destination;
}

typedef char check_aligned_vector_size[(sizeof(MovementAlignedVector)==16 && __alignof(MovementAlignedVector)==16)?1:-1];

/* EXE: FUN_004f70d0; complete zero stores with flag snapshot. */
typedef struct ZeroPair1370 { unsigned char pad[0x1370]; float first, second; } ZeroPair1370;
extern unsigned char DAT_00e8843f;
extern float DAT_00f9ea20;
extern float DAT_00f9ea28;
extern float DAT_00f9ea1c;
extern float DAT_00f9ea24;
void __cdecl FUN_004f70d0(void) {
 unsigned char flag = DAT_00e8843f;
 float zero = 0.0f;
 DAT_00f9ea20 = zero;
 DAT_00f9ea28 = zero;
 DAT_00f9ea1c = zero;
 DAT_00f9ea24 = zero;
 if (flag == 1) {
  ZeroPair1370 *root = (ZeroPair1370 *)DAT_021703d4;
  root->first = zero;
  root->second = zero;
 }
}

typedef char check_zero_pair[(offsetof(ZeroPair1370,first)==0x1370 && offsetof(ZeroPair1370,second)==0x1374)?1:-1];

typedef unsigned char (__cdecl *MovementDispatchPredicate)(void *player);
typedef void (__cdecl *MovementDispatchAction)(void);
typedef struct MovementDispatch16 { MovementDispatchPredicate predicate;unsigned int unknown04;MovementDispatchAction action;unsigned int unknown0c; } MovementDispatch16;
extern const MovementDispatch16 DAT_00dd4cf0[];
typedef struct MovementDispatchAction16 { MovementDispatchAction action;unsigned char tail[12]; } MovementDispatchAction16;
extern const MovementDispatchAction16 DAT_00dd4cf8[];
extern const MovementDispatch16 DAT_00dd4e90;
extern void __cdecl FUN_004f75b0(void);
/* EXE: FUN_004f6e50:004f6e50..004f6e94; 26 rows ending at 00dd4e90; signed address comparison at 004f6e78. */
__declspec(noinline) void __cdecl FUN_004f6e50(void) {
 void *player=(void *)DAT_021703d4;unsigned int index=0;const MovementDispatch16 *cursor=DAT_00dd4cf0;
 do { if(cursor->predicate(player)) { MovementDispatchAction action=DAT_00dd4cf8[index].action;if(action) action();return; } ++cursor;++index; } while((int)cursor<(int)&DAT_00dd4e90);
 FUN_004f75b0();
}

typedef char verify_MovementDispatch16_stride[(sizeof(MovementDispatch16)==16)?1:-1];
typedef char verify_MovementDispatch16_action[(offsetof(MovementDispatch16,action)==8)?1:-1];
typedef char verify_MovementDispatchAction16_stride[(sizeof(MovementDispatchAction16)==16)?1:-1];

/* EXE: FUN_00603e30:00603e30..00603e46; same virtual query interface as 005f7da0. */
__declspec(noinline) int __cdecl FUN_00603e30(void) {
 if(DAT_02527888) { MovementVirtualObjectView *object=DAT_02527888->field_0008;return object->field_0000->field_0008(object); }
 return -1;
}

/* EXE: FUN_0053c4d0:0053c4d0..0053c4ef. */
__declspec(noinline) int __cdecl FUN_0053c4d0(void) {
 MovementModeView *mode=(MovementModeView *)DAT_027b3c60;
 if(mode && mode->field_003c==1) { MovementVirtualObjectView *object=mode->field_0090;return object->field_0000->field_0004(object); }
 return -1;
}

/* EXE: FUN_007371a0:007371a0..007371bf. Aligned 16-byte stores. */
void __stdcall FUN_007371a0(float *source) {
    __m128 zero=_mm_setzero_ps();
    _mm_store_ps(source+0x160/4,zero);
    _mm_store_ps(source+0x140/4,zero);
}

typedef struct ThirdInit18  {
    int field0,field4,field8,fieldc,field10,field14;
    unsigned char byte18;
}
ThirdInit18;
extern int DAT_00e843ac;
/* EXE: FUN_004543a0:004543a0..004543d9. */
__declspec(noinline) void __cdecl FUN_004543a0(ThirdInit18 *source)  {
    int now;
    source->field4=0;
    source->field10=0;
    source->byte18=0;
    source->field8=0;
    now=DAT_00e843ac;
    source->field0=-1;
    source->field14=-1;
    source->fieldc=now;
    if(now>1800000000) source->fieldc=now-1800000000;
}

extern int DAT_00ec3abc;extern unsigned int DAT_00ec3ac0[];
/* EXE: FUN_00421dc0:00421dc0..00421e09. */
__declspec(noinline) int __cdecl FUN_00421dc0(int excluded)  {
    unsigned int value=DAT_00ec3ac0[DAT_00ec3abc];
    int result;
    ++DAT_00ec3abc;
    if(DAT_00ec3abc>=2048) DAT_00ec3abc=0;
    result=value%5;
    if(result==excluded) result=(result+1)%5;
    return result;
}

/* EXE: member offsets used by the complete recovered bodies above. */
typedef char verify_recent_ThirdInit18_field0[(offsetof(ThirdInit18,field0)==0x0)?1:-1];
typedef char verify_recent_ThirdInit18_field4[(offsetof(ThirdInit18,field4)==0x4)?1:-1];
typedef char verify_recent_ThirdInit18_field8[(offsetof(ThirdInit18,field8)==0x8)?1:-1];
typedef char verify_recent_ThirdInit18_fieldc[(offsetof(ThirdInit18,fieldc)==0xc)?1:-1];
typedef char verify_recent_ThirdInit18_field10[(offsetof(ThirdInit18,field10)==0x10)?1:-1];
typedef char verify_recent_ThirdInit18_field14[(offsetof(ThirdInit18,field14)==0x14)?1:-1];
typedef char verify_recent_ThirdInit18_byte18[(offsetof(ThirdInit18,byte18)==0x18)?1:-1];

typedef struct FourthDotVectors {
    unsigned char pad[0x100];
    __m128 first;
    unsigned char gap[0x1a0-0x110];
    __m128 second;
} FourthDotVectors;
typedef struct FourthDotRoot20 {
    unsigned char pad[0x20];
    const FourthDotVectors *object;
} FourthDotRoot20;
extern double DAT_00e5ca18;
/* EXE: FUN_00b02600:00b02600..00b0265d. */
__declspec(noinline) int __stdcall FUN_00b02600(const FourthDotRoot20 *source) {
    __m128 product=_mm_mul_ps(source->object->second,source->object->first);
    __m128 y=_mm_shuffle_ps(product,product,0x55);
    __m128 z=_mm_shuffle_ps(product,product,0xaa);
    __declspec(align(16)) float result;
    y=_mm_add_ss(y,product);
    z=_mm_add_ss(z,y);
    _mm_store_ss(&result,z);
    return result<DAT_00e5ca18;
}

typedef char verify_FourthDot_first[(offsetof(FourthDotVectors,first)==0x100)?1:-1];
typedef char verify_FourthDot_second[(offsetof(FourthDotVectors,second)==0x1a0)?1:-1];
typedef char verify_FourthDot_object[(offsetof(FourthDotRoot20,object)==0x20)?1:-1];

typedef struct ThirdCopy44 {
    __m128 first;
    float value10;
    unsigned int field14,field18,field1c,field20,field24,field28,field2c,field30,field34,field38,field3c,field40;
} ThirdCopy44;
/* EXE: FUN_00701f90:00701f90..00701ff4. */
__declspec(noinline) ThirdCopy44 * __fastcall FUN_00701f90(ThirdCopy44 *destination,void *unused,const ThirdCopy44 *source) {
    __m128 first=source->first;
    destination->first=first;
    destination->value10=source->value10;
    destination->field14=source->field14;
    destination->field18=source->field18;
    destination->field1c=source->field1c;
    destination->field20=source->field20;
    destination->field24=source->field24;
    destination->field28=source->field28;
    destination->field2c=source->field2c;
    destination->field30=source->field30;
    destination->field34=source->field34;
    destination->field38=source->field38;
    destination->field3c=source->field3c;
    destination->field40=source->field40;
    return destination;
}

typedef char verify_ThirdCopy44_first[(offsetof(ThirdCopy44,first)==0x0)?1:-1];
typedef char verify_ThirdCopy44_value10[(offsetof(ThirdCopy44,value10)==0x10)?1:-1];
typedef char verify_ThirdCopy44_field14[(offsetof(ThirdCopy44,field14)==0x14)?1:-1];
typedef char verify_ThirdCopy44_field18[(offsetof(ThirdCopy44,field18)==0x18)?1:-1];
typedef char verify_ThirdCopy44_field1c[(offsetof(ThirdCopy44,field1c)==0x1c)?1:-1];
typedef char verify_ThirdCopy44_field20[(offsetof(ThirdCopy44,field20)==0x20)?1:-1];
typedef char verify_ThirdCopy44_field24[(offsetof(ThirdCopy44,field24)==0x24)?1:-1];
typedef char verify_ThirdCopy44_field28[(offsetof(ThirdCopy44,field28)==0x28)?1:-1];
typedef char verify_ThirdCopy44_field2c[(offsetof(ThirdCopy44,field2c)==0x2c)?1:-1];
typedef char verify_ThirdCopy44_field30[(offsetof(ThirdCopy44,field30)==0x30)?1:-1];
typedef char verify_ThirdCopy44_field34[(offsetof(ThirdCopy44,field34)==0x34)?1:-1];
typedef char verify_ThirdCopy44_field38[(offsetof(ThirdCopy44,field38)==0x38)?1:-1];
typedef char verify_ThirdCopy44_field3c[(offsetof(ThirdCopy44,field3c)==0x3c)?1:-1];
typedef char verify_ThirdCopy44_field40[(offsetof(ThirdCopy44,field40)==0x40)?1:-1];

typedef struct BroadStateObject BroadStateObject;
typedef int (__fastcall *BroadStateQuery)(BroadStateObject *);
typedef struct BroadStateTable {
    BroadStateQuery entries[16];
    BroadStateQuery query;
} BroadStateTable;
struct BroadStateObject {BroadStateTable *table;};
extern BroadStateObject *DAT_0140b168[];
extern int DAT_00e97c0c;
extern int DAT_00e97c10;
extern int DAT_00e96c04;
extern int DAT_02527bb4;
typedef char verify_broad_state_query[(offsetof(BroadStateTable,query)==0x40)?1:-1];
/* EXE: FUN_00603250:00603250..00603291. */
__declspec(noinline) void __cdecl FUN_00603250(int value) {
    BroadStateObject *object=DAT_0140b168[DAT_00e97c0c];
    if(object->table->query(object)==value) {
        DAT_00e97c10=DAT_00e97c0c;
        if(DAT_00e96c00!=2) {
            DAT_00e96c04=2;
            DAT_02527bb4=0;
        }
    }
}

extern unsigned char DAT_0340d240[];
extern void __stdcall FUN_00ce89a0(void *source);

/* EXE: FUN_00cedc10:00cedc10..00cedc43. */
__declspec(noinline) void __fastcall FUN_00cedc10(int identifier) {
    unsigned char *slot;
    if (identifier >= 0)  {
        slot = DAT_0340d240 + (identifier % 190) * 0x5e8;
        if (slot) FUN_00ce89a0(slot);
    }
}

extern void __stdcall FUN_00ce8a00(void *source,unsigned char active);

/* EXE: FUN_00cedc90:00cedc90..00cedcd7. */
__declspec(noinline) void __fastcall FUN_00cedc90(int identifier) {
    unsigned char *slot;
    if (identifier >= 0)  {
        slot = DAT_0340d240 + (identifier % 190) * 0x5e8;
        if (slot)  {
            FUN_00ce8a00(slot, 1);
            *(float *)(slot + 0x244) = 0;
            *(float *)(slot + 0x248) = 0;
        }
    }
}


/* EXE: FUN_00ce5340:00ce5340..00ce536f. */
__declspec(noinline) unsigned char * __fastcall FUN_00ce5340(int identifier) {
    if(identifier<0)return 0;
    return DAT_0340d240+(identifier%190)*0x5e8;
}

#ifndef MOVEMENT_LEAF_REFERENCE_TRIAL
#define MOVEMENT_LEAF_REFERENCE_TRIAL
typedef void (__fastcall *LeafReleaseCallbackTrial)(void *source,void *unused,unsigned int deleting);
typedef struct LeafReferenceTrial {LeafReleaseCallbackTrial *vtable;short kind,references;} LeafReferenceTrial;
#endif

/* EXE: FUN_00d82300:00d82300..00d8231d. */
__declspec(noinline) void __fastcall FUN_00d82300(LeafReferenceTrial *source) {
    LeafReleaseCallbackTrial callback;
    if(source->kind&&--source->references==0) {
        callback=*source->vtable;
        callback(source,(void *)callback,1);
    }
}

#ifndef MOVEMENT_LEAF_REFERENCE_TRIAL
#define MOVEMENT_LEAF_REFERENCE_TRIAL
typedef void (__fastcall *LeafReleaseCallbackTrial)(void *source,void *unused,unsigned int deleting);
typedef struct LeafReferenceTrial {LeafReleaseCallbackTrial *vtable;short kind,references;} LeafReferenceTrial;
#endif

/* EXE: FUN_00d56830:00d56830..00d5684d. */
__declspec(noinline) void __fastcall FUN_00d56830(LeafReferenceTrial *source) {
    LeafReleaseCallbackTrial callback;
    if(source->kind&&--source->references==0) {
        callback=*source->vtable;
        callback(source,(void *)callback,1);
    }
}

typedef void (__fastcall *LeafReleaseNoStackTrial)(void *source,void *unused);
typedef struct LeafReference32Trial {LeafReleaseNoStackTrial *vtable;unsigned char prefix[0x18];int references;} LeafReference32Trial;

/* EXE: FUN_00ba0850:00ba0850..00ba0865. */
__declspec(noinline) void __fastcall FUN_00ba0850(LeafReference32Trial *source) {
    LeafReleaseNoStackTrial callback;
    if(source->references==1) {
        callback=source->vtable[5];
        callback(source,(void *)callback);
        return;
    }
    --source->references;
}

#ifndef MOVEMENT_LEAF_CALLBACKS_TRIAL
#define MOVEMENT_LEAF_CALLBACKS_TRIAL
typedef unsigned int (__cdecl *LeafAllocateCallbackTrial)(unsigned int second,unsigned int first);
typedef void (__cdecl *LeafFreeCallbackTrial)(unsigned int value);
typedef struct LeafCallbacksTrial {LeafAllocateCallbackTrial allocate;LeafFreeCallbackTrial release;} LeafCallbacksTrial;
extern LeafCallbacksTrial *DAT_0252a1e4;
#endif

/* EXE: FUN_00b8a2c0:00b8a2c0..00b8a2d9. */
__declspec(noinline) unsigned int __fastcall FUN_00b8a2c0(unsigned int first,unsigned int second) {
    LeafAllocateCallbackTrial callback;
    if(DAT_0252a1e4) {
        callback=DAT_0252a1e4->allocate;
        if(callback)return callback(second,first);
    }
    return 0;
}

#ifndef MOVEMENT_LEAF_CALLBACKS_TRIAL
#define MOVEMENT_LEAF_CALLBACKS_TRIAL
typedef unsigned int (__cdecl *LeafAllocateCallbackTrial)(unsigned int second,unsigned int first);
typedef void (__cdecl *LeafFreeCallbackTrial)(unsigned int value);
typedef struct LeafCallbacksTrial {LeafAllocateCallbackTrial allocate;LeafFreeCallbackTrial release;} LeafCallbacksTrial;
extern LeafCallbacksTrial *DAT_0252a1e4;
#endif

/* EXE: FUN_00b8a2e0:00b8a2e0..00b8a2f4. */
__declspec(noinline) void __fastcall FUN_00b8a2e0(unsigned int value) {
    LeafFreeCallbackTrial callback;
    if(DAT_0252a1e4) {
        callback=DAT_0252a1e4->release;
        if(callback)callback(value);
    }
}

#ifndef MOVEMENT_COMMAND_TRIAL
#define MOVEMENT_COMMAND_TRIAL
typedef struct MovementCommandQueueTrial {unsigned char prefix[8];unsigned char *cursor;} MovementCommandQueueTrial;
typedef struct MovementCommandRootTrial {unsigned char prefix[4];MovementCommandQueueTrial *queue;unsigned char gap[0x1c-8];int count;} MovementCommandRootTrial;
#endif

/* EXE: FUN_00cdfcb0:00cdfcb0..00cdfcd4. */
__declspec(noinline) void __fastcall FUN_00cdfcb0(MovementCommandRootTrial *source,void *unused,unsigned char active) {
    MovementCommandQueueTrial *queue=source->queue;
    unsigned int active_word=active!=0;
    unsigned int *command=(unsigned int *)queue->cursor;
    command[0]=1;
    command[2]=active_word;
    queue->cursor+=0x10;
    ++source->count;
}

#ifndef MOVEMENT_COMMAND_TRIAL
#define MOVEMENT_COMMAND_TRIAL
typedef struct MovementCommandQueueTrial {unsigned char prefix[8];unsigned char *cursor;} MovementCommandQueueTrial;
typedef struct MovementCommandRootTrial {unsigned char prefix[4];MovementCommandQueueTrial *queue;unsigned char gap[0x1c-8];int count;} MovementCommandRootTrial;
#endif

/* EXE: FUN_00cdfc80:00cdfc80..00cdfca5. */
__declspec(noinline) void __fastcall FUN_00cdfc80(MovementCommandRootTrial *source,void *unused,float value) {
    MovementCommandQueueTrial *queue=source->queue;
    unsigned char *command=queue->cursor;
    __declspec(align(8)) double widened=value;
    *(double *)(command+8)=widened;
    *(unsigned int *)command=3;
    queue->cursor+=0x10;
    ++source->count;
}

#include <math.h>

/* EXE: FUN_0049ee60:0049ee60..0049ee79. */
__declspec(noinline) float __cdecl FUN_0049ee60(float value) {
    __declspec(align(8)) double result=fabs(value);
    return (float)result;
}

typedef struct MovementRingNodeTrial {char reserved[20];struct MovementRingNodeTrial *next;} MovementRingNodeTrial;
typedef struct MovementRingRootTrial {char reserved[8];MovementRingNodeTrial *head;} MovementRingRootTrial;
typedef unsigned char (__cdecl *MovementRingCallbackTrial)(MovementRingNodeTrial *node);

/* EXE: FUN_00ba45c0:00ba45c0..00ba4601. */
__declspec(noinline) int __fastcall FUN_00ba45c0(MovementRingRootTrial *root, void *unused, MovementRingCallbackTrial callback) {
    int count;
    MovementRingNodeTrial *cursor;
    if(!callback)return 0;
    count=0;
    cursor=root->head;
    while(cursor) {
        if(!callback(cursor))break;
        cursor=cursor->next;
        ++count;
        if(cursor==root->head)break;
    }
    return count;
}

extern unsigned int DAT_02526360;
extern unsigned int DAT_02526368[];

/* EXE: FUN_00cdfd20:00cdfd20..00cdfd3d. */
__declspec(noinline) void __fastcall FUN_00cdfd20(unsigned int value) {
    if(value&&DAT_02526360<16) {
        DAT_02526368[DAT_02526360]=value;
        ++DAT_02526360;
    }
}

extern unsigned int DAT_0252a664;
extern unsigned int DAT_025268d8[];
extern unsigned int DAT_025268dc[];

/* EXE: FUN_00cdd1e0:00cdd1e0..00cdd20a. */
__declspec(noinline) unsigned int __fastcall FUN_00cdd1e0(void *unused, unsigned int key) {
    unsigned int index=0;
    unsigned int count=DAT_0252a664;
    if(count>0) {
        do {
            if(DAT_025268d8[index*2]==key)return DAT_025268dc[index*2];
            ++index;
        }
        while(index<count);
    }
    return 0;
}

extern int DAT_00e98818[];
extern unsigned char DAT_00e9881c[];
extern unsigned char DAT_0252740e;

/* EXE: FUN_0053d240:0053d240..0053d277. */
__declspec(noinline) void __fastcall FUN_0053d240(void *unused, int value) {
    unsigned int index=0;
    int *threshold=DAT_00e98818;
    do {
        if(value<*threshold)break;
        ++index;
        threshold+=4;
    }
    while(index<5);
    DAT_0252740e+=DAT_00e9881c[index*16];
    if(DAT_0252740e>24)DAT_0252740e=24;
}

#include <xmmintrin.h>
typedef struct __declspec(align(16)) MovementVectorRecordTrial {unsigned int *vtable;unsigned short reserved,kind;unsigned int zero,mode;float value;unsigned char gap[12];__m128 first,second;} MovementVectorRecordTrial;
extern unsigned int DAT_00e5542c[];

/* EXE: FUN_00d3ffb0:00d3ffb0..00d3ffff. */
__declspec(noinline) MovementVectorRecordTrial * __fastcall FUN_00d3ffb0(MovementVectorRecordTrial *source, void *unused, const __m128 *first, const __m128 *second, float value) {
    __m128 scalar=_mm_load_ss(&value);
    source->kind=1;
    source->zero=0;
    source->mode=6;
    _mm_store_ss(&source->value,scalar);
    source->vtable=DAT_00e5542c;
    source->first=*first;
    source->second=*second;
    _mm_store_ss(((float *)&source->first)+3,scalar);
    _mm_store_ss(((float *)&source->second)+3,scalar);
    return source;
}


/* EXE: FUN_00d94210:00d94210..00d9425d. */
__declspec(noinline) void __fastcall FUN_00d94210(__m128 *output, void *unused, const __m128 *matrix, const __m128 *vector) {
    __m128 input=*vector;
    __m128 y=_mm_mul_ps(_mm_shuffle_ps(input,input,0x55),matrix[1]);
    __m128 x=_mm_mul_ps(_mm_shuffle_ps(input,input,0),matrix[0]);
    __m128 z=_mm_mul_ps(_mm_shuffle_ps(input,input,0xaa),matrix[2]);
    *output=_mm_add_ps(_mm_add_ps(y,x),_mm_add_ps(z,matrix[3]));
}

typedef struct MovementRatioEntryTrial {int denominator,numerator;unsigned char reserved[0x88];} MovementRatioEntryTrial;
extern int DAT_0215d788;
extern MovementRatioEntryTrial DAT_02bc5b5c[];

/* EXE: FUN_00933f30:00933f30..00933f7b. */
__declspec(noinline) float __cdecl FUN_00933f30(void) {
    int numerator=0,denominator=0,count=DAT_0215d788;
    MovementRatioEntryTrial *entry;
    if(count>0) {
        entry=DAT_02bc5b5c;
        do {
            numerator+=entry->numerator;
            denominator+=entry->denominator;
            ++entry;
        }
        while(--count);
    }
    return (float)numerator/(float)denominator;
}

typedef struct MovementRatioNodeTrial {unsigned char flags;unsigned char reserved[15];struct MovementRatioNodeTrial *next;} MovementRatioNodeTrial;
extern MovementRatioNodeTrial *DAT_027a3fb4;

/* EXE: FUN_00626bf0:00626bf0..00626c42. */
__declspec(noinline) float __cdecl FUN_00626bf0(void) {
    int numerator=0,denominator=0;
    MovementRatioNodeTrial *head=DAT_027a3fb4,*cursor=head;
    while(cursor) {
        if(cursor->flags&2)++numerator;
        cursor=cursor->next;
        ++denominator;
        if(cursor==head)break;
    }
    return (float)numerator/(float)denominator;
}

/* EXE layout checks for the complete vector initializer and ratio loops. */
typedef char verify_vector_record_kind[(offsetof(MovementVectorRecordTrial,kind)==6)?1:-1];
typedef char verify_vector_record_first[(offsetof(MovementVectorRecordTrial,first)==0x20)?1:-1];
typedef char verify_vector_record_second[(offsetof(MovementVectorRecordTrial,second)==0x30)?1:-1];
typedef char verify_ratio_entry_stride[(sizeof(MovementRatioEntryTrial)==0x90)?1:-1];
typedef char verify_ratio_node_next[(offsetof(MovementRatioNodeTrial,next)==0x10)?1:-1];

typedef struct RequestedPredicate009b7880 {unsigned char pad[0xe88];int value;} RequestedPredicate009b7880;
typedef char verify_RequestedPredicate009b7880[(offsetof(RequestedPredicate009b7880,value)==0xe88)?1:-1];

/* EXE: FUN_009b7880:009b7880..009b7895. */
__declspec(noinline) unsigned char __cdecl FUN_009b7880(const RequestedPredicate009b7880 *source) { 
    if (!source)
        return 0;
    return (unsigned char)(source->value!=0);
 }

typedef struct RequestedPredicate00997d50 {unsigned char pad[0x591];unsigned char value;} RequestedPredicate00997d50;
typedef char verify_RequestedPredicate00997d50[(offsetof(RequestedPredicate00997d50,value)==0x591)?1:-1];

/* EXE: FUN_00997d50:00997d50..00997d65. */
__declspec(noinline) unsigned char __cdecl FUN_00997d50(const RequestedPredicate00997d50 *source) { 
    if (!source)
        return 0;
    return (unsigned char)(source->value==5);
 }

typedef struct RequestedPredicate00999280 {unsigned char pad[0x591];unsigned char value;} RequestedPredicate00999280;
typedef char verify_RequestedPredicate00999280[(offsetof(RequestedPredicate00999280,value)==0x591)?1:-1];

/* EXE: FUN_00999280:00999280..00999295. */
__declspec(noinline) unsigned char __cdecl FUN_00999280(const RequestedPredicate00999280 *source) { 
    if (!source)
        return 0;
    return (unsigned char)(source->value==6);
 }

typedef struct RequestedPredicate00999ee0 {unsigned char pad[0x591];unsigned char value;} RequestedPredicate00999ee0;
typedef char verify_RequestedPredicate00999ee0[(offsetof(RequestedPredicate00999ee0,value)==0x591)?1:-1];

/* EXE: FUN_00999ee0:00999ee0..00999ef5. */
__declspec(noinline) unsigned char __cdecl FUN_00999ee0(const RequestedPredicate00999ee0 *source) { 
    if (!source)
        return 0;
    return (unsigned char)(source->value==4);
 }


/* EXE: FUN_00604580:00604580..006045a5. */
__declspec(noinline) int __cdecl FUN_00604580(void) { 
    int value;
    MovementVirtualObjectView *object;
    if (!DAT_02527888)
        goto no;
    object=DAT_02527888->field_0008;
    value=object->field_0000->field_0008(object);
    if (value!=12 && value!=3)
        goto no;
    return 1;
no:
    return 0;
 }

typedef struct MovementChainView {
    int field_0000;
    struct MovementChainView *field_0004;
} MovementChainView;
extern MovementChainView *DAT_0213b4f8;
extern int DAT_0213c444;
extern unsigned char DAT_027a6a40;
extern int __cdecl FUN_004f56e0(void);
/* Native 004F5FB5..004F5FBA leaves the virtual table in EDX and object in ECX.
 * call_context preserves that observed register value; whether the runtime
 * virtual target reads EDX is not established by this caller certificate. */
typedef int (__fastcall *NativeContextQuery)(MovementVirtualObjectView *object, MovementVirtualTableView *call_context);

/* EXE: FUN_004f5f20:004f5f20..004f5fdb. */
__declspec(noinline) void __cdecl FUN_004f5f20(MovementFieldsView *source) { 
    MovementChainView *chain;
    MovementModeView *mode;
    MovementVirtualObjectView *object;
    source->field_139c = 3;
    source->field_13a0 = 1;
    source->field_13a4 = 0x18001;
    source->field_13a8 = 0;
    source->field_13ac = 0x208;
    if (FUN_005f9950(DAT_027a0840)) source->field_13ac |= 0x80;
    if (DAT_00e96c00 == 13 && DAT_0213c444 == 1 && DAT_0213b4f8) {
        chain = DAT_0213b4f8->field_0004;
        if (chain) {
            chain = chain->field_0004;
            if (chain && chain->field_0004->field_0000 == 2) goto apply_flags;
        }
    }
    mode = (MovementModeView *)DAT_027b3c60;
    if (mode && mode->field_003c == 1) {
        object = mode->field_0090;
        if (((NativeContextQuery)object->field_0000->field_0004)(object,object->field_0000) == 4) goto apply_flags;
    }
    if (!(DAT_027a6a40 & 1)) return;
apply_flags:
    source->field_13a4 = FUN_004f56e0() | 0x1000200;
 }

/* EXE: 004f5e80..004f5f19. The restricted destination permits the
 * observed global comparison before destination stores. Original caller bytes
 * are the certificate; arbitrary aliased invocation is not established.
 * NativeContextQuery retains ECX object / EDX vtable at the indirect call. */
__declspec(noinline) void __cdecl FUN_004f5e80(MovementFieldsView *__restrict source) {
    MovementChainView *chain;
    MovementModeView *mode;
    MovementVirtualObjectView *object;
    source->field_139c = 3;
    source->field_13a0 = 1;
    source->field_13a4 = 0;
    source->field_13a8 = 0;
    source->field_13ac = 0;
    if (DAT_00e96c00 == 13 && DAT_0213c444 == 1 && DAT_0213b4f8) {
        chain = DAT_0213b4f8->field_0004;
        if (chain) {
            chain = chain->field_0004;
            if (chain && chain->field_0004->field_0000 == 2) goto apply_flags;
        }
    }
    mode = (MovementModeView *)DAT_027b3c60;
    if (mode && mode->field_003c == 1) {
        object = mode->field_0090;
        if (((NativeContextQuery)object->field_0000->field_0004)(object,object->field_0000) == 4) goto apply_flags;
    }
    if (!(DAT_027a6a40 & 1)) return;
apply_flags:
    source->field_13a4 |= FUN_004f56e0() | 0x1000200;
}

typedef struct RequestedHandleSource {unsigned char unknown_0000[0xd74]; unsigned int handle_d74;} RequestedHandleSource;
typedef struct RequestedVehicleName {unsigned char unknown_0000[0x84e4]; char *name_record;} RequestedVehicleName;
typedef char verify_requested_handle_d74[(offsetof(RequestedHandleSource,handle_d74)==0xd74)?1:-1];
typedef char verify_requested_name_record[(offsetof(RequestedVehicleName,name_record)==0x84e4)?1:-1];
extern unsigned char DAT_0252726b;
extern char DAT_00ddeb94;
extern char DAT_00ddeba8;
extern void __cdecl FUN_004f6c90(MovementFieldsView *source);
extern int __cdecl FUN_00c99030(const char *left, const char *right);

static __forceinline MovementHandleObjectView *movement_flags_resolve_kind_five(unsigned int handle)
{
    MovementHandleObjectView *vehicle;
    vehicle = handle ? DAT_02149c64[handle & 0xfff].object : 0;
    if (!vehicle || vehicle->field_0044 != handle)
        vehicle = 0;
    if (vehicle && vehicle->field_004c != 5)
        vehicle = 0;
    return vehicle;
}

/* EXE: 004f68e0..004f69c1; whole body, ordinary stack arguments.
 * Handle lookup fields and branch order are checked against the original bytes. */
__declspec(noinline) void __cdecl FUN_004f68e0(MovementFieldsView *object)
{
    MovementHandleObjectView *vehicle;
    unsigned int handle;

    if (DAT_0252726b)
        return;
    DAT_0252726b = 1;
    FUN_004f6c90(object);
    object->field_13a8 &= 0xfffffbffu;
    handle = ((RequestedHandleSource *)DAT_021703d4)->handle_d74;
    DAT_0252726b = 0;

    vehicle = movement_flags_resolve_kind_five(handle);
    if (vehicle &&
        FUN_00c99030(&DAT_00ddeb94,
            ((RequestedVehicleName *)vehicle)->name_record + 0x80) == 0 &&
        FUN_00c99030(&DAT_00ddeba8,
            ((RequestedVehicleName *)vehicle)->name_record + 0x80) == 0)
        goto preserve_flag;
    object->field_13a8 &= 0xfffffdffu;

preserve_flag:
    object->field_13a8 &= 0xfffef7fcu;
    object->field_13a4 &= 0xfffffd06u;
    if (vehicle)
        object->field_13ac &= 0xfffdffffu;
    else
        object->field_13ac |= 0x20000;
}

#include <intrin.h>
#pragma intrinsic(_ReadWriteBarrier)
typedef struct MovementPredicateAction {unsigned char prefix[0x34];int field_0034;} MovementPredicateAction;
typedef struct MovementPredicatePropertyFlags {unsigned char prefix[8];MovementPredicateAction *field_0008;unsigned char gap;unsigned char field_000d;} MovementPredicatePropertyFlags;
typedef struct MovementPredicateProperty {unsigned char prefix[0xc4];MovementPredicatePropertyFlags *field_00c4;} MovementPredicateProperty;
typedef struct MovementPredicatePropertyRoot {unsigned char prefix[0x10cc];MovementPredicateProperty *field_10cc;} MovementPredicatePropertyRoot;
typedef char verify_probe_action[(offsetof(MovementPredicateAction,field_0034)==0x34)?1:-1];
typedef char verify_probe_flags[(offsetof(MovementPredicatePropertyFlags,field_000d)==0xd)?1:-1];
static __forceinline unsigned char movement_property_kind_five(
    const MovementPredicateAction *action)
{
    unsigned char result;
    result = (unsigned char)(action->field_0034 == 5);
    _ReadWriteBarrier();
    return result;
}

/* EXE: 004f5d90..004f5e72. Complete native body.
 * Compiler barrier preserves the materialized byte predicate; emits no instruction. */
void __cdecl FUN_004f5d90(MovementFieldsView *__restrict source) {
    
    MovementChainView *chain;
    MovementModeView *mode;
    MovementVirtualObjectView *object;
    MovementPredicateProperty *property;
    MovementPredicatePropertyFlags *flags;
    source->field_139c = 3;
    source->field_13a0 = 1;
    source->field_13a4 = 0x10000;
    source->field_13a8 = 0;
    source->field_13ac = 0;
    if (DAT_00e96c00 == 13 && DAT_0213c444 == 1 && DAT_0213b4f8) {
        chain = DAT_0213b4f8->field_0004;
        if (chain) {
            chain = chain->field_0004;
            if (chain && chain->field_0004->field_0000 == 2) goto apply_flags;
        }
    }
    mode = (MovementModeView *)DAT_027b3c60;
    if (mode && mode->field_003c == 1) {
        object = mode->field_0090;
        if (((NativeContextQuery)object->field_0000->field_0004)(object, object->field_0000) == 4) goto apply_flags;
    }
    if (!(DAT_027a6a40 & 1)) goto check_property;
apply_flags:
    source->field_13a4 |= FUN_004f56e0() | 0x1000200;
check_property:
    source->field_13ac = 8;
    property = ((MovementPredicatePropertyRoot *)source)->field_10cc;
    if (property) {
        flags = property->field_00c4;
        if (flags && flags->field_0008 && movement_property_kind_five(flags->field_0008) && (flags->field_000d & 2))
            source->field_13a4 |= 0x200;
    }
}


extern void __cdecl FUN_004f7e90(void);
extern void __cdecl FUN_004f9380(void);
extern void __cdecl FUN_004f9c80(void);
extern void __cdecl FUN_009f1d00(void);
extern void __fastcall FUN_004f82c0(void *source);
/* EXE: FUN_004faa90:004faa90..004faad9. */
__declspec(noinline) void __cdecl FUN_004faa90(void *argument) {
    MovementFieldsView *source = (MovementFieldsView *)DAT_021703d4;
    unsigned int flags;
    __declspec(align(8)) unsigned int stack_alignment;

    /* This true alignment assumption retains the native 8-byte stack frame.
     * It reads no uninitialized value and emits no runtime instruction.
     * This is a matching translation, not a claim about the original source. */
    __assume(((unsigned int)&stack_alignment & 7u) == 0);
    FUN_004f7e90();
    flags = source->field_139c;
    if (flags & 2) FUN_004f9380();
    else if (flags & 4) FUN_004f9c80();
    else FUN_009f1d00();
    if (source->field_139c & 1) FUN_004f82c0(argument);
}


typedef struct MovementValidityView {
    unsigned char unknown_0000[0x44];
    unsigned int field_0044;
    unsigned char unknown_0048[0xf8c - 0x48];
    int field_0f8c;
    unsigned char unknown_0f90[0x1124 - 0xf90];
    float field_1124;
} MovementValidityView;
typedef char verify_validity_handle[(offsetof(MovementValidityView, field_0044) == 0x44) ? 1 : -1];
typedef char verify_validity_state[(offsetof(MovementValidityView, field_0f8c) == 0xf8c) ? 1 : -1];
typedef char verify_validity_scalar[(offsetof(MovementValidityView, field_1124) == 0x1124) ? 1 : -1];

static __forceinline MovementHandleObjectView *movement_validity_resolve(unsigned int handle)
{
    MovementHandleObjectView *object;

    if (!handle) return 0;
    object = DAT_02149c64[handle & 0xfff].object;
    if (!object || object->field_0044 != handle) return 0;
    return object;
}

/* EXE: FUN_00985630:00985630..0098567b. Complete original body.
 * The <= comparison preserves the native unordered (NaN) path. */
__declspec(noinline) unsigned char __cdecl FUN_00985630(const MovementValidityView *source)
{
    MovementHandleObjectView *resolved;

    if (!source) goto valid;
    resolved = movement_validity_resolve(source->field_0044);
    if ((const void *)resolved != source) goto valid;
    if (source->field_1124 <= 0.0f) goto valid;
    return (unsigned char)(source->field_0f8c >= 0);

valid:
    return 1;
}
