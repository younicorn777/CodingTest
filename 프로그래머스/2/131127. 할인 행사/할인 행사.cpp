#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantTable, disTable;

    for (int i = 0; i < want.size(); i++)
	    wantTable[want[i]] = number[i];

    for (int i = 0; i <= (discount.size() - 10); i++) {
	    bool flag = true;
	    for (int j = i; j < (i + 10); j++)
		    disTable[discount[j]]++;

	    for (const string& w : want) {
		    if (wantTable[w] != disTable[w]) {
			    flag = false;
			    break;
		    }
	    }   

	    if (flag) answer++;
	    disTable.clear();
    }

    return answer;
}