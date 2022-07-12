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

            int m = i;
            while (m < version1.size() && version1[m] != '.') {
                m++;
            }
            int val1 = m > i ? atoi(version1.substr(i, m - i).c_str()) : 0;

            int n = j;
            while (n < version2.size() && version2[n] != '.') {
                n++;
            }
            int val2 = n > j ? atoi(version2.substr(j, n - j).c_str()) : 0;

            if (val1 > val2) {
                return 1;
            }
            else if (val1 < val2) {
                return -1;
            }

            i = m + 1;
            j = n + 1;
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    string version1 = "0.1";
    string version2 = "1.1";

    std::cout << sol.compareVersion(version1, version2) << endl;

    return 0;
}
