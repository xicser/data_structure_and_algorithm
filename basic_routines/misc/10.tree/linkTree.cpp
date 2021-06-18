
/*

����������ʽ�洢ʵ��:
          1
      2       3
    4   5   6   7

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

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <map>
#include <queue>
#include "linkTree.h"

using namespace std;

// ������� �ݹ������������н���ֵ, '^'�ַ���ʾ����
// ������������ʾ�Ķ�����T
void CreateBiTreeRecursion(BiTree &T)
{
    TElemType ch = getchar();
    fflush(stdin);
    if (ch == '^') {
        T = nullptr;//��������֤��Ҷ�ӽ�㣬�ݹ��������
        return;
    }

    //���ɽ��
    T = (BiTNode *)malloc(sizeof(BiTNode));
    if (T == nullptr) {
        return;
    }
    T->data = ch;

    //����������
    printf("����������:\n");
    CreateBiTreeRecursion(T->lchild);

    //����������
    printf("����������:\n");
    CreateBiTreeRecursion(T->rchild);
}

//�ݹ��������
//TΪָ�������������ָ��
//level����ָʾԪ������һ��
void PreOrderTraverseRecursion(BiTree T, int level)
{
    if (T == nullptr)return;//�ݹ�����������ﵽ��Ҷ�ӽ��

    printf("%c�ڵ�%d��\n", T->data, level);//���ʸ����
    level++;
    PreOrderTraverseRecursion(T->lchild, level);//����������
    PreOrderTraverseRecursion(T->rchild, level);//����������
}

//�ݹ��������
//TΪָ�������������ָ��
void InOrderTraverseRecursion(BiTree T)
{
    if (T == nullptr)return;

    InOrderTraverseRecursion(T->lchild);
    printf("%c ", T->data);
    InOrderTraverseRecursion(T->rchild);
}

//�ݹ�������
//TΪָ�������������ָ��
void PostOrderTraverseRecursion(BiTree T)
{
    if (T == nullptr)return;

    PostOrderTraverseRecursion(T->lchild);
    PostOrderTraverseRecursion(T->rchild);
    printf("%c ", T->data);
}

/* ͼ�λ�������ӡһ���� */
static void printTree(BiTree T, int depth, int wordLen)
{
    if (T == nullptr) {
        return;
    }

    printTree(T->rchild, depth + 1, wordLen);       //��

    for (int i = 0; i < depth; i++) {               //��
        printf("    ");
    }
    printf("%c\n", T->data);

    printTree(T->lchild, depth + 1, wordLen);       //��
}
void printTreeGraphic(BiTree T)
{
    if (T == nullptr) {
        return;
    }

    printTree(T, 1, 20);
}

/* ��ȡ��������µĺ�̽ڵ� */
static BiTree getLeftMostNode(BiTree node)
{
    if (node == nullptr) {
        return node;
    }
    while (node->lchild != nullptr) {
        node = node->lchild;
    }
    return node;
}
BiTree getInOrderTraverseSuccessorNode(BiTree treeNode)
{
    if (treeNode == nullptr) {
        return nullptr;
    }

    BiTree curNode = treeNode;

    //�����ǰ�ڵ���������, ��̽ڵ��������������, ������Ǹ��ڵ�
    if (curNode->rchild != nullptr) {
        return getLeftMostNode(curNode->rchild);
    }
    //����
    else {
        BiTree parent = curNode->parent;
        while (parent != nullptr && parent->rchild == curNode) { // ��ǰ�ڵ����丸�׽ڵ��Һ���, ��һֱ������, ֱ�����丸�׽ڵ������
            curNode = parent;
            parent = curNode->parent;
        }
        return parent;
    }
}
