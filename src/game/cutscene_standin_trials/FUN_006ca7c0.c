#include "../cutscene_types.h"
typedef struct CsAutoSoundDescriptor { unsigned short sound,unknown_02; unsigned char unknown_04[8]; float scale_0c,scale_10; unsigned char unknown_14[4]; int kind; unsigned char unknown_1c[0x3c]; unsigned short flags,unknown_5a; } CsAutoSoundDescriptor;
extern CsWord DAT_02527d30;extern unsigned char DAT_02527d27;
void FUN_00bff700(const char *,char *,CsWord);
extern char *__cdecl FUN_00c9a9e0(char *,int),*__cdecl FUN_00c990f0(char *,const char *,CsWord),*__cdecl FUN_00c9cfdd(char *);
extern unsigned short __cdecl FUN_006ca700(const char *);
void __stdcall FUN_00464920(CsAutoSoundDescriptor *,unsigned int,int,CsWord);
CsWords3 *FUN_00465b90(CsWords3 *,CsAutoSoundDescriptor *);
void __cdecl FUN_006d9400(const char **);
/* Whole resource-name sound cue 006CA7C0-006CA8C2. Native path ECX. Cuts the path's basename at its first '.',
 * lowercases it (FUN_00c9cfdd), bumps DAT_02527d30, clears DAT_02527d27, looks the sound up (FUN_006ca700) and,
 * when found, builds a descriptor (FUN_00464920), sets flag 0x800 and plays it (FUN_00465b90); then hands the
 * name pointer's address to FUN_006d9400. The lookup result is kept as a word and compared as 16 bits, as natively
 * (006CA877 MOVZX EAX,AX then CMP AX,0FFFF, the word pushed at 006CA887). FUN_006ca700, FUN_00c9a9e0, FUN_00c990f0
 * and FUN_00c9cfdd are non-/GL stubs; the other callees are /GL context stand-ins whose LTCG-chosen interfaces are
 * NOT claimed as native ABI bindings. Compiled with /GS (native carries the cookie). */
__declspec(noinline) void __fastcall FUN_006ca7c0(const char *source)
{
    if(source){
        char path[260],*extension;CsWord length;const char *name;CsWord sound;
        CsAutoSoundDescriptor descriptor;CsWords3 result;
        FUN_00bff700(source,path,260);extension=FUN_00c9a9e0(path,'.');
        if(!extension){FUN_00c990f0(path,path,260);path[259]=0;}
        else{length=(CsWord)(extension-path);if(length>259)length=259;FUN_00c990f0(path,path,length);path[length]=0;}
        FUN_00c9cfdd(path);++DAT_02527d30;DAT_02527d27=0;name=path;sound=FUN_006ca700(name);
        if((unsigned short)sound!=0xffff){FUN_00464920(&descriptor,sound,1,0);descriptor.flags|=0x800;FUN_00465b90(&result,&descriptor);}
        FUN_006d9400(&name);
    }
}
