///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                                Interface                                ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

#pragma once

///////////////////////////////////////////////////////////////////////////////
/// Types

typedef struct sml_vec2_t {
    float x, y;
} sml_vec2_t;

typedef struct sml_vec3_t {
    float x, y, z;
} sml_vec3_t;

typedef struct sml_vec4_t {
    float x, y, z, w;
} sml_vec4_t;

typedef struct sml_mat4_t {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
} sml_mat4_t;

///////////////////////////////////////////////////////////////////////////////
/// Functions / Macros

#define     SML_MIN(x, y)           ((x) < (y) ? (x) : (y))
#define     SML_MAX(x, y)           ((x) > (y) ? (x) : (y))
#define     SML_CLAMP(x, lo, hi)    (SML_MAX(SML_MIN(hi, x), lo))
#define     SML_ABS(x)              ((x) < 0 ? -(x) : (x))
#define     SML_SIGN(x)             (((x) > 0) - ((x) < 0))

float       sml_sinf                (float x);
float       sml_cosf                (float x);
float       sml_tanf                (float x);
float       sml_sqrtf               (float x);

sml_vec2_t  sml_vec2_add            (sml_vec2_t a, sml_vec2_t b);
sml_vec2_t  sml_vec2_sub            (sml_vec2_t a, sml_vec2_t b);
sml_vec2_t  sml_vec2_mul            (sml_vec2_t a, sml_vec2_t b);
sml_vec2_t  sml_vec2_scale          (sml_vec2_t a, float b);
float       sml_vec2_dot            (sml_vec2_t a, sml_vec2_t b);
float       sml_vec2_length         (sml_vec2_t a);
sml_vec2_t  sml_vec2_normalize      (sml_vec2_t a);

sml_vec3_t  sml_vec3_add            (sml_vec3_t a, sml_vec3_t b);
sml_vec3_t  sml_vec3_sub            (sml_vec3_t a, sml_vec3_t b);
sml_vec3_t  sml_vec3_mul            (sml_vec3_t a, sml_vec3_t b);
sml_vec3_t  sml_vec3_scale          (sml_vec3_t a, float b);
float       sml_vec3_dot            (sml_vec3_t a, sml_vec3_t b);
float       sml_vec3_length         (sml_vec3_t a);
sml_vec3_t  sml_vec3_normalize      (sml_vec3_t a);
sml_vec3_t  sml_vec3_cross          (sml_vec3_t a, sml_vec3_t b);

sml_vec4_t  sml_vec4_add            (sml_vec4_t a, sml_vec4_t b);
sml_vec4_t  sml_vec4_sub            (sml_vec4_t a, sml_vec4_t b);
sml_vec4_t  sml_vec4_mul            (sml_vec4_t a, sml_vec4_t b);
sml_vec4_t  sml_vec4_scale          (sml_vec4_t a, float b);
float       sml_vec4_dot            (sml_vec4_t a, sml_vec4_t b);
float       sml_vec4_length         (sml_vec4_t a);
sml_vec4_t  sml_vec4_normalize      (sml_vec4_t a);

sml_mat4_t  sml_mat4_identity       (void);
sml_mat4_t  sml_mat4_mul            (sml_mat4_t a, sml_mat4_t b);

sml_mat4_t  sml_translate           (sml_vec3_t translation);
sml_mat4_t  sml_rotate              (sml_vec3_t axis, float angle);
sml_mat4_t  sml_scale               (sml_vec3_t scale);
sml_mat4_t  sml_lookat              (sml_vec3_t eye, sml_vec3_t target, sml_vec3_t up);
sml_mat4_t  sml_perspective         (float fov, float aspect, float near, float far);
sml_mat4_t  sml_orthographic        (float left, float right, float bottom, float top, float near, float far);

///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                             Implementation                              ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

#if defined(SML_IMPL)

float sml_sinf(float x) {
    x *= 0.15915494309189534f;
    x *= 0.5f - (x * ((x > 0) - (x < 0)));
    return x * (57.3460872862336f * (x * ((x > 0) - (x < 0))) + 12.4158695446104f);
}

float sml_cosf(float x) {
    return sml_sinf(x + 1.570796327f);
}

float sml_tanf(float x) {
    return sml_sinf(x) / sml_cosf(x);
}

float sml_sqrtf(float x) {
    int y = ((*(int *)&x - 0x00800000) >> 1) + 0x20000000;
    float z = *(float *)&y;
    return (x / z + z) * 0.5f;
}

sml_vec2_t sml_vec2_add(sml_vec2_t a, sml_vec2_t b) {
    return (sml_vec2_t){a.x + b.x, a.y + b.y};
}

sml_vec2_t sml_vec2_sub(sml_vec2_t a, sml_vec2_t b) {
    return (sml_vec2_t){a.x - b.x, a.y - b.y};
}

sml_vec2_t sml_vec2_mul(sml_vec2_t a, sml_vec2_t b) {
    return (sml_vec2_t){a.x * b.x, a.y * b.y};
}

sml_vec2_t sml_vec2_scale(sml_vec2_t a, float b) {
    return (sml_vec2_t){a.x * b, a.y * b};
}

float sml_vec2_dot(sml_vec2_t a, sml_vec2_t b) {
    return a.x * b.x + a.y * b.y;
}

float sml_vec2_length(sml_vec2_t a) {
    return sml_sqrtf(sml_vec2_dot(a, a));
}

sml_vec2_t sml_vec2_normalize(sml_vec2_t a) {
    return sml_vec2_scale(a, 1.f / sml_vec2_length(a));
}

