#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board.size();
    vector<stack<int>> stacks(N);
    
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j >= 0; j--){
            if(board[j][i]){
                stacks[i].push(board[j][i]);
            }
            else break;
        }
    }
    
    stack <int> bucket;
    for(const int& m : moves){
        if(!stacks[m-1].empty()){
            if(!bucket.empty() && stacks[m-1].top() == bucket.top()){
                bucket.pop();
                answer+=2;
            }
            else{
                bucket.push(stacks[m-1].top());
            }
            stacks[m-1].pop();
        }
    }
    
    return answer;
}