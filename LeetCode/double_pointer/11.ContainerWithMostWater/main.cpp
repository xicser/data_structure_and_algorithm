#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int result = -1;

        int left = 0, right = height.size() - 1;
        while (left < right) {
            int S = (right - left) * min(height[left], height[right]);
            result = max(result, S);

            // ÿ�ζ��Ѷ̰������ƶ�,
            // ��Ϊ�ƶ��̰��п���ʹ�˵�ˮ���, �ƶ�����һ����ʹ�˵�ˮ����
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;

    cout << sol.maxArea(height) << endl;
    return 0;
}
