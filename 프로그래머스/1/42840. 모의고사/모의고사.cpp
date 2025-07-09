#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> person = {
		{1,2,3,4,5},          // 5
		{2,1,2,3,2,4,2,5},    // 8
		{3,3,1,1,2,2,4,4,5,5} // 10
	};

	vector<int> count(3);

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == person[0][i % 5]) count[0]++;
		if (answers[i] == person[1][i % 8]) count[1]++;
		if (answers[i] == person[2][i % 10]) count[2]++;
	}

	auto maxIt = max_element(count.begin(), count.end());

	for (int i = 0; i < count.size(); i++) {
		if (count[i] == *maxIt)
			answer.push_back(i + 1);
	}

    return answer;
}