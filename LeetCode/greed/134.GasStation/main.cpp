#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        //���Ǵ�ÿһ�������
        for (int i = 0; i < n; i++) {
            int j = i;

            //�Ȱѵ�ǰ�ڵ���ͼ���
            int remain = gas[i];

            //��ǰʣ������ܷ񵽴���һ����
            while (remain - cost[j] >= 0) {
                //��ȥ���ѵļ����µĵ�Ĳ���
                remain = remain - cost[j] + gas[(j + 1) % n];
                j = (j + 1) % n;

                //j�ص���i
                if (j == i) {
                    return i;
                }
            }
        }

        //�κε㶼������
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
