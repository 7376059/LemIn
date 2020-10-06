#include <stdio.h>

int main(void)
{
    int z[3] = {1|2|4};

    for (int i = 0; i < 1; ++i)
        printf("%d\n", z[i]);
    return (1);
}