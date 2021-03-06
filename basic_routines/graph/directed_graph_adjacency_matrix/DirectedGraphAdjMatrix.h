/*
有向图(网)在邻接矩阵上的实现
*/

#ifndef DIRECTED_GRAPHADJMATRIX_H
#define DIRECTED_GRAPHADJMATRIX_H

#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef char ElemtType;

//无穷远
#define INFINITE 99999999

//顶点
typedef struct {
    int id;          //顶点id
    ElemtType data;  //顶点数据
} Vertex_t;

//路径
typedef struct {
    int id;               //顶点id
    bool isDone;          //id顶点的最短路径是否已经求出
    int distance;         //路径长度
    vector<int> vertexes; //路径上的顶点
} Route_t;

//基于邻接矩阵的图
class DirectedGraphAdjMatrix
{
public:
    DirectedGraphAdjMatrix(int vertexCount);
    ~DirectedGraphAdjMatrix();

    void Dijkstra(int startVertexId); //迪杰斯特拉算法求最短路径

private:
    Vertex_t *vertexes; //顶点列表
    int vertexCount;    //顶点数量
    int **matrix;      //邻接矩阵
};

#endif // GRAPHADJMATRIX_H
