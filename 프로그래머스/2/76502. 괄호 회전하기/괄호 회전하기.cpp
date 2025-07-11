#include <string>
#include <vector>
#include <stack>

using namespace std;

bool StrTest(string str){
    if(str[0] == ')' || str[0] == '}'|| str[0] == ']')
        return false;
    
    stack<char> st;
    for(char s : str){
        if(s == ')' || s == '}'|| s == ']'){
            if(st.empty())
                return false;
            else{
                if(st.top() == '(' && s == ')' ||
                   st.top() == '{' && s == '}' || 
                   st.top() == '[' && s == ']')
                    st.pop();
                else
                    return false;
            }
        }
        else
            st.push(s);
    }
    
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    string test = s;
    for(int i = 0; i < s.size(); i++){
        test = test.substr(1) + test[0]; // 회전
        if(StrTest(test)) answer++;
    }
    
    return answer;
}