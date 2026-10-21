/* FUN_00786b70: maps the input through FUN_00787020 and FUN_00787450 to a band index; for index 0..3 returns a random
   float between DAT_00e8dd2c[index] and DAT_00e8dd3c[index] drawn from the generator at DAT_00ec30f8
   (FUN_00bdce30); otherwise 0. Native takes the input in EAX. */
extern float DAT_00e8dd2c[];
extern float DAT_00e8dd3c[];
extern int DAT_00ec30f8;
int FUN_00787020(int value);
unsigned int __fastcall FUN_00787450(int index);
float FUN_00bdce30(int *generator);

__declspec(noinline) float FUN_00786b70(int value)
{
	unsigned int band = FUN_00787450(FUN_00787020(value));
	float minimum;
	if (band <= 3) {
		minimum = DAT_00e8dd2c[band];
		return (DAT_00e8dd3c[band] - minimum) * FUN_00bdce30(&DAT_00ec30f8) + minimum;
	}
	return 0.0f;
}
