#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes"; // 기본값
    int idx1 = 0, idx2 = 0; // 각 카드 뭉치의 인덱스
    int size1 = cards1.size(), size2 = cards2.size();
    
    for(const string& str : goal){
        if((idx1 < size1) && cards1[idx1] == str) idx1++;
        else if((idx2 < size2) && cards2[idx2] == str) idx2++;
        else{
            answer = "No";
            break;
        }
    }
    
    return answer;
}