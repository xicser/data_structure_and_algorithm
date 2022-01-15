#include <iostream>
#include "graph.h"

using namespace std;

// [weight, from节点id, to节点id]
int matrix1[5][3] = {
7, 0, 4,
4, 1, 3,
3, 2, 3,
8, 2, 4,
6, 3, 4
};

// [weight, from节点id, to节点id]
int matrix2[18][3] = {
1, 1, 2,
1, 2, 1,
1, 2, 4,
1, 4, 2,
1, 4, 8,
1, 8, 4,
1, 8, 5,
1, 5, 8,
1, 2, 5,
1, 5, 2,
1, 1, 3,
1, 3, 1,
1, 3, 6,
1, 6, 3,
1, 3, 7,
1, 7, 3,
1, 6, 7,
1, 7, 6
};

// 有向无环图
int matrix3[7][3] = {
1, 0, 1,
1, 0, 2,
1, 1, 2,
1, 2, 3,
1, 2, 5,
1, 3, 4,
1, 4, 5
};

int matrix4[20][3] = {
6, 1, 2,
6, 2, 1,
1, 1, 3,
1, 3, 1,
5, 3, 4,
5, 4, 3,
5, 2, 3,
5, 3, 2,
5, 1, 4,
5, 4, 1,
3, 2, 5,
3, 5, 2,
6, 3, 5,
6, 5, 3,
4, 3, 6,
4, 6, 3,
2, 4, 6,
2, 6, 4,
6, 5, 6,
6, 6, 5
};

int matrix5[10][3] = {
 13, 0, 1,
 7 , 1, 6,
 9 , 1, 5,
 32, 0, 6,
 17, 5, 6,
 2 , 4, 5,
 8 , 0, 2,
 5 , 2, 3,
 6 , 3, 4,
 30, 0, 4,
};

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
//    test1();
    cout << "---------------------------------------" << endl;

//    test2();
    cout << "---------------------------------------" << endl;

//    test3();
    cout << "---------------------------------------" << endl;

//    test4();
    cout << "---------------------------------------" << endl;

    test5();
    cout << "---------------------------------------" << endl;


    return 0;
}


void test1()
{
    Graph graph1;
    graph1.createGraph1(matrix1, 5);

    Node *nodeStart1 = graph1.getNode(0);
    graph1.bfs(nodeStart1);
    graph1.dfs(nodeStart1);

    nodeStart1 = graph1.getNode(1);
    graph1.bfs(nodeStart1);
    graph1.dfs(nodeStart1);

    nodeStart1 = graph1.getNode(2);
    graph1.bfs(nodeStart1);
    graph1.dfs(nodeStart1);

    nodeStart1 = graph1.getNode(3);
    graph1.bfs(nodeStart1);
    graph1.dfs(nodeStart1);

    nodeStart1 = graph1.getNode(4);
    graph1.bfs(nodeStart1);
    graph1.dfs(nodeStart1);
}

void test2()
{
    Graph graph2;
    graph2.createGraph1(matrix2, 18);

    Node *nodeStart2 = graph2.getNode(1);
    graph2.bfs(nodeStart2);
    graph2.dfs(nodeStart2);

    nodeStart2 = graph2.getNode(2);
    graph2.bfs(nodeStart2);
    graph2.dfs(nodeStart2);

    nodeStart2 = graph2.getNode(4);
    graph2.bfs(nodeStart2);
    graph2.dfs(nodeStart2);
}

void test3()
{
    Graph graph;
    graph.createGraph1(matrix3, 7);
    graph.topologicalSort();
}

void test4()
{
    Graph graph;
    graph.createGraph1(matrix4, 20);
    graph.mstKruskal();
    printf("\n");
    graph.mstPrim(3);
}

void test5()
{
    Graph graph1;
    graph1.createGraph1(matrix5, 10);
    Node* nodeStart = graph1.getNode(1);
    unordered_map<Node*, int> result = graph1.dijkstra1(nodeStart);
    for (auto it : result) {
        Node* node = it.first;
        int cnt = it.second;
        printf("%d %d\n", node->id, cnt);
    }

}
