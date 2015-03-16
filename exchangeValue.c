#include <stdio.h>

int a = 13, b = 31;

void exchangeValue1(int* x, int* y)
{
    *x = (*x) ^ (*y);
    *y = (*x) ^ (*y);
    *x = (*x) ^ (*y);
}

void exchangeValue2(int* x, int* y)
{
    *x = (*x) + (*y);
    *y = (*x) - (*y);
    *x = (*x) - (*y);
}

void exchangeValue3(int* x, int* y)
{
    *x = (*x) - (*y);
    *y = (*x) + (*y);
    *x = (*y) - (*x);
}

void main()
{
    printf("Value:\t\t%d %d\n", a, b);
    exchangeValue1(&a, &b);
    printf("Exchange1:\t%d %d\n", a, b);
    exchangeValue2(&a, &b);
    printf("Exchange2:\t%d %d\n", a, b);
    exchangeValue3(&a, &b);
    printf("Exchange3:\t%d %d\n", a, b);
}
