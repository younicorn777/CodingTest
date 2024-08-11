#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // abs 함수를 위해 추가

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int spaces = abs(n - i);
        int stars = 2 * (n - spaces) - 1;

        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int k = 0; k < stars; k++)
            printf("*");
        printf("\n");
    }
}