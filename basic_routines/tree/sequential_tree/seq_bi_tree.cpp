/*
��������˳��洢ʵ��
˳��洢�ʺ���ȫ������(��������),
���ڸ�����, ���������ȫ������, Ҳ���Դ洢, ���ǻ��д����洢�ռ��˷�
*/

#include <iostream>
#include <stdio.h>
#include "seq_bi_tree.h"
#include <math.h>
#include <cmath>

void InitSeqTree(SeqTree tree)
{
	//���ַ������е�����Ԫ�س�ʼ����ֵ
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

	PrintSeqTree(tree , 2 * i + 1);     //ע��˴����±���㲻����ȫ�����������2 * i �� 2 * i + 1
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
    printf("�밴������������̬, ���ϵ���, �����ҵ�˳������������, �����㲻����, ����x: \n");

    CreatSeqTree(tree);
    printf("����������� = %c\n", GetSeqTreeRoot(tree));
    printf("������������ = %d\n", GetSeqTreeNodeCount(tree));
    printf("��������� = %d\n", GetSeqTreeDepth(tree));
    PrintSeqTree(tree);
	PrintSeqTree(tree, 0);
}
