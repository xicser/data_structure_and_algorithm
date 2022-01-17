#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;

//顶点
class Edge;
class Node {
public:
    Node(int id) {
        this->id = id;
        this->in = 0;
        this->out = 0;
        this->extraDataDomain = 0;
        nexts.clear();
        edges.clear();
    }

    int id;
    int in, out;
    double extraDataDomain;
    vector<Node*> nexts;   //出度顶点
    vector<Edge*> edges;   //出度边
};

//边
class Edge {
public:
    Edge(double weight, Node* from, Node* to) {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }

    double weight;    //边的权重
    Node* from;
    Node* to;
};

//图
class Graph {
public:
    Graph() {
        nodes.clear();
        edges.clear();
    }
    ~Graph() {
        for (unordered_map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
            delete it->second;
        }
        for (unordered_set<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
            delete* it;
        }
    }

    //创建图
    //n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2],
    void createGraph1(int n, vector<vector<int>>& edges, vector<double>& succProb) {

        unordered_set<int> usedNode;
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < edges.size(); i++) {

                int fromId, toId;
                double weight = succProb[i];
                if (k == 0) {
                    fromId = edges[i][0];
                    toId = edges[i][1];
                }
                else {
                    fromId = edges[i][1];
                    toId = edges[i][0];
                }

                //记录当前已经用过的顶点id
                usedNode.insert(fromId);
                usedNode.insert(toId);

                Node* fromNode, *toNode;
                Edge* edge;
                if (nodes.find(fromId) == nodes.end()) {
                    fromNode = new Node(fromId);
                    nodes[fromId] = fromNode;
                }
                else {
                    fromNode = nodes[fromId];
                }

                if (nodes.find(toId) == nodes.end()) {
                    toNode = new Node(toId);
                    nodes[toId] = toNode;
                }
                else {
                    toNode = nodes[toId];
                }

                //新建一条边
                edge = new Edge(weight, fromNode, toNode);

                fromNode->out++;
                toNode->in++;
                fromNode->nexts.push_back(toNode);
                fromNode->edges.push_back(edge);

                this->edges.insert(edge);
            }
        }

        //单独顶点
        for (int i = 0; i < n; i++) {
            if (usedNode.count(i) == 0) {
                Node* node = new Node(i);
                nodes[i] = node;
            }
        }
    }

    struct cmpNode
    {
        bool operator () (Node* n1, Node* n2) {
            return n1->extraDataDomain < n2->extraDataDomain;
        }
    };

    //迪杰斯特拉
    double dijkstra(int start, int end) {

        Node* startNode = nodes[start];
        //从startNode出发到所有点的最大概率的值
        //key: 从startNode出发到key
        //value: 从startNode出发到key当前的最大概率值
        unordered_map<Node*, double> probMap;

        //大根堆
        priority_queue<Node*, vector<Node*>, cmpNode> nodesQueue;

        for (auto& it : nodes) {
            Node* node = it.second;
            if (node == startNode) {
                node->extraDataDomain = 1;
                nodesQueue.push(node);
            }
            else {
                node->extraDataDomain = 0;
                nodesQueue.push(node);
            }
        }

        //已经计算好的点, 之后不能再动了
        unordered_set<Node*> lockSet;

        while (nodesQueue.empty() == false) {
            Node* maxNode = nodesQueue.top();
            nodesQueue.pop();

            double probCur = maxNode->extraDataDomain;

            //应对1处的重复加入问题
            if (probMap.count(maxNode) != 0) {
                continue;
            }

            for (Edge* edgeNext : maxNode->edges) {
                Node* to = edgeNext->to;
                if (lockSet.count(to) != 0) {
                    continue;
                }

                double newProb = probCur * edgeNext->weight;

                //如果通过新的桥连点到它所能到的节点的概率比以前大, 那么更新概率
                if (newProb > to->extraDataDomain) {
                    to->extraDataDomain = newProb;
                    nodesQueue.push(to);
                }
            }
            lockSet.insert(maxNode);    //把这个节点锁住
            probMap[maxNode] = probCur; //保存结果
        }

        return probMap[ nodes[end] ];
    }

private:
    unordered_map<int, Node*> nodes;       //顶点集合<id, Node_Addr>
    unordered_set<Edge*> edges;            //边集合
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        Graph graph;
        graph.createGraph1(n, edges, succProb);
        return graph.dijkstra(start, end);
    }
};

int main()
{
    vector<vector<int>> edges = { {0,1} ,{1,2},{0,2} };
    vector<double> succProb = { 0.5, 0.5, 0.3 };
    Solution sol;
    cout << sol.maxProbability(3, edges, succProb, 0, 2) << endl;
}

