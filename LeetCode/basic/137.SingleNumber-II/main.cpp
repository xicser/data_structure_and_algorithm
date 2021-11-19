#include <iostream>
#include <vector>

using namespace std;

/*
Ϊ�˷������������ǳơ�ֻ������һ�ε�Ԫ�ء�Ϊ���𰸡���
���������е�Ԫ�ض��� int���� 32 λ��������Χ�ڣ�������ǿ������μ���𰸵�ÿһ��������λ�� 0 ���� 1
����أ����Ǵ𰸵ĵ� i ��������λ��i �� 0 ��ʼ��ţ���������Ϊ 0 �� 1�����������зǴ𰸵�Ԫ�أ�ÿһ��Ԫ�ض������� 3 �Σ�
��Ӧ�ŵ� i ��������λ�� 3 �� 0 �� 3 �� 1����������һ����������ǵĺͶ��� 3 �ı���������Ϊ 0 �� 3����
��ˣ�
�𰸵ĵ� i ��������λ��������������Ԫ�صĵ� i ��������λ֮�ͳ��� 3 ��������

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        for (int i = 0; i < 32; i++) {

            int bitSum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & (1 << i)) {
                    bitSum += 1;
                }
            }

            int bitResult = bitSum % 3;

            result |= bitResult << i;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,0,1,0,1,99};

    cout << sol.singleNumber(nums) << endl;
    return 0;
}
