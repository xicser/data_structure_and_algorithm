#include "printSubSequence.h"

static void process(string &str, int index, int len, string &path)
{
    if (index == len) {

        //��ӡ����֧·
        if (path.size() == 0) {
            cout << "null" << endl;
        }
        else {
            cout << path << endl;
        }

        return;
    }

    //Ҫ
    string yes = path + str[index];
    process(str, index + 1, len, yes);

    //��Ҫ
    string no = path;
    process(str, index + 1, len, no);
}

//��ӡһ���ַ�����ȫ��������
void printSubSequence(string str)
{
    int len = str.size();
    string path;
    path.clear();

    process(str, 0, len, path);
}
