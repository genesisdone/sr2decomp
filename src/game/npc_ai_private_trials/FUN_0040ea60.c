/* EXE: FUN_0040ea60; full native helper C trial; offsets reflect original inputs.
 * Semantic AI ownership and unnamed fields remain unestablished. */
typedef struct View { float x,y,z; } View;
__declspec(noinline) float __cdecl FUN_0040ea60(const View *object) {
    float result=object->y*object->y+object->x*object->x+object->z*object->z;
    return result;
}
