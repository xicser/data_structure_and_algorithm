// 逛街.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param heights int整型vector
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int>& heights) {

        //单调栈
        stack<int> leftStk, rightStk;
        vector<int> leftVec(heights.size(), 0), rightVec(heights.size(), 0);

        for (int i = 0; i < heights.size(); i++) {
            int j = heights.size() - i - 1;

            leftVec[i] = leftStk.size();
            while (leftStk.empty() == false && leftStk.top() <= heights[i]) {
                leftStk.pop();
            }
            leftStk.push(heights[i]);

            rightVec[j] = rightStk.size();
            while (rightStk.empty() == false && rightStk.top() <= heights[j]) {
                rightStk.pop();
            }
            rightStk.push(heights[j]);
        }

        //求和
        for (int i = 0; i < leftVec.size(); i++) {
            leftVec[i] += rightVec[i] + 1;
        }

        return leftVec;
    }
};

int main()
{
    vector<int> heights = { 5,3,8,3,2,5 };
    Solution sol;
    vector<int> result = sol.findBuilding(heights);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    std::cout << "\n";
}
