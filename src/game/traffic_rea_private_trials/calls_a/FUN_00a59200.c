/* FUN_00a59200: returns 0 when object is null; otherwise whether point lies inside the box
   (object+4 .. object+0x10, FUN_00be9830) and FUN_00bfd510 holds for the record at object+0x1c
   and limit DAT_00dd0970. */
extern float DAT_00dd0970;
unsigned char FUN_00be9830(const float *point, const float *lower, const float *upper);
unsigned char FUN_00bfd510(const unsigned char *record, const float *point, float limit);
__declspec(noinline) unsigned char FUN_00a59200(unsigned char *object, const float *point)
{
    if (object == 0) {
        return 0;
    }
    return FUN_00be9830(point, (const float *)(object + 4), (const float *)(object + 0x10)) &&
           FUN_00bfd510(*(const unsigned char **)(object + 0x1c), point, DAT_00dd0970);
}
