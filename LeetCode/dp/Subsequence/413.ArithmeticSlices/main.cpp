#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        if (nums.size() < 3) {
            return 0;
        }

        //dp[i]��ʾ��num[i]Ϊ�յ�ĵȲ����еĸ���
        vector<int> dp(nums.size(), 0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = 0;
            }
        }

        //Ȼ���ۼ��������Ǵ�
        int sum = 0;
        for (int i = 0; i < dp.size(); i++) {
            sum += dp[i];
        }

        return sum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
