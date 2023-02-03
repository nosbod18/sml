#pragma once

typedef struct SmlVec2 {
    float x, y;
} SmlVec2;

typedef struct SmlVec3 {
    float x, y, z;
} SmlVec3;

typedef struct SmlVec4 {
    float x, y, z, w;
} SmlVec4;

typedef struct SmlMat4 {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
} SmlMat4;

SmlVec2 SmlAddVec2          (SmlVec2 a, SmlVec2 b);
SmlVec2 SmlSubVec2          (SmlVec2 a, SmlVec2 b);
SmlVec2 SmlMulVec2          (SmlVec2 a, SmlVec2 b);
SmlVec2 SmlScaleVec2        (SmlVec2 a, float b);
float   SmlDotVec2          (SmlVec2 a, SmlVec2 b);
float   SmlLengthVec2       (SmlVec2 a);
SmlVec2 SmlNormalizeVec2    (SmlVec2 a);

SmlVec3 SmlAddVec3          (SmlVec3 a, SmlVec3 b);
SmlVec3 SmlSubVec3          (SmlVec3 a, SmlVec3 b);
SmlVec3 SmlMulVec3          (SmlVec3 a, SmlVec3 b);
SmlVec3 SmlScaleVec3        (SmlVec3 a, float b);
float   SmlDotVec3          (SmlVec3 a, SmlVec3 b);
float   SmlLengthVec3       (SmlVec3 a);
SmlVec3 SmlNormalizeVec3    (SmlVec3 a);
SmlVec3 SmlCrossVec3        (SmlVec3 a, SmlVec3 b);

SmlVec4 SmlAddVec4          (SmlVec4 a, SmlVec4 b);
SmlVec4 SmlSubVec4          (SmlVec4 a, SmlVec4 b);
SmlVec4 SmlMulVec4          (SmlVec4 a, SmlVec4 b);
SmlVec4 SmlScaleVec4        (SmlVec4 a, float b);
float   SmlDotVec4          (SmlVec4 a, SmlVec4 b);
float   SmlLengthVec4       (SmlVec4 a);
SmlVec4 SmlNormalizeVec4    (SmlVec4 a);

SmlMat4 SmlIdentityMat4     (void);
SmlMat4 SmlMulMat4          (SmlMat4 a, SmlMat4 b);
SmlMat4 SmlTranslateMat4    (SmlVec3 translation);
SmlMat4 SmlRotateMat4       (SmlVec3 axis, float angle);
SmlMat4 SmlScaleMat4        (SmlVec3 scale);
SmlMat4 SmlLookatMat4       (SmlVec3 eye, SmlVec3 target, SmlVec3 up);
SmlMat4 SmlPerspectiveMat4  (float fov, float aspect, float near, float far);
SmlMat4 SmlOrthographicMat4 (float bottom, float top, float left, float right, float near, float far);
