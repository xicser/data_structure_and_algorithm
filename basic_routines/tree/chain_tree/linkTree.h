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
} BiTNode, *BiTree;

/*������*/

//�������������������н���ֵ��TElemType�����ո��ַ���ʾ����
//������������ʾ�Ķ�����T
void CreateBiTreeRecursion(BiTree &T);

/* �ݹ���ز��� */
void PreOrderTraverseRecursion(BiTree T, int level);       //�������
void InOrderTraverseRecursion(BiTree T);                   //�������
void PostOrderTraverseRecursion(BiTree T);                 //�������
void BiTreeCopyRecursion(BiTree pTree, BiTree &pTreeOut);  //����������
int  GetDepth(BiTree pTree);                               //��ȡ���
int  GetNodeCount(BiTree pTree);                           //��ȡ������
int  GetLeafNodeCount(BiTree pTree);                       //��ȡҶ�ӽ�����


/* �ǵݹ���� */
void PreOrderTraverse(BiTree pTree);    //�������
void InOrderTraverse(BiTree pTree);     //�������
void PostOrderTraverse(BiTree pTree);   //�������
void LevelOrderTraverse(BiTree pTree);  //�������

/* ������ز��� */
int  getMaxWidthUseMap(BiTree pTree);   //��ȡ�����������һ��Ŀ��
void preOrderSerialize(BiTree pTree);   //�������л�
void preOrderDeserialization(string serial, BiTree &T);    //�������л�
void levelOrderSerialize(BiTree pTree); //�������л�
void levelOrderDeserialize(string serial, BiTree &pTree);  //�������л�



#endif
