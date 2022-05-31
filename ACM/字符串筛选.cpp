#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串
     */
    string unique_string(string s) {
        
        unordered_set<char> st;
        string result;

        for (int i = 0; i < s.size(); i++) {

            if (st.count(s[i]) == 0) {
                st.insert(s[i]);

                result.push_back(s[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    std::cout << sol.unique_string("aab") << endl;
}

