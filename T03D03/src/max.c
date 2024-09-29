#include <stdio.h>

int find_max(int a, int b);

int main()
{
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) != 2)
    {
        printf("n/a\n");
        return 1;
    }
    printf("%d\n", find_max(num1, num2));
    return 0;
}

int find_max(int a, int b)
{
    return (a > b) ? a : b;
}