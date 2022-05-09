#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

unordered_map<int, string> numMap{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

string path;
string input;
vector<string> result;

void backTracking(int index)
{
    if (path.size() == input.size()) {
        result.emplace_back(path);
        return;
    }

    string str = numMap[ input[index] ];

    for (int i = 0; i < str.size(); i++) {

        path.push_back(str[i]);

        backTracking(index + 1);

        path.pop_back();
    }


}

int main()
{
    cin >> input;
    backTracking(0);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        if (i != result.size() - 1) {
            cout << result[i] << ", ";
        }
        else {
            cout << result[i];
        }
    }
    cout << "]";

    return 0;
}
