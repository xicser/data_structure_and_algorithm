#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

//����
class Edge;
class Node {
public:
    Node(int id);

    int id;
    int in, out;
    vector<Node *> nexts;   //���ȶ���
    vector<Edge *> edges;   //���ȱ�
};

//��
class Edge {
public:
    Edge(int weight, Node *from, Node *to);

    int weight;
    Node *from;
    Node *to;
};

//ͼ
class Graph {
public:
    Graph();
    ~Graph();

    //����ͼ
    void createGraph1(int matrix[][3], int line);

    //������ȱ���
    void bfs(Node *start);

    //������ȱ���
    void dfs(Node *start);

    //��������
    void topologicalSort();

    //��С������Kruskal�㷨(ֻ����������ͼ)
    void mstKruskal();


    //��ȡid����
    Node *getNode(int id);

private:
    map<int, Node *> nodes;       //���㼯��<id, Node Addr>
    set<Edge *> edges;            //�߼���
};



#endif // __GRAPH_H__
