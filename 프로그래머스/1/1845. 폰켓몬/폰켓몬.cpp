#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int select = nums.size() / 2;
    unordered_set<int> set(nums.begin(), nums.end());
    return min((int)set.size(), select);
}