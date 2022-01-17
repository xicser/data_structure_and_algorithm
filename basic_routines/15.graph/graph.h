#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//顶点
class Edge;
class Node {
public:
    Node(int id);

    int extraDataDomain;    //额外数据域
    int id;
    int in, out;
    vector<Node *> nexts;   //出度顶点
    vector<Edge *> edges;   //出度边
};

//边
class Edge {
public:
    Edge(int weight, Node *from, Node *to);

    int weight;    //边的权重
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
    void dfs(Node* node, unordered_set<Node*>& hasVisited);

    //拓扑排序
    void topologicalSort();

    //最小生成树Kruskal算法(只适用于无向图)
    void mstKruskal();

    //最小生成树Prim算法(只适用于无向图)
    unordered_set<Edge*> mstPrim(int nodeId);

    //迪杰斯特拉
    unordered_map<Node*, int> dijkstra1(Node *startNode);
    unordered_map<Node*, int> dijkstra2(Node* startNode);
    unordered_map<Node*, int> dijkstra3(Node* startNode);

    //获取id顶点
    Node *getNode(int id);

private:
    Node* getMinNodeExceptLockNodes(unordered_set<Node*>& lockSet,
                                    unordered_map<Node*, int>& distanceMap);
    static int distanceInf;
    unordered_map<int, Node *> nodes;       //顶点集合<id, Node_Addr>
    unordered_set<Edge *> edges;            //边集合
};



#endif // __GRAPH_H__
