#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rc4.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input output key\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (!fin) {
        perror("Input file error");
        return 1;
    }

    fseek(fin, 0, SEEK_END);
    long size = ftell(fin);
    rewind(fin);

    unsigned char *buffer = malloc(size);
    fread(buffer, 1, size, fin);
    fclose(fin);

    unsigned char S[256];
    rc4_init(S, (unsigned char *)argv[3], strlen(argv[3]));

    rc4_crypt(S, buffer, size);

    FILE *fout = fopen(argv[2], "wb");
    if (!fout) {
        perror("Output file error");
        free(buffer);
        return 1;
    }

    fwrite(buffer, 1, size, fout);
    fclose(fout);

    free(buffer);

    printf("Done.\n");
    return 0;
}
