#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
void createHuffTree(HuffmanTree &huffTree, int *leavesWeight, char *leavesValue, int leafCnt)
{
    int arrayLen = (2 * leafCnt - 1) + 1;  //[0]����
    huffTree = new HTNode[arrayLen];
    int last = arrayLen - 1;

    //��ʼ��
    for (int i = 1; i <= last; i++) {
        if (i <= leafCnt) {
            huffTree[i].value = leavesValue[i - 1];
            huffTree[i].weight = leavesWeight[i - 1];
        } else {
            huffTree[i].value = 0;
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

/* ���ɹ��������� */
void createHuffEncode(HuffmanTree huffTree, int leafCnt)
{
    //��������Ҷ�ӽ��
    for (int i = 1; i <= leafCnt; i++) {

        vector<char> code;
        code.clear();

        int parent = huffTree[i].parent;
        int last = i;
        while (parent != 0) {
            if (last == huffTree[parent].lch) {
                code.push_back('0');
            } else if (last == huffTree[parent].rch) {
                code.push_back('1');
            }
            last = parent;
            parent = huffTree[parent].parent;
        }

        //��һ��, ���
        reverse(code.begin(), code.end());
        for (unsigned int j = 0; j < code.size(); j++) {
            printf("%c", code[j]);
        }
        printf("\n");
    }
}

/* �ƽ���������� */
void createHuffDecode(string huffCode, HuffmanTree huffTree, int rootIndex)
{
    int newRoot = rootIndex;

    for (unsigned int i = 0; i < huffCode.size(); i++) {

        newRoot = huffCode[i] == '0' ?
               huffTree[newRoot].lch :
               huffTree[newRoot].rch;

        //�ж��Ƿ񵽴�Ҷ�ӽ��
        if (huffTree[newRoot].rch == 0 && huffTree[newRoot].lch == 0) {

            printf("%c ", huffTree[newRoot].value);

            //�ػظ����
            newRoot = rootIndex;
        }
    }
}

/* ��������������� */
void huffTraverse(HuffmanTree huffTree, int rootIndex)
{
    if (rootIndex == 0) {
        return;
    }

    if (huffTree[rootIndex].value != 0) {
        printf("%c", huffTree[rootIndex].value);
    }
    printf("(%d) ", rootIndex);
    huffTraverse(huffTree, huffTree[rootIndex].lch);
    huffTraverse(huffTree, huffTree[rootIndex].rch);
}

void testHuff(void)
{
    string huffCode;
    HuffmanTree huffTree;

    int leafCnt;
    printf("������Ҷ�ӽ�����:\n");
    scanf("%d", &leafCnt);
    int leavesWeight[leafCnt];
    char leavesValue[leafCnt];

    printf("������%d��Ҷ�ӽ���ֵ:\n", leafCnt);
    for (int i = 0; i < leafCnt; i++) {
        cin >> leavesValue[i];
    }

    printf("������%d��Ҷ�ӽ���Ȩ��:\n", leafCnt);
    for (int i = 0; i < leafCnt; i++) {
        cin >> leavesWeight[i];
    }

    createHuffTree(huffTree, leavesWeight, leavesValue, leafCnt);

    printf("�����������������\n");
    huffTraverse(huffTree, 2 * leafCnt - 1);

    printf("\n\n���ɹ��������룺\n");
    createHuffEncode(huffTree, leafCnt);

    printf("\n�ƽ����������:\n");
    printf("��������������������:");
    cin >> huffCode;
    printf("\n�ƽ�����Ϊ:\n");
    createHuffDecode(huffCode, huffTree, 2 * leafCnt - 1);
    printf("\n");

    delete huffTree;
}
