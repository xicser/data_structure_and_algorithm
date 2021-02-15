#ifndef __SEQ_BI_TREE_H__
#define __SEQ_BI_TREE_H__

using namespace std;

#define MAX_SIZE (1024)

typedef signed char ElemType;

//定义顺序树类型
typedef ElemType SeqTree[MAX_SIZE];

void InitSeqTree(SeqTree tree);             //初始化空二叉树
void CreatSeqTree(SeqTree tree, int i);     //i为数组的下标
void PrintSeqTree(SeqTree tree, int i);     //打印树(遍历结点)
void PrintSeqTree(SeqTree tree);            //打印树(存储结构)
char GetSeqTreeRoot(SeqTree tree);          //获取根结点
int  GetSeqTreeNodeCount(SeqTree tree);     //获取结点总数
int  GetSeqTreeDepth(SeqTree tree);         //获取二叉树深度
void testSeqTree(void);                     //测试


#endif // __SEQ_BI_TREE_H__
