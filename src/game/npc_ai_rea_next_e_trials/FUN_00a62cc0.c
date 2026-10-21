/* FUN_00a62cc0: scalar deleting destructor. Runs FUN_00a62d00 on the object; when bit 0 of `flags` is set, the object is
   non-null and DAT_02527bf7 != 1, frees it with FUN_00cde870 inside the critical section DAT_0347ade4 (import
   slots DAT_00db80cc EnterCriticalSection, DAT_00db80d0 LeaveCriticalSection). Returns the object.
   Native is a thiscall with one stack word (ret 4). It is written as __fastcall with an EDX parameter the body
   never reads, which gives the same callee code; this is a representation choice, not a source-ABI claim. The DAT_02527bf7 byte is declared volatile because native loads
   it into a register before comparing; whether SR2 declared it volatile is an unconfirmed hypothesis. The two import
   calls are audited literal import-table CALLs. */
typedef void (__stdcall *critical_section_call)(void *section);
extern critical_section_call DAT_00db80cc;
extern critical_section_call DAT_00db80d0;
extern unsigned char DAT_0347ade4[24];
extern volatile char DAT_02527bf7;
void __fastcall FUN_00a62d00(int object);
void FUN_00cde870(int block);

__declspec(noinline) int __fastcall FUN_00a62cc0(int object, int unused_edx, unsigned int flags)
{
	FUN_00a62d00(object);
	if ((flags & 1) == 0 || object == 0) {
		return object;
	}
	if (DAT_02527bf7 != 1) {
		DAT_00db80cc(DAT_0347ade4);
		FUN_00cde870(object);
		DAT_00db80d0(DAT_0347ade4);
	}
	return object;
}
