#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 23:59
    int convertToMinutes(string time) {

        string subHour = time.substr(0, 2);
        string subMin = time.substr(3, 2);

        if (subHour == "00" && subMin == "00") {
            subHour = "23";
            subMin = "60";
        }

        int h = atoi(subHour.c_str());
        int m = atoi(subMin.c_str());

        return 60 * h + m;
    }

public:
    int findMinDifference(vector<string>& timePoints) {

        if (timePoints.size() > 1440) {
            return 0;
        }

        vector<int> timesMin;
        for (int i = 0; i < timePoints.size(); i++) {
            timesMin.push_back(convertToMinutes(timePoints[i]));
        }
        sort(timesMin.begin(), timesMin.end());

        int minDelta = INT_MAX;
        for (int i = 1; i < timesMin.size(); i++) {
            int delta = abs(timesMin[i] - timesMin[i - 1]);
            minDelta = min(minDelta, delta);
        }

        //第一个和最后一个反向差有可能最小
        int perhaps = 1440 - timesMin[timesMin.size() - 1] + timesMin[0];

        return min(perhaps, minDelta);
    }
};

int main()
{
    Solution sol;
    vector<string> timePoints = { "05:31", "22:08", "00:35" };
    cout << sol.findMinDifference(timePoints) << endl;
}
