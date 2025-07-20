#include <iostream>

using namespace std;

void up(int& temp){
    if(temp % 2 == 0)
        temp /= 2;
    else
        temp = ((temp + 1) / 2);
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(a != b){
        up(a);
        up(b);
        answer++;
    }

    return answer;
}