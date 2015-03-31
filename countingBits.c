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

int countingLeadingBits0(int value)
{
     int n = 0;
     unsigned int tmp = (unsigned int)value;
     printf("\n");
     printf("tmp %u ", tmp);
     printValue(tmp, 32);
     printf("\n\n");

     if (tmp == 0)
     {
         return 32;
     }

     if(tmp <= 0x0000FFFF) {n = n + 16; tmp = tmp << 16;}
     if(tmp <= 0x00FFFFFF) {n = n +  8; tmp = tmp <<  8;}
     if(tmp <= 0x0FFFFFFF) {n = n +  4; tmp = tmp <<  4;}
     if(tmp <= 0x3FFFFFFF) {n = n +  2; tmp = tmp <<  2;}
     if(tmp <= 0x7FFFFFFF) {n = n +  1;}

     return n;
}


int value = -3743;


void main()
{
    printf("There are %d bit 1 in value %#x %d ", countingBits1(value), value, value);
    printValue(value, 32);
    printf("\n");

    printf("There are %d leading bits 0 in value %#x %d ", countingLeadingBits0(value), value, value);
    printValue(value, 32);
    printf("\n");
}
