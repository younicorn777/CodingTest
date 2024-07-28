#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    short a = 0, b = 0, c = 0; // 3개의 주사위 눈
    int max = 0;               // 주사위 눈 중 가장 큰 값
    scanf("%hd%hd%hd", &a, &b, &c);
    
    // 같은 눈이 3개 나올 때
    if((a == b) && (b == c)) 
        printf("%d", 10000 + (a * 1000));
        
    // 같은 눈이 2개 나올 때
    else if ((a == b) || (b == c) || (a == c))
    {
        if(a == b)
            printf("%d", 1000 + (a * 100));
        else if(b == c)
            printf("%d", 1000 + (b * 100));
        else
            printf("%d", 1000 + (a * 100));
    }
        
    // 모두 다른 눈이 나올 때    
    else
    {
        max = (a > b ? a : b);
        max = (max > c ? max : c);
        printf("%d", max * 100);
    }
    
    return 0;
}