#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candyVec(ratings.size(), 1);

        //先统计右大于左
        for (unsigned int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        //再统计左大于右
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i + 1] + 1,  //既要保证左大于右
                                  candyVec[i]);         //还要保证之前计算的右大于左
            }
        }

        //统计结果
        int result = 0;
        for (unsigned int i = 0; i < candyVec.size(); i++) {
            result += candyVec[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> ratings1 = {1,0,2};
    vector<int> ratings2 = {1,2,2};

    cout << sol.candy(ratings1) << endl;
    cout << sol.candy(ratings2) << endl;

    return 0;
}
