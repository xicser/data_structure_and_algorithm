#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//[[0,0],[1,0],[2,0]]
class Solution {
private:

    //计算两个点之间距离的平方
    int getDistanceSquare(const vector<int>& p1, const vector<int>& p2) {
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int result = 0;
        unordered_map<int, int> mapDistanceCnt;
        for (const vector<int>& point : points) {

            //对于每个点, 先统计其他点到这个点的每个距离的个数
            mapDistanceCnt.clear();
            for (const vector<int>& pointOther : points ) {
                if (pointOther == point) {
                    continue;
                }
                int distance = getDistanceSquare(point, pointOther);
                mapDistanceCnt[distance]++;  //记录到point点距离为distance的点的个数
            }

            //然后计算当前这个点 i 的(i, j, k)元组个数
            for (auto it : mapDistanceCnt) {
                int cnt = it.second;
                if (cnt > 1) {
                    result += cnt * (cnt - 1);
                            // j         k
                            //排列问题
                }
            }
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
