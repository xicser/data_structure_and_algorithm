#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__


typedef struct {
    char value;
    int weight;
    int parent, lch, rch;
} HTNode, *HuffmanTree;


void testHuff(void);

#endif // __HUFFMAN_TREE_H__
