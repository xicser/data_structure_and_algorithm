/*
无向图在邻接矩阵上的实现
*/

#ifndef GRAPHADJMATRIX_H
#define GRAPHADJMATRIX_H

#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef char ElemtType;

//无穷远
#define INFINITE 9999999

//顶点
typedef struct {
    int id;          //顶点id
    ElemtType data;  //顶点数据
} Vertex_t;

//边
typedef struct {
    int v1;          //顶点1
    int v2;          //顶点2
    int distance;    //距离
} Edge_t;

//基于邻接矩阵的图
class GraphAdjMatrix
{
public:
    GraphAdjMatrix(int vertexCount);
    ~GraphAdjMatrix();

    void DFSRecursionPrepare(void); //递归深搜准备
    //递归法深度优先搜索, startVertexId表示最开始要访问的那个顶点的id
    void DFSRecursion(int startVertexId);

    //非递归深搜
    void DFS(int startVertexId);

    //广搜
    void BFS(int startVertexId);

    //MST最小生成树
    void MST_Prim(int startVertexId);
    void MST_Kruskal(void);

private:
    Vertex_t *vertexes; //顶点列表
    int vertexCount;    //顶点数量

    int **matrix;      //邻接矩阵
    bool *isVisited;    //dfs遍历时, 表征顶点是否被访问过

    //获取id顶点的根
    int getRoot(int id, int Parenting[][2]);
};

#endif // GRAPHADJMATRIX_H
