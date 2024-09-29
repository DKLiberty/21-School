#include <stdio.h>
#include <math.h>

float important_function(float x)
{
    if (isnan(x))
    {
        return NAN;
    }
    return 7e-3 * powf(x, 4) + ((22.8 * cbrtf(x) - 1e3) * x + 3) / (x * x / 2) - x * powf(10 + x, 2 / x) - 1.01;
}

int main()
{
    float x;
    if (scanf("%f", &x) == 1)
    {
        printf("%.1f\n", important_function(x));
    }
    else
    {
        printf("n/a\n");
    }
    return 0;
}