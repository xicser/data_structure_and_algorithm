
/*

����������ʽ�洢ʵ��
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

/* ���������� */
void BiTreeCopyRecursion(BiTree pTree, BiTree &pTreeOut)
{
    if (pTree == nullptr) {
        pTreeOut = nullptr;
        return;
    }

    pTreeOut = (BiTree)malloc(sizeof(BiTNode));
    pTreeOut->data = pTree->data;

    BiTreeCopyRecursion(pTree->lchild, pTreeOut->lchild);
    BiTreeCopyRecursion(pTree->rchild, pTreeOut->rchild);
}

/* ��ȡ��� */
int GetDepth(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }

    int depthLeft = GetDepth(pTree->lchild);
    int depthRight = GetDepth(pTree->rchild);

    return max(depthLeft, depthRight) + 1;
}

/* ��ȡ������ */
int GetNodeCount(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }

    int nodeCntLeft = GetNodeCount(pTree->lchild);
    int nodeCntRight = GetNodeCount(pTree->rchild);

    return nodeCntLeft + nodeCntRight + 1;
}

/* ��ȡҶ�ӽ����� */
int GetLeafNodeCount(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }
    if (pTree->lchild == nullptr && pTree->rchild == nullptr) {
        return 1;
    }

    int nodeCntLeftLeaf = GetLeafNodeCount(pTree->lchild);
    int nodeCntRightLeaf = GetLeafNodeCount(pTree->rchild);

    return nodeCntLeftLeaf + nodeCntRightLeaf;
}

/*
�ǵݹ��������
1, ���ڵ��ջ;
2, �����ʹ�ӡ;
3, ������Һ���, ѹ���Һ���;
3, ���������, ѹ������;
*/
//pTreeΪָ�������ָ��
void PreOrderTraverse(BiTree pTree)
{
    if (pTree == nullptr) {
        return;
    }

    stack<BiTree> st;

    st.push(pTree);
    while (!st.empty()) {

        BiTree pCur = st.top();
        st.pop();
        printf("%c ", pCur->data);

        if (pCur->rchild != nullptr) {
            st.push(pCur->rchild);
        }
        if (pCur->lchild != nullptr) {
            st.push(pCur->lchild);
        }
    }
}

/*

�ǵݹ��������:
1, ������߽�������ջ
2, 1�ߵ���ͷ��ʱ��, ��ջ��ӡ
3, ��������, �ظ�1

*/
//pTreeΪָ�������ָ��
void InOrderTraverse(BiTree pTree)
{
    stack<BiTree> st;
    BiTree pCur = pTree;

    while (pCur || !st.empty()) {
        if (pCur) {
            st.push(pCur);
            pCur = pCur->lchild;
        }
        else {
            pCur = st.top();
            st.pop();
            printf("%c ", pCur->data);
            pCur = pCur->rchild;
        }
    }
}

//�ǵݹ�������
//pTreeΪָ�������ָ��
void PostOrderTraverse(BiTree pTree)
{
    if (pTree == nullptr) {
        return;
    }

    stack<BiTree> stOut;
    stack<BiTree> st;

    st.push(pTree);
    while (!st.empty()) {

        BiTree pCur = st.top();
        st.pop();
        stOut.push(pCur);

        if (pCur->lchild != nullptr) {
            st.push(pCur->lchild);
        }
        if (pCur->rchild != nullptr) {
            st.push(pCur->rchild);
        }
    }

    while (!stOut.empty()) {
        BiTree pCur = stOut.top();
        stOut.pop();
        printf("%c ", pCur->data);
    }
}

//�������
//pTreeΪָ�������ָ��
void LevelOrderTraverse(BiTree pTree)
{
    queue<BiTree> que;
    BiTree pCur = pTree;

    que.push(pCur);
    while (!que.empty())//�����зǿ�
    {
        pCur = que.front();
        que.pop();
        printf("%c ", pCur->data);

        if (pCur->lchild) {
            que.push(pCur->lchild);
        }
        if (pCur->rchild) {
            que.push(pCur->rchild);
        }
    }
}

/* ��ȡ�����������һ�� */
int getMaxWidthUseMap(BiTree pTree)
{
    if (pTree == nullptr) {
        return 0;
    }

    map<BiTree, int> levelMap; //��¼�ڵ�����һ��
    queue<BiTree> que;

    BiTree pCur = pTree;
    que.push(pCur);
    levelMap[pCur] = 1;       //���ڵ��ڵ�һ��

    int curLevel = 1;         //��ǰͳ�ƵĲ�
    int curLevelNodes = 0;    //��ǰͳ�ƵĲ��ϵĽڵ���
    int maxNodes = 0;
    while (!que.empty())      //�����зǿ�
    {
        pCur = que.front();
        que.pop();

        int curNodeLevel = levelMap[pCur];
//        printf("%c ", pCur->data);

        if (pCur->lchild) {
            que.push(pCur->lchild);
            levelMap[pCur->lchild] = curNodeLevel + 1;  //��¼���ӽڵ�����һ��
        }
        if (pCur->rchild) {
            que.push(pCur->rchild);
            levelMap[pCur->rchild] = curNodeLevel + 1;  //��¼�Һ��ӽڵ�����һ��
        }

        if (curNodeLevel == curLevel) {
            curLevelNodes++;
        }
        else {
            maxNodes = max(maxNodes, curLevelNodes);
            curLevel++;
            curLevelNodes = 1;
        }
    }
    maxNodes = max(maxNodes, curLevelNodes);

    return maxNodes;
}
