#include "kmp.h"

/* 获取前缀表(next数组) */
static void getPrefixTable(char *pattern, int *prefixTable, int n)
{
    prefixTable[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n) {
        if (prefixTable[i] == prefixTable[len]) {
            len++;
            prefixTable[i] = len;
            i++;
        }
        else {
            if (len > 0) {
                len = prefixTable[len - 1];
            }
            else {
                prefixTable[i] = len;
                i++;
            }
        }
    }

}




/* KMP查找算法
参数:
text: 主串
pattern: 模式串
hasFound: 出参, 表示是否找到过pattern

返回值:
模式串在主串中的下标集合


T: a b a a c a b a b c a c
P: a b a b c
 */

vector<int> KMP_Check(char *text, char *pattern, bool *hasFound)
{
    vector<int> posRet;

    //计算前缀表







    *hasFound = true;
    return posRet;
}












/*
KMP算法重载函数
*/
vector<int> KMP_Check(string text, string pattern, bool *hasFound)
{
    return KMP_Check(text.c_str(), pattern.c_str(), hasFound);
}
