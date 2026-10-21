/* FUN_00b7fc50: the second quad, built like FUN_00b7fb00 into its own globals: counts 0x00ebd0ec / 0x00ebd0f0 = 4,
   vertex and index arrays from the heap object at 0x02771480 (FUN_00c00db0, 16-byte aligned), 0x00ebd100 = 0x20,
   corners (A, A), (B, A), (B, B), (A, B) in x/y with z 0 (A = DAT_00e5c410, B = DAT_00dd1c8c), uvs (0,0) (1,0)
   (1,1) (0,1), indices 0..3, then the vertex buffer at 0x00ebd0f4 (FUN_00d18a20, flags 8). */
typedef struct { float x, y, z; } vec3_t;
typedef struct { vec3_t pos; float u, v; } quad_vertex_t;
void *__stdcall FUN_00c00db0(void *heap, int size, int align);
void FUN_00d18a20(int flags, int size, void *out_p, void *data);
extern int DAT_00ebd0ec;
extern int DAT_00ebd0f0;
extern quad_vertex_t *DAT_00ebd0e4;
extern unsigned short *DAT_00ebd0e8;
extern int DAT_00ebd100;
extern unsigned char DAT_02771480[];
extern unsigned char DAT_00ebd0f4[];
extern float DAT_00e5c410;
extern float DAT_00dd1c8c;

__declspec(noinline) void FUN_00b7fc50(void)
{
	vec3_t *p;
	DAT_00ebd0ec = 4;
	DAT_00ebd0f0 = 4;
	DAT_00ebd0e4 = (quad_vertex_t *)FUN_00c00db0(DAT_02771480, DAT_00ebd0ec * sizeof(quad_vertex_t), 16);
	DAT_00ebd0e8 = (unsigned short *)FUN_00c00db0(DAT_02771480, DAT_00ebd0f0 * sizeof(unsigned short), 16);
	DAT_00ebd100 = 0x20;
	p = &DAT_00ebd0e4[0].pos;
	p->x = DAT_00e5c410;
	p->y = DAT_00e5c410;
	p->z = 0.0f;
	p = &DAT_00ebd0e4[1].pos;
	p->x = DAT_00dd1c8c;
	p->y = DAT_00e5c410;
	p->z = 0.0f;
	p = &DAT_00ebd0e4[2].pos;
	p->x = DAT_00dd1c8c;
	p->y = DAT_00dd1c8c;
	p->z = 0.0f;
	p = &DAT_00ebd0e4[3].pos;
	p->x = DAT_00e5c410;
	p->y = DAT_00dd1c8c;
	p->z = 0.0f;
	DAT_00ebd0e4[0].u = 0.0f;
	DAT_00ebd0e4[0].v = 0.0f;
	DAT_00ebd0e4[1].u = 1.0f;
	DAT_00ebd0e4[1].v = 0.0f;
	DAT_00ebd0e4[2].u = 1.0f;
	DAT_00ebd0e4[2].v = 1.0f;
	DAT_00ebd0e4[3].u = 0.0f;
	DAT_00ebd0e4[3].v = 1.0f;
	DAT_00ebd0e8[0] = 0;
	DAT_00ebd0e8[1] = 1;
	DAT_00ebd0e8[2] = 2;
	DAT_00ebd0e8[3] = 3;
	FUN_00d18a20(8, DAT_00ebd0ec * sizeof(quad_vertex_t), DAT_00ebd0f4, DAT_00ebd0e4);
}
