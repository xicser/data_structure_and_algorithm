#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candies(ratings.size(), 1);

        //Ö»¿¼ÂÇ×ó±ß
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        //Ö»¿¼ÂÇÓÒ±ß
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i + 1] + 1, candies[i]);
            }
        }

        //ÇóºÍ
        int result = 0;
        for (int i : candies) {
            result += i;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> ratings1 = {1,0,2};
    vector<int> ratings2 = {1,2,2};

    cout << sol.candy(ratings1) << endl;
    cout << sol.candy(ratings2) << endl;

    return 0;
}
