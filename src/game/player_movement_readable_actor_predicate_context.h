/* Complete logical C dependency context for 00982380. These three native
 * bodies are NOT byte-certified here and contribute no coverage. Native
 * ranges: 0096da80..0096dabf, 00981e30..00981edd, 0096dac0..0096dbd7. */
extern unsigned char DAT_025296cd;
static unsigned char *movement_predicate_resolve(unsigned int handle) {
    return (unsigned char *)lookup_handle_untyped(handle);
}
__declspec(noinline) unsigned char __cdecl FUN_0096da80(unsigned char *actor) {
    if(!(*(unsigned int *)(actor+0xc0)&0x40000))return 0;
    if(!movement_predicate_resolve(*(unsigned int *)(actor+0x374)))return 0;
    return actor[0xb25]!=0xff;
}
__declspec(noinline) unsigned char __cdecl FUN_00981e30(unsigned char *actor) {
    unsigned char *container,*node;
    int index;
    if((*(unsigned int *)(actor+0xc0)&0x40000) && movement_predicate_resolve(*(unsigned int *)(actor+0x374))) {
        index=FUN_009cbb00(0,(const DispatchHandleRoot *)actor);
        if(index<0 || index>3)return 0;
    }
    container=*(unsigned char **)(actor+0x10cc);
    if(!container)return 1;
    container=*(unsigned char **)(container+0xc4);
    if(!container)return 1;
    node=*(unsigned char **)(container+8);
    if(!node)return 1;
    if(FUN_00b72800((const Switch34View *)node))return 0;
    if(*(int *)(node+0x34)==0xb || node[0x2c4]==0xff)return 0;
    if(actor[0x590]==2 && !DAT_025296cd && node && (node[0x2be] || node[0x2c9]))return 0;
    return *(int *)(*(unsigned char **)(actor+0x5e0)+0xc)!=0x25;
}
__declspec(noinline) unsigned char __cdecl FUN_0096dac0(unsigned char *actor,unsigned char flag) {
    unsigned char *container,*node,*object;
    int id;
    if(!actor || !(container=*(unsigned char **)(actor+0x10cc)))container=0;
    else container=*(unsigned char **)(container+0xc4);
    if(!container) {
        if(!(*(unsigned int *)(actor+0xc0)&0x40000))return 0;
        object=movement_predicate_resolve(*(unsigned int *)(actor+0x374));
        if(!object)return 0;
        /* 0096dbcc leaves actor in EDX; resolved object in ECX is not the argument. */
        return FUN_0096da80(actor);
    }
    if(actor && (container=*(unsigned char **)(actor+0x10cc)) &&
       (container=*(unsigned char **)(container+0xc4)) &&
       (node=*(unsigned char **)(container+8)) && FUN_00b72800((const Switch34View *)node)) {
        id=*(int *)(*(unsigned char **)(actor+0x5e0)+0x164);
        if(id!=-1 && (DAT_00e90e48[id].flags&0x40))return 1;
        if(actor[0xb25]==0xff || flag)return 0;
        return 1;
    }
    if(FUN_009c4060((const SwitchLink10CC *)actor))return actor[0xb25]!=0xff;
    if(!FUN_009c6060((const PropertyRoot *)actor))return 0;
    id=*(int *)(*(unsigned char **)(actor+0x5e0)+0x164);
    return id!=-1 && (DAT_00e90e48[id].flags&0x10)!=0;
}
