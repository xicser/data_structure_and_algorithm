#include <stdio.h>
#include <stdlib.h>
#include "BiThreadTree.h"

/*
1
2
4
^
^
5
^
^
3
6
^
^
7
^
^
*/

//������������ʼ��, ����������
void CreateBiThrNode(BiThrTree &tree)
{
	TElemType ch = getchar();
	fflush(stdin);
    if (ch=='^') {
        tree = nullptr;
    }
    else {
        tree = (BiThrTree)malloc(sizeof(BiThrNode));
        tree->data = ch;
        tree->LTag = Link; //Ĭ�϶�����
        tree->RTag = Link;

        printf("����������:\n");
        CreateBiThrNode(tree->lchild);

        printf("����������:\n");
        CreateBiThrNode(tree->rchild);
    }
}

//����������������
static void InThreading(BiThrTree tree, BiThrTree &pre)
{
    if(tree == nullptr) {
        return;
    }

    InThreading(tree->lchild, pre);

    //�������Ϊ��, lchildָ������ǰ��
    if (tree->lchild == nullptr) {
        tree->LTag = Thread;
        tree->lchild = pre;
    }

    //����������е�ǰһ�������Һ���Ϊ��, rchildָ��������
    if (pre->rchild == nullptr) {
        pre->RTag = Thread;
        pre->rchild = tree;
    }
    pre = tree; //��pre��¼��һ��������

    InThreading(tree->rchild, pre);
}

//Ϊ�����������������ͷ���, ʹ֮����˫�����
void InOrderThreading(BiThrTree tree, BiThrTree &head)
{
    //����ͷ���
    head = (BiThrTree)malloc(sizeof(BiThrNode));
    head->LTag = Link;
    head->RTag = Thread;
    head->lchild = tree;  //ͷ��������ָ������
    head->rchild = head;  //ͷ�����Һ���ָ��ͷ����Լ�

    //������
    BiThrTree pre;
    pre = head;           //preָ��ͷ���
    InThreading(tree, pre);

    //InThreading������, preָ�������������һ�����
    pre->rchild = head;
    pre->RTag = Thread;
    head->rchild = pre;  //ͷ�����Һ���ָ�������������һ�����
}

//�ǵݹ������������������
void InOrderTraverse(BiThrTree head)
{
    BiThrNode *p = head->lchild;
    while (p != head) {
        while (p->LTag == Link) {
            p = p->lchild;    //�����������ľ�ͷ
        }
        printf("%c", p->data);

        while (p->RTag == Thread && p->rchild != head) {  //���ʸý��ĺ�̽��
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}
