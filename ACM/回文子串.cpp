#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int result = 0;

    string str;
    cin >> str;
    int len = str.size();

    vector< vector<bool> > dp(len, vector<bool>(len, false));

    for (int i = len - 1; i >= 0; i--) {
        for (int j = i; j < len; j++) {

            //对角线上的元素
            if (i == j) {
                dp[i][j] = true;
                result++;
            }
            else {
                if (str[i] == str[j]) {

                    if (j - i == 1) {
                        dp[i][j] = true;
                        result++;
                    }
                    else if (dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                        result++;
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
    }

    std::cout << result << endl;

    return 0;
}
