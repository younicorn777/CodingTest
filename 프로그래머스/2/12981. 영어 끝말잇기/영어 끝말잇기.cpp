#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    unordered_set<string> set;
    set.insert(words[0]);
    
    for(int i = 1; i < words.size(); i++){
        auto it = set.find(words[i]);
        if(words[i-1].back() != words[i].front() || it != set.end()){
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            return answer;
        }
        else
            set.insert(words[i]);
    }

    return answer;
}