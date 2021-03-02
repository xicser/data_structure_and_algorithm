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

深搜结果:
2 1 3 5 4 6

广搜结果:
2 1 5 3 4 6
*/

#include "GraphAdjMatrix.h"
#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>

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

    while (st.empty() == false) {

        startVertexId = st.top();
        if (isVisited[startVertexId] == false) {
            cout << vertexes[startVertexId].data << " "; //访问该顶点
            isVisited[startVertexId] = true;
        }
        st.pop();

        //寻找当前顶点的所有未被访问的相邻顶点
        for (int i = 0; i < this->vetexCount; i++) {
            if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
                st.push(i);
            }
        }
    }

    cout << endl;
}

/* 非递归广搜 */
void GraphAdjMatrix::BFS(int startVertexId)
{
	queue<int> que;

    for (int i = 0; i < this->vetexCount; i++) {
        isVisited[i] = false;
    }
    cout << endl;
    cout << "No recursion BFS result = ";

    //先访问第一个顶点
    cout << vertexes[startVertexId].data << " ";
    isVisited[startVertexId] = true;
    que.push(startVertexId);

	while (!que.empty())//若队列非空
	{
	    startVertexId = que.front();
	    que.pop();

        for (int i = 0; i < this->vetexCount; i++) {
            if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
                cout << vertexes[i].data << " ";
                isVisited[i] = true;
                que.push(i);
            }
        }
    }

    cout << endl;
}
