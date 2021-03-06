/*
有向图(网)在邻接矩阵上的实现
0 13 8 0 30 0 32
0  0 0 0  0 9  7
0  0 0 5  0 0  0
0  0 0 0  6 0  0
0  0 0 0  0 2  0
0  0 0 0  0 0  17
0  0 0 0  0 0  0
*/

#include "DirectedGraphAdjMatrix.h"

DirectedGraphAdjMatrix::DirectedGraphAdjMatrix(int vertexCount)
{
    this->vertexCount = vertexCount;

    //创建顶点表
    cout << "input vetexes:" << endl;
    vertexes = new Vertex_t[this->vertexCount];
    for (int i = 0; i < this->vertexCount; i++) {
        vertexes[i].id = i;
        cin >> vertexes[i].data;
    }
    cout << "inputted vetexes: ";
    for (int i = 0; i < this->vertexCount; i++) {
        cout << vertexes[i].data;
    }
    cout << endl;

    //创建邻接矩阵
    cout << "input matrix:" << endl;
    matrix = new int*[this->vertexCount];
    for(int i = 0; i < this->vertexCount; i++) {
        matrix[i] = new int[this->vertexCount];
    }
    for (int i = 0; i < this->vertexCount; i++) {
        for (int j = 0; j < this->vertexCount; j++) {
            int inputTmp;
            cin >> inputTmp;
            if (inputTmp == 0) {
                matrix[i][j] = INFINITE;
            } else {
                matrix[i][j] = inputTmp;
            }
        }
    }
    cout << "inputted matrix: " << endl;
    for (int i = 0; i < this->vertexCount; i++) {
        for (int j = 0; j < this->vertexCount; j++) {
            if (matrix[i][j] == INFINITE) {
                printf("%2d ", 0);
            } else {
                printf("%2d ", matrix[i][j]);
            }
        }
        cout << endl;
    }
}

DirectedGraphAdjMatrix::~DirectedGraphAdjMatrix()
{
    delete []vertexes;

    for(int i = 0; i < this->vertexCount; i++) {
        delete [] matrix[i];
    }
    delete []matrix;
}

/* 迪杰斯特拉算法求最短路径 */
void DirectedGraphAdjMatrix::Dijkstra(int startVertexId)
{
    vector<Route_t> routes;
    vector<Route_t> resultRoutes;

    //初始化
    int disMin = INFINITE, disMinIndex;
    for (int i = 0; i < vertexCount; i++) {  //i就是顶点ID
        if (i == startVertexId) continue;

        Route_t routeTmp;
        routeTmp.id = i;
        int distance = matrix[startVertexId][i];
        if (distance < disMin) { //找出距离最小的那个
            disMin = distance;
            disMinIndex = i;
        }

        if (distance != INFINITE) {
            routeTmp.distance = distance;
            routeTmp.vertexes.clear();
            routeTmp.vertexes.push_back(startVertexId);
            routeTmp.vertexes.push_back(i);
        } else {
            routeTmp.distance = INFINITE;
        }
        routeTmp.isDone = false;
        routes.push_back(routeTmp);
    }
    //选出那个距离最短的
    routes[disMinIndex].isDone = true;
    //把这个结果存放到已完成vector中
    resultRoutes.push_back(routes[0]);

    //开始处理
//    int times = vertexCount - 2;
//    for (int i = ) {
//
//    }
}


