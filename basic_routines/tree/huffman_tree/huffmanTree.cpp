#include <iostream>
#include <stdio.h>
#include "huffmanTree.h"

using namespace std;


/*
ѡ��Ȩֵ��С�����������±�
*/
static void getWeightMinimumTwo(HuffmanTree huffTree, int len, int &indexMin, int &indexSubMin)
{
    //������СȨ�ص��±�
    int minWeight = 99999999;
    for (int i = 1; i <= len; i++) {
        if (huffTree[i].parent == 0) {
            if (minWeight > huffTree[i].weight) {
                minWeight = huffTree[i].weight;
                indexMin = i;
            }
        }
    }

    //���Ҵ�СȨ�ص��±�
    int subMinWeight = 99999999;
    for (int i = 1; i <= len; i++) {
        if (huffTree[i].parent == 0 && i != indexMin) {

            if (subMinWeight > huffTree[i].weight) {
                subMinWeight = huffTree[i].weight;
                indexSubMin = i;
            }
        }
    }
}

/*
�����������
huffTree: ���������������׵�ַ
leaves:   Ҷ�ӽ��Ȩ������
leafCnt:  Ҷ�ӽ�����

n = 8;
W = {7, 19, 2, 6, 32, 3, 21, 10}; //7 19 2 6 32 3 21 10
*/
void createHuff(HuffmanTree &huffTree, int *leavesWeight, int leafCnt)
{
    int arrayLen = (2 * leafCnt - 1) + 1;  //[0]����
    huffTree = new HTNode[arrayLen];
    int last = arrayLen - 1;

    //��ʼ��
    for (int i = 1; i <= last; i++) {
        if (i <= leafCnt) {
            huffTree[i].weight = leavesWeight[i - 1];
        } else {
            huffTree[i].weight = 0;
        }
        huffTree[i].parent = 0;
        huffTree[i].rch = 0;
        huffTree[i].lch = 0;
    }

    //���ɹ�������
    for (int i = leafCnt + 1; i <= last; i++) {
        int indexMin, indexSubMin;
        getWeightMinimumTwo(huffTree, i - 1, indexMin, indexSubMin);

        huffTree[indexMin].parent = i;
        huffTree[indexSubMin].parent = i;
        huffTree[i].weight = huffTree[indexMin].weight + huffTree[indexSubMin].weight;
        huffTree[i].lch = indexMin;
        huffTree[i].rch = indexSubMin;
    }

    //��ӡ���
    for (int i = 1; i < arrayLen; i++) {
        printf("(%2d) ", i);
        printf("%4d ", huffTree[i].weight);
        printf("%4d ", huffTree[i].parent);
        printf("%4d ", huffTree[i].lch);
        printf("%4d\n", huffTree[i].rch);
    }
    printf("\n");
}

/* ��������������� */
void huffTraverse(HuffmanTree huffTree, int rootIndex)
{
    if (rootIndex == 0) {
        return;
    }

    printf("%d ", rootIndex);
    huffTraverse(huffTree, huffTree[rootIndex].lch);
    huffTraverse(huffTree, huffTree[rootIndex].rch);
}

void testHuff(void)
{
    HuffmanTree huffTree;

    int leafCnt;
    printf("������Ҷ�ӽ�����:\n");
    scanf("%d", &leafCnt);
    int leavesWeight[leafCnt];

    printf("������%d��Ҷ�ӽ���Ȩ��:\n", leafCnt);
    for (int i = 0; i < leafCnt; i++) {
        scanf("%d", &leavesWeight[i]);
    }

    createHuff(huffTree, leavesWeight, leafCnt);

    printf("�����������������\n");
    huffTraverse(huffTree, 2 * leafCnt - 1);

    delete huffTree;
}
