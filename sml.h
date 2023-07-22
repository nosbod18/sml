///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                                Interface                                ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

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

#define PI                  (3.1415926535f)
#define TAU                 (PI * 2)
#define PI_2                (PI / 2)

#define MIN(x, y)           ((x) < (y) ? (x) : (y))
#define MAX(x, y)           ((x) > (y) ? (x) : (y))
#define CLAMP(x, lo, hi)    (MAX(MIN(hi, x), lo))
#define ABS(x)              ((x) < 0 ? -(x) : (x))
#define SIGN(x)             (((x) > 0) - ((x) < 0))
#define RADIANS(deg)        ((deg) * PI / 180.f)
#define DEGREES(rad)        ((rad) * 180.f / PI)

vec2    vec2_add            (vec2 a, vec2 b);
vec2    vec2_sub            (vec2 a, vec2 b);
vec2    vec2_mul            (vec2 a, vec2 b);
vec2    vec2_scale          (vec2 a, float b);
float   vec2_dot            (vec2 a, vec2 b);
float   vec2_len            (vec2 a);
vec2    vec2_norm           (vec2 a);

vec3    vec3_add            (vec3 a, vec3 b);
vec3    vec3_sub            (vec3 a, vec3 b);
vec3    vec3_mul            (vec3 a, vec3 b);
vec3    vec3_scale          (vec3 a, float b);
float   vec3_dot            (vec3 a, vec3 b);
float   vec3_len            (vec3 a);
vec3    vec3_norm           (vec3 a);
vec3    vec3_cross          (vec3 a, vec3 b);

vec4    vec4_add            (vec4 a, vec4 b);
vec4    vec4_sub            (vec4 a, vec4 b);
vec4    vec4_mul            (vec4 a, vec4 b);
vec4    vec4_scale          (vec4 a, float b);
float   vec4_dot            (vec4 a, vec4 b);
float   vec4_len            (vec4 a);
vec4    vec4_norm           (vec4 a);

mat4    mat4_identity       (void);
mat4    mat4_mul            (mat4 a, mat4 b);
mat4    mat4_translate      (vec3 v);
mat4    mat4_rotate         (float angle, vec3 axis);
mat4    mat4_scale          (vec3 v);
mat4    mat4_lookat         (vec3 eye, vec3 target, vec3 up);
mat4    mat4_perspective    (float fov, float aspect, float near, float far);
mat4    mat4_orthographic   (float left, float right, float bottom, float top, float near, float far);

///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                             Implementation                              ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

#if defined(SML_IMPL)

#include <math.h>


vec2 vec2_add(vec2 a, vec2 b) {
    return (vec2){a.x + b.x, a.y + b.y};
}

vec2 vec2_sub(vec2 a, vec2 b) {
    return (vec2){a.x - b.x, a.y - b.y};
}

vec2 vec2_mul(vec2 a, vec2 b) {
    return (vec2){a.x * b.x, a.y * b.y};
}

vec2 vec2_scale(vec2 a, float b) {
    return (vec2){a.x * b, a.y * b};
}

float vec2_dot(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}

float vec2_len(vec2 a) {
    return sqrtf(vec2_dot(a, a));
}

vec2 vec2_norm(vec2 a) {
    return vec2_scale(a, 1.0f / vec2_len(a));
}

