#include "rc4.h"

void rc4_init(unsigned char *S, const unsigned char *key, size_t keylen) {
    for (int i = 0; i < 256; i++)
        S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keylen]) % 256;

        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

void rc4_crypt(unsigned char *S, unsigned char *data, size_t len) {
    int i = 0, j = 0;

    for (size_t k = 0; k < len; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        unsigned char rnd = S[(S[i] + S[j]) % 256];
        data[k] ^= rnd;
    }
}
