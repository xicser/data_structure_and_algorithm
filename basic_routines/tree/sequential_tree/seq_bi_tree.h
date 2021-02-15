#ifndef __SEQ_BI_TREE_H__
#define __SEQ_BI_TREE_H__

using namespace std;

#define MAX_SIZE (1024)

typedef signed char ElemType;

//����˳��������
typedef ElemType SeqTree[MAX_SIZE];

void InitSeqTree(SeqTree tree);             //��ʼ���ն�����
void CreatSeqTree(SeqTree tree, int i);     //iΪ������±�
void PrintSeqTree(SeqTree tree, int i);     //��ӡ��(�������)
void PrintSeqTree(SeqTree tree);            //��ӡ��(�洢�ṹ)
char GetSeqTreeRoot(SeqTree tree);          //��ȡ�����
int  GetSeqTreeNodeCount(SeqTree tree);     //��ȡ�������
int  GetSeqTreeDepth(SeqTree tree);         //��ȡ���������
void testSeqTree(void);                     //����


#endif // __SEQ_BI_TREE_H__
