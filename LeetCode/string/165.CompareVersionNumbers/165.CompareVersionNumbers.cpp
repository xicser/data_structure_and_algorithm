#include <string>
#include <iostream>

using namespace std;

/*
    string version1 = "1.0";
    string version2 = "1.0.0";
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;

        while (i < version1.size() || j < version2.size()) {

            int k = i;
            while (k < version1.size() && version1[k] != '.') {
                k++;
            }

            //k > i表示, 能够得到非空数字字符串
            int val1 = k > i ? atoi(version1.substr(i, k - i).c_str()) : 0;

            int m = j;
            while (m < version2.size() && version2[m] != '.') {
                m++;
            }
            int val2 = m > j ? atoi(version2.substr(j, m - j).c_str()) : 0;

            if (val1 > val2) {
                return 1;
            }
            else if (val1 < val2) {
                return -1;
            }

            i = k + 1;
            j = m + 1;
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    string version1 = "1.01";
    string version2 = "1.001";

    std::cout << sol.compareVersion(version1, version2) << endl;

    return 0;
}
