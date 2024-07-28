#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int h = 0, m = 0, take = 0; //현재 시, 분, 요리하는데 필요한 시간 
    scanf("%d%d%d", &h, &m, &take);
    
    //요리하는데 필요한 시간 처리
    h += (take / 60);
    m += (take % 60);

    if(m>=60)
    {
        h += 1;
        m %= 60;
    }
    
    if (h>=24)
        printf("%d %d", h - 24, m);
    else
        printf("%d %d", h, m);
    
    return 0;
}