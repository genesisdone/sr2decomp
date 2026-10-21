/* FUN_004271a0: caches the animation-state indices of the grab and grapple actions (FUN_00980390 looks each name up:
   Human_Grab, Human_Grab_Away, ... Melee_Grapple_Escape) in their DAT_00ee1837 .. DAT_00ee1302 bytes, and the id of
   the SFX_FIGHTCLUB_NEG sound (FUN_00bdcb30 hashes the name with seed 0; FUN_00479a50 finds the id) in
   DAT_00e9a104. */
extern const char DAT_00dd5e18[];
extern const char DAT_00dd5e24[];
extern const char DAT_00dd5e34[];
extern const char DAT_00dd5e48[];
extern const char DAT_00dd5e60[];
extern const char DAT_00dd5e7c[];
extern const char DAT_00dd5e9c[];
extern const char DAT_00dd5eb8[];
extern const char DAT_00dc594c[];
extern const char DAT_00dd5ed8[];
extern const char DAT_00dd5ef0[];
extern const char DAT_00dd5f04[];
extern const char DAT_00dd5f1c[];
extern const char DAT_00dd5f30[];
extern const char DAT_00dd5f4c[];
extern const char DAT_00dd5f60[];
extern const char DAT_00dd5f74[];
extern const char DAT_00dd5f88[];
extern unsigned char DAT_00ee1837;
extern unsigned char DAT_00ee1836;
extern unsigned char DAT_00ee1835;
extern unsigned char DAT_00ee1834;
extern unsigned char DAT_00ee1833;
extern unsigned char DAT_00ee1832;
extern unsigned char DAT_00ee1831;
extern unsigned char DAT_00ee1830;
extern unsigned char DAT_00ee182f;
extern unsigned char DAT_00ee182e;
extern unsigned char DAT_00ee182d;
extern unsigned char DAT_00ee182c;
extern unsigned char DAT_00ee182b;
extern unsigned char DAT_00ee182a;
extern unsigned char DAT_00ee1829;
extern unsigned char DAT_00ee1828;
extern unsigned char DAT_00ee1303;
extern unsigned char DAT_00ee1302;
extern const char DAT_00dd5fa0[];
extern unsigned short DAT_00e9a104;
unsigned char FUN_00980390(const char *name);
unsigned int *__stdcall FUN_00bdcb30(const char *text, unsigned int seed, unsigned int *output);
unsigned short FUN_00479a50(const unsigned int *hash);

__declspec(noinline) void FUN_004271a0(void)
{
	unsigned int hash;
	DAT_00ee1837 = FUN_00980390(DAT_00dd5e18);
	DAT_00ee1836 = FUN_00980390(DAT_00dd5e24);
	DAT_00ee1835 = FUN_00980390(DAT_00dd5e34);
	DAT_00ee1834 = FUN_00980390(DAT_00dd5e48);
	DAT_00ee1833 = FUN_00980390(DAT_00dd5e60);
	DAT_00ee1832 = FUN_00980390(DAT_00dd5e7c);
	DAT_00ee1831 = FUN_00980390(DAT_00dd5e9c);
	DAT_00ee1830 = FUN_00980390(DAT_00dd5eb8);
	DAT_00ee182f = FUN_00980390(DAT_00dc594c);
	DAT_00ee182e = FUN_00980390(DAT_00dd5ed8);
	DAT_00ee182d = FUN_00980390(DAT_00dd5ef0);
	DAT_00ee182c = FUN_00980390(DAT_00dd5f04);
	DAT_00ee182b = FUN_00980390(DAT_00dd5f1c);
	DAT_00ee182a = FUN_00980390(DAT_00dd5f30);
	DAT_00ee1829 = FUN_00980390(DAT_00dd5f4c);
	DAT_00ee1828 = FUN_00980390(DAT_00dd5f60);
	DAT_00ee1303 = FUN_00980390(DAT_00dd5f74);
	DAT_00ee1302 = FUN_00980390(DAT_00dd5f88);
	DAT_00e9a104 = FUN_00479a50(FUN_00bdcb30(DAT_00dd5fa0, 0, &hash));
}
