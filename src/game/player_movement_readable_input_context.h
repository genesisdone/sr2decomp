/* NOT MATCHED: full C callees used only to investigate private input-call ABI.
 * These bodies contribute no certified functions or bytes. EXE exports:
 * 004fd510, 004fd540, 004ffe60. No comparison image is executed. */
typedef RequestedInputBinding RequestedInputPair;
typedef char verify_input_pair_size[(sizeof(RequestedInputPair)==16)?1:-1];
typedef char verify_input_pair_secondary[(offsetof(RequestedInputPair,secondary)==8)?1:-1];
typedef char verify_input_pair_secondary_invert[(offsetof(RequestedInputPair,secondary_invert)==12)?1:-1];
extern float DAT_02659908[];
extern float DAT_0265990c[];

__declspec(noinline) float __cdecl FUN_004fd510(unsigned int index) {
    volatile float result;
    if(DAT_0265992c[index*40]) result=0.0f;
    else result=DAT_02659908[index*10];
    return result;
}
__declspec(noinline) float __cdecl FUN_004fd540(unsigned int index) {
    volatile float result;
    if(DAT_0265992d[index*40]) result=0.0f;
    else result=DAT_0265990c[index*10];
    return result;
}
__declspec(noinline) float __cdecl FUN_004ffe60(unsigned int index) {
    const RequestedInputPair *binding=&DAT_00f9f278[index];
    float result=0.0f;
    switch(binding->kind) {
    case 0:result=FUN_004fd510(1);break;
    case 1:result=FUN_004fd540(1);break;
    case 2:result=FUN_004fd510(0);break;
    case 3:result=FUN_004fd540(0);break;
    case 4:result=FUN_004fd510(5);break;
    case 5:result=FUN_004fd540(5);break;
    case 6:result=FUN_004fd540(3);break;
    case 7:result=FUN_004fd540(4);break;
    case 8:result=FUN_004fd510(3);break;
    case 9:result=FUN_004fd510(4);break;
    case 10:result=FUN_004fd510(6);break;
    case 11:result=FUN_004fd540(6);break;
    default:goto secondary;
    }
    if(result==0.0f) {
secondary:
        switch(binding->secondary) {
        case 0:result=FUN_004fd510(1);break;
        case 1:result=FUN_004fd540(1);break;
        case 2:result=FUN_004fd510(0);break;
        case 3:result=FUN_004fd540(0);break;
        }
        if(binding->secondary_invert) result=-result;
    } else if(binding->primary_invert) result=-result;
    return result;
}
