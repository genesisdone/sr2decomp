/* EXE: FUN_00a2d8a0; complete readable C trial.
 * Matching status is determined only by reports/npc-ai-readable-match.json.
 * Evidence: .ghidra-exports/00a2d8a0.json and original native bytes.
 * No inferred field names: offsets are retained. */
extern int DAT_02528400;
extern unsigned int DAT_029dc318[];
__declspec(noinline) int __cdecl FUN_00a2d8a0(void)
{
    unsigned int *record;
    int remaining = DAT_02528400;
    if (remaining > 0) {
        record = DAT_029dc318;
        do {
            *record = 1;
            record += 0xeb;
            remaining -= 1;
        } while (remaining != 0);
    }
    return 0;
}
