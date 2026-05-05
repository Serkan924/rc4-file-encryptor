#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rc4.h"

#define STREAMS 100000

int main() {
    srand(time(NULL));

    int zero_count = 0;

    for (int s = 0; s < STREAMS; s++) {
        unsigned char key[16];
        for (int i = 0; i < 16; i++)
            key[i] = rand() % 256;

        unsigned char S[256];
        rc4_init(S, key, 16);

        unsigned char data[2] = {0, 0};
        rc4_crypt(S, data, 2);

        if (data[1] == 0x00)
            zero_count++;
    }

    printf("Second byte = 0x00 count: %d\n", zero_count);
    printf("Probability: %.6f\n", (double)zero_count / STREAMS);

    return 0;
}
