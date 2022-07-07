# math - Minimal math library

`math.h` is a very minimal vector and matrix math library that only defines the essential functions for
computer graphics and games.

`smath.h` has almost the same API as `math.h`, except the types are structs and the functions return
structs instead of taking an `out` parameter. `smath.h` also doesn't have the *\*_copy* funtions.

Since the types are named the same in `math.h` and `smath.h`, only one of the files is meant to be
used.

 API
```c
typedef float vec2[2];
typedef float vec3[3];
typedef float vec4[4];
typedef vec4  mat4[4];

static inline float fast_sinf           (float x);
static inline float fast_cosf           (float x);
static inline float fast_tanf           (float x);
static inline float fast_sqrtf          (float x);

static inline void  vecN_copy           (vecN out, vecN a);
static inline void  vecN_add            (vecN out, vecN a, vecN b);
static inline void  vecN_sub            (vecN out, vecN a, vecN b);
static inline void  vecN_mul            (vecN out, vecN a, vecN b);
static inline void  vecN_scale          (vecN out, vecN a, float b);
static inline float vecN_dot            (vecN a, vecN b);
static inline float vecN_len2           (vecN a);
static inline float vecN_len            (vecN a);
static inline void  vecN_norm           (vecN out, vecN a);

static inline void  vec3_cross          (vec3 out, vec3 a, vec3 b);

static inline void  mat4_copy           (mat4 out, mat4 a);
static inline void  mat4_identity       (mat4 out);
static inline void  mat4_mul            (mat4 out, mat4 a, mat4 b);
static inline void  mat4_translate      (mat4 out, vec3 translation);
static inline void  mat4_rotate         (mat4 out, vec3 axis, float angle);
static inline void  mat4_scale          (mat4 out, vec3 scale);
static inline void  mat4_lookat         (mat4 out, vec3 eye, vec3 target, vec3 up);
static inline void  mat4_perspective    (mat4 out, float fov, float aspect, float near, float far);
static inline void  mat4_ortho          (mat4 out, float bottom, float top, float left, float right, float near, float far);
```
