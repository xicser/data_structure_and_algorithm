#include <iostream>
#include <vector>

using namespace std;

//-2, 1, -3, 4, -1, 2, 1, -5, 4
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int result = INT_MIN;
        int count = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {

            count += nums[i];

            result = max(result, count);
            if (count < 0) {
                count = 0;
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
