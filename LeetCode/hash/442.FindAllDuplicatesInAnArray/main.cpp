#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> timesMap;

        for (int num : nums) {
            timesMap[num]++;
        }

        for (auto num : timesMap) {
            if (num.second == 2) {
                result.push_back(num.first);
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
