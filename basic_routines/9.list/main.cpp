#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List list;

    list.insertHead('a');
    list.insertHead('b');
    list.insertHead('c');
    list.insertHead('d');
    list.traverse();
    cout << list.detectionPalindrome() << endl;

    return 0;
}
