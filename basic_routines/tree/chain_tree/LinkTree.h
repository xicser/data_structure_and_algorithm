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

/*�ݹ麯��*/
void PreOrderTraverseRecursion(BiTree T, int level);//�������
void InOrderTraverseRecursion(BiTree T);//�������
void PostOrderTraverseRecursion(BiTree T);//�������


/*�ǵݹ麯��*/
void PreOrderTraverse(BiTree pTree);//�������
void InOrderTraverse(BiTree pTree);//�������
void PostOrderTraverse(BiTree pTree);//�������
void LevelOrderTraverse(BiTree pTree);//�������


#endif
