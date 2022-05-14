#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> vals(n);

    vector<long long> leftSum(n, 0);
    vector<long long> rightSum(n, 0);
    unordered_map<long long, int> valMap;

    for (int i = 0; i < n; i++) {
        cin >> vals[i];

        if (i == 0) {
            leftSum[0] = vals[0];
        }
        else {
            leftSum[i] = vals[i] + leftSum[i - 1];
        }

        //记录一下<sum, index>
        valMap[leftSum[i]] = i;
    }

    //计算
    long long result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            rightSum[i] = vals[i];
        }
        else {
            rightSum[i] = vals[i] + rightSum[i + 1];
        }

        //如果出现过这个加和的值
        if (valMap.count(rightSum[i]) != 0) {
            int index = valMap[rightSum[i]];
            //再看看下标是否符合要求
            if (index < i) {
                result = max(result, rightSum[i]); //记录最大的那个
            }
        }
    }

    cout << result << endl;

    return 0;
}
