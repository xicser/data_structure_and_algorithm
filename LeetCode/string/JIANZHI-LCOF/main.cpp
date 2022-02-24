#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string reverseLeftWords(string s, int n) {

        reverseSubStr(s, 0, n - 1);
        reverseSubStr(s, n, s.size() - 1);
        reverseSubStr(s, 0, s.size() - 1);

        return s;
    }

private:
    void reverseSubStr(string &s, int i, int j) {

        while (i <= j) {
            char tmpC = s[i];
            s[i] = s[j];
            s[j] = tmpC;
            i++;
            j--;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
