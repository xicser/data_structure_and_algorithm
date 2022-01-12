#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int windowSum = 0;
        int winSizeMin = INT_MAX;

        while (right < nums.size()) {
            windowSum += nums[right];
            right++;

            while (windowSum >= target) {

                int winSize = right - left;
                if (winSizeMin > winSize) {
                    winSizeMin = winSize;
                }

                windowSum -= nums[left];
                left++;
            }
        }

        if (winSizeMin == INT_MAX) {
            return 0;
        }
        return winSizeMin;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
