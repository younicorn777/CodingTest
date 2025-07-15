#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
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
    
    return st.empty();
}