/*
无向图(网)在邻接矩阵上的实现
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 0 1
0 1 1 0 0 0
0 0 0 1 0 0

input vetexes:
ABCDEF
input matrix:
0 6 1 5 0 0
6 0 5 0 3 0
1 5 0 5 6 4
5 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

Recursion DFS result = A B C D F E
No recursion DFS result = A D F E C B
No recursion BFS result = A B C D E F


*/

#include "UndirectedGraphAdjMatrix.h"

UndirectedGraphAdjMatrix::UndirectedGraphAdjMatrix(int vertexCount)
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
            cin >> matrix[i][j];
        }
    }
    cout << "inputted matrix: " << endl;
    for (int i = 0; i < this->vertexCount; i++) {
        for (int j = 0; j < this->vertexCount; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //顶点访问标记
    isVisited = new bool[this->vertexCount];
}

UndirectedGraphAdjMatrix::~UndirectedGraphAdjMatrix()
{
    delete []vertexes;
    delete []isVisited;

    for(int i = 0; i < this->vertexCount; i++) {
        delete [] matrix[i];
    }
    delete []matrix;
}

/* 递归深搜准备 */
void UndirectedGraphAdjMatrix::DFSRecursionPrepare(void)
{
    for (int i = 0; i < this->vertexCount; i++) {
        isVisited[i] = false;
    }
    cout << endl;
    cout << "Recursion DFS result = ";
}

/* 递归法深度优先搜索 */
void UndirectedGraphAdjMatrix::DFSRecursion(int startVertexId)
{
    cout << vertexes[startVertexId].data << " "; //访问顶点的数据
    isVisited[startVertexId] = true;             //标记该顶点已经被访问过

    for (int i = 0; i < this->vertexCount; i++) {
        //如果和当前顶点有通路, 并且没有被访问过, 则访问它
        if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
            DFSRecursion(i);
        }
    }
}

/* 非递归深搜 */
void UndirectedGraphAdjMatrix::DFS(int startVertexId)
{
    stack<int> st;
    for (int i = 0; i < this->vertexCount; i++) {
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
        for (int i = 0; i < this->vertexCount; i++) {
            if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
                st.push(i);
            }
        }
    }
}

/* 非递归广搜 */
void UndirectedGraphAdjMatrix::BFS(int startVertexId)
{
	queue<int> que;

    for (int i = 0; i < this->vertexCount; i++) {
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

        for (int i = 0; i < this->vertexCount; i++) {
            if (matrix[startVertexId][i] != 0 && isVisited[i] == false) {
                cout << vertexes[i].data << " ";
                isVisited[i] = true;
                que.push(i);
            }
        }
    }
}

//最小生成树的Prim算法
void UndirectedGraphAdjMatrix::MST_Prim(int startVertexId)
{
    cout << endl;
    cout << "MST_Prim result = " << endl;

    vector<int> vecU; //顶点u集合(已经加入的顶点集合)
    vector<int> vecV; //顶点v集合(剩下的顶点集合)

    //初始化
    vecU.push_back(startVertexId); //把第一个顶点放在u中
    //把剩下的顶点放在v中
    for (int i = 0; i < this->vertexCount; i++) {
        if (i != startVertexId) {
            vecV.push_back(i);
        }
    }

    while (vecV.size() > (unsigned int)0) {

        //针对v中的每个顶点,
        //计算该顶点到u中各个顶点的边的代价,
        //记录这些边中代价最小的那个
        vector<Edge_t> edges;
        edges.clear();
        for (unsigned int i = 0; i < vecV.size(); i++) {

            Edge_t minDisEdge;
            int minDistance = INFINITE;  //假设顶点间的距离为无穷大
            bool hasConnected = false;
            for (unsigned int j = 0; j < vecU.size(); j++) {
                if (matrix[ vecV[i] ][ vecU[j] ] != 0 &&
                    matrix[ vecV[i] ][ vecU[j] ] < minDistance) {

                    minDistance = matrix[ vecV[i] ][ vecU[j] ];
                    minDisEdge.v1 = vecU[j];
                    minDisEdge.v2 = vecV[i];
                    minDisEdge.distance = minDistance;

                    hasConnected = true;
                }
            }
            if (hasConnected == true) {
                edges.push_back(minDisEdge);
            } else {
                minDisEdge.distance = INFINITE;
                edges.push_back(minDisEdge);
            }
        }

        //按照代价, 将边排序
        sort(edges.begin(), edges.end(), [=](const Edge_t &e1, const Edge_t &e2) {
            return e1.distance < e2.distance;
        });

        //选代价最小的那个边, 打印输出
        printf("%c---%c(%d)\n", vertexes[edges[0].v1].data, vertexes[edges[0].v2].data, edges[0].distance);

        //给u加顶点
        vecU.push_back(edges[0].v2);
        //给v删顶点
        for (vector<int>::iterator it = vecV.begin(); it != vecV.end(); it++) {
            if (*it == edges[0].v2) {
                vecV.erase(it);
                break;
            }
        }
    }
}

//最小生成树的Kruskal算法
void UndirectedGraphAdjMatrix::MST_Kruskal(void)
{
    cout << "MST_Kruskal result = " << endl;

    vector<Edge_t> edges;

    //先从邻接矩阵中获取边的信息
    for (int i = 0; i < this->vertexCount; i++) {
        for (int j = 0; j < this->vertexCount; j++) {

            if (i < j && matrix[i][j] != 0) {

                Edge_t edgeTmp;
                edgeTmp.v1 = i;
                edgeTmp.v2 = j;
                edgeTmp.distance = matrix[i][j];
                edges.push_back(edgeTmp);
            }
        }
    }
    //按照代价, 将边排序
    sort(edges.begin(), edges.end(), [=](const Edge_t &e1, const Edge_t &e2) {
        return e1.distance < e2.distance;
    });

    //创建并查集
    int Parenting[vertexCount][2]; //这里使用的是类似树的双亲表示法
    for (int i = 0; i < vertexCount; i++) {
        Parenting[i][0] = i;
        Parenting[i][1] = -1; //根结点
    }

    //从小到大依次选边
    int edgeCnt = 0;
    for (unsigned int i = 0; i < edges.size(); i++) {

        //判断这个边的两个顶点在不在同一颗树上
        int root1 = getRoot(edges[i].v1, Parenting);
        int root2 = getRoot(edges[i].v2, Parenting);
        if (root1 != root2) {
            //满足条件, 打印输出
            printf("%c---%c(%d)\n", vertexes[edges[i].v1].data,
                                    vertexes[edges[i].v2].data,
                                    edges[i].distance);
            edgeCnt++;

            //合并顶点到同一棵树上
            Parenting[root1][1] = root2;
        }

        if (edgeCnt == vertexCount - 1) {
            break;
        }
    }
}

/* 获取id顶点的根 */
int UndirectedGraphAdjMatrix::getRoot(int id, int Parenting[][2])
{
    while (Parenting[id][1] != -1) {
        id = Parenting[id][1];
    }

    return id;
}
