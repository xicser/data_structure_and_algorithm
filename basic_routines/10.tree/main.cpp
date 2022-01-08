#include <iostream>
#include "linkTree.h"

using namespace std;

int main()
{
    BiTree tree;
    CreateBiTreeRecursion(tree);

    printTreeGraphic(tree);
    printCrease(3);

    cout << endl << isTreeBalance(tree) << endl;

    return 0;
}
