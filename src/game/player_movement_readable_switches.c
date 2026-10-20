#include <stddef.h>
/* Readable C. Comparison images are never executed. */

/* EXE: FUN_00989a50; cases independently checked from original tables. */
__declspec(noinline) unsigned char __cdecl FUN_00989a50(unsigned int value) {
    switch (value) {
    case 0x181:
    case 0x182:
    case 0x185:
    case 0x186:
    case 0x187:
    case 0x188:
    case 0x18a:
    case 0x18b:
        return 1;
    default:
        return 0;
    }
}

/* EXE: FUN_00994cc0; cases independently checked from original tables. */
__declspec(noinline) unsigned char __cdecl FUN_00994cc0(unsigned int value) {
    switch (value) {
    case 0xa:
    case 0xb:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x89:
    case 0x8b:
        return 1;
    default:
        return 0;
    }
}

/* EXE: FUN_00b72800; cases independently checked from original tables. */
typedef struct Switch34View { unsigned char pad[0x34]; unsigned int kind; } Switch34View;
__declspec(noinline) unsigned char __cdecl FUN_00b72800(const Switch34View *source) {
    if (!source) return 0;
    switch (source->kind) {
    case 0x0:
    case 0x1:
    case 0x2:
    case 0x3:
    case 0x4:
    case 0x8:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x14:
    case 0x16:
        return 1;
    default:
        return 0;
    }
}

/* EXE: FUN_0096dcf0; cases independently checked from original tables. */
typedef struct Switch164View { unsigned char pad[0x164]; unsigned int kind; } Switch164View;
typedef struct Switch5E0Root { unsigned char pad[0x5e0]; const Switch164View *nested; } Switch5E0Root;
__declspec(noinline) unsigned char __cdecl FUN_0096dcf0(const Switch5E0Root *source) {
    switch (source->nested->kind) {
    case 0x76:
    case 0x77:
    case 0x134:
    case 0x135:
    case 0x136:
    case 0x137:
    case 0x138:
    case 0x139:
        return 1;
    default:
        return 0;
    }
}

typedef char check_switch34[(offsetof(Switch34View,kind)==0x34)?1:-1];
typedef char check_switch164[(offsetof(Switch164View,kind)==0x164)?1:-1];
typedef char check_switch_root[(offsetof(Switch5E0Root,nested)==0x5e0)?1:-1];

/* EXE: FUN_009c4060; cases verified from original tables. */

typedef struct SwitchLink8 { unsigned char pad[8]; const Switch34View *object; } SwitchLink8;
typedef struct SwitchLinkC4 { unsigned char pad[0xc4]; const SwitchLink8 *nested; } SwitchLinkC4;
typedef struct SwitchLink10CC { unsigned char pad[0x10cc]; const SwitchLinkC4 *nested; } SwitchLink10CC;
__declspec(noinline) int __cdecl FUN_009c4060(const SwitchLink10CC *source) {
    const SwitchLinkC4 *first;
    const SwitchLink8 *second;
    const Switch34View *object;
    if (!source) return 0;
    first = source->nested;
    if (!first) return 0;
    second = first->nested;
    if (!second) return 0;
    object = second->object;
    if (!object) return 0;
    switch (object->kind) {
    case 0x6:
    case 0x7:
    case 0x9:
    case 0xa:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x13:
        return 1;
    default:
        return 0;
    }
}

/* EXE: FUN_00970a70; field offsets and case destinations read from original code. */
typedef struct ShortSelectionFields {
    unsigned char gap_0000[0x806];
    short field_0806;
    unsigned char gap_0808[0x2];
    short field_080a;
    unsigned char gap_080c[0x498];
    short field_0ca4;
    short field_0ca6;
    short field_0ca8;
    short field_0caa;
    unsigned char gap_0cac[0x4];
    short field_0cb0;
    short field_0cb2;
    unsigned char gap_0cb4[0x6];
    short field_0cba;
    short field_0cbc;
    short field_0cbe;
    unsigned char gap_0cc0[0xa];
    short field_0cca;
    short field_0ccc;
    unsigned char gap_0cce[0x8];
    short field_0cd6;
    short field_0cd8;
    unsigned char gap_0cda[0xc];
    short field_0ce6;
    short field_0ce8;
} ShortSelectionFields;
__declspec(noinline) int __cdecl FUN_00970a70(const ShortSelectionFields *source, unsigned int selector) {
    switch (selector) {
    case 1:
        return source->field_0ca4;
    case 0:
        return source->field_0ca6;
    case 2:
        return source->field_0ccc;
    case 3:
        return source->field_0cca;
    case 4:
        return source->field_0cd6;
    case 5:
        return source->field_0cd8;
    case 6:
        return source->field_080a;
    case 7:
        return source->field_0806;
    case 8:
    case 10:
        return source->field_0ce8;
    case 9:
    case 11:
        return source->field_0ce6;
    case 12:
        return source->field_0cb0;
    case 13:
        return source->field_0ca8;
    case 14:
        return source->field_0cbe;
    case 15:
        return source->field_0cb2;
    case 16:
        return source->field_0cba;
    case 17:
        return source->field_0cbc;
    case 18:
        return source->field_0caa;
    default:
        return -1;
    }
}

