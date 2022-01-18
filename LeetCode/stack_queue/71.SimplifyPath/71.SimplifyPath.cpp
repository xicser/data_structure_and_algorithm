#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    stack<string> stk;

public:
    //   "/a//b////c/d//././/.."
    string simplifyPath(string path) {

        for (int i = 0; i < path.size(); ) {
            char c = path[i];

            switch (c) {
                case '/': {
                    i++;
                    break;
                }
                case '.': {
                    int index = i;
                    string tmpStr;
                    while (index < path.size() && path[index] != '/') {
                        tmpStr.push_back(path[index]);
                        index++;
                    }
                    if (tmpStr == ".") {
                        i = index;
                        continue;
                    }
                    else if (tmpStr == "..") {
                        if (stk.empty() == false) {
                            stk.pop();
                        }
                    }
                    else {
                        stk.push(tmpStr);
                    }
                    i = index;
                    break;
                }

                default: {
                    int index = i;
                    string tmpStr;
                    while (index < path.size() && path[index] != '/') {
                        tmpStr.push_back(path[index]);
                        index++;
                    }
                    stk.push(tmpStr);
                    i = index;

                    break;
                }
            }
        }

        vector<string> resultStr;
        string result;

        while (stk.empty() == false) {
            resultStr.push_back(stk.top());
            resultStr.push_back("/");
            stk.pop();
        }
        reverse(resultStr.begin(), resultStr.end());
        
        for (string& tmpStr: resultStr) {
            result += tmpStr;
        }
        if (result.size() == 0) {
            result.push_back('/');
        }

        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.simplifyPath("/a//b////c/d//././/..") << endl;
}

