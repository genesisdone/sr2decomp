/* REA ev_ba6c85c7c4902f66b183384855423a8d0eb93e4c903147db70b45dceff2ebef1; complete native body. */
extern unsigned char *DAT_02225b3c[];
void FUN_00a7d6a0(unsigned int handle)
{
    unsigned char *record = DAT_02225b3c[handle >> 16] + (handle & 0xffff) * 0x28;
    *(unsigned int *)(record + 4) = 0;
    *(unsigned int *)(record + 8) = 0;
    *(unsigned int *)(record + 12) = 0;
}
