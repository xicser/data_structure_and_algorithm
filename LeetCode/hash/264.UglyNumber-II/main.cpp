#include <iostream>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        int fac[3] = {2, 3, 5};

        //����һ��С����
        priority_queue<long long, vector<long long>, greater<long long> > heap;
        set<long long> recordSet;  //��ż���������г���

        heap.push(1);
        recordSet.insert(1);

        long long uglyNumber;
        while (n--) {
            uglyNumber = heap.top();  //���ﵯ�����ǵ�n������, ��С���Ǹ�
            heap.pop();

            for (long long facItem : fac) {

                long long uglyNext = facItem * uglyNumber;
                if (!recordSet.count(uglyNext)) {
                    heap.push(uglyNext);
                    recordSet.insert(uglyNext);
                }
            }
        }

        return uglyNumber;
    }
};

int main()
{
    Solution sol;

    cout << sol.nthUglyNumber(1) << endl;
    return 0;
}
