#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hashTable;
    for(const string& c : completion){
        auto it = hashTable.find(c);
        if(it != hashTable.end())
            (it->second)++;
        else
            hashTable[c] = 1;
    }
    
    for(const string& p : participant){
        auto it = hashTable.find(p);
        if((it != hashTable.end()) && (it->second) >= 1)
            (it->second)--;
        else{
            answer = p;
            break;
        }
    }
    
    return answer;
}