#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    short black[6] = {1,1,2,2,2,8};
    short white[6] = { 0 };

    for(int i = 0; i < 6; i++)
        scanf("%hd", &white[i]);

    for(int i = 0; i < 6; i++)
        printf("%hd ", black[i] - white[i]);
}