#include "graph.h"


Node::Node(int id)
{
    this->id = id;
    this->in = 0;
    this->out = 0;
    nexts.clear();
    edges.clear();
}

Edge::Edge(int weight, Node *from, Node *to)
{
    this->weight = weight;
    this->from = from;
    this->to = to;
}


Graph::Graph()
{
    nodes.clear();
    edges.clear();
}

Graph::~Graph()
{

}

/* 创建图
 matrix 所有的边
 N * 3的矩阵
 [weight, from节点上面的值，to节点上面的值]
 [ 5 , 0 , 7]
 [ 3 , 0,  1]
*/
void Graph::createGraph1(int matrix[][3], int line)
{
    for (int i = 0; i < line; i++) {
        int weight = matrix[i][0];
        int from = matrix[i][1];
        int to = matrix[i][2];

        if (nodes.find(from) != nodes.end()) {
            nodes[from] = Node(from);
        }
        if (nodes.find(to) != nodes.end()) {
            nodes[to] = Node(to);
        }

    }
}
