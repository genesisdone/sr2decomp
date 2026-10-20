/* REA ev_bbf89cf09c87406da26c22a8e2beb9be12abdd04502c0098664a82cc25e05c40.
 * Complete 006d9090..006d90b2 inclusive, 35 bytes. Both float stores and
 * the shared double operand come from REA's native assembly. REA byte
 * evidence ev_e300b8a39cc6185e19070116ee740e36c6d9bf8aba02b3ad7c35e98e1162b300
 * observes 1800.0 at 00e5c2d0. const models that read-only operand for this
 * recovery; it does not establish the original source declaration. */
extern float DAT_027e6714, DAT_027e6700;
extern const double DAT_00e5c2d0;
__declspec(noinline) void __cdecl FUN_006d9090(void)
{
    DAT_027e6714 = (float)(DAT_027e6714 + DAT_00e5c2d0);
    DAT_027e6700 = (float)(DAT_027e6700 + DAT_00e5c2d0);
    return;
}
