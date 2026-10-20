/* FUN_0093a6f0: source in a register. Computes FUN_00c04110(source[0], &source[1]) (a float) and
   passes source[0] and that value, with two zero words, to FUN_0093a2e0. The double temporary
   reproduces native's x87 round-trip of the SSE float return. */
float __stdcall FUN_00c04110(int first, const unsigned int *rest);
void FUN_0093a2e0(int id, float value, int zero_a, int zero_b);
__declspec(noinline) void FUN_0093a6f0(const unsigned int *source)
{
    int id = (int)source[0];
    double result = FUN_00c04110(id, source + 1);
    FUN_0093a2e0(id, (float)result, 0, 0);
}
