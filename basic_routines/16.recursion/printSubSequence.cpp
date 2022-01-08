#include "printSubSequence.h"

static void process(string &str, int index, int len, string &path)
{
    if (index == len) {

        //打印这条支路
        if (path.size() == 0) {
            cout << "null" << endl;
        }
        else {
            cout << path << endl;
        }

        return;
    }

    //要
    string yes = path + str[index];
    process(str, index + 1, len, yes);

    //不要
    string no = path;
    process(str, index + 1, len, no);
}

//打印一个字符串的全部子序列
void printSubSequence(string str)
{
    int len = str.size();
    string path;
    path.clear();

    process(str, 0, len, path);
}
