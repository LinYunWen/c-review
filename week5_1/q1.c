#include <stdio.h>
#include <inttypes.h>
uint8_t Func32(uint32_t x) {
    printf("x: %" PRIu32 "\n", x);
    return x ? Func32(x >> 1) - 1 : 32;
}

int main() {
    uint8_t result = Func32(0x0000ffff);
    printf("result: %" PRIu8 "\n", result);
    return 0;
}