/* REA ev_d2fcdc2dda6d4ffc8fad2035bfdfc86b8f121a824fc71cadcdfad6a3045f35fd; logical C interface, not a callable native ABI declaration. */
struct Matrix { unsigned int words[9]; };
extern struct Matrix DAT_025f5b5c;
extern struct Matrix DAT_025f5b38;
__declspec(noinline) void FUN_00493c10(const struct Matrix *matrix)
{
    DAT_025f5b5c = *matrix;
    DAT_025f5b38 = *matrix;
}
