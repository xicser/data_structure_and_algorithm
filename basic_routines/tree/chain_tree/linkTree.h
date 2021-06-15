#ifndef __LINK_TREE_H__
#define __LINK_TREE_H__


//������Ԫ������
typedef char TElemType;

//���Ľ��
typedef struct BiTNode
{
	TElemType		 data;				//������
	struct BiTNode	*lchild, *rchild;	//���Һ���ָ��
} BiTNode, *BiTree;

/*������*/

//�������������������н���ֵ��TElemType�����ո��ַ���ʾ����
//������������ʾ�Ķ�����T
void CreateBiTreeRecursion(BiTree &T);

/* �ݹ���� */
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

int getMaxWidthUseMap(BiTree pTree);    //��ȡ�����������һ��

#endif
