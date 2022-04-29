#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
TestVariable
test_variable
TEST_VARIABLE，
*/
class Solution {
public:

    string format(string name) {

        if (name.size() == 0) {
            return "";
        }

        if (has_(name) == true) {
            return cope_(name);
        }
        else {
            name[0] = lower(name[0]);
            return name;
        }
    }

private:
    vector<string> tokens;

    string cope_(const string& str) {

        for (int i = 0; i < str.size(); ) {
            if (str[i] != '_') {

                int j = i;
                while (j < str.size() && str[j] != '_') {
                    j++;
                }

                tokens.push_back(str.substr(i, j - i));

                i = j + 1;
            }
            else {
                i++;
            }
        }

        string result;
        for (int i = 0; i < tokens.size(); i++) {

            for (int j = 0; j < tokens[i].size(); j++) {
                tokens[i][j] = lower(tokens[i][j]);
            }

            if (i != 0) {
                tokens[i][0] = upper(tokens[i][0]);
            }

            result += tokens[i];
        }

        return result;
    }

    char lower(char c) {
        if (isLow(c) == true) {
            return c;
        }
        return c + 32;
    }

    char upper(char c) {
        if (isBig(c) == true) {
            return c;
        }
        return c - 32;
    }

    bool isLow(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool isBig(char c) {
        return 'A' <= c && c <= 'Z';
    }

    bool has_(const string& str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '_') {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.format("TestVariable") << endl;
}

