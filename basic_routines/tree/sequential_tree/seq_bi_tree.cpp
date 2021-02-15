/*
二叉树的顺序存储实现
顺序存储适合完全二叉树(满二叉树),
对于该例程, 如果不是完全二叉树, 也可以存储, 但是会有大量存储空间浪费
*/

#include <iostream>
#include <stdio.h>
#include "seq_bi_tree.h"
#include <math.h>
#include <cmath>

void InitSeqTree(SeqTree tree)
{
	//将字符数组中的所有元素初始化赋值
	for(int i = 0; i < MAX_SIZE; i++) {
		tree[i] = -1;
	}
}

void CreatSeqTree(SeqTree tree)
{
    char ch;
    string input;
    cin >> input;

    for (unsigned int i = 0; i < input.length() ; i++) {
        ch = input[i];
        tree[i] = ch;
    }
}

void PrintSeqTree(SeqTree tree, int i)
{
	char ch;
	ch = tree[i];
	if (ch == -1 || ch == 'x') {
		return;
	}
    printf("%c", ch);

	PrintSeqTree(tree , 2 * i + 1);     //注意此处的下标计算不是完全二叉树里面的2 * i 和 2 * i + 1
	PrintSeqTree(tree , 2 * (i + 1));
}

static int getUsefulElemt(SeqTree tree)
{
	int cnt = 0;
	for(int i = 0; i < MAX_SIZE; i++) {
		if(tree[i] == -1) {
			continue;
		}
		cnt++;
	}
	return cnt;
}

void PrintSeqTree(SeqTree tree)
{
    int nodeCnt = getUsefulElemt(tree);
	for(int i = 0; i < nodeCnt; i++) {
		printf("%c", tree[i]);
	}
	printf("\n");
}

char GetSeqTreeRoot(SeqTree tree)
{
	return tree[0];
}

int GetSeqTreeNodeCount(SeqTree tree)
{
	int len = 0;
	for(int i = 0; i < MAX_SIZE; i++) {
		if(tree[i] == -1 || tree[i] == 'x') {
			continue;
		}
		len++;
	}
	return len;
}

int GetSeqTreeDepth(SeqTree tree)
{
    int nodeCnt = getUsefulElemt(tree);
	double log2N = log10(nodeCnt) / log10(2);
	return ((int)log2N + 1);
}

void testSeqTree(void)
{
    SeqTree tree;
    InitSeqTree(tree);
    printf("请按满二叉树的形态, 由上到下, 由左到右的顺序依次输入结点, 如果结点不存在, 输入x: \n");

    CreatSeqTree(tree);
    printf("二叉树根结点 = %c\n", GetSeqTreeRoot(tree));
    printf("二叉树结点个数 = %d\n", GetSeqTreeNodeCount(tree));
    printf("二叉树深度 = %d\n", GetSeqTreeDepth(tree));
    PrintSeqTree(tree);
	PrintSeqTree(tree, 0);
}
