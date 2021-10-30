#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int strStr(string text, string pattern) {

        if (text.size() == 0 && pattern.size() == 0) {
            return 0;
        }
        if (text.size() < pattern.size()) {
            return -1;
        }
        if (text.size() != 0 && pattern.size() == 0) {
            return 0;
        }

        vector<int> next(pattern.size(), 0);
        makeNext(pattern, next);

        int index = -1;

        int i = 0, j = 0;  //i指向text, j指向pattern
        while (i < text.size()) {

            //找到一个
            if (j == pattern.size() - 1 && text[i] == pattern[j]) {
                index = i - j;
                break;  //只用找到一个就行
            }

            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            else {
                if (j != 0) {
                    j = next[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return index;
    }

private:
    //计算next数组
    void makeNext(const string &pattern, vector<int> &next)
    {
        int q, k; //q:模版字符串下标；k:最大前后缀长度
        int m = pattern.size();  //模版字符串长度
        next[0] = 0;        //模版字符串的第一个字符的最大前后缀长度为0
        for (q = 1, k = 0; q < m; ++q)       //for循环，从第二个字符开始，依次计算每一个字符对应的next值
        {
            while(k > 0 && pattern[q] != pattern[k])    //递归的求出P[0]···P[q]的最大的相同的前后缀长度k
                k = next[k - 1];            //不理解没关系看下面的分析, 这个while循环是整段代码的精髓所在, 确实不好理解
            if (pattern[q] == pattern[k])               //如果相等，那么最大相同前后缀长度加1
            {
                k++;
            }
            next[q] = k;
        }
    }
};

int main()
{
    Solution sol;

    cout << sol.strStr("aaa", "a") << endl;
    return 0;
}
