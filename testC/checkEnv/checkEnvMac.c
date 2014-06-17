#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    time_t tt;

    unsigned short is = 0x1234;
    unsigned int ii = 0x12345678;
    unsigned char *c = NULL;

    time(&tt);

    printf("============\n");
    printf("Path: %s\n", argv[0]);
    printf("Local time:%s\n",ctime(&tt));

    printf("Char size:\t%d\tCHAR_MAX:\t%d\tCHAR_MIN:\t%d\n", (int)sizeof(char),CHAR_MAX,CHAR_MIN);
    printf("UChar size:\t%u\tUCHAR_MAX:\t%u\n", (int)sizeof(unsigned char),UCHAR_MAX);
    printf("Short size:\t%d\tSHRT_MAX:\t%d\tSHRT_MIN:\t%d\n", (int)sizeof(short),SHRT_MAX,SHRT_MIN);
    printf("UShort size:\t%u\tUSHRT_MAX:\t%u\n", (int)sizeof(unsigned short),USHRT_MAX);
    printf("Int size:\t%d\tINT_MAX:\t%d\tINT_MIN:\t%d\n", (int)sizeof(int),INT_MAX,INT_MIN);
    printf("UInt size:\t%u\tUINT_MAX:\t%u\n", (int)sizeof(unsigned int),UINT_MAX);
    printf("Long size:\t%d\tLONG_MAX:\t%ld\tLONG_MIN:\t%ld\n", (int)sizeof(long),LONG_MAX,LONG_MIN);
    printf("ULong size:\t%d\tULONG_MAX:\t%lu\n", (int)sizeof(unsigned long),ULONG_MAX);
    printf("LLong size:\t%d\t\n", (int)sizeof(long long));
    printf("ULLong size:\t%d\t\n", (int)sizeof(unsigned long long));

    printf("Float size:\t%d\t limits defined in float.h\n", (int)sizeof(float));
    printf("Double size:\t%d\t limits defined in float.h\n", (int)sizeof(double));

    printf("Random int:\t%d\tRAND_MAX:\t0x%x\n",rand(),RAND_MAX);

    //test big/little endian
    printf("\nBigEndian:1234(5678),str-like\tLittleEndian:(7856)3412,logically accordent\n");
    printf("short:0x%x int:0x%x\n",is,ii);
    c = (unsigned char *)(&is);
    printf("Byte0:%2x Byte1:%2x\n",*c,*(c+1));
    c = (unsigned char *)(&ii);
    printf("Byte0:%2x Byte1:%2x Byte2:%2x Byte3:%2x\n",*c,*(c+1),*(c+2),*(c+3));
    
    printf("============\n");

    return 0;
}

