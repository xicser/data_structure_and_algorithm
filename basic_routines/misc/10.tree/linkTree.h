#ifndef __LINK_TREE_H__
#define __LINK_TREE_H__

#include <string>

using namespace std;

//������Ԫ������
typedef char TElemType;

//���Ľ��
typedef struct BiTNode
{
    TElemType        data;				//������
    struct BiTNode  *lchild, *rchild;	//���Һ���ָ��
    struct BiTNode  *parent;            //���ڵ�ָ��
} BiTNode, *BiTree;


//�������������������н���ֵ��TElemType�����ո��ַ���ʾ����
//������������ʾ�Ķ�����T
void CreateBiTreeRecursion(BiTree &T);

/* �ݹ���ز��� */
void PreOrderTraverseRecursion(BiTree T, int level);       //�������
void InOrderTraverseRecursion(BiTree T);                   //�������
void PostOrderTraverseRecursion(BiTree T);                 //�������

void printTreeGraphic(BiTree T);                           //ͼ�λ�������ӡһ����
BiTree getInOrderTraverseSuccessorNode(BiTree treeNode);   //��ȡ��������µĺ�̽ڵ�
void printCrease(int N);                                   //��ӡ�ۺ�
bool isTreeBalance(BiTree T);                              //�ж�һ�����Ƿ���ƽ�������
int  getFarestDistance(BiTree T);                          //��ȡһ�����ϵ�������, ����: �������������ڵ�
BiTree getMaxBiSearchSubTree(BiTree T);                    //������Ŷ����������Ķ�������������ͷ�ڵ�(�����������������ṹ���������)



#endif
