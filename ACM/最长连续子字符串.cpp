#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
//sssssssssssssss
//sssssssssssssss
class Solution {
public:

    string findLongestSubstr(string str) {
        if (str.size() == 0) {
            return "";
        }

        int left = 0, right = 0;

        string result;
        int maxLen = INT_MIN;
        unordered_map<char, int> window;

        while (right < str.size()) {

            window[ str[right] ] ++;
            right++;

            while (check(window) == false) {
                window[ str[left] ] --;
                if (window[str[left]] == 0) {
                    window.erase(str[left]);
                }
                
                left++;
            }

            int winSize = right - left;
            if (winSize > maxLen) {
                maxLen = winSize;
                result = str.substr(left, winSize);
            }
        }

        return result;
    }

private:
    bool check(unordered_map<char, int>& window) {
        return window.size() == 1;
    }
};

int main()
{
    Solution sol;

    std::cout << sol.findLongestSubstr("ssssssssssssssshhhhopeeeeeeee") << endl;
}