sml_vec3_t sml_vec3_add(sml_vec3_t a, sml_vec3_t b) {
    return (sml_vec3_t){a.x + b.x, a.y + b.y, a.z + b.z};
}

sml_vec3_t sml_vec3_sub(sml_vec3_t a, sml_vec3_t b) {
    return (sml_vec3_t){a.x - b.x, a.y - b.y, a.z - b.z};
}

sml_vec3_t sml_vec3_mul(sml_vec3_t a, sml_vec3_t b) {
    return (sml_vec3_t){a.x * b.x, a.y * b.y, a.z * b.z};
}

sml_vec3_t sml_vec3_scale(sml_vec3_t a, float b) {
    return (sml_vec3_t){a.x * b,   a.y * b,   a.z * b  };
}

float sml_vec3_dot(sml_vec3_t a, sml_vec3_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float sml_vec3_length(sml_vec3_t a) {
    return sml_sqrtf(sml_vec3_dot(a, a));
}

sml_vec3_t sml_vec3_normalize(sml_vec3_t a) {
    return sml_vec3_scale(a, 1.f / sml_vec3_length(a));
}

sml_vec3_t sml_vec3_cross(sml_vec3_t a, sml_vec3_t b) {
    return (sml_vec3_t){ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

sml_vec4_t sml_vec4_add(sml_vec4_t a, sml_vec4_t b) {
    return (sml_vec4_t){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

sml_vec4_t sml_vec4_sub(sml_vec4_t a, sml_vec4_t b) {
    return (sml_vec4_t){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

sml_vec4_t sml_vec4_mul(sml_vec4_t a, sml_vec4_t b) {
    return (sml_vec4_t){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

sml_vec4_t sml_vec4_scale(sml_vec4_t a, float b) {
    return (sml_vec4_t){a.x * b,   a.y * b,   a.z * b,   a.w * b  };
}

float sml_vec4_dot(sml_vec4_t a, sml_vec4_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float sml_vec4_length(sml_vec4_t a) {
    return sml_sqrtf(sml_vec4_dot(a, a));
}

sml_vec4_t sml_vec4_normalize(sml_vec4_t a) {
    return sml_vec4_scale(a, 1.f / sml_vec4_length(a));
}

sml_mat4_t sml_mat4_identity(void) {
    return (sml_mat4_t){.m00 = 1.f, .m11 = 1.f, .m22 = 1.f, .m33 = 1.f};
}

sml_mat4_t sml_mat4_mul(sml_mat4_t a, sml_mat4_t b) {
    return (sml_mat4_t){
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

sml_mat4_t sml_translate(sml_vec3_t translation) {
    return (sml_mat4_t){
        .m30 = translation.x,
        .m31 = translation.y,
        .m32 = translation.z,
        .m33 = 1.f,
    };
}

sml_mat4_t sml_rotate(sml_vec3_t axis, float angle) {
    float c = sml_cosf(angle);
    sml_vec3_t an = sml_vec3_normalize(axis);
    sml_vec3_t at = sml_vec3_scale(an, 1.f - c);
    sml_vec3_t as = sml_vec3_scale(an, sml_sinf(angle));
    return (sml_mat4_t){
        an.x * at.x + c,    an.y * at.x + as.z, an.z * at.x - as.y, 0.f,
        an.x * at.y - as.z, an.y * at.y + c,    an.z * at.y + as.x, 0.f,
        an.x * at.z + as.z, an.y * at.z + as.x, an.z * at.z + c,    0.f,
        0.f,                0.f,                0.f,                1.f
    };
}

sml_mat4_t sml_scale(sml_vec3_t scale) {
    return (sml_mat4_t) {
        .m00 = scale.x,
        .m11 = scale.y,
        .m22 = scale.z,
        .m33 = 1.f
    };
}

sml_mat4_t sml_lookat(sml_vec3_t eye, sml_vec3_t target, sml_vec3_t up) {
    sml_vec3_t f = sml_vec3_normalize(sml_vec3_sub(target, eye));
    sml_vec3_t r = sml_vec3_normalize(sml_vec3_cross(f, up));
    sml_vec3_t u = sml_vec3_cross(r, f);
    return (sml_mat4_t){
        r.x, u.x, -f.x, 0.0f,
        r.y, u.y, -f.y, 0.0f,
        r.z, u.z, -f.z, 0.0f,
        -sml_vec3_dot(r, eye), -sml_vec3_dot(u, eye), -sml_vec3_dot(f, eye), 1.0f
    };
}

sml_mat4_t sml_perspective(float fov, float aspect, float near, float far) {
    float nf  = 1.f / (near - far);
    fov = 1.f / sml_tanf(fov * 0.5f);
    return (sml_mat4_t){
        .m00 = fov / aspect,
        .m11 = fov,
        .m22 = (near + far) * nf,
        .m23 = -1.f,
        .m32 = 2.f * near * far * nf
    };
}

sml_mat4_t sml_orthographic(float left, float right, float bottom, float top, float near, float far) {
    float rl =  1.f / (right - left);
    float tb =  1.f / (top - bottom);
    float fn = -1.f / (far - near);
    return (sml_mat4_t){
        .m00 = 2.f * rl,
        .m11 = 2.f * tb,
        .m22 = 2.f * fn,
        .m30 = -(right + left) * rl,
        .m31 = -(top + bottom) * tb,
        .m32 =  (far + near) * fn,
        .m33 = 1.f
    };
}

#endif // SML_IMPL
