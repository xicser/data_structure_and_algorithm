#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
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
    vector<Edge> edges;     //出度边
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

private:
    map<int, Node> nodes;
    set<Edge> edges;





};



#endif // __GRAPH_H__
