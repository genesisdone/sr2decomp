/* FUN_006e9fe0: whole 103-byte body; ushort running sum wraps across all rows. */
typedef unsigned char View;
extern View DAT_01634872[],DAT_01673fa6[];
__declspec(noinline) void __cdecl FUN_006e9fe0(const View *unused) {
 unsigned short sum=0,*output;View *row=DAT_01634872,*counts;unsigned int left;
 do {
  counts=row-0x7de;output=(unsigned short *)row;left=0x7dd;
  do {
   if(*counts) {*output=sum;sum=(unsigned short)(sum+*counts);}
   else *output=0xffff;
   *counts=0;++output;++counts;--left;
  }while(left);
  row+=0x179c;
 }while((int)row<(int)DAT_01673fa6);
}
