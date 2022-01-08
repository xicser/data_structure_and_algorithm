#include <stdio.h>
#include <stdlib.h>
#include "BiThreadTree.h"


int main()
{
    BiThrTree tree, head; //tree指向二叉树根结点, head指向线索化后的头结点

    //创建
    CreateBiThrNode(tree);

    //中序线索化
    InOrderThreading(tree, head);

    printf("中序遍历二叉树的结果为:");
    InOrderTraverse(head); //用头结点
    printf("\n");
}
