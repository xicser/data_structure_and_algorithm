#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

//顶点
class Edge;
class Node {
public:
    Node(int id);

    int id;
    int in, out;
    vector<Node *> nexts;   //出度顶点
    vector<Edge *> edges;   //出度边
};

//边
class Edge {
public:
    Edge(int weight, Node *from, Node *to);

    int weight;
    Node *from;
    Node *to;
};

//图
class Graph {
public:
    Graph();
    ~Graph();

    //创建图
    void createGraph1(int matrix[][3], int line);

    //广度优先遍历
    void bfs(Node *start);

    //深度优先遍历
    void dfs(Node *start);

    //拓扑排序
    void topologicalSort();

    //最小生成树Kruskal算法(只适用于无向图)
    void mstKruskal();


    //获取id顶点
    Node *getNode(int id);

private:
    map<int, Node *> nodes;       //顶点集合<id, Node Addr>
    set<Edge *> edges;            //边集合
};



#endif // __GRAPH_H__
