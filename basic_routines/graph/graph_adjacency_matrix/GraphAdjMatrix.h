/*
无向图在邻接矩阵上的实现
*/

#ifndef GRAPHADJMATRIX_H
#define GRAPHADJMATRIX_H

typedef char ElemtType;

//顶点
typedef struct {
    int id;          //顶点id
    ElemtType data;  //顶点数据
} Vertex_t;


//基于邻接矩阵的图
class GraphAdjMatrix
{
public:
    GraphAdjMatrix(int vetexCount);
    ~GraphAdjMatrix();

    void DFSRecursionPrepare(void); //递归深搜准备
    //递归法深度优先搜索, startVertexId表示最开始要访问的那个顶点的id
    void DFSRecursion(int startVertexId);

    //非递归深搜
    void DFS(int startVertexId);

    //广搜
    void BFS(int startVertexId);

private:
    Vertex_t *vertexes; //顶点列表
    int vetexCount;     //顶点数量

    bool **matrix;      //邻接矩阵
    bool *isVisited;    //dfs遍历时, 表征顶点是否被访问过
};

#endif // GRAPHADJMATRIX_H