vec3 vec3_add(vec3 a, vec3 b) {
    return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 vec3_sub(vec3 a, vec3 b) {
    return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 vec3_mul(vec3 a, vec3 b) {
    return (vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

vec3 vec3_scale(vec3 a, float b) {
    return (vec3){a.x * b,   a.y * b,   a.z * b  };
}

float vec3_dot(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float vec3_len(vec3 a) {
    return sqrtf(vec3_dot(a, a));
}

vec3 vec3_norm(vec3 a) {
    return vec3_scale(a, 1.0f / vec3_len(a));
}

vec3 vec3_cross(vec3 a, vec3 b) {
    return (vec3){ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

vec4 vec4_add(vec4 a, vec4 b) {
    return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

vec4 vec4_sub(vec4 a, vec4 b) {
    return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

vec4 vec4_mul(vec4 a, vec4 b) {
    return (vec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

vec4 vec4_scale(vec4 a, float b) {
    return (vec4){a.x * b,   a.y * b,   a.z * b,   a.w * b  };
}

float vec4_dot(vec4 a, vec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float vec4_len(vec4 a) {
    return sqrtf(vec4_dot(a, a));
}

vec4 vec4_norm(vec4 a) {
    return vec4_scale(a, 1.0f / vec4_len(a));
}

mat4 mat4_identity(void) {
    return (mat4){.m00 = 1.0f, .m11 = 1.0f, .m22 = 1.0f, .m33 = 1.0f};
}

mat4 mat4_mul(mat4 a, mat4 b) {
    return (mat4){
        a.m00 * b.m00 + a.m10 * b.m01 + a.m20 * b.m02 + a.m30 * b.m03,
        a.m01 * b.m00 + a.m11 * b.m01 + a.m21 * b.m02 + a.m31 * b.m03,
        a.m02 * b.m00 + a.m12 * b.m01 + a.m22 * b.m02 + a.m32 * b.m03,
        a.m03 * b.m00 + a.m13 * b.m01 + a.m23 * b.m02 + a.m33 * b.m03,
        a.m00 * b.m10 + a.m10 * b.m11 + a.m20 * b.m12 + a.m30 * b.m13,
        a.m01 * b.m10 + a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13,
        a.m02 * b.m10 + a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13,
        a.m03 * b.m10 + a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13,
        a.m00 * b.m20 + a.m10 * b.m21 + a.m20 * b.m22 + a.m30 * b.m23,
        a.m01 * b.m20 + a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23,
        a.m02 * b.m20 + a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23,
        a.m03 * b.m20 + a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23,
        a.m00 * b.m30 + a.m10 * b.m31 + a.m20 * b.m32 + a.m30 * b.m33,
        a.m01 * b.m30 + a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33,
        a.m02 * b.m30 + a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33,
        a.m03 * b.m30 + a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33,
    };
}

mat4 mat4_translate(vec3 v) {
    return (mat4){
        .m00 = 1.0f,
        .m11 = 1.0f,
        .m22 = 1.0f,
        .m30 = v.x,
        .m31 = v.y,
        .m32 = v.z,
        .m33 = 1.0f,
    };
}

mat4 mat4_rotate(mat4 m, float angle, vec3 axis) {
    float c = cosf(angle);
    vec3 an = vec3_norm(axis);
    vec3 ac = vec3_scale(an, 1.0f - c);
    vec3 as = vec3_scale(an, sinf(angle));
    mat4 rot = {
        an.x * ac.x + c, an.y * ac.x + as.z, an.z * ac.x - as.y, 0.f,
        an.x * ac.y - as.z, an.y * ac.y + c, an.z * ac.y + as.x, 0.f,
        an.x * ac.z + as.y, an.y * ac.z - as.x, an.z * ac.z + c, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
    return mat4_mul(m, rot);
}

mat4 mat4_scale(vec3 v) {
    return (mat4) {
        .m00 = v.x,
        .m11 = v.y,
        .m22 = v.z,
        .m33 = 1.0f
    };
}

mat4 mat4_lookat(vec3 eye, vec3 target, vec3 up) {
    vec3 f = vec3_norm(vec3_sub(target, eye));
    vec3 r = vec3_norm(vec3_cross(f, up));
    vec3 u = vec3_cross(r, f);
    return (mat4){
        r.x, u.x, -f.x, 0.0f,
        r.y, u.y, -f.y, 0.0f,
        r.z, u.z, -f.z, 0.0f,
        vec3_dot(r, eye), vec3_dot(u, eye), vec3_dot(f, eye), 1.0f
    };
}

mat4 mat4_perspective(float fov, float aspect, float near, float far) {
    float nf  = 1.0f / (near - far);
    fov = 1.0f / tanf(fov * 0.5f);
    return (mat4){
        .m00 = fov / aspect,
        .m11 = fov,
        .m22 = (near + far) * nf,
        .m23 = -1.0f,
        .m32 = 2.f * near * far * nf
    };
}

mat4 mat4_orthographic(float left, float right, float bottom, float top, float near, float far) {
    float rl =  1.0f / (right - left);
    float tb =  1.0f / (top - bottom);
    float fn = -1.0f / (far - near);
    return (mat4){
        .m00 = 2.f * rl,
        .m11 = 2.f * tb,
        .m22 = 2.f * fn,
        .m30 = -(right + left) * rl,
        .m31 = -(top + bottom) * tb,
        .m32 =  (far + near) * fn,
        .m33 = 1.0f
    };
}

#endif // SML_IMPL
