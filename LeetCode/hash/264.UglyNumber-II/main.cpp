#include <iostream>
#include <set>
#include <queue>

using namespace std;

class Solution {
//public:
//    int nthUglyNumber(int n) {
//
//        int fac[3] = {2, 3, 5};
//
//        //����һ��С����
//        priority_queue<long long, vector<long long>, greater<long long> > heap;
//        set<long long> recordSet;  //��ż���������г���
//
//        heap.push(1);
//        recordSet.insert(1);
//
//        long long uglyNumber;
//        while (n--) {
//            uglyNumber = heap.top();  //���ﵯ�����ǵ�n������, ��С���Ǹ�
//            heap.pop();
//
//            for (long long facItem : fac) {
//
//                long long uglyNext = facItem * uglyNumber;  //ÿ������С���Ǹ�����, ���ܱ�֤�м䲻©��ĳЩ����
//                if (!recordSet.count(uglyNext)) {
//                    heap.push(uglyNext);
//                    recordSet.insert(uglyNext);
//                }
//            }
//        }
//
//        return uglyNumber;
//    }


public:
    int nthUglyNumber(int n) {

        //dp[i]��ʾ��i������
        vector<long long> dp(n + 1, 1);
        int index2 = 1, index3 = 1, index5 = 1;
        dp[1] = 1;

        for (int i = 2; i < dp.size(); i++) {

            dp[i] = min(dp[index2] * 2, 
                    min(dp[index3] * 3, 
                    dp[index5] * 5));

            //�жϵ�ǰ�������dp[i]����Դ
            if (dp[i] == dp[index2] * 2) {
                index2++;
            }
            if (dp[i] == dp[index3] * 3) {
                index3++;
            }
            if (dp[i] == dp[index5] * 5) {
                index5++;
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;

    cout << sol.nthUglyNumber(12) << endl;
    return 0;
}
