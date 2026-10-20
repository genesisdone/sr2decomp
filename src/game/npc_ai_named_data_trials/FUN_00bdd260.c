/* EXE: FUN_00bdd260; complete 62-byte body. Logical C inputs are uncertified until whole linked bytes match. */
extern int DAT_00e843ac;
__declspec(noinline) int __cdecl FUN_00bdd260(const int *clock) {
 int value=*clock,now,delta;
 if(value<0)return 1800000000;
 now=DAT_00e843ac;
 if(value>now) {delta=(int)((unsigned int)value-(unsigned int)now);if(delta>900000000)return (int)((unsigned int)delta-1800000000u);return delta;}
 delta=(int)((unsigned int)now-(unsigned int)value);
 if(delta>900000000)return (int)((unsigned int)value-(unsigned int)now+1800000000u);
 return (int)(0u-(unsigned int)delta);
}
