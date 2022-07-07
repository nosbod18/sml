#pragma once

typedef struct vec2 {
    float x, y;
} vec2;

typedef struct vec3 {
    float x, y, z;
} vec3;

typedef struct vec4 {
    float x, y, z, w;
} vec4;

typedef struct mat4 {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
} mat4;

static inline float fast_sinf(float x) {
    x *= 0.15915494309189534f;
    x *= 0.5f - (x * ((x > 0) - (x < 0)));
    return x * (57.3460872862336f * (x * ((x > 0) - (x < 0))) + 12.4158695446104f);
}
static inline float fast_cosf(float x) {
    return fast_sinf(x + 1.570796327f);
}
static inline float fast_tanf(float x) {
    return fast_sinf(x) / fast_cosf(x);
}
static inline float fast_sqrtf(float x) {
    int y = ((*(int *)&x - 0x00800000) >> 1) + 0x20000000;
    float z = *(float *)&y;
    return (x / z + z) * 0.5f;
}

static inline vec2  vec2_add(vec2 a, vec2 b)    { return (vec2){a.x + b.x, a.y + b.y}; }
static inline vec2  vec2_sub(vec2 a, vec2 b)    { return (vec2){a.x - b.x, a.y - b.y}; }
static inline vec2  vec2_mul(vec2 a, vec2 b)    { return (vec2){a.x * b.x, a.y * b.y}; }
static inline vec2  vec2_scale(vec2 a, float b) { return (vec2){a.x * b, a.y * b}; }
static inline float vec2_dot(vec2 a, vec2 b)    { return a.x * b.x + a.y * b.y; }
static inline float vec2_len2(vec2 a)           { return vec2_dot(a, a); }
static inline float vec2_len(vec2 a)            { return fast_sqrtf(vec2_len2(a)); }
static inline vec2  vec2_norm(vec2 a)           { return vec2_scale(a, 1.f / vec2_len(a)); }

static inline vec3  vec3_add(vec3 a, vec3 b)    { return (vec3){a.x + b.x, a.y + b.y, a.z + b.z}; }
static inline vec3  vec3_sub(vec3 a, vec3 b)    { return (vec3){a.x - b.x, a.y - b.y, a.z - b.z}; }
static inline vec3  vec3_mul(vec3 a, vec3 b)    { return (vec3){a.x * b.x, a.y * b.y, a.z * b.z}; }
static inline vec3  vec3_scale(vec3 a, float b) { return (vec3){a.x * b,   a.y * b,   a.z * b  }; }
static inline float vec3_dot(vec3 a, vec3 b)    { return a.x * b.x + a.y * b.y + a.z * b.z; }
static inline float vec3_len2(vec3 a)           { return vec3_dot(a, a); }
static inline float vec3_len(vec3 a)            { return fast_sqrtf(vec3_len2(a)); }
static inline vec3  vec3_norm(vec3 a)           { return vec3_scale(a, 1.f / vec3_len(a)); }
static inline vec3  vec3_cross(vec3 a, vec3 b)  { return (vec3){ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x}; }

static inline vec4  vec4_add(vec4 a, vec4 b)    { return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
static inline vec4  vec4_sub(vec4 a, vec4 b)    { return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
static inline vec4  vec4_mul(vec4 a, vec4 b)    { return (vec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }
static inline vec4  vec4_scale(vec4 a, float b) { return (vec4){a.x * b,   a.y * b,   a.z * b,   a.w * b  }; }
static inline float vec4_dot(vec4 a, vec4 b)    { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
static inline float vec4_len2(vec4 a)           { return vec4_dot(a, a); }
static inline float vec4_len(vec4 a)            { return fast_sqrtf(vec4_len2(a)); }
static inline vec4  vec4_norm(vec4 a)           { return vec4_scale(a, 1.f / vec4_len(a)); }

static inline mat4 mat4_identity(mat4) {
    return (mat4){.m00 = 1.f, .m11 = 1.f, .m22 = 1.f, .m33 = 1.f};
}
static inline mat4 mat4_mul(mat4 a, mat4 b) {
    return (mat4){
        a.m00 * b.m00, a.m01 * b.m01, a.m02 * b.m02, a.m03 * b.m03,
        a.m10 * b.m10, a.m11 * b.m11, a.m12 * b.m12, a.m13 * b.m13,
        a.m20 * b.m20, a.m21 * b.m21, a.m22 * b.m22, a.m23 * b.m23,
        a.m30 * b.m30, a.m31 * b.m31, a.m32 * b.m32, a.m33 * b.m33,
    };
}
static inline mat4 mat4_translate(vec3 translation) {
    return (mat4){
        .m30 = translation.x,
        .m31 = translation.y,
        .m32 = translation.z,
        .m33 = 1.f,
    };
}
static inline mat4 mat4_rotate(vec3 axis, float angle) {
    float c = fast_cosf(angle);
    vec3 an = vec3_norm(axis);
    vec3 at = vec3_scale(an, 1.f - c);
    vec3 as = vec3_scale(an, fast_sinf(angle));
    return (mat4){
        an.x * at.x + c,    an.y * at.x + as.z, an.z * at.x - as.y, 0.f,
        an.x * at.y - as.z, an.y * at.y + c,    an.z * at.y + as.x, 0.f,
        an.x * at.z + as.z, an.y * at.z + as.x, an.z * at.z + c,    0.f,
        0.f,                0.f,                0.f,                1.f
    };
}
static inline mat4 mat4_scale(vec3 scale) {
    return (mat4) {
        .m00 = scale.x,
        .m11 = scale.y,
        .m22 = scale.z,
        .m33 = 1.f
    };
}
static inline mat4 mat4_lookat(vec3 eye, vec3 target, vec3 up) {
    vec3 f = vec3_norm(vec3_sub(target, eye)); 
    vec3 r = vec3_norm(vec3_cross(f, up));
    vec3 u = vec3_cross(r, f);
    return (mat4){
        r.x, u.x, -f.x, 0.0f,
        r.y, u.y, -f.y, 0.0f,
        r.z, u.z, -f.z, 0.0f,
        -vec3_dot(r, eye), -vec3_dot(u, eye), -vec3_dot(f, eye), 1.0f
    };
}
static inline mat4 mat4_perspective(float fov, float aspect, float near, float far) {
    float nf  = 1.f / (near - far);
    fov = 1.f / fast_tanf(fov * 0.5f);
    return (mat4){
        .m00 = fov / aspect,
        .m11 = fov,
        .m22 = (near + far) * nf,
        .m23 = -1.f,
        .m32 = 2.f * near * far * nf
    };
}
static inline mat4 mat4_ortho(float bottom, float top, float left, float right, float near, float far) {
    float rl =  1.f / (right - bottom);
    float tb =  1.f / (top - bottom);
    float fn = -1.f / (far - near);
    return (mat4){
        .m00 = 2.f * rl,
        .m11 = 2.f * tb,
        .m22 = 2.f * fn,
        .m30 = -(right + left) * rl,
        .m31 = -(top + bottom) * tb,
        .m32 = -(far + near) * fn,
        .m33 = 1.f
    };
}
