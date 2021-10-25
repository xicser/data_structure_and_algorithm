#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int left = 0, right = nums.size() - 1;

        //����ָ�벻������ָ��, ѭ��ִ��
        while (left <= right) {
            //����ָ��ָ���Ԫ�ز�Ϊval, ��ָ������
            if (nums[left] != val) {
                left++;
            }
            else {
                // ������ָ�����ָ����ֵ����, ��ָ������
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;

                right--;
            }
        }

        return left;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int len = sol.removeElement(nums, 2);

    cout << "size = " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}
