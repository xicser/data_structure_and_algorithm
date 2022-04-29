#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    int petalsBreak(vector<int>& petals) {
        
        int result = 0;

        for (int val : petals) {
            if (val % 2 == 0) {
                result += val / 2;
            }
            else {
                result += val / 2 + 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> petals = { 4,2,1 };
    std::cout << sol.petalsBreak(petals) << endl;
}
