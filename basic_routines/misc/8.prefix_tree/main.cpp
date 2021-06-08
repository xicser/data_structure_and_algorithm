#include <iostream>
#include "PrefixTree.h"

using namespace std;

int main()
{
    PrefixTree *pre = new PrefixTree();
    pre->insertString("abc");
    pre->insertString("abc");
    pre->insertString("abcdef");
    pre->insertString("abcdef");

    pre->deleteString("abcdef");

    cout << pre->prefixStringCount("ab") << endl;
    cout << pre->searchStringCount("abcdef") << endl;

    pre->deleteString("abcdef");

    cout << pre->prefixStringCount("ab") << endl;
    cout << pre->searchStringCount("abcdef") << endl;

    delete pre;

    return 0;
}
