#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
private:
    vector<int>& nums;
//public:
    //������
//    Solution(vector<int>& nums) : nums(nums) {
//        srand((unsigned)time(NULL));
//    }
//
//    int pick(int target) {
//        vector<int> indexes;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == target) {
//                indexes.push_back(i);
//            }
//        }
//
//        int random = rand() % indexes.size();    //����0 ~ (cnt - 1)�������
//
//        return indexes[random];
//    }

public:
    //��ˮ�ط�
    Solution(vector<int>& nums) : nums(nums) {
        srand((unsigned)time(NULL));
    }

    int pick(int target) {

        int index = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt++; //��¼��ǰ�ҵ��˵ڼ���target

                // ����һ��0��(cnt - 1)֮���һ�������, һ��cnt��, �Ǹ�cnt == 0�ĸ��ʾ��� 1 / cnt
                if ( rand() % cnt == 0 ) {
                    // �� 1 / cnt �ĸ��ʱ��������
                    index = i;
                }
            }
        }

        return index;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
