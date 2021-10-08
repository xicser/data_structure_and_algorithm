#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        unordered_map<int, int> changes; //记录每种零钱的个数
        changes[5] = 0;
        changes[10] = 0;
        changes[20] = 0;

        for (unsigned int i = 0; i < bills.size(); i++) {
            switch(bills[i]) {
                case 5: {
                    changes[5]++;
                    break;
                }
                case 10: {
                    if (changes[5] > 0) {
                        changes[5]--;
                        changes[10]++;
                    }
                    else {
                        return false;
                    }
                    break;
                }
                case 20: {
                    //优先消耗10美元
                    if (changes[5] > 0 && changes[10] > 0) {
                        changes[5]--;
                        changes[10]--;
                        changes[20]++;
                    }
                    else if (changes[5] >= 3 && changes[10] == 0) {
                        changes[5] -= 3;
                        changes[20]++;
                    }
                    else {
                        return false;
                    }

                    break;
                }
                default: break;
            }
        }

        return true;
    }
};




int main()
{
    Solution sol;
    vector<int> bills1 = {5,5,10};
    vector<int> bills2 = {10,10};

    cout << sol.lemonadeChange(bills1) << endl;
    cout << sol.lemonadeChange(bills2) << endl;

    return 0;
}
