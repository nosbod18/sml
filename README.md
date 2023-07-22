# sml
A single-header math library for games

```c
#define SML_IMPL
#include "sml/sml.h"

int main(void) {
    // ...

    mat4 p = mat4_perspective(45.f, (float)window.width / (float)window.height, 0.1f, 100.f);
    mat4 v = mat4_lookat(camera_pos, vec3_add(camera.pos, camera.front), camera.up);
    mat4 m = mat4_identity();
    mat4 mvp = mat4_mul(mat4_mul(p, v), m);

    // ...

    glDrawArrays(...);
}
```

## License
Copyright 2023 Evan Dobson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