typedef char check_link8[(offsetof(SwitchLink8,object)==8)?1:-1];
typedef char check_linkc4[(offsetof(SwitchLinkC4,nested)==0xc4)?1:-1];
typedef char check_link10cc[(offsetof(SwitchLink10CC,nested)==0x10cc)?1:-1];
typedef char check_short_0806[(offsetof(ShortSelectionFields,field_0806)==0x0806)?1:-1];
typedef char check_short_080a[(offsetof(ShortSelectionFields,field_080a)==0x080a)?1:-1];
typedef char check_short_0ca4[(offsetof(ShortSelectionFields,field_0ca4)==0x0ca4)?1:-1];
typedef char check_short_0ca6[(offsetof(ShortSelectionFields,field_0ca6)==0x0ca6)?1:-1];
typedef char check_short_0ca8[(offsetof(ShortSelectionFields,field_0ca8)==0x0ca8)?1:-1];
typedef char check_short_0caa[(offsetof(ShortSelectionFields,field_0caa)==0x0caa)?1:-1];
typedef char check_short_0cb0[(offsetof(ShortSelectionFields,field_0cb0)==0x0cb0)?1:-1];
typedef char check_short_0cb2[(offsetof(ShortSelectionFields,field_0cb2)==0x0cb2)?1:-1];
typedef char check_short_0cba[(offsetof(ShortSelectionFields,field_0cba)==0x0cba)?1:-1];
typedef char check_short_0cbc[(offsetof(ShortSelectionFields,field_0cbc)==0x0cbc)?1:-1];
typedef char check_short_0cbe[(offsetof(ShortSelectionFields,field_0cbe)==0x0cbe)?1:-1];
typedef char check_short_0cca[(offsetof(ShortSelectionFields,field_0cca)==0x0cca)?1:-1];
typedef char check_short_0ccc[(offsetof(ShortSelectionFields,field_0ccc)==0x0ccc)?1:-1];
typedef char check_short_0cd6[(offsetof(ShortSelectionFields,field_0cd6)==0x0cd6)?1:-1];
typedef char check_short_0cd8[(offsetof(ShortSelectionFields,field_0cd8)==0x0cd8)?1:-1];
typedef char check_short_0ce6[(offsetof(ShortSelectionFields,field_0ce6)==0x0ce6)?1:-1];
typedef char check_short_0ce8[(offsetof(ShortSelectionFields,field_0ce8)==0x0ce8)?1:-1];

/* EXE: FUN_00b72740; original targets 00b72764 and indices 00b7276c. */
__declspec(noinline) unsigned char __cdecl FUN_00b72740(const Switch34View *source) {
 if(!source) return 0;
 switch(source->kind) {
 case 6:
 case 7:
 case 9:
 case 10:
 case 11:
 case 12:
 case 13:
 case 14:
 case 19:
 return 1;
 default: return 0;
 }
}

typedef struct RequestedInputBinding {
    unsigned int kind;
    unsigned char primary_invert;
    unsigned char unknown_5[3];
    unsigned int secondary;
    unsigned char secondary_invert;
    unsigned char unknown_d[3];
} RequestedInputBinding;
extern RequestedInputBinding DAT_00f9f278[];
extern unsigned char DAT_02659954[];
extern unsigned char DAT_02659955[];
extern unsigned char DAT_0265992c[];
extern unsigned char DAT_0265992d[];
typedef char verify_requested_input_binding[(sizeof(RequestedInputBinding)==16)?1:-1];
/* EXE: FUN_00500230:00500230..00500264; complete original and owned local table. */
__declspec(noinline) void __cdecl FUN_00500230(unsigned int index) {
    switch(DAT_00f9f278[index].kind) {
    case 0:DAT_02659954[0]=1;return;
    case 1:DAT_02659955[0]=1;return;
    case 2:DAT_0265992c[0]=1;return;
    case 3:DAT_0265992d[0]=1;
    }
}
