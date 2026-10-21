/* FUN_00b7fb00: builds a unit quad. Sets the vertex and index counts (0x00ebd0cc, 0x00ebd0d0) to 4, allocates the
   vertex array (4 x 20-byte {xyz, uv}) and the 16-bit index array from the heap object at 0x02771480
   (FUN_00c00db0, 16-byte aligned), sets 0x00ebd0e0 to 0x20, fills the quad x in {-0.5, 0.5}, z in {0, 1} with uvs
   and indices 0..3, then creates the vertex buffer at 0x00ebd0d4 from it (FUN_00d18a20, flags 8). */
typedef struct { float x, y, z; } vec3_t;
typedef struct { vec3_t pos; float u, v; } quad_vertex_t;
void *__stdcall FUN_00c00db0(void *heap, int size, int align);
void FUN_00d18a20(int flags, int size, void *out_p, void *data);
extern int DAT_00ebd0cc;
extern int DAT_00ebd0d0;
extern quad_vertex_t *DAT_00ebd0c4;
extern unsigned short *DAT_00ebd0c8;
extern int DAT_00ebd0e0;
extern unsigned char DAT_02771480[];
extern unsigned char DAT_00ebd0d4[];
extern float DAT_00e5c410;
extern float DAT_00dd1c8c;

__declspec(noinline) void FUN_00b7fb00(void)
{
	vec3_t *p;
	DAT_00ebd0cc = 4;
	DAT_00ebd0d0 = 4;
	DAT_00ebd0c4 = (quad_vertex_t *)FUN_00c00db0(DAT_02771480, DAT_00ebd0cc * sizeof(quad_vertex_t), 16);
	DAT_00ebd0c8 = (unsigned short *)FUN_00c00db0(DAT_02771480, DAT_00ebd0d0 * sizeof(unsigned short), 16);
	DAT_00ebd0e0 = 0x20;
	p = &DAT_00ebd0c4[0].pos;
	p->x = DAT_00e5c410;
	p->y = 0.0f;
	p->z = 0.0f;
	p = &DAT_00ebd0c4[1].pos;
	p->x = DAT_00e5c410;
	p->y = 0.0f;
	p->z = 1.0f;
	p = &DAT_00ebd0c4[2].pos;
	p->x = DAT_00dd1c8c;
	p->y = 0.0f;
	p->z = 1.0f;
	p = &DAT_00ebd0c4[3].pos;
	p->x = DAT_00dd1c8c;
	p->y = 0.0f;
	p->z = 0.0f;
	DAT_00ebd0c4[0].u = 0.0f;
	DAT_00ebd0c4[0].v = 1.0f;
	DAT_00ebd0c4[1].u = 0.0f;
	DAT_00ebd0c4[1].v = 0.0f;
	DAT_00ebd0c4[2].u = 1.0f;
	DAT_00ebd0c4[2].v = 0.0f;
	DAT_00ebd0c4[3].u = 1.0f;
	DAT_00ebd0c4[3].v = 1.0f;
	DAT_00ebd0c8[0] = 0;
	DAT_00ebd0c8[1] = 1;
	DAT_00ebd0c8[2] = 2;
	DAT_00ebd0c8[3] = 3;
	FUN_00d18a20(8, DAT_00ebd0cc * sizeof(quad_vertex_t), DAT_00ebd0d4, DAT_00ebd0c4);
}
