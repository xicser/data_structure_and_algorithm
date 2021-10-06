#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        //考虑从每一个点出发
        for (int i = 0; i < n; i++) {
            int j = i;

            //先把当前节点的油加上
            int remain = gas[i];

            //当前剩余的油能否到达下一个点
            while (remain - cost[j] >= 0) {
                //减去花费的加上新的点的补给
                remain = remain - cost[j] + gas[(j + 1) % n];
                j = (j + 1) % n;

                //j回到了i
                if (j == i) {
                    return i;
                }
            }
        }

        //任何点都不可以
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};

    cout << sol.canCompleteCircuit(gas1, cost1) << endl;
    cout << sol.canCompleteCircuit(gas2, cost2) << endl;

    return 0;
}
