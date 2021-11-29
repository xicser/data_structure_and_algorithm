#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int, int> mapValCnt;

        //ͳ��ÿ�����ֳ��ֵĴ���
        for (unsigned int i = 0; i < nums.size(); i++) {
            mapValCnt[ nums[i] ]++;
        }
        vector<int> number;
        number.push_back(0);
        for (auto it = mapValCnt.begin(); it != mapValCnt.end(); it++) {
            number.push_back(it->first);
        }
        sort(number.begin(), number.end());

        // dp[i]��ʾ��i���λ��, ��͵�����Ǯ��
        vector<int> dp(number.size(), 0);

        //dp�����ʼ��
        dp[1] = number[1] * mapValCnt[ number[1] ];

        //����
        for (unsigned int i = 2; i < number.size(); i++) {

            //�ᱨ��
            if (number[i] - number[i - 1] == 1) {
                dp[i] = max(dp[i - 2] + number[i] * mapValCnt[ number[i] ],  //͵��i��
                            dp[i - 1]);  //��͵��i��
            }
            //���ᱨ��ֱ�Ӿ�͵
            else {
                dp[i] = dp[i - 1] + number[i] * mapValCnt[ number[i] ];
            }
        }

        return dp[number.size() - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0};

    cout << sol.deleteAndEarn(nums) << endl;

    return 0;
}
