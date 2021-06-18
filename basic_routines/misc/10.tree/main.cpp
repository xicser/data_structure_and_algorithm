#include <iostream>
#include "linkTree.h"

using namespace std;

int main()
{
    BiTree tree;
    CreateBiTreeRecursion(tree);

    printTreeGraphic(tree);

    return 0;
}
