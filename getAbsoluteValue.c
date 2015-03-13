#include <stdio.h>

#if 1
#define PRINTF printf
#else
#define PRINTF
#endif

int getAbs(int value)
{
    int tmp, record;

    record = value;
    tmp = value >> 31;
    value = (value ^ tmp) - tmp;

    PRINTF("abs of %d is %d\n", record, value);

    return value;
}

int getAbs2(int value)
{
    int record;
    
    record = value;
    if(value < 0)
    {
        value = ~value + 1;
    }

    PRINTF("abs (v2) of %d is %d\n", record, value);

    return value;
}

void main()
{
    getAbs(-3721);
    getAbs2(-3721);
}
