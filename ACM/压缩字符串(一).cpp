#include <iostream>
#include <string>

using namespace std;

//aabcccccaaa
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param param string字符串
     * @return string字符串
     */
    string compressString(string param) {
        
        string result;
        for (int i = 0; i < param.size(); ) {

            int j = i + 1;
            while (j < param.size() && param[j] == param[j - 1]) {
                j++;
            }

            int cnt = j - i;

            if (cnt != 1) {
                result.push_back(param[i]);
                result += to_string(cnt);
            }
            else {
                result.push_back(param[i]);
            }

            i = j;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.compressString("shopeew") << endl;
}
