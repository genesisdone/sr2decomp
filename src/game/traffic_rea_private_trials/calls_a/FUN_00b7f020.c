/* FUN_00b7f020: forwards to FUN_00a8a7b0 with its two leading inputs swapped, the two floats plus
   the global float DAT_00e86fb8, the global word DAT_0252a194 and two 3-float vectors, and returns
   the word FUN_00a8a7b0 writes through its out pointer. */
extern float DAT_00e86fb8;
extern int DAT_0252a194;
void FUN_00a8a7b0(int first, int second, float x, float y, float z, int word, const float *a,
                  const float *b, int *out);
__declspec(noinline) int FUN_00b7f020(int first, int second, const float *b, const float *a, float x,
                                     float y)
{
    const float **keep_a = &a;
    const float **keep_b = &b;
    float *keep_x = &x;
    float *keep_y = &y;
    int result;
    (void)keep_a;
    (void)keep_b;
    (void)keep_x;
    (void)keep_y;
    FUN_00a8a7b0(second, first, x, y, DAT_00e86fb8, DAT_0252a194, a, b, &result);
    return result;
}
