#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include "huffmanTree.h"

using namespace std;


/*
选出权值最小的两个结点的下标
*/
static void getWeightMinimumTwo(HuffmanTree huffTree, int len, int &indexMin, int &indexSubMin)
{
    //先找最小权重的下标
    int minWeight = 99999999;
    for (int i = 1; i <= len; i++) {
        if (huffTree[i].parent == 0) {
            if (minWeight > huffTree[i].weight) {
                minWeight = huffTree[i].weight;
                indexMin = i;
            }
        }
    }

    //再找次小权重的下标
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
构造哈弗曼树
huffTree: 哈弗曼树的数组首地址
leaves:   叶子结点权重数组
leafCnt:  叶子结点个数

n = 8;
W = {7, 19, 2, 6, 32, 3, 21, 10}; //7 19 2 6 32 3 21 10
*/
void createHuffTree(HuffmanTree &huffTree, int *leavesWeight, char *leavesValue, int leafCnt)
{
    int arrayLen = (2 * leafCnt - 1) + 1;  //[0]不用
    huffTree = new HTNode[arrayLen];
    int last = arrayLen - 1;

    //初始化
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

    //生成哈夫曼树
    for (int i = leafCnt + 1; i <= last; i++) {
        int indexMin, indexSubMin;
        getWeightMinimumTwo(huffTree, i - 1, indexMin, indexSubMin);

        huffTree[indexMin].parent = i;
        huffTree[indexSubMin].parent = i;
        huffTree[i].weight = huffTree[indexMin].weight + huffTree[indexSubMin].weight;
        huffTree[i].lch = indexMin;
        huffTree[i].rch = indexSubMin;
    }

    //打印输出
    for (int i = 1; i < arrayLen; i++) {
        printf("(%2d) ", i);
        printf("%4d ", huffTree[i].weight);
        printf("%4d ", huffTree[i].parent);
        printf("%4d ", huffTree[i].lch);
        printf("%4d\n", huffTree[i].rch);
    }
    printf("\n");
}

/* 生成哈夫曼编码 */
void createHuffEncode(HuffmanTree huffTree, int leafCnt)
{
    //遍历所有叶子结点
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

        //反一下, 输出
        reverse(code.begin(), code.end());
        for (unsigned int j = 0; j < code.size(); j++) {
            printf("%c", code[j]);
        }
        printf("\n");
    }
}

/* 破解哈夫曼编码 */
void createHuffDecode(string huffCode, HuffmanTree huffTree, int rootIndex)
{
    int newRoot = rootIndex;

    for (unsigned int i = 0; i < huffCode.size(); i++) {

        newRoot = huffCode[i] == '0' ?
               huffTree[newRoot].lch :
               huffTree[newRoot].rch;

        //判断是否到达叶子结点
        if (huffTree[newRoot].rch == 0 && huffTree[newRoot].lch == 0) {

            printf("%c ", huffTree[newRoot].value);

            //重回根结点
            newRoot = rootIndex;
        }
    }
}

/* 先序遍历哈夫曼树 */
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
    printf("请输入叶子结点个数:\n");
    scanf("%d", &leafCnt);
    int leavesWeight[leafCnt];
    char leavesValue[leafCnt];

    printf("请输入%d个叶子结点的值:\n", leafCnt);
    for (int i = 0; i < leafCnt; i++) {
        cin >> leavesValue[i];
    }

    printf("请输入%d个叶子结点的权重:\n", leafCnt);
    for (int i = 0; i < leafCnt; i++) {
        cin >> leavesWeight[i];
    }

    createHuffTree(huffTree, leavesWeight, leavesValue, leafCnt);

    printf("先序遍历哈夫曼树：\n");
    huffTraverse(huffTree, 2 * leafCnt - 1);

    printf("\n\n生成哈夫曼编码：\n");
    createHuffEncode(huffTree, leafCnt);

    printf("\n破解哈夫曼编码:\n");
    printf("请输入待解码二进制序列:");
    cin >> huffCode;
    printf("\n破解序列为:\n");
    createHuffDecode(huffCode, huffTree, 2 * leafCnt - 1);
    printf("\n");

    delete huffTree;
}
