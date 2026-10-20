/* Recovered caller context. Both complete bodies are rechecked in each LTCG image.
 * These ordinary-gate originals are not counted again here. */
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
/* EXE: FUN_0098e710:0098e710..0098e74b. EDX input. */
__declspec(noinline) MovementHandleObjectView * __fastcall FUN_0098e710(void *unused, MovementHandleObjectView *source) {
    unsigned int handle;
    MovementHandleObjectView *object;
    if (!source) return 0;
    handle = source->field_02a4;
    if (handle) {
        object = (MovementHandleObjectView *)DAT_02149c64[handle & 0xfff].object;
        if (object && object->field_0044 == handle && object->field_004c == 1 &&
            !(object->field_0080 & 0xb)) return object;
    }
    return source;
}

/* EXE: FUN_0098e750:0098e750..0098e7bd. EDX input. */
__declspec(noinline) MovementHandleObjectView * __fastcall FUN_0098e750(void *unused, MovementHandleObjectView *source) {
    unsigned int handle;
    MovementHandleObjectView *object;
    if (!source) return 0;
    handle = source->field_02a8;
    if (handle) {
        object = (MovementHandleObjectView *)DAT_02149c64[handle & 0xfff].object;
        if (object && object->field_0044 == handle && object->field_004c == 1 &&
            !(object->field_0080 & 0xb)) return object;
    }
    handle = source->field_02a4;
    if (handle) {
        object = (MovementHandleObjectView *)DAT_02149c64[handle & 0xfff].object;
        if (object && object->field_0044 == handle && object->field_004c == 1 &&
            !(object->field_0080 & 0xb)) return object;
    }
    return source;
}

/* Layout evidence: original callee field operands. */
typedef char verify_relation_context_field_0044[(offsetof(MovementHandleObjectView,field_0044)==0x44)?1:-1];
typedef char verify_relation_context_field_004c[(offsetof(MovementHandleObjectView,field_004c)==0x4c)?1:-1];
typedef char verify_relation_context_field_0080[(offsetof(MovementHandleObjectView,field_0080)==0x80)?1:-1];
typedef char verify_relation_context_field_02a4[(offsetof(MovementHandleObjectView,field_02a4)==0x2a4)?1:-1];
typedef char verify_relation_context_field_02a8[(offsetof(MovementHandleObjectView,field_02a8)==0x2a8)?1:-1];
typedef char verify_relation_context_field_03cc[(offsetof(MovementHandleObjectView,field_03cc)==0x3cc)?1:-1];
