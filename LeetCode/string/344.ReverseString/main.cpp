#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0, right = s.size() - 1;
        while (left <= right) {
            int tmp;
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left++;
            right--;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
