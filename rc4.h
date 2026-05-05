#ifndef RC4_H
#define RC4_H

#include <stddef.h>

void rc4_init(unsigned char *S, const unsigned char *key, size_t keylen);
void rc4_crypt(unsigned char *S, unsigned char *data, size_t len);

#endif
