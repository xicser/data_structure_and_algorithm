#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candyVec(ratings.size(), 1);

        //��ͳ���Ҵ�����
        for (unsigned int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        //��ͳ���������
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i + 1] + 1,  //��Ҫ��֤�������
                                  candyVec[i]);         //��Ҫ��֤֮ǰ������Ҵ�����
            }
        }

        //ͳ�ƽ��
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
