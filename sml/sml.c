#include "sml.h"

static float FastSinf(float x) {
    x *= 0.15915494309189534f;
    x *= 0.5f - (x * ((x > 0) - (x < 0)));
    return x * (57.3460872862336f * (x * ((x > 0) - (x < 0))) + 12.4158695446104f);
}

static float FastCosf(float x) {
    return FastSinf(x + 1.570796327f);
}

static float FastTanf(float x) {
    return FastSinf(x) / FastCosf(x);
}

static float FastSqrtf(float x) {
    int y = ((*(int *)&x - 0x00800000) >> 1) + 0x20000000;
    float z = *(float *)&y;
    return (x / z + z) * 0.5f;
}

SmlVec2 SmlAddVec2(SmlVec2 a, SmlVec2 b) {
    return (SmlVec2){a.x + b.x, a.y + b.y};
}

SmlVec2 SmlSubVec2(SmlVec2 a, SmlVec2 b) {
    return (SmlVec2){a.x - b.x, a.y - b.y};
}

SmlVec2 SmlMulVec2(SmlVec2 a, SmlVec2 b) {
    return (SmlVec2){a.x * b.x, a.y * b.y};
}

SmlVec2 SmlScaleVec2(SmlVec2 a, float b) {
    return (SmlVec2){a.x * b, a.y * b};
}

float SmlDotVec2(SmlVec2 a, SmlVec2 b) {
    return a.x * b.x + a.y * b.y;
}

float SmlLengthVec2(SmlVec2 a) {
    return FastSqrtf(SmlDotVec2(a, a));
}

SmlVec2 SmlNormalizeVec2(SmlVec2 a) {
    return SmlScaleVec2(a, 1.f / SmlLengthVec2(a));
}

SmlVec3 SmlAddVec3(SmlVec3 a, SmlVec3 b) {
    return (SmlVec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

SmlVec3 SmlSubVec3(SmlVec3 a, SmlVec3 b) {
    return (SmlVec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

SmlVec3 SmlMulVec3(SmlVec3 a, SmlVec3 b) {
    return (SmlVec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

SmlVec3 SmlScaleVec3(SmlVec3 a, float b) {
    return (SmlVec3){a.x * b,   a.y * b,   a.z * b  };
}

float SmlDotVec3(SmlVec3 a, SmlVec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float SmlLengthVec3(SmlVec3 a) {
    return FastSqrtf(SmlDotVec3(a, a));
}

SmlVec3 SmlNormalizeVec3(SmlVec3 a) {
    return SmlScaleVec3(a, 1.f / SmlLengthVec3(a));
}

SmlVec3 SmlCrossVec3(SmlVec3 a, SmlVec3 b) {
    return (SmlVec3){ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

SmlVec4 SmlAddVec4(SmlVec4 a, SmlVec4 b) {
    return (SmlVec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

SmlVec4 SmlSubVec4(SmlVec4 a, SmlVec4 b) {
    return (SmlVec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

SmlVec4 SmlMulVec4(SmlVec4 a, SmlVec4 b) {
    return (SmlVec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

SmlVec4 SmlScaleVec4(SmlVec4 a, float b) {
    return (SmlVec4){a.x * b,   a.y * b,   a.z * b,   a.w * b  };
}

float SmlDotVec4(SmlVec4 a, SmlVec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float SmlLengthVec4(SmlVec4 a) {
    return FastSqrtf(SmlDotVec4(a, a));
}

SmlVec4 SmlNormalizeVec4(SmlVec4 a) {
    return SmlScaleVec4(a, 1.f / SmlLengthVec4(a));
}

SmlMat4 SmlIdentityMat4(void) {
    return (SmlMat4){.m00 = 1.f, .m11 = 1.f, .m22 = 1.f, .m33 = 1.f};
}

SmlMat4 SmlMulMat4(SmlMat4 a, SmlMat4 b) {
    return (SmlMat4){
        a.m00 * b.m00, a.m01 * b.m01, a.m02 * b.m02, a.m03 * b.m03,
        a.m10 * b.m10, a.m11 * b.m11, a.m12 * b.m12, a.m13 * b.m13,
        a.m20 * b.m20, a.m21 * b.m21, a.m22 * b.m22, a.m23 * b.m23,
        a.m30 * b.m30, a.m31 * b.m31, a.m32 * b.m32, a.m33 * b.m33,
    };
}

SmlMat4 SmlTranslateMat4(SmlVec3 translation) {
    return (SmlMat4){
        .m30 = translation.x,
        .m31 = translation.y,
        .m32 = translation.z,
        .m33 = 1.f,
    };
}

SmlMat4 SmlRotateMat4(SmlVec3 axis, float angle) {
    float c = FastCosf(angle);
    SmlVec3 an = SmlNormalizeVec3(axis);
    SmlVec3 at = SmlScaleVec3(an, 1.f - c);
    SmlVec3 as = SmlScaleVec3(an, FastSinf(angle));
    return (SmlMat4){
        an.x * at.x + c,    an.y * at.x + as.z, an.z * at.x - as.y, 0.f,
        an.x * at.y - as.z, an.y * at.y + c,    an.z * at.y + as.x, 0.f,
        an.x * at.z + as.z, an.y * at.z + as.x, an.z * at.z + c,    0.f,
        0.f,                0.f,                0.f,                1.f
    };
}

SmlMat4 SmlScaleMat4(SmlVec3 scale) {
    return (SmlMat4) {
        .m00 = scale.x,
        .m11 = scale.y,
        .m22 = scale.z,
        .m33 = 1.f
    };
}

SmlMat4 SmlLookatMat4(SmlVec3 eye, SmlVec3 target, SmlVec3 up) {
    SmlVec3 f = SmlNormalizeVec3(SmlSubVec3(target, eye));
    SmlVec3 r = SmlNormalizeVec3(SmlCrossVec3(f, up));
    SmlVec3 u = SmlCrossVec3(r, f);
    return (SmlMat4){
        r.x, u.x, -f.x, 0.0f,
        r.y, u.y, -f.y, 0.0f,
        r.z, u.z, -f.z, 0.0f,
        -SmlDotVec3(r, eye), -SmlDotVec3(u, eye), -SmlDotVec3(f, eye), 1.0f
    };
}

SmlMat4 SmlPerspectiveMat4(float fov, float aspect, float near, float far) {
    float nf  = 1.f / (near - far);
    fov = 1.f / FastTanf(fov * 0.5f);
    return (SmlMat4){
        .m00 = fov / aspect,
        .m11 = fov,
        .m22 = (near + far) * nf,
        .m23 = -1.f,
        .m32 = 2.f * near * far * nf
    };
}

SmlMat4 SmlOrthographicMat4(float bottom, float top, float left, float right, float near, float far) {
    float rl =  1.f / (right - bottom);
    float tb =  1.f / (top - bottom);
    float fn = -1.f / (far - near);
    return (SmlMat4){
        .m00 = 2.f * rl,
        .m11 = 2.f * tb,
        .m22 = 2.f * fn,
        .m30 = -(right + left) * rl,
        .m31 = -(top + bottom) * tb,
        .m32 = -(far + near) * fn,
        .m33 = 1.f
    };
}
