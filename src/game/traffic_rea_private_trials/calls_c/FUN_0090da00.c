/* FUN_0090da00: returns 0 when bit 0x20 of byte object+0x22 is set, when FUN_0090d720(object) is
   zero or FUN_0090d9b0(object) is non-zero; otherwise whether FUN_0090cf10(distance, object) is
   zero, distance being the float at +0x10 of the record at (record at object+0x30)+4. */
unsigned char FUN_0090d720(unsigned char *object);
unsigned char FUN_0090d9b0(unsigned char *object);
unsigned char FUN_0090cf10(float distance, unsigned char *object);
__declspec(noinline) unsigned char FUN_0090da00(unsigned char *object)
{
    if ((object[0x22] & 0x20) != 0) {
        return 0;
    }
    if (FUN_0090d720(object) == 0) {
        return 0;
    }
    if (FUN_0090d9b0(object) != 0) {
        return 0;
    }
    if (FUN_0090cf10(*(float *)(*(int *)(*(int *)(object + 0x30) + 4) + 0x10), object) != 0) {
        return 0;
    }
    return 1;
}
