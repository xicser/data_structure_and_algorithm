#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        unordered_map<int, int> changeMap;
        changeMap[5] = 0;
        changeMap[10] = 0;
        changeMap[20] = 0;

        for (int i = 0; i < bills.size(); i++) {

            switch (bills[i]) {
            case 5: {
                changeMap[5]++;
                break;
            }
            case 10: {
                //只有5块能找开10块
                if (changeMap[5] >= 1) {
                    changeMap[5]--;
                    changeMap[10]++;
                } else {
                    return false;
                }
                break;
            }
            case 20: {
                //优先使用10块找
                if (changeMap[10] >= 1 && changeMap[5] >= 1) {
                    changeMap[5]--;
                    changeMap[10]--;
                    changeMap[20]++;
                }
                //也可以使用3个五块
                else if (changeMap[5] >= 3) {
                    changeMap[5] -= 3;
                    changeMap[20]++;
                }
                else {
                    return false;
                }
                break;
            }
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
