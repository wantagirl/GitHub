#ifndef _COMPRESS_H
#define _COMPRESS_H

#include "includes.h"

char *compress(char *a, int len);
char *decompress(char *a, int len);
void testCompress(void);

#endif