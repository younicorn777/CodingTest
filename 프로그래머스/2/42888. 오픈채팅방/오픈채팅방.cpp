#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> chat;
    unordered_map<string, string> map;
    
    for(const string& r : record){
        size_t pos1 = r.find(' ');
        size_t pos2 = r.find(' ', pos1 + 1);
        string status = r.substr(0, pos1);
        string user_id = r.substr(pos1 + 1, pos2 - pos1 - 1);
        
        if(status == "Enter" || status == "Change"){
            string nickname = r.substr(pos2+1);
            map[user_id] = nickname;
        }
        
        if(status == "Enter" || status == "Leave")
            chat.push_back({status, user_id});
    }
    
    for(const auto& pair : chat){
        if(pair.first == "Enter")
            answer.push_back(map[pair.second] + "님이 들어왔습니다.");
        else
            answer.push_back(map[pair.second] + "님이 나갔습니다.");
    }
    
    return answer;
}