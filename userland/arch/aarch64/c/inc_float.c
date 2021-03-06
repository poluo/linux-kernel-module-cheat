/* https://github.com/cirosantilli/linux-kernel-module-cheat#gcc-inline-assembly-floating-point-arm */

#include <assert.h>

int main(void) {
    float my_float = 1.5;
    __asm__ (
        "fmov s0, 1.0;"
        "fadd %s[my_float], %s[my_float], s0;"
        : [my_float] "+w" (my_float)
        :
        : "s0"
    );
    assert(my_float == 2.5);

    double my_double = 1.5;
    __asm__ (
        "fmov d0, 1.0;"
        "fadd %d[my_double], %d[my_double], d0;"
        : [my_double] "+w" (my_double)
        :
        : "d0"
    );
    assert(my_double == 2.5);
}
