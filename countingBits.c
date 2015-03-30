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


int value = -3743;


void main()
{
    printf("There are %d bit 1 in value %#x %d ", countingBits1(value), value, value);
    printValue(value, 32);
    printf("\n");
}
