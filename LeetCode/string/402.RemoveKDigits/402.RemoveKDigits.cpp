#include <iostream>
#include <string>
#include <stack>

using namespace std;

// num = "1432219", k = 3
class Solution {
public:
    string removeKdigits(string num, int k) {

        //要移除的数字个数 >= num位数
        if (num.size() <= k) {
            return "0";
        }

        bool has_remove = false;
        string result;
        stack<char> stk;
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && stk.empty() == false && stk.top() > num[i]) {
                stk.pop();
                has_remove = true;
                k--;
            }

            stk.push(num[i]);
        }

        // 没有删除过, 说明原数字就是一个升序的, 直接删除后面的k个数
        if (has_remove == false) {
            return num.replace(num.size() - k, k, "");
        }

        while (stk.empty() == false) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        
        //移除前导0
        int len = 0;
        while (len < result.size() && result[len] == '0') {
            len++;
        }
        result.replace(0, len, "");

        if (k >= result.size()) {
            return "0";
        }

        if (result.size() == 0) {
            return "0";
        }
        return result;
    }
};

int main()
{
    Solution sol;
    
    std::cout << sol.removeKdigits("10001", 4) << endl;

    return 0;
}
