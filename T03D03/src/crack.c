#include <stdio.h>

int main()
{
    float x, y;
    const float radius = 5.0f;

    if (scanf("%f %f", &x, &y) != 2)
    {
        printf("n/a\n");
        return 1;
    }

    if (x * x + y * y < radius * radius)
    {
        printf("GOTCHA\n");
    }
    else
    {
        printf("MISS\n");
    }

    return 0;
}