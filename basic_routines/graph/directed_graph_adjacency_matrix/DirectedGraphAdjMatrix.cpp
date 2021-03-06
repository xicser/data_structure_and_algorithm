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
    map<int, Route_t> routes;
    vector<Route_t> resultRoutes;

    //初始化
    int disMin = INFINITE + 10, disMinIndex;
    for (int i = 0; i < vertexCount; i++) {  //i就是顶点ID
        if (i == startVertexId) continue;

        Route_t routeTmp;
        int distance = matrix[startVertexId][i];
        if (disMin > distance) {
            //选出那个距离最短的
            disMin = distance;
            disMinIndex = i;
        }
        routeTmp.distance = distance;
        routeTmp.vertexes.clear();
        routeTmp.vertexes.push_back(startVertexId);
        routeTmp.vertexes.push_back(i);
        routeTmp.isDone = false;
        routes[i] = routeTmp;
    }
    //把距离最短的那个结果存放到已完成vector中
    resultRoutes.push_back(routes[disMinIndex]);
    routes[disMinIndex].isDone = true;

    //开始处理
    int times = vertexCount - 2;
    int startNew = disMinIndex;
    int lastDist = routes[disMinIndex].distance;
    for (int i = 0; i < times; i++) {

        int index, disMinTmp = INFINITE + 10;   //index记录最小的那个的下标(ID)
        for (int j = 0; j < vertexCount; j++) { //j就是顶点ID
            if (j == startVertexId) continue;
            if (routes[j].isDone == true) continue;   //已经计算过的顶点就不用算了

            //需要更新
            if (lastDist + matrix[startNew][j] < routes[j].distance) {
                Route_t routeTmp;
                routeTmp.isDone = false;
                routeTmp.distance = lastDist + matrix[startNew][j];
                routeTmp.vertexes.clear();
                for (unsigned int k = 0; k < resultRoutes[i].vertexes.size(); k++) {
                    routeTmp.vertexes.push_back( resultRoutes[i].vertexes[k] );
                }
                routeTmp.vertexes.push_back(j);
                routes[j] = routeTmp;
            }

            //记录最小distance的那个下标(ID)
            if (routes[j].distance < disMinTmp) {
                disMinTmp = routes[j].distance;
                index = j;
            }
        }
        //将本轮最小的那个加入resultRoutes
        resultRoutes.push_back(routes[index]);
        routes[index].isDone = true;
        startNew = index;
        lastDist = routes[index].distance;
    }

    //输出
    for (unsigned int i = 0; i < resultRoutes.size(); i++) {
        int destIndex = resultRoutes[i].vertexes.size() - 1;
        printf("-->%c(id = %d), distance = %d \n",
                    vertexes[ resultRoutes[i].vertexes[destIndex] ].data,
                    resultRoutes[i].vertexes[destIndex],
                    resultRoutes[i].distance);
        for (unsigned int j = 0; j < resultRoutes[i].vertexes.size(); j++) {
            int id = resultRoutes[i].vertexes[j];
            printf("%c(%d) ", vertexes[id].data, id);
        }
        printf("\n\n");
    }
}
