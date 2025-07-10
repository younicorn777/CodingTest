#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    double people = stages.size(), temp;
    vector<pair<int, double>> ret(N, {0, 0.0});
    for (const auto& s : stages)
        if (s <= N)
            ret[s - 1].second++;

    for (int i = 0; i < N; i++) {
        ret[i].first = i + 1;
        temp = ret[i].second;
        if (people > 0)
            ret[i].second = temp / people;
        else
            ret[i].second = 0;
        people -= temp;
    }

    sort(ret.begin(), ret.end(), compare);

    for (const auto& r : ret)
        answer.push_back(r.first);
    
    return answer;
}