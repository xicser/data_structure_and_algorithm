#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int size) {
        int bagSize = size;

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j < bagSize + 1; j++) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

int main()
{
    string input;
    getline(cin, input);

    int size;

    int j = 0;
    while (j < input.size() && input[j] != ' ') {
        j++;
    }

    string sub = input.substr(0, j);
    size = atoi(sub.c_str());
    string next = input.substr(j + 1, input.size() - j);

    next.erase(next.begin());
    next.erase(--next.end());

    Solution sol;
    vector<int> nums;

    for (int i = 0; i < next.size(); ) {
        int j = i;
        while (j < next.size() && next[j] != ',') {
            j++;
        }

        string sub = next.substr(i, j - i);
        nums.push_back(atoi(sub.c_str()));
        i = j + 1;
    }

    std::cout << sol.findTargetSumWays(nums, size) << endl;

    return 0;
}
