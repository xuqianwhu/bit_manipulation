#include <stdio.h>

int value = 0x93;

void printValue(int value, int bits)
{
    if(bits > 0)
    {
        printValue(value>>1, bits-1);
        printf("%d", (value&1));
    }
}

int turnOffRightmostSet(int value)
{
    value &= (value - 1);
    printValue(value, 8);
    printf(" TORMS\n");
    return value;
}

void checkValue(int value)
{
    if(0 == (value & (value - 1)))
    {
        printf("%d is (2 power n)\n", value);
    }
    else
    {
        printf("%d is NOT (2 power n)\n", value);
    }
    
    if(0 == (value & (value + 1)))
    {
        printf("%d is (2 power n) - 1\n", value);
    }
    else
    {
        printf("%d is NOT (2 power n) - 1\n", value);
    }
    printf("\n");
}

int isolateRightmostSet(int value)
{
    value &= -value;
    printValue(value, 8);
    printf(" IRMS\n");
    return value;
}


void main()
{
    printValue(value, 8);
    printf("\n");
    turnOffRightmostSet(value);
    checkValue(64);
    checkValue(63);
    checkValue(62);
    isolateRightmostSet(value);
}
