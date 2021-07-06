#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
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
    vector<Edge> edges;     //���ȱ�
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

private:
    map<int, Node> nodes;
    set<Edge> edges;





};



#endif // __GRAPH_H__
