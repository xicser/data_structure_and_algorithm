#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 23W223D
     *
     * @param order string字符串
     * @return int整型vector
     */
    vector<int> GetEndPoint(string order) {
        
        Point start;

        for (int i = 0; i < order.size(); ) {

            if (isOrder(order[i]) == false) {

                int j = i;
                while (j < order.size() && isOrder(order[j]) == false) {
                    j++;
                }

                string numStr = order.substr(i, j - i);
                int num = atoi(numStr.c_str());
                calCoord(order[j], num, start);

                i = j + 1;
            }
            else {
                calCoord(order[i], 1, start);
                i++;
            }
        }

        return { start.x, start.y };
    }

private:
    struct Point
    {
        int x;
        int y;

        Point() {
            x = 0;
            y = 0;
        }
    };

    void calCoord(char dir, int step, Point& p) {
        switch (dir)
        {
        case 'w':
        case 'W':
            p.y += step;
            break;
        case 's':
        case 'S':
            p.y -= step;
            break;
        case 'a':
        case 'A':
            p.x -= step;
            break;
        case 'd':
        case 'D':
            p.x += step;
            break;
        default:
            break;
        }
    }

    bool isOrder(char c) {
        return c == 'W' || c == 'A' || c == 'S' || c == 'D' ||
            c == 'w' || c == 'a' || c == 's' || c == 'd';
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.GetEndPoint("DW2D");
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
