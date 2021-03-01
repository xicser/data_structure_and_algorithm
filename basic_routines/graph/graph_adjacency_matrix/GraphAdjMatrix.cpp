/*
无向图在邻接矩阵上的实现

input vetexes:
123456
inputted vetexes: 123456
input matrix:
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 0 1
0 1 1 0 0 0
0 0 0 1 0 0

结果:
2 1 3 5 4 6
*/

#include "GraphAdjMatrix.h"
#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

GraphAdjMatrix::GraphAdjMatrix(int vetexCount)
{
    this->vetexCount = vetexCount;

    //创建顶点表
    cout << "input vetexes:" << endl;
    vertexes = new Vertex_t[this->vetexCount];
    for (int i = 0; i < this->vetexCount; i++) {
        vertexes[i].id = i;
        cin >> vertexes[i].data;
    }
    cout << "inputted vetexes: ";
    for (int i = 0; i < this->vetexCount; i++) {
        cout << vertexes[i].data;
    }
    cout << endl;

    //创建邻接矩阵
    cout << "input matrix:" << endl;
    matrix = new bool*[this->vetexCount];
    for(int i = 0; i < this->vetexCount; i++) {
        matrix[i] = new bool[this->vetexCount];
    }
    for (int i = 0; i < this->vetexCount; i++) {
        for (int j = 0; j < this->vetexCount; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "inputted matrix: " << endl;
    for (int i = 0; i < this->vetexCount; i++) {
        for (int j = 0; j < this->vetexCount; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //顶点访问标记
    isVisited = new bool[this->vetexCount];
}

GraphAdjMatrix::~GraphAdjMatrix()
{
    delete []vertexes;
    delete []isVisited;

    for(int i = 0; i < this->vetexCount; i++) {
        delete [] matrix[i];
    }
    delete []matrix;
}

/* 递归深搜准备 */
void GraphAdjMatrix::DFSRecursionPrepare(void)
{
    for (int i = 0; i < this->vetexCount; i++) {
        isVisited[i] = false;
    }
    cout << endl;
    cout << "Recursion DFS result = ";
}

/* 递归法深度优先搜索 */
void GraphAdjMatrix::DFSRecursion(int startVertexId)
{
    cout << vertexes[startVertexId].data << " "; //访问顶点的数据
    isVisited[startVertexId] = true;             //标记该顶点已经被访问过

    for (int i = 0; i < this->vetexCount; i++) {
        //如果和当前顶点有通路, 并且没有被访问过, 则访问它
        if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
            DFSRecursion(i);
        }
    }
}

/* 非递归深搜 */
void GraphAdjMatrix::DFS(int startVertexId)
{
    stack<int> st;
    for (int i = 0; i < this->vetexCount; i++) {
        isVisited[i] = false;
    }
    cout << endl;
    cout << "No recursion DFS result = ";

    st.push(startVertexId);
    isVisited[startVertexId] = true;
    while (st.empty() == false) {
        cout << vertexes[st.top()].data << " "; //访问该顶点
        startVertexId = st.top();
        st.pop();
        //寻找当前顶点的所有相邻顶点
        for (int i = 0; i < this->vetexCount; i++) {
            if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
                st.push(i);
                isVisited[i] = true;
            }
        }
    }

    cout << endl;
}
