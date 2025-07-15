#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(const auto& c : s){
        if(st.empty())
            st.push(c);
        else{
            if(c == st.top())
                st.pop();
            else
                st.push(c);
        }
    }
    answer = st.empty() ? 1 : 0;
    return answer;
}