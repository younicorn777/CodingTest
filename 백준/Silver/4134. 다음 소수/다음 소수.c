#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int is_prime(long long n) {
    
    if (n <= 1) return 0;
    if (n == 2) return 1;   
    if (n % 2 == 0) return 0; 

    for (long long i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0)
            return 0;
    }

    return 1; 
}

int main() 
{
    int t;
    long long n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) 
    {
        scanf("%lld", &n);

        if (n == 0 || n == 1) 
        {
            printf("2\n");
            continue;
        }

        if (is_prime(n))
            printf("%lld\n", n);
        else 
        {
            while (!is_prime(n)) 
                n++;

            printf("%lld\n", n);
        }
    }
}