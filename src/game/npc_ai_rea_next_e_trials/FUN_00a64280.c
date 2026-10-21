/* FUN_00a64280: scalar deleting destructor. Sets the object's vtable to DAT_00e435b4 and clears +0x18, runs the base destructor
   FUN_00a629f0; when bit 0 of `flags` is set and DAT_02527bf7 != 1, frees the object with FUN_00cde870 inside the
   critical section DAT_0347ade4 (import slots DAT_00db80cc EnterCriticalSection, DAT_00db80d0
   LeaveCriticalSection). Returns the object. Native is a thiscall with one stack word (ret 4), written as
   __fastcall with an unused EDX word (the usual C spelling, not a source-ABI claim). The DAT_02527bf7 byte is
   declared volatile because native loads it into a register before comparing; whether SR2 declared it volatile is
   an unconfirmed hypothesis. The two import calls are audited literal import-table CALLs. */
typedef void (__stdcall *critical_section_call)(void *section);
extern critical_section_call DAT_00db80cc;
extern critical_section_call DAT_00db80d0;
extern unsigned char DAT_0347ade4[24];
extern volatile char DAT_02527bf7;
extern unsigned char DAT_00e435b4[];
void __fastcall FUN_00a629f0(int object);
void FUN_00cde870(int block);

__declspec(noinline) int __fastcall FUN_00a64280(int object, int unused_edx, unsigned int flags)
{
	*(unsigned char **)object = DAT_00e435b4;
	*(int *)(object + 0x18) = 0;
	FUN_00a629f0(object);
	if ((flags & 1) != 0 && DAT_02527bf7 != 1) {
		DAT_00db80cc(DAT_0347ade4);
		FUN_00cde870(object);
		DAT_00db80d0(DAT_0347ade4);
	}
	return object;
}
