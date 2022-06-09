#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        string result;

        vector<string> strs;

        for (int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }

        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
            return s1 + s2 > s2 + s1;
        });

        for (int i = 0; i < strs.size(); i++) {
            result += strs[i];
        }

        //去除前导0
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        if (i == result.size()) {
            return "0";
        }
        
        return result.substr(i, result.size() - i);
    }
};

int main()
{
    vector<int> nums = { 00 };
    Solution sol;
    
    std::cout << sol.largestNumber(nums) << endl;
}
