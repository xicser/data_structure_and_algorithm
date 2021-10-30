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

        int i = 0, j = 0;  //iָ��text, jָ��pattern
        while (i < text.size()) {

            //�ҵ�һ��
            if (j == pattern.size() - 1 && text[i] == pattern[j]) {
                index = i - j;
                break;  //ֻ���ҵ�һ������
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
    //����next����
    void makeNext(const string &pattern, vector<int> &next)
    {
        int q, k; //q:ģ���ַ����±ꣻk:���ǰ��׺����
        int m = pattern.size();  //ģ���ַ�������
        next[0] = 0;        //ģ���ַ����ĵ�һ���ַ������ǰ��׺����Ϊ0
        for (q = 1, k = 0; q < m; ++q)       //forѭ�����ӵڶ����ַ���ʼ�����μ���ÿһ���ַ���Ӧ��nextֵ
        {
            while(k > 0 && pattern[q] != pattern[k])    //�ݹ�����P[0]������P[q]��������ͬ��ǰ��׺����k
                k = next[k - 1];            //�����û��ϵ������ķ���, ���whileѭ�������δ���ľ�������, ȷʵ�������
            if (pattern[q] == pattern[k])               //�����ȣ���ô�����ͬǰ��׺���ȼ�1
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
