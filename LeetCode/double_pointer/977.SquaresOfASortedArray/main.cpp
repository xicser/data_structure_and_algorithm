#include <iostream>
#include <vector>

using namespace std;

/*
��Ŀ˵���������飬�����������

��1��ȫ�Ǹ���
-6��-5��-4��-3��-2

��2��ȫ������
1��3��4��5��6��7

��3�������и�
-3��-2��0��5��6��7

��ϸ�۲죬���ǾͿ�֪���������ǣ�1����2����3�������������Ԫ�ص�ƽ�����ֵһ��������ԭ���������߻������ұߡ�
��ĿҪ����������һ��ƽ�����飬��С�����ź��򷵻أ����������Ѿ��ܹ�ȷ��ƽ�����ֵ�Ĳ���λ���ˡ�
���ǽ����ֵ����ƽ����������һ��λ�þͺ��ˡ�

*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int resultIndex = right;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[resultIndex] = leftSquare;
                resultIndex--;
                left++;
            }
            else {
                result[resultIndex] = rightSquare;
                resultIndex--;
                right--;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> result = sol.sortedSquares(nums);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
