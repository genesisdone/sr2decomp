/* FUN_00b27550: copies three words from source into object+0x3d0, +0x3d4 and +0x3d8, stores value
   at object+0x3dc, then calls FUN_00b2b9f0(object, 1). */
void __stdcall FUN_00b2b9f0(unsigned char *object, int flag);
__declspec(noinline) void FUN_00b27550(unsigned char *object, unsigned int *source, float value)
{
    float *keep_value = &value;
    (void)keep_value;
    *(unsigned int *)(object + 0x3d0) = source[0];
    *(unsigned int *)(object + 0x3d4) = source[1];
    *(unsigned int *)(object + 0x3d8) = source[2];
    *(float *)(object + 0x3dc) = value;
    FUN_00b2b9f0(object, 1);
}
