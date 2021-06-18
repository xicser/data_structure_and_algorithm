
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
#include <algorithm>
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

/* ��ӡ�ۺ�
   ���������ڵ㶼�ǰ�, ���������ڵ㶼��͹
 */
static void printCreaseRecursion(int i, int N, bool down)
{
    if (i > N) {
        return;
    }

    printCreaseRecursion(i + 1, N, true);
    down == true ? printf("��") : printf("͹");
    printCreaseRecursion(i + 1, N, false);
}
void printCrease(int N)
{
    printCreaseRecursion(1, N, true);
}

/* �ж�һ�����Ƿ���ƽ������� */
typedef struct {
    bool isBalance;
    int  height;
} Info_t;
static Info_t checkIsBalance(BiTree T)
{
    if (T == nullptr) {
        Info_t node;
        node.height = 0;
        node.isBalance = true;
        return node;
    }

    Info_t infoLeft = checkIsBalance(T->lchild);
    Info_t infoRight = checkIsBalance(T->rchild);

    Info_t node;
    node.height = max(infoLeft.height, infoRight.height) + 1;

    if (infoLeft.isBalance == true && infoRight.isBalance == true && abs(infoLeft.height - infoRight.height) <= 1 ) {
        node.isBalance = true;
    }
    else {
        node.isBalance = false;
    }

    return node;
}
bool isTreeBalance(BiTree T)
{
    return checkIsBalance(T).isBalance;
}


/* ��ȡһ�����ϵ�������, ����: �������������ڵ� */
int FarestDistance(BiTree T)
{
    if (T == nullptr) {
        return 0;
    }

    int leftHeight = FarestDistance(T->lchild);
    int rightHeight = FarestDistance(T->rchild);



}


int getFarestDistance(BiTree T)
{
    return FarestDistance(T);
}
























