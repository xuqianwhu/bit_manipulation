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

int isolateRightmostZero(int value)
{
    value = ~value & (value+1);
    printValue(value, 8);
    printf(" IRMZ\n");
    return value;
}

int identifyTrailingZeros(int value)
{
    value = ~value & (value - 1);
    printValue(value, 8);
    printf(" ITZS\n");
    return value;
}

int identifyRightmostSetAndTrailingZeros(int value)
{
    value ^= (value - 1);
    printValue(value, 8);
    printf(" IRSTZS\n");
    return value;
}

int turnOffRightmostContiguousStringOfSet(int value)
{
    value = ((value | (value - 1)) + 1) & value;
    printValue(value, 8);
    printf(" TORCSOS\n");
    return value;
}

int turnOnRightmostZero(int value)
{
    value |= (value+1) ;
    printValue(value, 8);
    printf(" TORZ\n");
    return value;
}

void main()
{
    printValue(value, 8);
    printf("\n");
    turnOffRightmostSet(value);
    isolateRightmostSet(value);
    isolateRightmostZero(value);
    identifyTrailingZeros(value);
    identifyRightmostSetAndTrailingZeros(value);
    turnOffRightmostContiguousStringOfSet(value);
    turnOnRightmostZero(value);
    printf("\n");
    checkValue(64);
    checkValue(63);
    checkValue(62);
}
