/* FUN_00a61840: when byte +0x14 of the object is set and either FUN_00a26380() reports true or byte +0x179 is set,
   passes the object to FUN_00a60110; then always hands it to FUN_00a62240 (a tail transfer in native). */
unsigned char FUN_00a26380(void);
void FUN_00a60110(unsigned char *object);
void FUN_00a62240(unsigned char *object);
__declspec(noinline) void __fastcall FUN_00a61840(unsigned char *object)
{
	if (object[0x14] != 0 && (FUN_00a26380() != 0 || object[0x179] != 0)) {
		FUN_00a60110(object);
	}
	FUN_00a62240(object);
}
