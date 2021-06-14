#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List list;

    list.traverse();
    cout << list.detectionPalindrome() << endl;

    return 0;
}
