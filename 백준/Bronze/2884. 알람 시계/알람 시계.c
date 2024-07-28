#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    short h = 0, m = 0; //시, 분
    scanf("%hd%hd", &h, &m);
    
    if (m >= 45)
        printf("%hd %hd", h, m - 45);
    else
    {
        if (h > 0)
            printf("%hd %hd", h - 1, (60 - (45 - m)));
        else
            printf("%hd %hd", 23 , (60 - (45 - m)));
    }
    
    return 0;
}