#include <stdio.h>
#include <stdlib.h>
#include "BiThreadTree.h"


int main()
{
    BiThrTree tree, head; //treeָ������������, headָ�����������ͷ���

    //����
    CreateBiThrNode(tree);

    //����������
    InOrderThreading(tree, head);

    printf("��������������Ľ��Ϊ:");
    InOrderTraverse(head); //��ͷ���
    printf("\n");
}
