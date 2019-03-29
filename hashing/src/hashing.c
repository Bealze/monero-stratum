#include "crypto/hash-ops.h"

void cryptonight_hash(const char* input, char* output, uint32_t len) {
    if (input[0] >= 8)
    {
        k12(input, len, output);
    }
    else
    {
        const int variant = input[0] >= 7 ? input[0] - 6 : 0;
        cn_slow_hash(input, len, output, 1, variant, 0);
    }
}

void cryptonight_fast_hash(const char* input, char* output, uint32_t len) {
    cn_fast_hash(input, len, output);
}
