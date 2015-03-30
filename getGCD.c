#include <stdio.h>

int getGCD(int value1, int value2)
{
    int tmp;

    while(value2) {
        tmp = value2;
        value2 = (int)(value1 % value2);
        value1 = tmp;
    }

    return value1;
}

int value_pair[2] = {12, 42};

void main()
{
    printf("GCD of [%d] and [%d] is [%d]\n", value_pair[0], value_pair[1], getGCD(value_pair[0], value_pair[1]));
}
