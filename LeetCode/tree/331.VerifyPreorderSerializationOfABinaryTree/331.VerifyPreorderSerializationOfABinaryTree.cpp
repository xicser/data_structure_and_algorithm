#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
private:
    //分割字符串
    vector<string> split(const string& str, const string& pattern)
    {
        char* strc = new char[strlen(str.c_str()) + 1];
        strcpy(strc, str.c_str());

        vector<string> resultVec;
        char* tmpStr = strtok(strc, pattern.c_str());
        cout << tmpStr << endl;
        while (tmpStr != NULL)
        {
            resultVec.push_back(string(tmpStr));
            tmpStr = strtok(NULL, pattern.c_str());
            cout << tmpStr << endl;
        } 

        delete[] strc;

        return resultVec;
    };

public:
    //"9,331,4,#,#,1,#,#,212,#,6,#,#"
    bool isValidSerialization(string preorder) {

        string pattern = ",";
        vector<string> resultVec = split(preorder, pattern);
        stack<string> st;

        int len = resultVec.size();
        for (int i = 0; i < len; i++) {

            string tmpStr = resultVec[i];
            st.push(tmpStr);

            //每次都看一下栈顶前三个元素是否是 # # x
            while (st.size() >= 3) {
                string top = st.top();
                st.pop();

                string second = st.top();
                st.pop();

                string third = st.top();
                st.pop();

                if (top == "#" && second == "#" && third != "#") {
                    st.push("#");
                }
                else {
                    //恢复
                    st.push(third);
                    st.push(second);
                    st.push(top);
                    break;
                }
            }
        }

        return st.size() == 1 && st.top() == "#";
    }
};

int main()
{
    Solution sol;
    cout << sol.isValidSerialization("9,331,4,#,#,1,#,#,212,#,6,#,#") << endl;
}
