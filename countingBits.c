#include <stdio.h>

void printValue(int value, int bits)
{
    if(bits > 0)
    {
        printValue(value>>1, bits-1);
        printf("%d", (value&1));
    }
}

int countingBits1(int value)
{
    int tmp = value;

    tmp = (tmp & 0x55555555) + ((tmp >> 1) & 0x55555555);
    tmp = (tmp & 0x33333333) + ((tmp >> 2) & 0x33333333);
    tmp = (tmp & 0x0F0F0F0F) + ((tmp >> 4) & 0x0F0F0F0F);
    tmp = (tmp & 0x00FF00FF) + ((tmp >> 8) & 0x00FF00FF);
    tmp = (tmp & 0x0000FFFF) + ((tmp >> 16) & 0x0000FFFF);

    return tmp;
}

int countingLeadingBits0_v1(int value)
{
     int n;
     unsigned int tmp;

     if (value == 0)
     {
         return 32;
     }
     else if (value < 0)
     {
         return 0;
     }

     n = 0;
     tmp = (unsigned int)value;

     if((tmp & 0xFFFF0000) == 0) {n = n + 16; tmp = tmp << 16;}
     if((tmp & 0xFF000000) == 0) {n = n +  8; tmp = tmp <<  8;}
     if((tmp & 0xF0000000) == 0) {n = n +  4; tmp = tmp <<  4;}
     if((tmp & 0xC0000000) == 0) {n = n +  2; tmp = tmp <<  2;}
     if((tmp & 0x80000000) == 0) {n = n +  1;}

     return n;
}

int countingLeadingBits0_v2(int value)
{
     int n;
     unsigned int tmp;

     if (value == 0)
     {
         return 32;
     }
     else if (value < 0)
     {
         return 0;
     }

     n = 0;
     tmp = (unsigned int)value;

     if(tmp <= 0x0000FFFF) {n = n + 16; tmp = tmp << 16;}
     if(tmp <= 0x00FFFFFF) {n = n +  8; tmp = tmp <<  8;}
     if(tmp <= 0x0FFFFFFF) {n = n +  4; tmp = tmp <<  4;}
     if(tmp <= 0x3FFFFFFF) {n = n +  2; tmp = tmp <<  2;}
     if(tmp <= 0x7FFFFFFF) {n = n +  1;}

     return n;
}

int countingLeadingBits0_v3(int value)
{
     int n;
     unsigned int tmp;

     if (value == 0)
     {
         return 32;
     }
     else if (value < 0)
     {
         return 0;
     }

     n = 0;
     tmp = (unsigned int)value;

     if(tmp >> 16 == 0) {n = n + 16; tmp = tmp << 16;}
     if(tmp >> 24 == 0) {n = n +  8; tmp = tmp <<  8;}
     if(tmp >> 28 == 0) {n = n +  4; tmp = tmp <<  4;}
     if(tmp >> 30 == 0) {n = n +  2; tmp = tmp <<  2;}
     //if(tmp >> 31 == 0) {n = n +  1;}
     n = n + 1 - (tmp >> 31);

     return n;
}


int value = 3743;


void main()
{
    printf("\n");
    printf("There are %d bit 1 in value %#x %d ", countingBits1(value), value, value);
    printValue(value, 32);
    printf("\n\n");

    printf("V1 There are %d leading bits 0 in value %#x %d ", countingLeadingBits0_v1(value), value, value);
    printValue(value, 32);
    printf("\n\n");
    printf("V2 There are %d leading bits 0 in value %#x %d ", countingLeadingBits0_v2(value), value, value);
    printValue(value, 32);
    printf("\n\n");
    printf("V3 There are %d leading bits 0 in value %#x %d ", countingLeadingBits0_v3(value), value, value);
    printValue(value, 32);
    printf("\n\n");
}
