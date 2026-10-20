/* Complete 006d7aa0..006d7aea. Native imports remain call boundaries:
 * DB8400 = BinkGoto@12; DB83D0 = BinkPause@8. No Bink code is translated.
 * The movie global is read twice on the seek path: once for the test and
 * seek (ECX), once into the register kept for the unpause (ESI).
 */
typedef struct CsMovieFrameOption { unsigned int unknown_00[2]; float value; } CsMovieFrameOption;
extern void *DAT_0140e670;
extern int (__stdcall *DAT_00db8400)(void *movie, int frame, int flags);
extern int (__stdcall *DAT_00db83d0)(void *movie, int paused);
__declspec(noinline) void __cdecl FUN_006d7aa0(const CsMovieFrameOption *option)
{
    int frame = (int)option->value;
    void *movie;
    if (frame >= 1) {
        void *current = DAT_0140e670;
        movie = DAT_0140e670;
        if (current) {
            DAT_00db8400(current,frame,1);
            DAT_00db83d0(movie,0);
        }
    } else if (frame < 0) {
        movie = DAT_0140e670;
        if (movie)
            DAT_00db83d0(movie,1);
    }
}
