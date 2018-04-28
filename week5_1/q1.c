#include <stdio.h>
#include <inttypes.h>
uint8_t Func32(uint32_t x) {
    printf("x: %" PRIu32 "\n", x);
    return x ? Func32(x >> 1) - 1 : 32;
}

uint8_t FuncI(uint32_t x)
{
    if (!x) return 32;
    int n = 1;
    if (!(x >> 16)) { n += 16; x <<= 16; }
    if (!(x >> 24)) { n +=  8; x <<=  8; }
    if (!(x >> 28)) { n +=  4; x <<=  4; }
    if (!(x >> 30)) { n +=  2; x <<=  2; }
    n = n - (x >> 31);
    return n;
}

int main() {
    // uint8_t result = Func32(0x0000ffff);
    uint8_t result = FuncI(0x00003fff);
    printf("result: %" PRIu8 "\n", result);
    return 0;
}