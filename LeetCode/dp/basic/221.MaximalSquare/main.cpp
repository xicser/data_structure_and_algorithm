#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        int maxSide = 0;
        //dp[i][j]��ʾ��[i][j]λ��Ϊ���½ǵĵ������εı߳�
        //Ϊ�˷��㴦��, ��һ�к�һ�� ȫ��0
        vector< vector<int> > dp(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < col + 1; j++) {

                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1],        //����
                               min(dp[i - 1][j],            //��
                                   dp[i][j - 1])) + 1;      //��

                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
