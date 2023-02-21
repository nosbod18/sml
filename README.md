# sml
A single-header math library for games

```c
#define SML_IMPLEMENTATION
#include "sml/sml.h"
#include <stdio.h>

int main(void) {
    SmlVec3 a = {1.f, 2.f, 3.f};
    SmlVec3 b = {4.f, 5.f, 6.f};
    SmlVec3 c = SmlAddVec3(a, b);
    printf("c = {%.1f, %.1f, %.1f}\n", c.x, c.y, c.z);
}
```